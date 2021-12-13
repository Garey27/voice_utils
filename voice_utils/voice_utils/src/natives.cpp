#include <amxx/api.h>
#include <amxx/string.h>
#include <voice_utils/revoice_api.h>

#include <soxr.h>
#include <unordered_map>
#include <iterator>
#include <fstream>
#include <iostream>

#include "libnyquist/Decoders.h"

#include "metamod/api.h"
#include "metamod/utils.h"
#include "rnnoise.h"

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
std::unordered_map<size_t, bool> g_player_denoise_active;
extern int g_onclient_stop_speak;
void clear_sounds()
{
	g_audio_data.clear();
}
size_t resample_buffer(void* srcBuff, size_t srcBufLen,  void* dstBuff, size_t dstBuffLen, double srcRate, double targetRate, soxr_io_spec_t iospec)
{	
	soxr_quality_spec_t _soxrQualitySpec = soxr_quality_spec(SOXR_QQ, 0);
	soxr_runtime_spec_t _soxrRuntimeSpec = soxr_runtime_spec(1);
	size_t idone = 0;
	size_t odone = 0;

	soxr_oneshot(srcRate, targetRate, 1,
		srcBuff, srcBufLen, &idone,
		dstBuff, dstBuffLen, &odone,
		&iospec, &_soxrQualitySpec, &_soxrRuntimeSpec);

	return odone;
}
void OnSoundDecompress(size_t clientIndex, uint16_t sampleRate, uint8_t* samples, size_t* sample_size)
{
#define FRAME_SIZE 480
	static DenoiseState* st[33] = {nullptr};
	if(g_player_denoise_active[clientIndex])
	{
		if(!st[clientIndex])
		{
			st[clientIndex] = rnnoise_create(NULL);
		}
		auto iospec = soxr_io_spec(SOXR_INT16, SOXR_INT16);
		size_t olen48k = (size_t)(*sample_size * 48000.0 / sampleRate + .5); 
		std::vector<short> outputBuffer(olen48k);
  		float x[FRAME_SIZE];
		auto samplesToDenoise = resample_buffer(samples, *sample_size, outputBuffer.data(), olen48k, sampleRate, 48000.0, iospec);
		int i = 0 ,j = 0;

		while(i < samplesToDenoise)
		{
			for (j=0;j<FRAME_SIZE;j++) x[j] = outputBuffer[i+j];
			auto ret = rnnoise_process_frame(st[clientIndex], x, x);
			for (j=0;j<FRAME_SIZE;j++) outputBuffer[i+j] = x[j];
			i += FRAME_SIZE;
		}
		iospec = soxr_io_spec(SOXR_INT16, SOXR_INT16);
		*sample_size = resample_buffer(outputBuffer.data(), olen48k, samples, *sample_size, 48000.0, sampleRate, iospec);
	}

	//AmxxApi::execute_forward(g_onclient_stop_speak, clientIndex, sampleRate, samples, *sample_size);
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
	size_t olen16k = (size_t)(num_samples * 24000.0 / fileData.sampleRate + .5);   /* Assay output len. */
	size_t olen8k = (size_t)(num_samples * 8000.0 / fileData.sampleRate + .5);   /* Assay output len. */

	std::vector<int16_t> outputBuffer16(olen16k);
	std::vector<int16_t> outputBuffer8(olen8k);
	soxr_io_spec_t iospec = soxr_io_spec(SOXR_FLOAT32, SOXR_INT16);
	auto odone16k = resample_buffer(frames.data(), num_samples, outputBuffer16.data(), olen16k, fileData.sampleRate, 24000.0, iospec);
	iospec = soxr_io_spec(SOXR_INT16, SOXR_INT16);
	auto odone8k = resample_buffer(outputBuffer16.data(), olen16k, outputBuffer8.data(), olen8k, 24000.0, 8000.0, iospec);
	if (!audio_id)
	{
		return g_pRevoiceApi->SoundAdd(
			std::make_shared<audio_wave>((uint16_t*)outputBuffer8.data(), odone8k, 1, 8000.0),
			std::make_shared<audio_wave>((uint16_t*)outputBuffer16.data(), odone16k, 1, 24000.0));
	}
	g_pRevoiceApi->SoundPush(audio_id,
		std::make_shared<audio_wave>((uint16_t*)outputBuffer8.data(), odone8k, 1, 8000.0),
		std::make_shared<audio_wave>((uint16_t*)outputBuffer16.data(), odone16k, 1, 24000.0));
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
	enum args_e { arg_count, arg_receive_index, arg_index };

	CHECK_ISPLAYER(arg_receive_index);

	g_pRevoiceApi->MuteClient(params[arg_index], params[arg_receive_index]);
	return true;
}

cell AMX_NATIVE_CALL UnmuteClient(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_receive_index, arg_index  };

	CHECK_ISPLAYER(arg_receive_index);

	g_pRevoiceApi->UnmuteClient(params[arg_index], params[arg_receive_index]);
	return true;
}

cell AMX_NATIVE_CALL IsClientMuted(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_receive_index, arg_index };

	CHECK_ISPLAYER(arg_receive_index);

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

std::vector<uint8_t> readFile(const char* filename)
{
    // open the file:
    std::ifstream file(filename, std::ios::binary);
    
    std::vector<uint8_t> vec;
    if (!file.is_open())
    {
        return vec;
    }
    // Stop eating new lines in binary mode!!!
    file.unsetf(std::ios::skipws);

    // get its size:
    std::streampos fileSize;

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // reserve capacity
    std::vector<uint8_t> vec;
    vec.reserve(fileSize);

    // read the data:
    vec.insert(vec.begin(),
               std::istream_iterator<uint8_t>(file),
               std::istream_iterator<uint8_t>());

    return vec;
}


cell AMX_NATIVE_CALL SoundAdd(Amx* amx, cell* params)
{
	
	enum args_e { arg_count, arg_path, arg_extension};

	const auto* path = AmxxApi::get_amx_string(amx, params[arg_path], 0);
	const auto* extension = AmxxApi::get_amx_string(amx, params[arg_extension], 1);

	char* pszGameDir = (char*)MetaUtils::get_game_info(MetaGameInfo::Directory);

	char szPath[256];
	snprintf(szPath, sizeof(szPath), "%s/%s", pszGameDir, path);
#ifdef WIN32
	std::replace(szPath, szPath + strlen(szPath), '/', '\\');
#else
	std::replace(szPath, szPath + strlen(szPath), '\\', '/');
#endif

	nqr::AudioData fileData;
	try
	{
		std::vector<uint8_t> vec = readFile(szPath);
		if (extension && strlen(extension))
		{	
			loader.Load(&fileData, std::string(extension), vec);
		}
		else
		{
			loader.Load(&fileData, vec);
		}
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

cell AMX_NATIVE_CALL SetDenoise(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_index, arg_denoise };

	CHECK_ISPLAYER(arg_index);

	g_player_denoise_active[params[arg_index]-1] = params[arg_denoise];
	return true;
}

cell AMX_NATIVE_CALL IsDenoised(Amx* amx, cell* params)
{
	enum args_e { arg_count, arg_index };

	CHECK_ISPLAYER(arg_index);

	return (cell)g_player_denoise_active[params[arg_index]-1];
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
	{ "VU_IsDenoised",				IsDenoised        },
	{ "VU_SetDenoise",				SetDenoise        },
	{ nullptr, nullptr }
};

void RegisterNatives_REVOICE()
{
	AmxxApi::add_natives(VTC_Natives);
}
