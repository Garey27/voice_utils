// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <amxx/api.h>
#include <cstring>
#include <memory>

/// <summary>
/// <para>AMXX API function pointers.</para>
/// </summary>
AmxxApiFuncPointers AmxxApi::amxx_api_funcs_;

// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define AMXX_API_PTR_PTR(F) (reinterpret_cast<void**>(std::addressof(AmxxApi::amxx_api_funcs_.F)))

/// <summary>
/// </summary>
extern "C" AmxxStatus DLLEXPORT AMXX_Query(int* interface_version, AmxxModuleInfo* module_info)
{
	// Check parameters.
	if (!interface_version || !module_info) {
		return AmxxStatus::InvalidParameter;
	}

	// Check interface version.
	if (*interface_version != AMXX_INTERFACE_VERSION) {
		// Tell amxx core our interface version.
		*interface_version = AMXX_INTERFACE_VERSION;
		return AmxxStatus::InterfaceMismatch;
	}

	AmxxModuleInfo info =
	{
		AMXX_MODULE_NAME,
		AMXX_MODULE_AUTHOR,
		AMXX_MODULE_VERSION,
		AMXX_MODULE_RELOAD_ON_MAP_CHANGE,
		AMXX_MODULE_LOG_TAG,
		AMXX_MODULE_LIBRARY,
		AMXX_MODULE_LIB_CLASS
	};

	// Copy module info.
	std::memcpy(module_info, &info, sizeof(AmxxModuleInfo));

#ifdef AMXX_QUERY
	AMXX_QUERY();
#endif

	return AmxxStatus::Ok;
}

/// <summary>
/// </summary>
extern "C" AmxxGameStatus DLLEXPORT AMXX_CheckGame([[maybe_unused]] const char* game)
{
#ifdef AMXX_CHECK_GAME
	return AMXX_CHECK_GAME(game);
#else
	return AmxxGameStatus::Ok;
#endif
}

/// <summary>
/// </summary>
extern "C" AmxxStatus DLLEXPORT AMXX_Attach(const std::add_pointer_t<void*(const char*)> request_function)
{
	if (!request_function) {
		return AmxxStatus::InvalidParameter;
	}

	struct AmxxFuncs {
		const char* name;
		void** pointer;
	} amxx_functions[] = {
			{"amx_Allot", AMXX_API_PTR_PTR(amx_allot)},
			{"amx_Exec", AMXX_API_PTR_PTR(amx_exec)},
			{"amx_Execv", AMXX_API_PTR_PTR(amx_exec_v)},
			{"amx_FindNative", AMXX_API_PTR_PTR(amx_find_native)},
			{"amx_FindPublic", AMXX_API_PTR_PTR(amx_find_public)},
			{"amx_Push", AMXX_API_PTR_PTR(amx_push)},
			{"AddLibraries", AMXX_API_PTR_PTR(add_libraries)},
			{"AddNatives", AMXX_API_PTR_PTR(add_natives)},
			{"AddNewNatives", AMXX_API_PTR_PTR(add_new_natives)},
			{"AmxReregister", AMXX_API_PTR_PTR(amx_re_register)},
			{"BuildPathname", AMXX_API_PTR_PTR(build_path_name)},
			{"BuildPathnameR", AMXX_API_PTR_PTR(build_path_name_r)},
			//{"CellToReal", AMXX_API_PTR_PTR(cell_to_real)},
			{"CopyAmxMemory", AMXX_API_PTR_PTR(copy_amx_memory)},
			{"ExecuteForward", AMXX_API_PTR_PTR(execute_forward)},
			{"FindAmxScriptByAmx", AMXX_API_PTR_PTR(find_amx_script_by_amx)},
			{"FindAmxScriptByName", AMXX_API_PTR_PTR(find_amx_script_by_name)},
			{"FindLibrary", AMXX_API_PTR_PTR(find_library)},
			{"Format", AMXX_API_PTR_PTR(format)},
			{"FormatAmxString", AMXX_API_PTR_PTR(format_amx_string)},
			{"GetAmxAddr", AMXX_API_PTR_PTR(get_amx_address)},
			{"GetAmxScript", AMXX_API_PTR_PTR(get_amx_script)},
			{"GetAmxScriptName", AMXX_API_PTR_PTR(get_amx_script_name)},
			{"GetAmxString", AMXX_API_PTR_PTR(get_amx_string)},
			{"GetAmxStringLen", AMXX_API_PTR_PTR(get_amx_string_len)},
			{"GetLocalInfo", AMXX_API_PTR_PTR(get_local_info)},
			{"GetModname", AMXX_API_PTR_PTR(get_mod_name)},
			{"GetPlayerArmor", AMXX_API_PTR_PTR(get_player_armor)},
			{"GetPlayerCurweapon", AMXX_API_PTR_PTR(get_player_cur_weapon)},
			{"GetPlayerDeaths", AMXX_API_PTR_PTR(get_player_deaths)},
			{"GetPlayerEdict", AMXX_API_PTR_PTR(get_player_edict)},
			{"GetPlayerFlags", AMXX_API_PTR_PTR(get_player_flags)},
			{"GetPlayerFrags", AMXX_API_PTR_PTR(get_player_frags)},
			{"GetPlayerHealth", AMXX_API_PTR_PTR(get_player_health)},
			{"GetPlayerIP", AMXX_API_PTR_PTR(get_player_ip)},
			{"GetPlayerKeys", AMXX_API_PTR_PTR(get_player_keys)},
			{"GetPlayerMenu", AMXX_API_PTR_PTR(get_player_menu)},
			{"GetPlayerName", AMXX_API_PTR_PTR(get_player_name)},
			{"GetPlayerPlayTime", AMXX_API_PTR_PTR(get_player_play_time)},
			{"GetPlayerTeam", AMXX_API_PTR_PTR(get_player_team)},
			{"GetPlayerTeamID", AMXX_API_PTR_PTR(get_player_team_id)},
			{"GetPlayerTime", AMXX_API_PTR_PTR(get_player_time)},
			{"IsPlayerAlive", AMXX_API_PTR_PTR(is_player_alive)},
			{"IsPlayerAuthorized", AMXX_API_PTR_PTR(is_player_authorized)},
			{"IsPlayerBot", AMXX_API_PTR_PTR(is_player_bot)},
			{"IsPlayerConnecting", AMXX_API_PTR_PTR(is_player_connected)},
			{"IsPlayerHLTV", AMXX_API_PTR_PTR(is_player_hltv)},
			{"IsPlayerInGame", AMXX_API_PTR_PTR(is_player_in_game)},
			{"IsPlayerValid", AMXX_API_PTR_PTR(is_player_valid)},
			{"LoadAmxScript", AMXX_API_PTR_PTR(load_amx_script)},
			{"Log", AMXX_API_PTR_PTR(log)},
			{"LogError", AMXX_API_PTR_PTR(log_error)},
			{"MergeDefinitionFile", AMXX_API_PTR_PTR(merge_definition_file)},
			{"MessageBlock", AMXX_API_PTR_PTR(message_block)},
			{"OverrideNatives", AMXX_API_PTR_PTR(override_natives)},
			{"PlayerPropAddr", AMXX_API_PTR_PTR(player_prop_address)},
			{"PrepareCellArray", AMXX_API_PTR_PTR(prepare_cell_array)},
			{"PrepareCellArrayA", AMXX_API_PTR_PTR(prepare_cell_array_a)},
			{"PrepareCharArray", AMXX_API_PTR_PTR(prepare_char_array)},
			{"PrepareCharArrayA", AMXX_API_PTR_PTR(prepare_char_array_a)},
			{"PrintSrvConsole", AMXX_API_PTR_PTR(print_srv_console)},
			{"RaiseAmxError", AMXX_API_PTR_PTR(raise_amx_error)},
			//{"RealToCell", AMXX_API_PTR_PTR(real_to_cell)},
			{"RegAuthFunc", AMXX_API_PTR_PTR(register_auth_func)},
			{"RegisterForward", AMXX_API_PTR_PTR(register_forward)},
			{"RegisterFunction", AMXX_API_PTR_PTR(register_function)},
			{"RegisterFunctionEx", AMXX_API_PTR_PTR(register_function_ex)},
			{"RegisterSPForward", AMXX_API_PTR_PTR(register_sp_forward)},
			{"RegisterSPForwardByName", AMXX_API_PTR_PTR(register_sp_forward_by_name)},
			{"RemoveLibraries", AMXX_API_PTR_PTR(remove_libraries)},
			{"SetAmxString", AMXX_API_PTR_PTR(set_amx_string)},
			{"SetPlayerTeamInfo", AMXX_API_PTR_PTR(set_player_team_info)},
			{"UnloadAmxScript", AMXX_API_PTR_PTR(unload_amx_script)},
			{"UnregAuthFunc", AMXX_API_PTR_PTR(unregister_auth_func)},
			{"UnregisterSPForward", AMXX_API_PTR_PTR(unregister_sp_forward)},

#ifndef AMXX_182_COMPATIBILITY
			{"GetAmxStringNull", AMXX_API_PTR_PTR(get_amx_string_null)},
			{"GetAmxVectorNull", AMXX_API_PTR_PTR(get_amx_vector_null)},
			{"GetConfigManager", AMXX_API_PTR_PTR(get_config_manager)},
			{"LoadAmxScriptEx", AMXX_API_PTR_PTR(load_amx_script_ex)},
			{"SetAmxStringUTF8Cell", AMXX_API_PTR_PTR(set_amx_string_utf8_cell)},
			{"SetAmxStringUTF8Char", AMXX_API_PTR_PTR(set_amx_string_utf8_char)}
#endif
		};

	for (auto& function : amxx_functions) {
		if ((*function.pointer = request_function(function.name)) == nullptr) {
			return AmxxStatus::FuncNotPresent;
		}
	}

#ifdef AMXX_ATTACH
	return AMXX_ATTACH();
#else
	return AmxxStatus::Ok;
#endif
}

/// <summary>
/// </summary>
extern "C" AmxxStatus DLLEXPORT AMXX_Detach()
{
#ifdef AMXX_DETACH
	AMXX_DETACH();
#endif

	return AmxxStatus::Ok;
}

/// <summary>
/// </summary>
extern "C" AmxxStatus DLLEXPORT AMXX_PluginsLoaded() //-V524
{
#ifdef AMXX_PLUGINS_LOADED
	AMXX_PLUGINS_LOADED();
#endif

	return AmxxStatus::Ok;
}

/// <summary>
/// </summary>
extern "C" void DLLEXPORT AMXX_PluginsUnloaded()
{
#ifdef AMXX_PLUGINS_UNLOADED
	AMXX_PLUGINS_UNLOADED();
#endif
}

/// <summary>
/// </summary>
extern "C" void DLLEXPORT AMXX_PluginsUnloading()
{
#ifdef AMXX_PLUGINS_UNLOADING
	AMXX_PLUGINS_UNLOADING();
#endif
}

/// <summary>
/// </summary>
const char* filename_from_path(const char* const path)
{
	if (!path) {
		return path;
	}

	std::size_t index = 0;

#ifdef _WIN32
	for (std::size_t i = 0; path[i]; ++i) {
		if (path[i] == '\\') {
			index = i;
		}
	}
#else
	for (std::size_t i = 0; path[i]; ++i) {
		if (path[i] == '/') {
			index = i;
		}
	}
#endif

	return index ? path + index + 1 : path;
}
