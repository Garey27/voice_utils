#include <amxx/api.h>
#include <amxx/string.h>
#include <voice_utils/revoice_api.h>

#include <soxr.h>
#include <unordered_map>

#include "libnyquist/Decoders.h"

#include "metamod/api.h"
#include "metamod/utils.h"
extern GlobalVars* g_global_vars;
nqr::NyquistIO loader;
#define PARAMS_COUNT            (params[0] / sizeof(cell))

#ifndef _MSC_VER
#define likely(x)      __builtin_expect(!!(x), 1)
#define unlikely(x)    __builtin_expect(!!(x), 0)
#else
#define likely(x)      (x)
#define unlikely(x)    (x)
#endif
#define CHECK_ISPLAYER(x)       if (unlikely(params[x] <= 0 || params[x] > g_global_vars->max_clients)) { AmxxApi::log_error(amx, AmxError::Native, "%s: invalid player index %i [%s]", __FUNCTION__, params[x], #x); return false; }

extern IRevoiceApi* g_pRevoiceApi;
std::unordered_map<size_t, std::unique_ptr<std::vector<uint8_t>>> g_audio_data;
size_t g_numAudios = 1;
void clear_sounds()
{
	g_audio_data.clear();
}


uint64_t Resample_s16(const int16_t* input, int16_t* output, int inSampleRate, int outSampleRate, uint64_t inputSize,
	uint32_t channels
) {
	if (input == NULL)
		return 0;
	uint64_t outputSize = (uint64_t)(inputSize * (double)outSampleRate / (double)inSampleRate);
	outputSize -= outputSize % channels;
	if (output == NULL)
		return outputSize;
	double stepDist = ((double)inSampleRate / (double)outSampleRate);
	const uint64_t fixedFraction = (1LL << 32);
	const double normFixed = (1.0 / (1LL << 32));
	uint64_t step = ((uint64_t)(stepDist * fixedFraction + 0.5));
	uint64_t curOffset = 0;
	for (uint32_t i = 0; i < outputSize; i += 1) {
		for (uint32_t c = 0; c < channels; c += 1) {
			*output++ = (int16_t)(input[c] + (input[c + channels] - input[c]) * (
				(double)(curOffset >> 32) + ((curOffset & (fixedFraction - 1)) * normFixed)
				)
				);
		}
		curOffset += step;
		input += (curOffset >> 32) * channels;
		curOffset &= (fixedFraction - 1);
	}
	return outputSize;
}


uint32_t LoadAudio(nqr::AudioData& fileData, uint32_t audio_id)
{

	std::vector<float> frames;
	int num_samples = fileData.samples.size();
	if (fileData.channelCount > 1)
	{
		frames = std::vector<float>(num_samples);
		nqr::StereoToMono(fileData.samples.data(), frames.data(), num_samples);
		num_samples /= 2;
	}
	else
	{
		frames = fileData.samples;
	}
	size_t olen16k = (size_t)(num_samples * 16000.0 / fileData.sampleRate + .5);   /* Assay output len. */
	size_t olen8k = (size_t)(num_samples * 8000.0 / fileData.sampleRate + .5);   /* Assay output len. */

	soxr_runtime_spec_t _soxrRuntimeSpec = soxr_runtime_spec(1);
	size_t idone = 0;
	size_t odone16k = 0;
	size_t odone8k = 0;

	soxr_quality_spec_t _soxrQualitySpec = soxr_quality_spec(SOXR_QQ, 0);
	std::vector<int16_t> outputBuffer16(olen16k);
	std::vector<int16_t> outputBuffer8(olen8k);
	soxr_io_spec_t iospec = soxr_io_spec(SOXR_FLOAT32, SOXR_INT16);

	soxr_oneshot(fileData.sampleRate, 16000.0, 1,
		frames.data(), num_samples, &idone,
		outputBuffer16.data(), olen16k, &odone16k,
		&iospec, &_soxrQualitySpec, &_soxrRuntimeSpec);
	iospec = soxr_io_spec(SOXR_INT16, SOXR_INT16);
	soxr_oneshot(16000.0, 8000.0, 1,
		outputBuffer16.data(), olen16k, &idone,
		outputBuffer8.data(), olen8k, &odone8k,
		&iospec, &_soxrQualitySpec, &_soxrRuntimeSpec);
	if (!audio_id)
	{
		return g_pRevoiceApi->SoundAdd(
			std::make_shared<audio_wave>((uint16_t*)outputBuffer8.data(), odone8k, 1, 8000.0),
			std::make_shared<audio_wave>((uint16_t*)outputBuffer16.data(), odone16k, 1, 16000.0));
	}
	g_pRevoiceApi->SoundPush(audio_id,
		std::make_shared<audio_wave>((uint16_t*)outputBuffer8.data(), odone8k, 1, 8000.0),
		std::make_shared<audio_wave>((uint16_t*)outputBuffer16.data(), odone16k, 1, 16000.0));
	return audio_id;
}
cell AMX_NATIVE_CALL IsClientSpeaking(Amx * amx, cell * params)
{
	enum args_e { arg_count, arg_index };
	CHECK_ISPLAYER(arg_index);

	return (cell)g_pRevoiceApi->IsClientSpeaking((size_t)params[arg_index]);
}


cell AMX_NATIVE_CALL MuteClient(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_index, arg_receive_index };

	CHECK_ISPLAYER(arg_index);

	g_pRevoiceApi->MuteClient(params[arg_index], params[arg_receive_index]);
	return true;
}

cell AMX_NATIVE_CALL UnmuteClient(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_index, arg_receive_index };

	CHECK_ISPLAYER(arg_index);

	g_pRevoiceApi->UnmuteClient(params[arg_index], params[arg_receive_index]);
	return true;
}

cell AMX_NATIVE_CALL IsClientMuted(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_index, arg_receive_index };

	CHECK_ISPLAYER(arg_index);

	return (cell)g_pRevoiceApi->IsClientMuted(params[arg_index], params[arg_receive_index]);
}


void NormalizePath(char* path)
{
	for (char* cp = path; *cp; cp++) {
		if (*cp == '\\')
			*cp = '/';
	}
}

cell AMX_NATIVE_CALL SoundCreateEmpty(Amx* amx, cell* params)
{
	std::vector<uint16_t> placeholder_buffer(1);
	return g_pRevoiceApi->SoundAdd(std::make_shared<audio_wave>(placeholder_buffer.data(), 1, 1, 8000.0),
		std::make_shared<audio_wave>(placeholder_buffer.data(), 1, 1, 16000.0));
}
cell AMX_NATIVE_CALL SoundAddAudio(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_audioid, arg_extension};
	if(g_audio_data.find(params[arg_audioid]) == g_audio_data.end())
	{
		return 0;
	}
	nqr::AudioData fileData;
	try
	{
		const auto* extension = AmxxApi::get_amx_string(amx, params[arg_extension], 0);
		if (strlen(extension))
		{
			loader.Load(&fileData, extension, *g_audio_data[params[arg_audioid]]);
		}
		else
		{
			loader.Load(&fileData, *g_audio_data[params[arg_audioid]]);			
		}
		return LoadAudio(fileData, 0);
	}
	catch (...)
	{
		return 0;
	}
}

cell AMX_NATIVE_CALL SoundAdd(Amx* amx, cell* params)
{
	
	enum args_e { arg_count, arg_path};

	const auto* path = AmxxApi::get_amx_string(amx, params[arg_path], 0);

	char* pszGameDir = (char*)MetaUtils::get_game_info(MetaGameInfo::Directory);

	char szPath[256];
	snprintf(szPath, sizeof(szPath), "%s/%s", pszGameDir, path);
#ifdef WIN32
	std::replace(szPath, szPath + strlen(szPath), '/', '\\');
#else
		std::replace(szPath, szPath + strlen(szPath), '/', '\\');
#endif

	nqr::AudioData fileData;
	try
	{
		loader.Load(&fileData, std::string(szPath));
		return LoadAudio(fileData, 0);
	}
	catch(...)
	{
		return 0;
	}
}


cell AMX_NATIVE_CALL SoundDelAuto(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_soundid };
	g_pRevoiceApi->SoundAutoDelete(params[arg_soundid]);
	return true;
}
cell AMX_NATIVE_CALL SoundDel(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_soundid };
	g_pRevoiceApi->SoundDelete(params[arg_soundid]);
	return true;
}


cell AMX_NATIVE_CALL SoundPush(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_sound_id, arg_audioid, arg_extension };
	if (g_audio_data.find(params[arg_audioid]) == g_audio_data.end())
	{
		return 0;
	}
	nqr::AudioData fileData;
	try
	{
		const auto* extension = AmxxApi::get_amx_string(amx, params[arg_extension], 0);
		if (strlen(extension))
		{
			loader.Load(&fileData, extension, *g_audio_data[params[arg_audioid]]);
		}
		else
		{
			loader.Load(&fileData, *g_audio_data[params[arg_audioid]]);
		}
		LoadAudio(fileData, params[arg_sound_id]);
		return 1;
	}
	catch (...)
	{
		return 0;
	}
}

cell AMX_NATIVE_CALL SoundPlay(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_index, arg_receive_index, arg_soundid };
	g_pRevoiceApi->SoundPlay(params[arg_index], params[arg_receive_index], params[arg_soundid]);
	return true;
}

cell AMX_NATIVE_CALL SoundPause(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_soundid };
	g_pRevoiceApi->SoundPause(params[arg_soundid]);

	return true;
}

cell AMX_NATIVE_CALL SoundSeek(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_soundid, arg_seek, arg_seektype };
	g_pRevoiceApi->SoundSeek(params[arg_soundid], amx_ctof(params[arg_seek]), static_cast<audio_wave::seekParam>(params[arg_seektype]));
	return true;
}

cell AMX_NATIVE_CALL SoundTell(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_soundid };	
	return amx_ftoc(g_pRevoiceApi->SoundTell(params[arg_soundid]));
}

cell AMX_NATIVE_CALL SoundLength(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_soundid };
	return amx_ftoc(g_pRevoiceApi->SoundLength(params[arg_soundid]));
}

cell AMX_NATIVE_CALL AudioDel(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_audioid	};
	g_audio_data.erase(params[arg_audioid]);
	return true;
}

cell AMX_NATIVE_CALL AudioPush(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_audioid, arg_buffer, arg_bufferlen };
	auto addr = AmxxApi::get_amx_address(amx, params[arg_buffer]);
	for(int i = 0; i < params[arg_bufferlen]; i++)
	{
		g_audio_data[params[arg_audioid]]->push_back(addr[i]);
	}
	return true;
}

cell AMX_NATIVE_CALL AudioCreate(Amx* amx, cell* params)
{
	enum args_e { arg_count};
	g_audio_data[g_numAudios] = std::make_unique<std::vector<uint8_t>>();
	
	return g_numAudios++;
}

AmxNativeInfo VTC_Natives[] =
{
	{ "VU_IsClientSpeaking",	IsClientSpeaking },
	{ "VU_MuteClient",				MuteClient       },
	{ "VU_UnmuteClient",			UnmuteClient     },
	{ "VU_IsClientMuted",			IsClientMuted    },
	{ "VU_BufferCreate",			AudioCreate        },
	{ "VU_BufferPush",				AudioPush        },
	{ "VU_BufferDel",				AudioDel        },
	{ "VU_SoundCreateEmpty",		SoundCreateEmpty        },
	{ "VU_SoundCreateFromBuffer",	SoundAddAudio        },
	{ "VU_SoundCreateFromFile",		SoundAdd        },
	{ "VU_SoundDeleteAuto",			SoundDelAuto        },
	{ "VU_SoundDelete",				SoundDel       },
	{ "VU_SoundPlay",				SoundPlay     },
	{ "VU_SoundPushAudio",			SoundPush     },
	{ "VU_SoundPause",				SoundPause    },
	{ "VU_SoundSeek",				SoundSeek        },
	{ "VU_SoundTell",				SoundTell        },
	{ "VU_SoundLength",				SoundLength        },
	{ nullptr, nullptr }
};

void RegisterNatives_REVOICE()
{
	AmxxApi::add_natives(VTC_Natives);
}