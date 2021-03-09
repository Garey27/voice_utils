// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/ammo.h>
#include <cssdk/dll/items.h>
#include <cssdk/game_shared/voice_manager.h>

/// <summary>
/// </summary>
constexpr auto GAME_RULES_API_INTERFACE_VERSION = "GAMERULES_API_INTERFACE_VERSION001";

/// <summary>
/// </summary>
constexpr auto MAX_RULE_BUFFER = 1024;

/// <summary>
/// </summary>
constexpr auto MAX_VOTE_MAPS = 100;

/// <summary>
/// </summary>
constexpr auto MAX_VIP_QUEUES = 5;

/// <summary>
/// <para>Allowable money limit in the game that can be drawn on the HUD.</para>
/// </summary>
constexpr auto MAX_MONEY_THRESHOLD = 999999;

/// <summary>
/// </summary>
constexpr auto MAX_MOTD_CHUNK = 60;

/// <summary>
/// <para>(MAX_MOTD_CHUNK * 4)</para>
/// </summary>
constexpr auto MAX_MOTD_LENGTH = 1536;

/// <summary>
/// </summary>
constexpr auto ITEM_RESPAWN_TIME = 30.0f;

/// <summary>
/// </summary>
constexpr auto WEAPON_RESPAWN_TIME = 20.0f;

/// <summary>
/// </summary>
constexpr auto AMMO_RESPAWN_TIME = 20.0f;

/// <summary>
/// </summary>
constexpr auto ROUND_RESPAWN_TIME = 20.0f;

/// <summary>
/// <para>Delay before beginning new round.</para>
/// </summary>
constexpr auto ROUND_BEGIN_DELAY = 5.0f;

/// <summary>
/// </summary>
constexpr auto ITEM_KILL_DELAY = 300.0f;

/// <summary>
/// </summary>
constexpr auto RADIO_TIMEOUT = 1.5f;

/// <summary>
/// <para>Longest the intermission can last, in seconds.</para>
/// </summary>
constexpr auto MAX_INTERMISSION_TIME = 120;

/// <summary>
/// <para>When we are within this close to running out of entities,
/// items marked with the ITEM_FLAG_LIMIT_IN_WORLD will delay their respawn.</para>
/// </summary>
constexpr auto ENTITY_INTOLERANCE = 100;

/// <summary>
/// </summary>
constexpr auto REWARD_TARGET_BOMB = 3500;

/// <summary>
/// </summary>
constexpr auto REWARD_VIP_ESCAPED = 3500;

/// <summary>
/// </summary>
constexpr auto REWARD_VIP_ASSASSINATED = 3250;

/// <summary>
/// </summary>
constexpr auto REWARD_TERRORISTS_ESCAPED = 3150;

/// <summary>
/// </summary>
constexpr auto REWARD_CTS_PREVENT_ESCAPE = 3500;

/// <summary>
/// </summary>
constexpr auto REWARD_ESCAPING_TERRORISTS_NEUTRALIZED = 3250;

/// <summary>
/// </summary>
constexpr auto REWARD_BOMB_DEFUSED = 3250;

/// <summary>
/// </summary>
constexpr auto REWARD_BOMB_PLANTED = 800;

/// <summary>
/// </summary>
constexpr auto REWARD_BOMB_EXPLODED = 3250;

/// <summary>
/// </summary>
constexpr auto REWARD_CTS_WIN = 3000;

/// <summary>
/// </summary>
constexpr auto REWARD_TERRORISTS_WIN = 3000;

/// <summary>
/// </summary>
constexpr auto REWARD_ALL_HOSTAGES_RESCUED = 2500;

/// <summary>
/// <para>The end round was by the expiration time.</para>
/// </summary>
constexpr auto REWARD_TARGET_BOMB_SAVED = 3250;

/// <summary>
/// </summary>
constexpr auto REWARD_HOSTAGE_NOT_RESCUED = 3250;

/// <summary>
/// </summary>
constexpr auto REWARD_VIP_NOT_ESCAPED = 3250;

/// <summary>
/// <para>Loser bonus.</para>
/// </summary>
constexpr auto REWARD_LOSER_BONUS_DEFAULT = 1400;

/// <summary>
/// </summary>
constexpr auto REWARD_LOSER_BONUS_MIN = 1500;

/// <summary>
/// </summary>
constexpr auto REWARD_LOSER_BONUS_MAX = 3000;

/// <summary>
/// </summary>
constexpr auto REWARD_LOSER_BONUS_ADD = 500;

/// <summary>
/// </summary>
constexpr auto REWARD_RESCUED_HOSTAGE = 750;

/// <summary>
/// </summary>
constexpr auto REWARD_KILLED_ENEMY = 300;

/// <summary>
/// </summary>
constexpr auto REWARD_KILLED_VIP = 2500;

/// <summary>
/// </summary>
constexpr auto REWARD_VIP_HAVE_SELF_RESCUED = 2500;

/// <summary>
/// </summary>
constexpr auto REWARD_TAKEN_HOSTAGE = 1000;

/// <summary>
/// </summary>
constexpr auto REWARD_TOOK_HOSTAGE_ACC = 100;

/// <summary>
/// </summary>
constexpr auto REWARD_TOOK_HOSTAGE = 150;

/// <summary>
/// </summary>
constexpr auto PAYBACK_FOR_KILLED_TEAMMATES = -3300;

/// <summary>
/// <para>Flag "a".</para>
/// </summary>
constexpr auto SCENARIO_BLOCK_TIME_EXPIRED = 1 << 0;

/// <summary>
/// <para>Flag "b".</para>
/// </summary>
constexpr auto SCENARIO_BLOCK_NEED_PLAYERS = 1 << 1;

/// <summary>
/// <para>Flag "c".</para>
/// </summary>
constexpr auto SCENARIO_BLOCK_VIP_ESCAPE = 1 << 2;

/// <summary>
/// <para>Flag "d".</para>
/// </summary>
constexpr auto SCENARIO_BLOCK_PRISON_ESCAPE = 1 << 3;

/// <summary>
/// <para>Flag "e".</para>
/// </summary>
constexpr auto SCENARIO_BLOCK_BOMB = 1 << 4;

/// <summary>
/// <para>Flag "f".</para>
/// </summary>
constexpr auto SCENARIO_BLOCK_TEAM_EXTERMINATION = 1 << 5;

/// <summary>
/// <para>Flag "g".</para>
/// </summary>
constexpr auto SCENARIO_BLOCK_HOSTAGE_RESCUE = 1 << 6;

/// <summary>
/// <para>Flag "h".</para>
/// </summary>
constexpr auto SCENARIO_BLOCK_VIP_ESCAPE_TIME = 1 << 7;

/// <summary>
/// <para>Flag "i".</para>
/// </summary>
constexpr auto SCENARIO_BLOCK_PRISON_ESCAPE_TIME = 1 << 8;

/// <summary>
/// <para>Flag "j".</para>
/// </summary>
constexpr auto SCENARIO_BLOCK_BOMB_TIME = 1 << 9;

/// <summary>
/// <para>Flag "k".</para>
/// </summary>
constexpr auto SCENARIO_BLOCK_HOSTAGE_RESCUE_TIME = 1 << 10;

/// <summary>
/// Enum WinStatus
/// </summary>
enum class WinStatus {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	Cts,

	/// <summary>
	/// </summary>
	Terrorists,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// <para>Used for <c>end_round_message()</c> logged messages.</para>
/// </summary>
enum class ScenarioEventEndRound {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	TargetBomb,

	/// <summary>
	/// </summary>
	VipEscaped,

	/// <summary>
	/// </summary>
	VipAssassinated,

	/// <summary>
	/// </summary>
	TerroristsEscaped,

	/// <summary>
	/// </summary>
	CtsPreventEscape,

	/// <summary>
	/// </summary>
	EscapingTerroristsNeutralized,

	/// <summary>
	/// </summary>
	BombDefused,

	/// <summary>
	/// </summary>
	CtsWin,

	/// <summary>
	/// </summary>
	TerroristsWin,

	/// <summary>
	/// </summary>
	EndDraw,

	/// <summary>
	/// </summary>
	AllHostagesRescued,

	/// <summary>
	/// </summary>
	TargetSaved,

	/// <summary>
	/// </summary>
	HostageNotRescued,

	/// <summary>
	/// </summary>
	TerroristsNotEscaped,

	/// <summary>
	/// </summary>
	VipNotEscaped,

	/// <summary>
	/// </summary>
	GameCommence,

	/// <summary>
	/// </summary>
	GameRestart,

	/// <summary>
	/// </summary>
	GameOver
};

/// <summary>
/// Enum RewardRules
/// </summary>
enum class RewardRules {
	/// <summary>
	/// </summary>
	CtsWin = 0,

	/// <summary>
	/// </summary>
	TerroristsWin,

	/// <summary>
	/// </summary>
	TargetBomb,

	/// <summary>
	/// </summary>
	VipEscaped,

	/// <summary>
	/// </summary>
	VipAssassinated,

	/// <summary>
	/// </summary>
	TerroristsEscaped,

	/// <summary>
	/// </summary>
	CtsPreventEscape,

	/// <summary>
	/// </summary>
	EscapingTerroristsNeutralized,

	/// <summary>
	/// </summary>
	BombDefused,

	/// <summary>
	/// </summary>
	BombPlanted,

	/// <summary>
	/// </summary>
	BombExploded,

	/// <summary>
	/// </summary>
	AllHostagesRescued,

	/// <summary>
	/// </summary>
	TargetBombSaved,

	/// <summary>
	/// </summary>
	HostageNotRescued,

	/// <summary>
	/// </summary>
	VipNotEscaped,

	/// <summary>
	/// </summary>
	LoserBonusDefault,

	/// <summary>
	/// </summary>
	LoserBonusMin,

	/// <summary>
	/// </summary>
	LoserBonusMax,

	/// <summary>
	/// </summary>
	LoserBonusAdd,

	/// <summary>
	/// </summary>
	RescuedHostage,

	/// <summary>
	/// </summary>
	TookHostageAcc,

	/// <summary>
	/// </summary>
	TookHostage,

	/// <summary>
	/// </summary>
	End
};

/// <summary>
/// Enum InfoMapBuyParam
/// </summary>
enum InfoMapBuyParam {
	/// <summary>
	/// </summary>
	Everyone = 0,

	/// <summary>
	/// </summary>
	OnlyCts,

	/// <summary>
	/// </summary>
	OnlyTerrorists,

	/// <summary>
	/// </summary>
	NoOne
};

/// <summary>
/// <para>Weapon respawning return codes.</para>
/// </summary>
enum class WeaponRespawnCode {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	WeaponRespawnYes,

	/// <summary>
	/// </summary>
	WeaponRespawnNo,

	/// <summary>
	/// </summary>
	AmmoRespawnYes,

	/// <summary>
	/// </summary>
	AmmoRespawnNo,

	/// <summary>
	/// </summary>
	ItemRespawnYes,

	/// <summary>
	/// </summary>
	ItemRespawnNo,

	/// <summary>
	/// </summary>
	PlrDropGunAll,

	/// <summary>
	/// </summary>
	PlrDropGunActive,

	/// <summary>
	/// </summary>
	PlrDropGunNo,

	/// <summary>
	/// </summary>
	PlrDropAmmoAll,

	/// <summary>
	/// </summary>
	PlrDropAmmoActive,

	/// <summary>
	/// </summary>
	PlrDropAmmoNo
};

/// <summary>
/// <para>Player relationship return codes.</para>
/// </summary>
enum class PlayerRelationship {
	/// <summary>
	/// </summary>
	NotTeammate = 0,

	/// <summary>
	/// </summary>
	Teammate,

	/// <summary>
	/// </summary>
	Enemy,

	/// <summary>
	/// </summary>
	Ally,

	/// <summary>
	/// </summary>
	Neutral
};

/// <summary>
/// Class GameRules.
/// </summary>
class GameRules {
public:
	/// <summary>
	/// </summary>
	GameRules(const GameRules&) = default;

	/// <summary>
	/// </summary>
	GameRules& operator=(const GameRules&) = default;

	/// <summary>
	/// </summary>
	virtual ~GameRules() = 0;

	/// <summary>
	/// <para>Fill skill data struct with proper values.</para>
	/// </summary>
	virtual void refresh_skill_data() = 0;

	/// <summary>
	/// <para>Runs every server frame, should handle any timer tasks, periodic events, etc.</para>
	/// </summary>
	virtual void think() = 0;

	/// <summary>
	/// <para>Can this item spawn (eg monsters don't spawn in deathmatch).</para>
	/// </summary>
	virtual qboolean is_allowed_to_spawn(EntityBase* entity) = 0;

	/// <summary>
	/// <para>Are players allowed to switch on their flashlight?</para>
	/// </summary>
	virtual qboolean allow_flashlight() = 0;

	/// <summary>
	/// <para>Should the player switch to this weapon?</para>
	/// </summary>
	virtual qboolean should_switch_weapon(PlayerBase* player, PlayerItemBase* weapon) = 0;

	/// <summary>
	/// <para>I can't use this weapon anymore, get me the next best one.</para>
	/// </summary>
	virtual qboolean get_next_best_weapon(PlayerBase* player, PlayerItemBase* current_weapon) = 0;

	//
	// Functions to verify the single/multiplayer status of a game.
	// 

	/// <summary>
	/// <para>Is this a multiplayer game (either coop or deathmatch)?</para>
	/// </summary>
	virtual qboolean is_multiplayer() = 0;

	/// <summary>
	/// <para>Is this a deathmatch game?</para>
	/// </summary>
	virtual qboolean is_deathmatch() = 0;

	/// <summary>
	/// <para>Is this deathmatch game being played with team rules?</para>
	/// </summary>
	virtual qboolean is_teamplay() = 0;

	/// <summary>
	/// <para>Is this a coop game?</para>
	/// </summary>
	virtual qboolean is_coop() = 0;

	/// <summary>
	/// <para>This is the game name that gets seen in the server browser.</para>
	/// </summary>
	virtual const char* get_game_description() = 0;

	//
	// Client connection/disconnection.
	// 

	/// <summary>
	/// <para>A client just connected to the server (player hasn't spawned yet).</para>
	/// </summary>
	virtual qboolean client_connected(Edict* entity, const char* name, const char* address, char* reject_reason) = 0;

	/// <summary>
	/// <para>The client dll is ready for updating.</para>
	/// </summary>
	virtual void init_hud(PlayerBase* player) = 0;

	/// <summary>
	/// <para>A client just disconnected from the server.</para>
	/// </summary>
	virtual void client_disconnected(Edict* client) = 0;

	/// <summary>
	/// <para>The client needs to be informed of the current game mode.</para>
	/// </summary>
	virtual void update_game_mode(PlayerBase* player) = 0;

	//
	// Client damage rules.
	// 

	/// <summary>
	/// </summary>
	virtual float player_fall_damage(PlayerBase* player) = 0;

	/// <summary>
	/// <para>Can this player take damage from this attacker?</para>
	/// </summary>
	virtual qboolean player_can_take_damage(PlayerBase* player, EntityBase* attacker) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean should_auto_aim(PlayerBase* player, Edict* target) = 0;

	//
	// Client spawn/respawn control.
	// 

	/// <summary>
	/// <para>Called by <c>PlayerBase::spawn</c> just before releasing player into the game.</para>
	/// </summary>
	virtual void player_spawn(PlayerBase* player) = 0;

	/// <summary>
	/// <para>Called by <c>PlayerBase::pre_think</c> every frame, before physics are run and after keys are accepted.</para>
	/// </summary>
	virtual void player_think(PlayerBase* player) = 0;

	/// <summary>
	/// <para>Is this player allowed to respawn now?</para>
	/// </summary>
	virtual qboolean player_can_respawn(PlayerBase* player) = 0;

	/// <summary>
	/// <para>When in the future will this player be able to spawn?</para>
	/// </summary>
	virtual float player_spawn_time(PlayerBase* player) = 0;

	/// <summary>
	/// <para>Place this player on their spawn spot and face them the proper direction.</para>
	/// </summary>
	virtual Edict* get_player_spawn_spot(PlayerBase* player) = 0;

	//
	//
	//

	/// <summary>
	/// </summary>
	virtual qboolean allow_auto_target_crosshair() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean client_command_dead_or_alive(PlayerBase* player, const char* cmd) = 0;

	/// <summary>
	/// <para>Handles the user commands; returns TRUE if command handled properly.</para>
	/// </summary>
	virtual qboolean client_command(PlayerBase* player, const char* cmd) = 0;

	/// <summary>
	/// <para>The player has changed user info; can change it now.</para>
	/// </summary>
	virtual void client_user_info_changed(PlayerBase* player, char* info_buffer) = 0;

	//
	// Client kills/scoring.
	//

	/// <summary>
	/// <para>How many points do I award whoever kills this player?</para>
	/// </summary>
	virtual int points_for_kill(PlayerBase* attacker, PlayerBase* killed) = 0;

	/// <summary>
	/// <para>Called each time a player dies.</para>
	/// </summary>
	virtual void player_killed(PlayerBase* victim, EntityVars* killer, EntityVars* inflictor) = 0;

	/// <summary>
	/// <para>Call this from within a GameRules class to report an obituary.</para>
	/// </summary>
	virtual void death_notice(PlayerBase* victim, EntityVars* killer, EntityVars* inflictor) = 0;

	//
	// Weapon retrieval.
	// 

	/// <summary>
	/// <para>The player is touching an PlayerItemBase, do I give it to him?</para>
	/// </summary>
	virtual qboolean can_have_player_item(PlayerBase* player, PlayerItemBase* item) = 0;

	/// <summary>
	/// <para>Called each time a player picks up a weapon from the ground.</para>
	/// </summary>
	virtual void player_got_weapon(PlayerBase* player, PlayerItemBase* weapon) = 0;

	//
	// Weapon spawn/respawn control.
	// 

	/// <summary>
	/// <para>Should this weapon respawn?.</para>
	/// </summary>
	virtual WeaponRespawnCode weapon_should_respawn(PlayerItemBase* weapon) = 0;

	/// <summary>
	/// <para>When may this weapon respawn?</para>
	/// </summary>
	virtual float weapon_respawn_time(PlayerItemBase* weapon) = 0;

	/// <summary>
	/// <para>Can i respawn now, and if not, when should I try again?</para>
	/// </summary>
	virtual float weapon_try_respawn(PlayerItemBase* weapon) = 0;

	/// <summary>
	/// <para>Where in the world should this weapon respawn?</para>
	/// </summary>
	virtual Vector weapon_respawn_spot(PlayerItemBase* weapon) = 0;

	//
	// Item retrieval.
	// 

	/// <summary>
	/// <para>Is this player allowed to take this item?</para>
	/// </summary>
	virtual qboolean can_have_item(PlayerBase* player, Item* item) = 0;

	/// <summary>
	/// <para>Call each time a player picks up an item (battery, health kit, long jump).</para>
	/// </summary>
	virtual void player_got_item(PlayerBase* player, Item* item) = 0;

	//
	// Item spawn/respawn control.
	// 

	/// <summary>
	/// <para>Should this item respawn?</para>
	/// </summary>
	virtual WeaponRespawnCode item_should_respawn(Item* item) = 0;

	/// <summary>
	/// <para>When may this item respawn?</para>
	/// </summary>
	virtual float item_respawn_time(Item* item) = 0;

	/// <summary>
	/// <para>Where in the world should this item respawn?</para>
	/// </summary>
	virtual Vector item_respawn_spot(Item* item) = 0;

	//
	// Ammo retrieval.
	// 

	/// <summary>
	/// <para>Can this player take more of this ammo?</para>
	/// </summary>
	virtual qboolean can_have_ammo(PlayerBase* player, const char* ammo_name, int max_carry) = 0;

	/// <summary>
	/// <para>Called each time a player picks up some ammo in the world.</para>
	/// </summary>
	virtual void player_got_ammo(PlayerBase* player, char* name, int count) = 0;

	//
	// Ammo spawn/respawn control.
	// 

	/// <summary>
	/// <para>Should this ammo item respawn?</para>
	/// </summary>
	virtual WeaponRespawnCode ammo_should_respawn(PlayerAmmoBase* ammo) = 0;

	/// <summary>
	/// <para>When should this ammo item respawn?</para>
	/// </summary>
	virtual float ammo_respawn_time(PlayerAmmoBase* ammo) = 0;

	/// <summary>
	/// <para>Where in the world should this ammo item respawn?</para>
	/// </summary>
	virtual Vector ammo_respawn_spot(PlayerAmmoBase* ammo) = 0;

	//
	// Health charger respawn control.
	// 

	/// <summary>
	/// <para>How long until a depleted HealthCharger recharges itself?</para>
	/// </summary>
	virtual float health_charger_recharge_time() = 0;

	/// <summary>
	/// <para>How long until a depleted health_charger recharges itself?</para>
	/// </summary>
	virtual float hev_charger_recharge_time() = 0;

	//
	// What happens to a dead player's weapons.
	// 

	/// <summary>
	/// <para>What do I do with a player's weapons when he's killed?</para>
	/// </summary>
	virtual WeaponRespawnCode dead_player_weapons(PlayerBase* player) = 0;

	//
	// What happens to a dead player's ammo.
	// 

	/// <summary>
	/// <para>Do I drop ammo when the player dies? How much?</para>
	/// </summary>
	virtual WeaponRespawnCode dead_player_ammo(PlayerBase* player) = 0;

	//
	// Teamplay stuff.
	// 

	/// <summary>
	/// <para>What team is this entity on?</para>
	/// </summary>
	virtual const char* get_team_id(EntityBase* entity) = 0;

	/// <summary>
	/// <para>What is the player's relationship with this entity?</para>
	/// </summary>
	virtual PlayerRelationship player_relationship(PlayerBase* player, EntityBase* target) = 0;

	/// <summary>
	/// </summary>
	virtual int get_team_index(const char* team_name) = 0;

	/// <summary>
	/// </summary>
	virtual const char* get_indexed_team_name(int team_index) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_valid_team(const char* team_name) = 0;

	/// <summary>
	/// </summary>
	virtual void change_player_team(PlayerBase* player, const char* team_name, qboolean kill, qboolean gib) = 0;

	/// <summary>
	/// </summary>
	virtual const char* set_default_player_team(PlayerBase* player) = 0;

	//
	// Sounds.
	// 

	/// <summary>
	/// </summary>
	virtual qboolean play_texture_sounds() = 0;

	//
	// Monsters.
	// 

	/// <summary>
	/// <para>Are monsters allowed.</para>
	/// </summary>
	virtual qboolean allow_monsters() = 0;

	/// <summary>
	/// <para>Immediately end a multiplayer game.</para>
	/// </summary>
	virtual void end_multiplayer_game() = 0;

	//
	// Stuff that is shared between client and server.
	// 

	/// <summary>
	/// </summary>
	virtual qboolean is_freeze_period() = 0;

	/// <summary>
	/// </summary>
	virtual void server_deactivate() = 0;

	/// <summary>
	/// </summary>
	virtual void check_map_conditions() = 0;

	//
	//
	//

	/// <summary>
	/// <para>TRUE at beginning of round, set to FALSE when the period expires.</para>
	/// </summary>
	qboolean freeze_period{};

	/// <summary>
	/// </summary>
	qboolean bomb_dropped{};

	/// <summary>
	/// </summary>
	char* game_desc{};

	/// <summary>
	/// <para>Intermission or finale.</para>
	/// </summary>
	bool is_game_over{};
};

/// <summary>
/// Class HalfLifeRules.
/// </summary>
class HalfLifeRules : public GameRules {
public:
	/// <summary>
	/// </summary>
	~HalfLifeRules() override = 0;

	/// <summary>
	/// </summary>
	void think() override = 0;

	/// <summary>
	/// </summary>
	qboolean is_allowed_to_spawn(EntityBase* entity) override = 0;

	/// <summary>
	/// </summary>
	qboolean allow_flashlight() override = 0;

	/// <summary>
	/// </summary>
	qboolean should_switch_weapon(PlayerBase* player, PlayerItemBase* weapon) override = 0;

	/// <summary>
	/// </summary>
	qboolean get_next_best_weapon(PlayerBase* player, PlayerItemBase* current_weapon) override = 0;

	//
	// Functions to verify the single/multiplayer status of a game.
	// 

	/// <summary>
	/// </summary>
	qboolean is_multiplayer() override = 0;

	/// <summary>
	/// </summary>
	qboolean is_deathmatch() override = 0;

	/// <summary>
	/// </summary>
	qboolean is_coop() override = 0;

	//
	// Client connection/disconnection.
	// 

	/// <summary>
	/// </summary>
	qboolean client_connected(Edict* entity, const char* name, const char* address, char reject_reason[128]) override = 0;

	/// <summary>
	/// <para>The client dll is ready for updating.</para>
	/// </summary>
	void init_hud(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	void client_disconnected(Edict* client) override = 0;

	//
	// Client damage rules.
	// 

	/// <summary>
	/// </summary>
	float player_fall_damage(PlayerBase* player) override = 0;

	//
	// Client spawn/respawn control.
	// 

	/// <summary>
	/// </summary>
	void player_spawn(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	void player_think(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	qboolean player_can_respawn(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	float player_spawn_time(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	Edict* get_player_spawn_spot(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	qboolean allow_auto_target_crosshair() override = 0;

	//
	// Client kills/scoring.
	// 

	/// <summary>
	/// </summary>
	int points_for_kill(PlayerBase* attacker, PlayerBase* killed) override = 0;

	/// <summary>
	/// </summary>
	void player_killed(PlayerBase* victim, EntityVars* killer, EntityVars* inflictor) override = 0;

	/// <summary>
	/// </summary>
	void death_notice(PlayerBase* victim, EntityVars* killer, EntityVars* inflictor) override = 0;

	//
	// Weapon retrieval.
	// 

	/// <summary>
	/// </summary>
	void player_got_weapon(PlayerBase* player, PlayerItemBase* weapon) override = 0;

	//
	// Weapon spawn/respawn control.
	// 

	/// <summary>
	/// </summary>
	WeaponRespawnCode weapon_should_respawn(PlayerItemBase* weapon) override = 0;

	/// <summary>
	/// </summary>
	float weapon_respawn_time(PlayerItemBase* weapon) override = 0;

	/// <summary>
	/// </summary>
	float weapon_try_respawn(PlayerItemBase* weapon) override = 0;

	/// <summary>
	/// </summary>
	Vector weapon_respawn_spot(PlayerItemBase* weapon) override = 0;

	//
	// Item retrieval.
	// 

	/// <summary>
	/// </summary>
	qboolean can_have_item(PlayerBase* player, Item* item) override = 0;

	/// <summary>
	/// </summary>
	void player_got_item(PlayerBase* player, Item* item) override = 0;

	//
	// Item spawn/respawn control.
	// 

	/// <summary>
	/// </summary>
	WeaponRespawnCode item_should_respawn(Item* item) override = 0;

	/// <summary>
	/// </summary>
	float item_respawn_time(Item* item) override = 0;

	/// <summary>
	/// </summary>
	Vector item_respawn_spot(Item* item) override = 0;

	//
	// Ammo retrieval.
	// 

	/// <summary>
	/// </summary>
	void player_got_ammo(PlayerBase* player, char* name, int count) override = 0;

	//
	// Ammo spawn/respawn control.
	// 

	/// <summary>
	/// </summary>
	WeaponRespawnCode ammo_should_respawn(PlayerAmmoBase* ammo) override = 0;

	/// <summary>
	/// </summary>
	float ammo_respawn_time(PlayerAmmoBase* ammo) override = 0;

	/// <summary>
	/// </summary>
	Vector ammo_respawn_spot(PlayerAmmoBase* ammo) override = 0;

	//
	// Health charger respawn control.
	// 

	/// <summary>
	/// </summary>
	float health_charger_recharge_time() override = 0;

	//
	// What happens to a dead player's weapons.
	// 

	/// <summary>
	/// </summary>
	WeaponRespawnCode dead_player_weapons(PlayerBase* player) override = 0;

	//
	// What happens to a dead player's ammo.
	// 

	/// <summary>
	/// </summary>
	WeaponRespawnCode dead_player_ammo(PlayerBase* player) override = 0;

	//
	// Teamplay stuff.
	// 

	/// <summary>
	/// </summary>
	const char* get_team_id(EntityBase* entity) override = 0;

	/// <summary>
	/// </summary>
	PlayerRelationship player_relationship(PlayerBase* player, EntityBase* target) override = 0;

	//
	// Monsters.
	// 

	/// <summary>
	/// </summary>
	qboolean allow_monsters() override = 0;
};

#ifdef __INTEL_COMPILER
#pragma warning(push)
#pragma warning(disable: 2021)
#endif

/// <summary>
/// Class HalfLifeMultiplay.
/// </summary>
class HalfLifeMultiplay : public GameRules {
public:
	/// <summary>
	/// </summary>
	~HalfLifeMultiplay() override = 0;

	/// <summary>
	/// </summary>
	void refresh_skill_data() override = 0;

	/// <summary>
	/// </summary>
	void think() override = 0;

	/// <summary>
	/// </summary>
	qboolean is_allowed_to_spawn(EntityBase* entity) override = 0;

	/// <summary>
	/// </summary>
	qboolean allow_flashlight() override = 0;

	/// <summary>
	/// </summary>
	qboolean should_switch_weapon(PlayerBase* player, PlayerItemBase* weapon) override = 0;

	/// <summary>
	/// </summary>
	qboolean get_next_best_weapon(PlayerBase* player, PlayerItemBase* current_weapon) override = 0;

	/// <summary>
	/// </summary>
	qboolean is_multiplayer() override = 0;

	/// <summary>
	/// </summary>
	qboolean is_deathmatch() override = 0;

	/// <summary>
	/// </summary>
	qboolean is_coop() override = 0;

	//
	// Client connection/disconnection.
	// 

	/// <summary>
	/// <para>If <c>client_connected</c> returns <c>FALSE</c>, the connection is rejected and the user is provided the reason specified in <c>reject_reason</c>.<br/>
	/// Only the client's name and remote address are provided to the dll for verification.
	/// </para>
	/// </summary>
	qboolean client_connected(Edict* entity, const char* name, const char* address, char reject_reason[128]) override = 0;

	/// <summary>
	/// <para>The client dll is ready for updating.</para>
	/// </summary>
	void init_hud(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	void client_disconnected(Edict* client) override = 0;

	/// <summary>
	/// <para>The client needs to be informed of the current game mode.</para>
	/// </summary>
	void update_game_mode(PlayerBase* player) override = 0;

	//
	// Client damage rules.
	//

	/// <summary>
	/// </summary>
	float player_fall_damage(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	qboolean player_can_take_damage(PlayerBase* player, EntityBase* attacker) override = 0;

	//
	// Client spawn/respawn control.
	// 

	/// <summary>
	/// </summary>
	void player_spawn(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	void player_think(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	qboolean player_can_respawn(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	float player_spawn_time(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	Edict* get_player_spawn_spot(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	qboolean allow_auto_target_crosshair() override = 0;

	/// <summary>
	/// </summary>
	qboolean client_command_dead_or_alive(PlayerBase* player, const char* cmd) override = 0;

	/// <summary>
	/// </summary>
	qboolean client_command(PlayerBase* player, const char* cmd) override = 0;

	/// <summary>
	/// </summary>
	void client_user_info_changed(PlayerBase* player, char* info_buffer) override = 0;

	//
	// Client kills/scoring.
	// 

	/// <summary>
	/// </summary>
	int points_for_kill(PlayerBase* attacker, PlayerBase* killed) override = 0;

	/// <summary>
	/// </summary>
	void player_killed(PlayerBase* victim, EntityVars* killer, EntityVars* inflictor) override = 0;

	/// <summary>
	/// </summary>
	void death_notice(PlayerBase* victim, EntityVars* killer, EntityVars* inflictor) override = 0;

	//
	// Weapon retrieval.
	// 

	/// <summary>
	/// <para>The player is touching an PlayerItemBase, do I give it to him?</para>
	/// </summary>
	qboolean can_have_player_item(PlayerBase* player, PlayerItemBase* weapon) override = 0;

	/// <summary>
	/// </summary>
	void player_got_weapon(PlayerBase* player, PlayerItemBase* weapon) override = 0;

	//
	// Weapon spawn/respawn control.
	// 

	/// <summary>
	/// </summary>
	WeaponRespawnCode weapon_should_respawn(PlayerItemBase* weapon) override = 0;

	/// <summary>
	/// </summary>
	float weapon_respawn_time(PlayerItemBase* weapon) override = 0;

	/// <summary>
	/// </summary>
	float weapon_try_respawn(PlayerItemBase* weapon) override = 0;

	/// <summary>
	/// </summary>
	Vector weapon_respawn_spot(PlayerItemBase* weapon) override = 0;

	//
	// Item retrieval.
	// 

	/// <summary>
	/// </summary>
	qboolean can_have_item(PlayerBase* player, Item* item) override = 0;

	/// <summary>
	/// </summary>
	void player_got_item(PlayerBase* player, Item* item) override = 0;

	//
	// Item spawn/respawn control.
	// 

	/// <summary>
	/// </summary>
	WeaponRespawnCode item_should_respawn(Item* item) override = 0;

	/// <summary>
	/// </summary>
	float item_respawn_time(Item* item) override = 0;

	/// <summary>
	/// </summary>
	Vector item_respawn_spot(Item* item) override = 0;

	//
	// Ammo retrieval.
	// 

	/// <summary>
	/// </summary>
	void player_got_ammo(PlayerBase* player, char* name, int count) override = 0;

	//
	// Ammo spawn/respawn control.
	// 

	/// <summary>
	/// </summary>
	WeaponRespawnCode ammo_should_respawn(PlayerAmmoBase* ammo) override = 0;

	/// <summary>
	/// </summary>
	float ammo_respawn_time(PlayerAmmoBase* ammo) override = 0;

	/// <summary>
	/// </summary>
	Vector ammo_respawn_spot(PlayerAmmoBase* ammo) override = 0;

	//
	// Health charger respawn control.
	// 

	/// <summary>
	/// </summary>
	float health_charger_recharge_time() override = 0;

	/// <summary>
	/// </summary>
	float hev_charger_recharge_time() override = 0;

	//
	// What happens to a dead player's weapons.
	// 

	/// <summary>
	/// </summary>
	WeaponRespawnCode dead_player_weapons(PlayerBase* player) override = 0;

	//
	// What happens to a dead player's ammo.
	// 

	/// <summary>
	/// </summary>
	WeaponRespawnCode dead_player_ammo(PlayerBase* player) override = 0;

	//
	// Teamplay stuff.
	// 

	/// <summary>
	/// </summary>
	const char* get_team_id(EntityBase* entity) override = 0;

	/// <summary>
	/// </summary>
	PlayerRelationship player_relationship(PlayerBase* player, EntityBase* target) override = 0;

	/// <summary>
	/// </summary>
	void change_player_team(PlayerBase* player, const char* team_name, qboolean kill, qboolean gib) override = 0;

	/// <summary>
	/// </summary>
	qboolean play_texture_sounds() override = 0;

	//
	// Monsters.
	// 

	/// <summary>
	/// </summary>
	qboolean allow_monsters() override = 0;

	//
	// Immediately end a multiplayer game.
	// 

	/// <summary>
	/// </summary>
	void end_multiplayer_game() override = 0;

	/// <summary>
	/// </summary>
	void server_deactivate() override = 0;

	/// <summary>
	/// </summary>
	void check_map_conditions() override = 0;

	//
	// Recreate all the map entities from the map data (preserving their indices), then remove everything else except the players.
	// Also get rid of all world decals.
	// 

	/// <summary>
	/// </summary>
	virtual void clean_up_map() = 0;

	/// <summary>
	/// </summary>
	virtual void restart_round() = 0;

	//
	// Check if the scenario has been won/lost.
	// 

	/// <summary>
	/// </summary>
	virtual void check_win_conditions() = 0;

	/// <summary>
	/// </summary>
	virtual void remove_guns() = 0;

	/// <summary>
	/// </summary>
	virtual void give_c4() = 0;

	/// <summary>
	/// </summary>
	virtual void change_level() = 0;

	/// <summary>
	/// </summary>
	virtual void go_to_intermission() = 0;

#ifdef REGAMEDLL_ADD
	/// <summary>
	/// </summary>
	virtual void initialize_player_counts(int& num_alive_terrorist, int& num_alive_ct, int& num_dead_terrorist, int& num_dead_ct) = 0;

	/// <summary>
	/// </summary>
	virtual void balance_teams() = 0;

	/// <summary>
	/// </summary>
	virtual void swap_all_players() = 0;

	/// <summary>
	/// </summary>
	virtual void update_team_scores() = 0;

	/// <summary>
	/// </summary>
	virtual void end_round_message(const char* sentence, ScenarioEventEndRound event) = 0;

	/// <summary>
	/// </summary>
	virtual void set_account_rules(RewardRules rules, int amount) = 0;

	/// <summary>
	/// </summary>
	[[nodiscard]] virtual int get_account_rules(RewardRules rules) const = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_there_a_bomber() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_there_a_bomb() = 0;

	/// <summary>
	/// </summary>
	virtual TeamName select_default_team() = 0;

	/// <summary>
	/// </summary>
	virtual bool has_round_time_expired() = 0;

	/// <summary>
	/// </summary>
	virtual bool is_bomb_planted() = 0;
#endif

	/// <summary>
	/// </summary>
	VoiceGameMgr voice_manager;

	/// <summary>
	/// <para>The global time when the round is supposed to end, if this is not 0 (deprecated name <c>team_count</c>).</para>
	/// </summary>
	float restart_round_time;

	/// <summary>
	/// </summary>
	float win_conditions;

	/// <summary>
	/// <para>Time round has started (deprecated name <c>round_count</c>).</para>
	/// </summary>
	float round_start_time;

	/// <summary>
	/// <para>(From mp_roundtime) - How many seconds long this round is.</para>
	/// </summary>
	int round_time;

	/// <summary>
	/// </summary>
	int round_time_secs;

	/// <summary>
	/// <para>(From mp_freezetime) - How many seconds long the intro round (when players are frozen) is.</para>
	/// </summary>
	int intro_round_time;

	/// <summary>
	/// <para>The global time when the intro round ends and the real one starts
	/// wrote the original "RoundTime" comment for this variable).</para>
	/// </summary>
	float round_start_time_real;

	/// <summary>
	/// </summary>
	int account_terrorist;

	/// <summary>
	/// </summary>
	int account_ct;

	/// <summary>
	/// <para>The number of terrorists on the team (this is generated at the end of a round).</para>
	/// </summary>
	int num_terrorist;

	/// <summary>
	/// <para>The number of CTs on the team (this is generated at the end of a round).</para>
	/// </summary>
	int num_ct;

	/// <summary>
	/// </summary>
	int num_spawnable_terrorist;

	/// <summary>
	/// </summary>
	int num_spawnable_ct;

	/// <summary>
	/// <para>Number of Terrorist spawn points.</para>
	/// </summary>
	int spawn_point_count_terrorist;

	/// <summary>
	/// <para>Number of CT spawn points.</para>
	/// </summary>
	int spawn_point_count_ct;

	/// <summary>
	/// </summary>
	int hostages_rescued;

	/// <summary>
	/// </summary>
	int hostages_touched;

	/// <summary>
	/// </summary>
	WinStatus round_win_status;

	/// <summary>
	/// </summary>
	short num_ct_wins;

	/// <summary>
	/// </summary>
	short num_terrorist_wins;

	/// <summary>
	/// <para>Whether or not the bomb has been bombed.</para>
	/// </summary>
	bool target_bombed;

	/// <summary>
	/// <para>Whether or not the bomb has been defused.</para>
	/// </summary>
	bool bomb_defused;

	/// <summary>
	/// </summary>
	bool map_has_bomb_target;

	/// <summary>
	/// </summary>
	bool map_has_bomb_zone;

	/// <summary>
	/// </summary>
	bool map_has_buy_zone;

	/// <summary>
	/// </summary>
	bool map_has_rescue_zone;

	/// <summary>
	/// </summary>
	bool map_has_escape_zone;

	/// <summary>
	/// <para>TRUE = has VIP safety zone, FALSE = does not have VIP safety zone.</para>
	/// </summary>
	qboolean map_has_vip_safety_zone;

	/// <summary>
	/// </summary>
	qboolean map_has_cameras;

	/// <summary>
	/// </summary>
	int c4_timer;

	/// <summary>
	/// <para>The current Terrorist who has the C4.</para>
	/// </summary>
	int c4_guy;

	/// <summary>
	/// <para>The amount of money the losing team gets. This scales up as they lose more rounds in a row.</para>
	/// </summary>
	int loser_bonus;

	/// <summary>
	/// <para>The number of rounds the CTs have lost in a row.</para>
	/// </summary>
	int num_consecutive_ct_loses;

	/// <summary>
	/// <para>The number of rounds the Terrorists have lost in a row.</para>
	/// </summary>
	int num_consecutive_terrorist_loses;

	/// <summary>
	/// <para>For the idle kick functionality. This is tha max amount of time that the player has to be idle before being kicked.</para>
	/// </summary>
	float max_idle_period;

	/// <summary>
	/// </summary>
	int limit_teams;

	/// <summary>
	/// </summary>
	bool level_initialized;

	/// <summary>
	/// </summary>
	bool round_terminating;

	/// <summary>
	/// <para>Set to TRUE to have the scores reset next time round restarts.</para>
	/// </summary>
	bool complete_reset;

	/// <summary>
	/// </summary>
	float required_escape_ratio;

	/// <summary>
	/// </summary>
	int num_escapers;

	/// <summary>
	/// </summary>
	int have_escaped;

	/// <summary>
	/// </summary>
	bool ct_cant_buy;

	/// <summary>
	/// </summary>
	bool t_cant_buy;

	/// <summary>
	/// </summary>
	float bomb_radius;

	/// <summary>
	/// </summary>
	int consecutive_vip;

	/// <summary>
	/// </summary>
	int total_gun_count;

	/// <summary>
	/// </summary>
	int total_grenade_count;

	/// <summary>
	/// </summary>
	int total_armour_count;

	/// <summary>
	/// <para>Keeps track of the # of consecutive rounds that have gone by where one team outnumbers the other team by more than 2.</para>
	/// </summary>
	int unbalanced_rounds;

	/// <summary>
	/// <para>Keeps track of the # of consecutive rounds of escape played. Teams will be swapped after 8 rounds</para>
	/// </summary>
	int num_escape_rounds;

	/// <summary>
	/// </summary>
	int map_votes[MAX_VOTE_MAPS];

	/// <summary>
	/// </summary>
	int last_pick;

	/// <summary>
	/// </summary>
	int max_map_time;

	/// <summary>
	/// </summary>
	int max_rounds;

	/// <summary>
	/// </summary>
	int total_rounds_played;

	/// <summary>
	/// </summary>
	int max_rounds_won;

	/// <summary>
	/// </summary>
	int stored_spect_value;

	/// <summary>
	/// </summary>
	float force_camera_value;

	/// <summary>
	/// </summary>
	float force_chase_cam_value;

	/// <summary>
	/// </summary>
	float fade_to_black_value;

	/// <summary>
	/// </summary>
	PlayerBase* vip;

	/// <summary>
	/// </summary>
	PlayerBase* vip_queue[MAX_VIP_QUEUES];

//protected:
	/// <summary>
	/// </summary>
	float intermission_end_time_;

	/// <summary>
	/// </summary>
	float intermission_start_time_;

	/// <summary>
	/// </summary>
	qboolean end_intermission_button_hit_;

	/// <summary>
	/// </summary>
	float next_periodic_think_;

	/// <summary>
	/// <para>TRUE = the game commencing when there is at least one CT and T,
	/// FALSE = scoring will not start until both teams have players (deprecated name <c>first_connected</c>).</para>
	/// </summary>
	bool game_started_;

	/// <summary>
	/// </summary>
	bool in_career_game_;

	/// <summary>
	/// </summary>
	float career_round_menu_time_;

	/// <summary>
	/// </summary>
	int career_match_wins_;

	/// <summary>
	/// </summary>
	int round_win_difference_;

	/// <summary>
	/// </summary>
	float career_match_menu_time_;

	/// <summary>
	/// </summary>
	bool skip_spawn_;

	//
	// Custom.
	// 

	/// <summary>
	/// </summary>
	bool skip_show_menu_;

	/// <summary>
	/// </summary>
	bool needed_players_;

	/// <summary>
	/// </summary>
	float escape_ratio_;

	/// <summary>
	/// </summary>
	float time_limit_;

	/// <summary>
	/// </summary>
	float game_start_time_;

	/// <summary>
	/// </summary>
	bool team_balanced_;
};

#ifdef __INTEL_COMPILER
#pragma warning(pop)
#endif
