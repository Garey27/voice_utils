// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 06-02-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/common/event_args.h>
#include <cssdk/common/hook_chains.h>
#include <cssdk/engine/cmd_rehlds.h>
#include <cssdk/engine/consistency.h>
#include <cssdk/engine/delta_packet.h>
#include <cssdk/engine/eiface.h>
#include <cssdk/engine/flight_recorder.h>
#include <cssdk/engine/pr_dlls.h>
#include <cssdk/engine/rehlds_interfaces.h>
#include <cssdk/engine/server.h>
#include <cssdk/public/arch_types.h>
#include <cstddef>

//-V::122
//-V:RehldsFuncs:730

/// <summary>
/// </summary>
constexpr auto REHLDS_API_VERSION_MAJOR = 3;

/// <summary>
/// </summary>
constexpr auto REHLDS_API_VERSION_MINOR = 7;

/// <summary>
/// </summary>
constexpr auto VREHLDS_HLDS_API_VERSION = "VREHLDS_HLDS_API_VERSION001";

// Steam_NotifyClientConnect hook
using ReHookSteamNotifyClientConnect = IHookChain<qboolean, GameClient*, const void*, unsigned int>;
using ReHookRegistrySteamNotifyClientConnect = IHookChainRegistry<qboolean, GameClient*, const void*, unsigned int>;

// SV_ConnectClient hook
using ReHookSvConnectClient = IHookChainVoid<>;
using ReHookRegistrySvConnectClient = IHookChainVoidRegistry<>;

// SV_GetIDString hook
using ReHookSvGetIdString = IHookChain<char*, UserId*>;
using ReHookRegistrySvGetIdString = IHookChainRegistry<char*, UserId*>;

// SV_SendServerinfo hook
using ReHookSvSendServerInfo = IHookChainVoid<SizeBuf*, GameClient*>;
using ReHookRegistrySvSendServerInfo = IHookChainVoidRegistry<SizeBuf*, GameClient*>;

// SV_CheckProtocol hook
using ReHookSvCheckProtocol = IHookChain<int, NetAddress*, int>;
using ReHookRegistrySvCheckProtocol = IHookChainRegistry<int, NetAddress*, int>;

// SVC_GetChallenge_mod hook
using ReHookSvcGetChallengeMod = IHookChainVoid<char*, int>;
using ReHookRegistrySvcGetChallengeMod = IHookChainVoidRegistry<char*, int>;

// SV_CheckKeyInfo hook
using ReHookSvCheckKeyInfo = IHookChain<int, NetAddress*, char*, uint16*, int*, char*, char*>;
using ReHookRegistrySvCheckKeyInfo = IHookChainRegistry<int, NetAddress*, char*, uint16*, int*, char*, char*>;

// SV_CheckIPRestrictions hook
using ReHookSvCheckIpRestrictions = IHookChain<int, NetAddress*, int>;
using ReHookRegistrySvCheckIpRestrictions = IHookChainRegistry<int, NetAddress*, int>;

// SV_FinishCertificateCheck hook
using ReHookSvFinishCertificateCheck = IHookChain<int, NetAddress*, int, char*, char*>;
using ReHookRegistrySvFinishCertificateCheck = IHookChainRegistry<int, NetAddress*, int, char*, char*>;

// Steam_NotifyBotConnect hook
using ReHookSteamNotifyBotConnect = IHookChain<qboolean, GameClient*>;
using ReHookRegistrySteamNotifyBotConnect = IHookChainRegistry<qboolean, GameClient*>;

// SerializeSteamId
using ReHookSerializeSteamId = IHookChainVoid<UserId*, UserId*>;
using ReHookRegistrySerializeSteamId = IHookChainVoidRegistry<UserId*, UserId*>;

// SV_CompareUserID hook
using ReHookSvCompareUserId = IHookChain<qboolean, UserId*, UserId*>;
using ReHookRegistrySvCompareUserId = IHookChainRegistry<qboolean, UserId*, UserId*>;

// Steam_NotifyClientDisconnect
using ReHookSteamNotifyClientDisconnect = IHookChainVoid<GameClient*>;
using ReHookRegistrySteamNotifyClientDisconnect = IHookChainVoidRegistry<GameClient*>;

// PreProcessPacket
using ReHookPreprocessPacket = IHookChain<bool, uint8*, unsigned int, const NetAddress&>;
using ReHookRegistryPreprocessPacket = IHookChainRegistry<bool, uint8*, unsigned int, const NetAddress&>;

// ValidateCommand
using ReHookValidateCommand = IHookChain<bool, const char*, CmdSource, GameClient*>;
using ReHookRegistryValidateCommand = IHookChainRegistry<bool, const char*, CmdSource, GameClient*>;

// ExecuteServerStringCmd
using ReHookExecuteServerStringCmd = IHookChainVoid<const char*, CmdSource, GameClient*>;
using ReHookRegistryExecuteServerStringCmd = IHookChainVoidRegistry<const char*, CmdSource, GameClient*>;

// ClientConnected
using ReHookClientConnected = IHookChainVoid<GameClient*>;
using ReHookRegistryClientConnected = IHookChainVoidRegistry<GameClient*>;

// HandleNetCommand
using ReHookHandleNetCommand = IHookChainVoid<GameClient*, int8>;
using ReHookRegistryHandleNetCommand = IHookChainVoidRegistry<GameClient*, int8>;

// Mod_LoadBrushModel
using ReHookModLoadBrushModel = IHookChainVoid<Model*, void*>;
using ReHookRegistryModLoadBrushModel = IHookChainVoidRegistry<Model*, void*>;

// Mod_LoadStudioModel
using ReHookModLoadStudioModel = IHookChainVoid<Model*, void*>;
using ReHookRegistryModLoadStudioModel = IHookChainVoidRegistry<Model*, void*>;

// SV_EmitEvents hook
using ReHookSvEmitEvents = IHookChainVoid<GameClient*, PacketEntities*, SizeBuf*>;
using ReHookRegistrySvEmitEvents = IHookChainVoidRegistry<GameClient*, PacketEntities*, SizeBuf*>;

// EV_PlayReliableEvent hook
using ReHookEvPlayReliableEvent = IHookChainVoid<GameClient*, int, unsigned short, float, EventArgs*>;
using ReHookRegistryEvPlayReliableEvent = IHookChainVoidRegistry<GameClient*, int, unsigned short, float, EventArgs*>;

// SV_StartSound hook
using ReHookSvStartSound = IHookChainVoid<int, Edict*, int, const char*, int, float, int, int>;
using ReHookRegistrySvStartSound = IHookChainVoidRegistry<int, Edict*, int, const char*, int, float, int, int>;

// PF_Remove_I hook
using ReHookPfRemoveI = IHookChainVoid<Edict*>;
using ReHookRegistryPfRemoveI = IHookChainVoidRegistry<Edict*>;

// PF_BuildSoundMsg_I hook
using ReHookPfBuildSoundMsgI = IHookChainVoid<Edict*, int, const char*, float, float, int, int, int, int, const float*, Edict*>;
using ReHookRegistryPfBuildSoundMsgI = IHookChainVoidRegistry<Edict*, int, const char*, float, float, int, int, int, int, const float*, Edict*>;

// SV_WriteFullClientUpdate hook
using ReHookSvWriteFullClientUpdate = IHookChainVoid<GameClient*, char*, std::size_t, SizeBuf*, GameClient*>;
using ReHookRegistrySvWriteFullClientUpdate = IHookChainVoidRegistry<GameClient*, char*, std::size_t, SizeBuf*, GameClient*>;

// SV_CheckConsistencyResponse hook
using ReHookSvCheckConsistencyResponse = IHookChain<bool, GameClient*, Resource*, uint32>;
using ReHookRegistrySvCheckConsistencyResponse = IHookChainRegistry<bool, GameClient*, Resource*, uint32>;

// SV_DropClient hook
using ReHookSvDropClient = IHookChainVoid<GameClient*, bool, const char*>;
using ReHookRegistrySvDropClient = IHookChainVoidRegistry<GameClient*, bool, const char*>;

// SV_ActivateServer hook
using ReHookSvActivateServer = IHookChainVoid<int>;
using ReHookRegistrySvActivateServer = IHookChainVoidRegistry<int>;

// SV_WriteVoiceCodec hook
using ReHookSvWriteVoiceCodec = IHookChainVoid<SizeBuf*>;
using ReHookRegistrySvWriteVoiceCodec = IHookChainVoidRegistry<SizeBuf*>;

// Steam_GSGetSteamID hook
using ReHookSteamGsGetSteamId = IHookChain<uint64>;
using ReHookRegistrySteamGsGetSteamId = IHookChainRegistry<uint64>;

// SV_TransferConsistencyInfo hook
using ReHookSvTransferConsistencyInfo = IHookChain<int>;
using ReHookRegistrySvTransferConsistencyInfo = IHookChainRegistry<int>;

// Steam_GSBUpdateUserData hook
using ReHookSteamGsbUpdateUserData = IHookChain<bool, uint64, const char*, uint32>;
using ReHookRegistrySteamGsbUpdateUserData = IHookChainRegistry<bool, uint64, const char*, uint32>;

// Cvar_DirectSet hook
using ReHookCvarDirectSet = IHookChainVoid<CVar*, const char*>;
using ReHookRegistryCvarDirectSet = IHookChainVoidRegistry<CVar*, const char*>;

// SV_EstablishTimeBase hook
using ReHookSvEstablishTimeBase = IHookChainVoid<GameClient*, UserCmd*, int, int, int>;
using ReHookRegistrySvEstablishTimeBase = IHookChainVoidRegistry<GameClient*, UserCmd*, int, int, int>;

// SV_Spawn_f hook
using ReHookSvSpawnF = IHookChainVoid<>;
using ReHookRegistrySvSpawnF = IHookChainVoidRegistry<>;

// SV_CreatePacketEntities hook
using ReHookSvCreatePacketEntities = IHookChain<int, SvDelta, GameClient*, PacketEntities*, SizeBuf*>;
using ReHookRegistrySvCreatePacketEntities = IHookChainRegistry<int, SvDelta, GameClient*, PacketEntities*, SizeBuf*>;

// SV_EmitSound2 hook
using ReHookSvEmitSound2 = IHookChain<bool, Edict*, GameClient*, int, const char*, float, float, int, int, int, const float*>;
using ReHookRegistrySvEmitSound2 = IHookChainRegistry<bool, Edict*, GameClient*, int, const char*, float, float, int, int, int, const float*>;

// CreateFakeClient hook
using ReHookCreateFakeClient = IHookChain<Edict*, const char*>;
using ReHookRegistryCreateFakeClient = IHookChainRegistry<Edict*, const char*>;

// SV_CheckConnectionLessRateLimits
using ReHookSvCheckConnectionLessRateLimits = IHookChain<bool, NetAddress&, const uint8*, int>;
using ReHookRegistrySvCheckConnectionLessRateLimits = IHookChainRegistry<bool, NetAddress&, const uint8*, int>;

// SV_Frame hook
using ReHookSvFrame = IHookChainVoid<>;
using ReHookRegistrySvFrame = IHookChainVoidRegistry<>;

/// <summary>
/// Class RehldsHookChains.
/// </summary>
class RehldsHookChains {
public:
	/// <summary>
	/// </summary>
	virtual ~RehldsHookChains() = default;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySteamNotifyClientConnect* steam_notify_client_connect() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvConnectClient* sv_connect_client() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvGetIdString* sv_get_id_string() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvSendServerInfo* sv_send_server_info() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvCheckProtocol* sv_check_protocol() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvcGetChallengeMod* svc_get_challenge_mod() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvCheckKeyInfo* sv_check_key_info() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvCheckIpRestrictions* sv_check_ip_restrictions() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvFinishCertificateCheck* sv_finish_certificate_check() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySteamNotifyBotConnect* steam_notify_bot_connect() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySerializeSteamId* serialize_steam_id() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvCompareUserId* sv_compare_user_id() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySteamNotifyClientDisconnect* steam_notify_client_disconnect() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPreprocessPacket* preprocess_packet() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryValidateCommand* validate_command() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryClientConnected* client_connected() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryHandleNetCommand* handle_net_command() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryModLoadBrushModel* mod_load_brush_model() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryModLoadStudioModel* mod_load_studio_model() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryExecuteServerStringCmd* execute_server_string_cmd() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvEmitEvents* sv_emit_events() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryEvPlayReliableEvent* ev_play_reliable_event() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvStartSound* sv_start_sound() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPfRemoveI* pf_remove_i() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPfBuildSoundMsgI* pf_build_sound_msg_i() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvWriteFullClientUpdate* sv_write_full_client_update() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvCheckConsistencyResponse* sv_check_consistency_response() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvDropClient* sv_drop_client() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvActivateServer* sv_activate_server() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvWriteVoiceCodec* sv_write_voice_codec() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySteamGsGetSteamId* steam_gs_get_steam_id() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvTransferConsistencyInfo* sv_transfer_consistency_info() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySteamGsbUpdateUserData* steam_gsb_update_user_data() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryCvarDirectSet* cvar_direct_set() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvEstablishTimeBase* sv_establish_time_base() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvSpawnF* sv_spawn_f() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvCreatePacketEntities* sv_create_packet_entities() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvEmitSound2* sv_emit_sound2() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryCreateFakeClient* create_fake_client() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvCheckConnectionLessRateLimits* sv_check_connection_less_rate_limits() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySvFrame* sv_frame() = 0;
};

/// <summary>
/// Struct RehldsFuncs
/// </summary>
struct RehldsFuncs {
	/// <summary>
	/// </summary>
	void (*drop_client)(GameClient* client, bool crash, const char* format, ...){}; //-V591

	/// <summary>
	/// </summary>
	void (*reject_connection)(NetAddress* address, char* format, ...){}; //-V591

	/// <summary>
	/// </summary>
	qboolean (*steam_notify_bot_connect)(GameClient* client){}; //-V591

	/// <summary>
	/// </summary>
	SizeBuf* (*get_net_message)(){}; //-V591

	/// <summary>
	/// </summary>
	GameClient* (*get_host_client)(){}; //-V591

	/// <summary>
	/// </summary>
	int* (*get_msg_read_count)(){}; //-V591

	/// <summary>
	/// </summary>
	qboolean (*filter_user)(UserId* user_id){}; //-V591

	/// <summary>
	/// </summary>
	void (*net_send_packet)(unsigned int length, void* data, const NetAddress& to){}; //-V591

	/// <summary>
	/// </summary>
	void (*tokenize_string)(char* text){};

	/// <summary>
	/// </summary>
	bool (*check_challenge)(const NetAddress& address, int challenge){}; //-V591

	/// <summary>
	/// </summary>
	void (*send_user_reg)(SizeBuf* message){};

	/// <summary>
	/// </summary>
	void (*write_delta_descriptions_to_client)(SizeBuf* message){};

	/// <summary>
	/// </summary>
	void (*set_move_vars)(){};

	/// <summary>
	/// </summary>
	void (*write_move_vars_to_client)(SizeBuf* message){};

	/// <summary>
	/// </summary>
	char* (*get_client_fallback)(){}; //-V591

	/// <summary>
	/// </summary>
	int* (*get_allow_cheats)(){}; //-V591

	/// <summary>
	/// </summary>
	bool (*gsb_secure)(){};

	/// <summary>
	/// </summary>
	int (*get_build_number)(){};

	/// <summary>
	/// </summary>
	double (*get_real_time)(){};

	/// <summary>
	/// </summary>
	int* (*get_msg_bad_read)(){}; //-V591

	/// <summary>
	/// </summary>
	CmdSource* (*get_cmd_source)(){}; //-V591

	/// <summary>
	/// </summary>
	void (*log)(const char* prefix, const char* message){}; //-V591

	/// <summary>
	/// </summary>
	DllFuncPointers* (*get_entity_interface)(){}; //-V591

	/// <summary>
	/// </summary>
	void (*ev_play_reliable_event)(GameClient* client, int entity_index, unsigned short event_index, float delay, EventArgs* args){}; //-V591

	/// <summary>
	/// </summary>
	int (*sv_lookup_sound_index)(const char* sample){};

	/// <summary>
	/// </summary>
	void (*msg_start_bit_writing)(SizeBuf* buf){};

	/// <summary>
	/// </summary>
	void (*msg_write_bits)(uint32 data, int num_bits){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_bit_vec3_coord)(const Vector& coord){};

	/// <summary>
	/// </summary>
	void (*msg_end_bit_writing)(SizeBuf* buf){};

	/// <summary>
	/// </summary>
	void* (*sz_get_space)(SizeBuf* buf, int length){}; //-V591

	/// <summary>
	/// </summary>
	CVar* (*get_cvar_vars)(){}; //-V591

	/// <summary>
	/// </summary>
	int (*sv_get_challenge)(const NetAddress& address){};

	/// <summary>
	/// </summary>
	void (*sv_add_resource)(ResourceType type, const char* name, int size, byte flags, int index){}; //-V591

	/// <summary>
	/// </summary>
	int (*msg_read_short)(){};

	/// <summary>
	/// </summary>
	int (*msg_read_buf)(int size, void* buf){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_buf)(SizeBuf* buf, int size, void* data){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_byte)(SizeBuf* buf, int c){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_short)(SizeBuf* buf, int c){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_string)(SizeBuf* buf, const char* s){}; //-V591

	/// <summary>
	/// </summary>
	void* (*get_plugin_api)(const char* name){}; //-V591

	/// <summary>
	/// </summary>
	void (*register_plugin_api)(const char* name, void* impl){}; //-V591

	/// <summary>
	/// </summary>
	qboolean (*sv_file_in_consistency_list)(const char* file_name, Consistency** consist){}; //-V591

	/// <summary>
	/// </summary>
	qboolean (*steam_notify_client_connect)(GameClient* client, const void* steam_auth_buf, unsigned int size){}; //-V591

	/// <summary>
	/// </summary>
	void (*steam_notify_client_disconnect)(GameClient* client){};

	/// <summary>
	/// </summary>
	void (*sv_start_sound)(int recipients, Edict* entity, int channel, const char* sample, int volume, float attenuation, int flags, int pitch){}; //-V591

	/// <summary>
	/// </summary>
	bool (*sv_emit_sound2)(Edict* entity, GameClient* receiver, SoundChannel channel, const char* sample, float volume,
	                       float attenuation, int flags, int pitch, int emit_flags, const vec_t* origin){}; //-V591

	/// <summary>
	/// </summary>
	void (*sv_update_user_info)(GameClient* client){};

	/// <summary>
	/// </summary>
	bool (*strip_unprintable_and_space)(char* string){};

	/// <summary>
	/// </summary>
	void (*cmd_remove_cmd)(const char* cmd_name){};

	/// <summary>
	/// </summary>
	void (*get_command_matches)(const char* string, class object_list* match_list){}; //-V591

	/// <summary>
	/// </summary>
	bool (*add_ext_dll)(void* module_handle){};

	/// <summary>
	/// </summary>
	void (*add_cvar_listener)(const char* cvar_name, CVarCallback func){}; //-V591

	/// <summary>
	/// </summary>
	void (*remove_ext_dll)(void* module_handle){};

	/// <summary>
	/// </summary>
	void (*remove_cvar_listener)(const char* cvar_name, CVarCallback func){}; //-V591

	/// <summary>
	/// </summary>
	EntityInit (*get_entity_init)(char* class_name){}; //-V591

	//
	// Read functions.
	// 

	/// <summary>
	/// </summary>
	int (*msg_read_char)(){};

	/// <summary>
	/// </summary>
	int (*msg_read_byte)(){};

	/// <summary>
	/// </summary>
	int (*msg_read_long)(){};

	/// <summary>
	/// </summary>
	float (*msg_read_float)(){};

	/// <summary>
	/// </summary>
	char* (*msg_read_string)(){}; //-V591

	/// <summary>
	/// </summary>
	char* (*msg_read_string_line)(){}; //-V591

	/// <summary>
	/// </summary>
	float (*msg_read_angle)(){};

	/// <summary>
	/// </summary>
	float (*msg_read_hires_angle)(){};

	/// <summary>
	/// </summary>
	void (*msg_read_user_cmd)(UserCmd* to, UserCmd* from){}; //-V591

	/// <summary>
	/// </summary>
	float (*msg_read_coord)(){};

	/// <summary>
	/// </summary>
	void (*msg_read_vec3_coord)(SizeBuf* sb, Vector& vec){}; //-V591

	//
	// Read bit functions.
	//

	/// <summary>
	/// </summary>
	bool (*msg_is_bit_reading)(){};

	/// <summary>
	/// </summary>
	void (*msg_start_bit_reading)(SizeBuf* buf){};

	/// <summary>
	/// </summary>
	void (*msg_end_bit_reading)(SizeBuf* buf){};

	/// <summary>
	/// </summary>
	uint32 (*msg_peek_bits)(int num_bits){}; //-V591

	/// <summary>
	/// </summary>
	int (*msg_read_one_bit)(){};

	/// <summary>
	/// </summary>
	uint32 (*msg_read_bits)(int num_bits){}; //-V591

	/// <summary>
	/// </summary>
	int (*msg_read_s_bits)(int num_bits){};

	/// <summary>
	/// </summary>
	float (*msg_read_bit_coord)(){};

	/// <summary>
	/// </summary>
	void (*msg_read_bit_vec3_coord)(Vector& vec){};

	/// <summary>
	/// </summary>
	float (*msg_read_bit_angle)(int num_bits){};

	/// <summary>
	/// </summary>
	int (*msg_read_bit_data)(void* dest, int length){}; //-V591

	/// <summary>
	/// </summary>
	char* (*msg_read_bit_string)(){}; //-V591

	/// <summary>
	/// </summary>
	int (*msg_current_bit)(){};

	//
	// Write functions.
	//

	/// <summary>
	/// </summary>
	void (*msg_write_long)(SizeBuf* sb, int c){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_float)(SizeBuf* sb, float f){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_angle)(SizeBuf* sb, float f){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_hires_angle)(SizeBuf* sb, float f){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_user_cmd)(SizeBuf* sb, UserCmd* to, UserCmd* from){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_coord)(SizeBuf* sb, float f){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_vec3_coord)(SizeBuf* sb, Vector& vec){}; //-V591

	//
	// Write bit functions.
	//

	/// <summary>
	/// </summary>
	bool (*msg_is_bit_writing)(){};

	/// <summary>
	/// </summary>
	void (*msg_write_one_bit)(int value){};

	/// <summary>
	/// </summary>
	void (*msg_write_s_bits)(uint32 data, int num_bits){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_bit_coord)(float f){};

	/// <summary>
	/// </summary>
	void (*msg_write_bit_angle)(float angle, int num_bits){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_bit_data)(void* src, int length){}; //-V591

	/// <summary>
	/// </summary>
	void (*msg_write_bit_string)(const char* string){};

	/// <summary>
	/// </summary>
	void (*sz_write)(SizeBuf* buf, const void* data, int length){}; //-V591

	/// <summary>
	/// </summary>
	void (*sz_print)(SizeBuf* buf, const char* data){}; //-V591

	/// <summary>
	/// </summary>
	void (*sz_clear)(SizeBuf* buf){};

	/// <summary>
	/// </summary>
	void (*msg_begin_reading)(){};

	/// <summary>
	/// </summary>
	double (*get_host_frame_time)(){};

	/// <summary>
	/// </summary>
	CmdFunction* (*get_first_cmd_function_handle)(){}; //-V591
};

/// <summary>
/// Class RehldsApiInterface.
/// </summary>
class RehldsApiInterface {
public:
	/// <summary>
	/// </summary>
	virtual ~RehldsApiInterface() = default;

	/// <summary>
	/// </summary>
	virtual int get_major_version() = 0;

	/// <summary>
	/// </summary>
	virtual int get_minor_version() = 0;

	/// <summary>
	/// </summary>
	virtual const RehldsFuncs* get_funcs() = 0;

	/// <summary>
	/// </summary>
	virtual RehldsHookChains* get_hook_chains() = 0;

	/// <summary>
	/// </summary>
	virtual RehldsServerStatic* get_server_static() = 0;

	/// <summary>
	/// </summary>
	virtual RehldsServerData* get_server_data() = 0;

	/// <summary>
	/// </summary>
	virtual RehldsFlightRecorder* get_flight_recorder() = 0;
};
