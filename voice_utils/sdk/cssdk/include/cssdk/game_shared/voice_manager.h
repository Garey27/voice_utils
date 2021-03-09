// ***********************************************************************
// Created          : 06-30-2020
//
// Last Modified By : the_hunter
// Last Modified On : 06-30-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/player.h>

#ifdef __INTEL_COMPILER
#pragma warning(push)
#pragma warning(disable: 2021)
#endif

/// <summary>
/// Class IVoiceGameMgrHelper.
/// </summary>
class IVoiceGameMgrHelper {
public:
	/// <summary>
	/// </summary>
	virtual ~IVoiceGameMgrHelper() = 0;

	/// <summary>
	/// <para>Called each frame to determine which players are allowed to hear each other.<br/>
	/// This overrides whatever squelch settings players have.</para>
	/// </summary>
	virtual bool can_player_hear_player(PlayerBase* listener, PlayerBase* talker) = 0;

#ifdef REGAMEDLL_ADD
	/// <summary>
	/// </summary>
	virtual void reset_can_hear_player(Edict* edict) = 0;

	/// <summary>
	/// </summary>
	virtual void set_can_hear_player(PlayerBase* listener, PlayerBase* sender, bool can_hear) = 0;

	/// <summary>
	/// </summary>
	virtual bool get_can_hear_player(PlayerBase* listener, PlayerBase* sender) = 0;
#endif
};

/// <summary>
/// Class VoiceGameMgr.
/// </summary>
class VoiceGameMgr {
public:
	/// <summary>
	/// </summary>
	virtual ~VoiceGameMgr() = default;

	//private:
	/// <summary>
	/// </summary>
	int msg_player_voice_mask_{}; // NOLINT(clang-diagnostic-unused-private-field)

	/// <summary>
	/// </summary>
	int msg_request_state_{}; // NOLINT(clang-diagnostic-unused-private-field)

	/// <summary>
	/// </summary>
	IVoiceGameMgrHelper* helper_{}; // NOLINT(clang-diagnostic-unused-private-field)

	/// <summary>
	/// </summary>
	int max_players_{}; // NOLINT(clang-diagnostic-unused-private-field)

	/// <summary>
	/// <para>How long since the last update.</para>
	/// </summary>
	double update_interval_{}; // NOLINT(clang-diagnostic-unused-private-field)
};

#ifdef __INTEL_COMPILER
#pragma warning(pop)
#endif
