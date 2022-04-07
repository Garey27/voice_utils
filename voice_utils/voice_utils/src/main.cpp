#include <amxx/api.h>
#include <voice_utils/rehlds_api.h>
#include <voice_utils/revoice_api.h>
#include <unordered_map>
#include "metamod/utils.h"

IRevoiceApi* g_pRevoiceApi;

int g_onsound_decompress;
int g_onsound_complete;
int g_onclient_start_speak;
int g_onclient_stop_speak;
int g_onclient_sound_decompress;;

void OnSoundComplete(uint32_t receiverIndex, uint32_t soundIndex)
{
	AmxxApi::execute_forward(g_onsound_complete, receiverIndex, soundIndex);
}

void OnClientStartSpeak(size_t clientIndex)
{
	AmxxApi::execute_forward(g_onclient_start_speak, clientIndex);
}

void OnClientStopSpeak(size_t clientIndex)
{
	AmxxApi::execute_forward(g_onclient_stop_speak, clientIndex);
}

extern void RegisterNatives_REVOICE();

void OnSoundDecompress(size_t clientIndex, uint16_t sampleRate, uint8_t* samples, size_t* sample_size);
AmxxStatus on_amxx_attach()
{
	if (!RehldsApi::init()) {
		return AmxxStatus::Failed;
	}

	g_pRevoiceApi = (IRevoiceApi*)RehldsApi::funcs()->get_plugin_api("RevoicePlus");

	if (!g_pRevoiceApi)
		return AmxxStatus::Failed;

	int majorVersion = g_pRevoiceApi->MajorVersion();
	int minorVersion = g_pRevoiceApi->MinorVersion();


	if (majorVersion != REVOICE_API_VERSION_MAJOR)
	{
		
		MetaUtils::log_error("[%s]: Revoice+ API major version mismatch; expected %d, real %d\n", MetaUtils::get_plugin_id()->log_tag, REVOICE_API_VERSION_MAJOR, majorVersion);

		// need to notify that it is necessary to update the VTC.
		if (majorVersion < REVOICE_API_VERSION_MAJOR)
		{
			MetaUtils::log_error("[%s]: Please update the Revoice+ up to a major version API >= %d\n", MetaUtils::get_plugin_id()->log_tag, REVOICE_API_VERSION_MAJOR);
		}

		// need to notify that it is necessary to update the module.
		else if (majorVersion > REVOICE_API_VERSION_MAJOR)
		{
			MetaUtils::log_error("[%s]: Please update the %s up to a major version API >= %d\n", MetaUtils::get_plugin_id()->log_tag, MetaUtils::get_plugin_id()->log_tag, majorVersion);
		}

		return AmxxStatus::Failed;
	}

	if (minorVersion < REVOICE_API_VERSION_MINOR)
	{
		MetaUtils::log_error("[%s]: Revoice+ API minor version mismatch; expected at least %d, real %d\n", MetaUtils::get_plugin_id()->log_tag, REVOICE_API_VERSION_MINOR, minorVersion);
		MetaUtils::log_error("[%s]: Please update the Revoice+ up to a minor version API >= %d\n", MetaUtils::get_plugin_id()->log_tag, REVOICE_API_VERSION_MINOR);

		return AmxxStatus::Failed;
	}

	g_pRevoiceApi->OnClientStartSpeak() += OnClientStartSpeak;
	g_pRevoiceApi->OnClientStopSpeak() += OnClientStopSpeak;
	g_pRevoiceApi->OnSoundComplete() += OnSoundComplete;
	g_pRevoiceApi->OnDecompress() += OnSoundDecompress;
	RegisterNatives_REVOICE();
	
	return AmxxStatus::Ok;
}

void on_amxx_plugins_loaded()
{
	g_audio_data.clear();
	g_numAudios = 1;
	g_onsound_complete = AmxxApi::register_forward("VU_OnSoundComplete",
		ForwardExecType::Ignore, ForwardParam::Cell, ForwardParam::Done);

	g_onclient_start_speak = AmxxApi::register_forward("VU_OnStartSpeak",
		ForwardExecType::Ignore, ForwardParam::Cell, ForwardParam::Done);

	g_onclient_stop_speak = AmxxApi::register_forward("VU_OnStopSpeak",
		ForwardExecType::Stop, ForwardParam::Cell, ForwardParam::Done);

	g_onclient_stop_speak = AmxxApi::register_forward("VU_OnStopSpeak",
		ForwardExecType::Stop, ForwardParam::Cell, ForwardParam::Done);
	
	g_onclient_sound_decompress = AmxxApi::register_forward("VU_OnDecompress",
		ForwardExecType::Stop, ForwardParam::Cell, ForwardParam::Cell, ForwardParam::Array, ForwardParam::Cell, ForwardParam::Done);
}

void on_amxx_plugins_unloaded()
{
	g_audio_data.clear();
	g_numAudios = 1;
}
