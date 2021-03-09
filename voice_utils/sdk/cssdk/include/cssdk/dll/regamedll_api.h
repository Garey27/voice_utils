// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 06-02-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/common/hook_chains.h>
#include <cssdk/dll/game_rules.h>
#include <cssdk/dll/gib.h>

//-V::122
//-V:RegamedllFuncs:730

/// <summary>
/// </summary>
constexpr auto REGAMEDLL_API_VERSION_MAJOR = 5;

/// <summary>
/// </summary>
constexpr auto REGAMEDLL_API_VERSION_MINOR = 18;

/// <summary>
/// </summary>
constexpr auto VREGAMEDLL_API_VERSION = "VRE_GAMEDLL_API_VERSION001";

// PlayerBase::Spawn hook
using ReHookPlayerSpawn = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerSpawn = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::Precache hook
using ReHookPlayerPrecache = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerPrecache = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::ObjectCaps hook
using ReHookPlayerObjectCaps = IHookChainClass<int, PlayerBase>;
using ReHookRegistryPlayerObjectCaps = IHookChainClassRegistry<int, PlayerBase>;

// PlayerBase::Classify hook
using ReHookPlayerClassify = IHookChainClass<int, PlayerBase>;
using ReHookRegistryPlayerClassify = IHookChainClassRegistry<int, PlayerBase>;

// PlayerBase::TraceAttack hook
using ReHookPlayerTraceAttack = IHookChainClass<void, PlayerBase, EntityVars*, float, Vector&, TraceResult*, int>;
using ReHookRegistryPlayerTraceAttack = IHookChainClassRegistry<void, PlayerBase, EntityVars*, float, Vector&, TraceResult*, int>;

// PlayerBase::TakeDamage hook
using ReHookPlayerTakeDamage = IHookChainClass<qboolean, PlayerBase, EntityVars*, EntityVars*, float&, int>;
using ReHookRegistryPlayerTakeDamage = IHookChainClassRegistry<qboolean, PlayerBase, EntityVars*, EntityVars*, float&, int>;

// PlayerBase::TakeHealth hook
using ReHookPlayerTakeHealth = IHookChainClass<qboolean, PlayerBase, float, int>;
using ReHookRegistryPlayerTakeHealth = IHookChainClassRegistry<qboolean, PlayerBase, float, int>;

// PlayerBase::Killed hook
using ReHookPlayerKilled = IHookChainClass<void, PlayerBase, EntityVars*, int>;
using ReHookRegistryPlayerKilled = IHookChainClassRegistry<void, PlayerBase, EntityVars*, int>;

// PlayerBase::AddPoints hook
using ReHookPlayerAddPoints = IHookChainClass<void, PlayerBase, int, qboolean>;
using ReHookRegistryPlayerAddPoints = IHookChainClassRegistry<void, PlayerBase, int, qboolean>;

// PlayerBase::AddPointsToTeam hook
using ReHookPlayerAddPointsToTeam = IHookChainClass<void, PlayerBase, int, qboolean>;
using ReHookRegistryPlayerAddPointsToTeam = IHookChainClassRegistry<void, PlayerBase, int, qboolean>;

// PlayerBase::AddPlayerItem hook
using ReHookPlayerAddPlayerItem = IHookChainClass<qboolean, PlayerBase, PlayerItemBase*>;
using ReHookRegistryPlayerAddPlayerItem = IHookChainClassRegistry<qboolean, PlayerBase, PlayerItemBase*>;

// PlayerBase::RemovePlayerItem hook
using ReHookPlayerRemovePlayerItem = IHookChainClass<qboolean, PlayerBase, PlayerItemBase*>;
using ReHookRegistryPlayerRemovePlayerItem = IHookChainClassRegistry<qboolean, PlayerBase, PlayerItemBase*>;

// PlayerBase::GiveAmmo hook
using ReHookPlayerGiveAmmo = IHookChainClass<int, PlayerBase, int, const char*, int>;
using ReHookRegistryPlayerGiveAmmo = IHookChainClassRegistry<int, PlayerBase, int, const char*, int>;

// PlayerBase::ResetMaxSpeed hook
using ReHookPlayerResetMaxSpeed = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerResetMaxSpeed = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::Jump hook
using ReHookPlayerJump = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerJump = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::Duck hook
using ReHookPlayerDuck = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerDuck = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::PreThink hook
using ReHookPlayerPreThink = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerPreThink = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::PostThink hook
using ReHookPlayerPostThink = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerPostThink = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::UpdateClientData hook
using ReHookPlayerUpdateClientData = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerUpdateClientData = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::ImpulseCommands hook
using ReHookPlayerImpulseCommands = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerImpulseCommands = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::RoundRespawn hook
using ReHookPlayerRoundRespawn = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerRoundRespawn = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::Blind hook
using ReHookPlayerBaseBlind = IHookChainClass<void, PlayerBase, float, float, float, int>;
using ReHookRegistryPlayerBaseBlind = IHookChainClassRegistry<void, PlayerBase, float, float, float, int>;

// PlayerBase::Observer_IsValidTarget hook
using ReHookPlayerObserverIsValidTarget = IHookChainClass<PlayerBase*, PlayerBase, int, bool>;
using ReHookRegistryPlayerObserverIsValidTarget = IHookChainClassRegistry<PlayerBase*, PlayerBase, int, bool>;

// PlayerBase::SetAnimation hook
using ReHookPlayerSetAnimation = IHookChainClass<void, PlayerBase, PlayerAnim>;
using ReHookRegistryPlayerSetAnimation = IHookChainClassRegistry<void, PlayerBase, PlayerAnim>;

// PlayerBase::GiveDefaultItems hook
using ReHookPlayerGiveDefaultItems = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerGiveDefaultItems = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::GiveNamedItem hook
using ReHookPlayerGiveNamedItem = IHookChainClass<EntityBase*, PlayerBase, const char*>;
using ReHookRegistryPlayerGiveNamedItem = IHookChainClassRegistry<EntityBase*, PlayerBase, const char*>;

// PlayerBase::AddAccount hook
using ReHookPlayerAddAccount = IHookChainClass<void, PlayerBase, int, RewardType, bool>;
using ReHookRegistryPlayerAddAccount = IHookChainClassRegistry<void, PlayerBase, int, RewardType, bool>;

// PlayerBase::GiveShield hook
using ReHookPlayerGiveShield = IHookChainClass<void, PlayerBase, bool>;
using ReHookRegistryPlayerGiveShield = IHookChainClassRegistry<void, PlayerBase, bool>;

// PlayerBase:SetClientUserInfoModel hook
using ReHookPlayerSetClientUserInfoModel = IHookChainClass<void, PlayerBase, char*, char*>;
using ReHookRegistryPlayerSetClientUserInfoModel = IHookChainClassRegistry<void, PlayerBase, char*, char*>;

// PlayerBase:SetClientUserInfoName hook
using ReHookPlayerSetClientUserInfoName = IHookChainClass<bool, PlayerBase, char*, char*>;
using ReHookRegistryPlayerSetClientUserInfoName = IHookChainClassRegistry<bool, PlayerBase, char*, char*>;

// PlayerBase::HasRestrictItem hook
using ReHookPlayerHasRestrictItem = IHookChainClass<bool, PlayerBase, ItemId, ItemRestType>;
using ReHookRegistryPlayerHasRestrictItem = IHookChainClassRegistry<bool, PlayerBase, ItemId, ItemRestType>;

// PlayerBase::DropPlayerItem hook
using ReHookPlayerDropPlayerItem = IHookChainClass<EntityBase*, PlayerBase, const char*>;
using ReHookRegistryPlayerDropPlayerItem = IHookChainClassRegistry<EntityBase*, PlayerBase, const char*>;

// PlayerBase::DropShield hook
using ReHookPlayerDropShield = IHookChainClass<EntityBase*, PlayerBase, bool>;
using ReHookRegistryPlayerDropShield = IHookChainClassRegistry<EntityBase*, PlayerBase, bool>;

// PlayerBase::OnSpawnEquip hook
using ReHookPlayerOnSpawnEquip = IHookChainClass<void, PlayerBase, bool, bool>;
using ReHookRegistryPlayerOnSpawnEquip = IHookChainClassRegistry<void, PlayerBase, bool, bool>;

// PlayerBase::Radio hook
using ReHookPlayerRadio = IHookChainClass<void, PlayerBase, const char*, const char*, short, bool>;
using ReHookRegistryPlayerRadio = IHookChainClassRegistry<void, PlayerBase, const char*, const char*, short, bool>;

// PlayerBase::Disappear hook
using ReHookPlayerDisappear = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerDisappear = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::MakeVIP hook
using ReHookPlayerMakeVip = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerMakeVip = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::MakeBomber hook
using ReHookPlayerMakeBomber = IHookChainClass<bool, PlayerBase>;
using ReHookRegistryPlayerMakeBomber = IHookChainClassRegistry<bool, PlayerBase>;

// PlayerBase::StartObserver hook
using ReHookPlayerStartObserver = IHookChainClass<void, PlayerBase, Vector&, Vector&>;
using ReHookRegistryPlayerStartObserver = IHookChainClassRegistry<void, PlayerBase, Vector&, Vector&>;

// PlayerBase::GetIntoGame hook
using ReHookPlayerGetIntoGame = IHookChainClass<bool, PlayerBase>;
using ReHookRegistryPlayerGetIntoGame = IHookChainClassRegistry<bool, PlayerBase>;

// AnimatingBase::ResetSequenceInfo hook
using ReHookAnimatingResetSequenceInfo = IHookChainClass<void, AnimatingBase>;
using ReHookRegistryAnimatingResetSequenceInfo = IHookChainClassRegistry<void, AnimatingBase>;

// GetForceCamera hook
using ReHookGetForceCamera = IHookChain<int, PlayerBase*>;
using ReHookRegistryGetForceCamera = IHookChainRegistry<int, PlayerBase*>;

// PlayerBlind hook
using ReHookPlayerBlind = IHookChain<void, PlayerBase*, EntityVars*, EntityVars*, float, float, int, Vector&>;
using ReHookRegistryPlayerBlind = IHookChainRegistry<void, PlayerBase*, EntityVars*, EntityVars*, float, float, int, Vector&>;

// RadiusFlash_TraceLine hook
using ReHookRadiusFlashTraceLine = IHookChain<void, PlayerBase*, EntityVars*, EntityVars*, Vector&, Vector&, TraceResult*>;
using ReHookRegistryRadiusFlashTraceLine = IHookChainRegistry<void, PlayerBase*, EntityVars*, EntityVars*, Vector&, Vector&, TraceResult*>;

// RoundEnd hook
using ReHookRoundEnd = IHookChain<bool, int, ScenarioEventEndRound, float>;
using ReHookRegistryRoundEnd = IHookChainRegistry<bool, int, ScenarioEventEndRound, float>;

// InstallGameRules hook
using ReHookInstallGameRules = IHookChain<GameRules*>;
using ReHookRegistryInstallGameRules = IHookChainRegistry<GameRules*>;

// PM_Init hook
using ReHookPmInit = IHookChain<void, PlayerMove*>;
using ReHookRegistryPmInit = IHookChainRegistry<void, PlayerMove*>;

// PM_Move hook
using ReHookPmMove = IHookChain<void, PlayerMove*, int>;
using ReHookRegistryPmMove = IHookChainRegistry<void, PlayerMove*, int>;

// PM_AirMove hook
using ReHookPmAirMove = IHookChain<void, int>;
using ReHookRegistryPmAirMove = IHookChainRegistry<void, int>;

// HandleMenu_ChooseAppearance hook
using ReHookHandleMenuChooseAppearance = IHookChain<void, PlayerBase*, int>;
using ReHookRegistryHandleMenuChooseAppearance = IHookChainRegistry<void, PlayerBase*, int>;

// HandleMenu_ChooseTeam hook
using ReHookHandleMenuChooseTeam = IHookChain<qboolean, PlayerBase*, ChooseTeamMenuSlot>;
using ReHookRegistryHandleMenuChooseTeam = IHookChainRegistry<qboolean, PlayerBase*, ChooseTeamMenuSlot>;

// ShowMenu hook
using ReHookShowMenu = IHookChain<void, PlayerBase*, int, int, qboolean, char*>;
using ReHookRegistryShowMenu = IHookChainRegistry<void, PlayerBase*, int, int, qboolean, char*>;

// ShowVGUIMenu hook
using ReHookShowVguiMenu = IHookChain<void, PlayerBase*, VguiMenu, int, char*>;
using ReHookRegistryShowVguiMenu = IHookChainRegistry<void, PlayerBase*, VguiMenu, int, char*>;

// BuyGunAmmo hook
using ReHookBuyGunAmmo = IHookChain<bool, PlayerBase*, PlayerItemBase*, bool>;
using ReHookRegistryBuyGunAmmo = IHookChainRegistry<bool, PlayerBase*, PlayerItemBase*, bool>;

// BuyWeaponByWeaponID hook
using ReHookBuyWeaponByWeaponId = IHookChain<EntityBase*, PlayerBase*, WeaponId>;
using ReHookRegistryBuyWeaponByWeaponId = IHookChainRegistry<EntityBase*, PlayerBase*, WeaponId>;

// InternalCommand hook
using ReHookInternalCommand = IHookChain<void, Edict*, const char*, const char*>;
using ReHookRegistryInternalCommand = IHookChainRegistry<void, Edict*, const char*, const char*>;

// CHalfLifeMultiplay::FShouldSwitchWeapon hook
using ReHookGameRulesShouldSwitchWeapon = IHookChain<qboolean, PlayerBase*, PlayerItemBase*>;
using ReHookRegistryGameRulesShouldSwitchWeapon = IHookChainRegistry<qboolean, PlayerBase*, PlayerItemBase*>;

// CHalfLifeMultiplay::GetNextBestWeapon hook
using ReHookGameRulesGetNextBestWeapon = IHookChain<qboolean, PlayerBase*, PlayerItemBase*>;
using ReHookRegistryGameRulesGetNextBestWeapon = IHookChainRegistry<qboolean, PlayerBase*, PlayerItemBase*>;

// CHalfLifeMultiplay::FlPlayerFallDamage hook
using ReHookGameRulesPlayerFallDamage = IHookChain<float, PlayerBase*>;
using ReHookRegistryGameRulesPlayerFallDamage = IHookChainRegistry<float, PlayerBase*>;

// CHalfLifeMultiplay::FPlayerCanTakeDamage hook
using ReHookGameRulesPlayerCanTakeDamage = IHookChain<qboolean, PlayerBase*, EntityBase*>;
using ReHookRegistryGameRulesPlayerCanTakeDamage = IHookChainRegistry<qboolean, PlayerBase*, EntityBase*>;

// CHalfLifeMultiplay::PlayerSpawn hook
using ReHookGameRulesPlayerSpawn = IHookChain<void, PlayerBase*>;
using ReHookRegistryGameRulesPlayerSpawn = IHookChainRegistry<void, PlayerBase*>;

// CHalfLifeMultiplay::FPlayerCanRespawn hook
using ReHookGameRulesPlayerCanRespawn = IHookChain<qboolean, PlayerBase*>;
using ReHookRegistryGameRulesPlayerCanRespawn = IHookChainRegistry<qboolean, PlayerBase*>;

// CHalfLifeMultiplay::GetPlayerSpawnSpot hook
using ReHookGameRulesGetPlayerSpawnSpot = IHookChain<Edict*, PlayerBase*>;
using ReHookRegistryGameRulesGetPlayerSpawnSpot = IHookChainRegistry<Edict*, PlayerBase*>;

// CHalfLifeMultiplay::ClientUserInfoChanged hook
using ReHookGameRulesClientUserInfoChanged = IHookChain<void, PlayerBase*, char*>;
using ReHookRegistryGameRulesClientUserInfoChanged = IHookChainRegistry<void, PlayerBase*, char*>;

// CHalfLifeMultiplay::PlayerKilled hook
using ReHookGameRulesPlayerKilled = IHookChain<void, PlayerBase*, EntityVars*, EntityVars*>;
using ReHookRegistryGameRulesPlayerKilled = IHookChainRegistry<void, PlayerBase*, EntityVars*, EntityVars*>;

// CHalfLifeMultiplay::DeathNotice hook
using ReHookGameRulesDeathNotice = IHookChain<void, PlayerBase*, EntityVars*, EntityVars*>;
using ReHookRegistryGameRulesDeathNotice = IHookChainRegistry<void, PlayerBase*, EntityVars*, EntityVars*>;

// CHalfLifeMultiplay::CanHavePlayerItem hook
using ReHookGameRulesCanHavePlayerItem = IHookChain<qboolean, PlayerBase*, PlayerItemBase*>;
using ReHookRegistryGameRulesCanHavePlayerItem = IHookChainRegistry<qboolean, PlayerBase*, PlayerItemBase*>;

// CHalfLifeMultiplay::DeadPlayerWeapons hook
using ReHookGameRulesDeadPlayerWeapons = IHookChain<int, PlayerBase*>;
using ReHookRegistryGameRulesDeadPlayerWeapons = IHookChainRegistry<int, PlayerBase*>;

// CHalfLifeMultiplay::ServerDeactivate hook
using ReHookGameRulesServerDeactivate = IHookChain<void>;
using ReHookRegistryGameRulesServerDeactivate = IHookChainRegistry<void>;

// CHalfLifeMultiplay::CheckMapConditions hook
using ReHookGameRulesCheckMapConditions = IHookChain<void>;
using ReHookRegistryGameRulesCheckMapConditions = IHookChainRegistry<void>;

// CHalfLifeMultiplay::CleanUpMap hook
using ReHookGameRulesCleanUpMap = IHookChain<void>;
using ReHookRegistryGameRulesCleanUpMap = IHookChainRegistry<void>;

// CHalfLifeMultiplay::RestartRound hook
using ReHookGameRulesRestartRound = IHookChain<void>;
using ReHookRegistryGameRulesRestartRound = IHookChainRegistry<void>;

// CHalfLifeMultiplay::CheckWinConditions hook
using ReHookGameRulesCheckWinConditions = IHookChain<void>;
using ReHookRegistryGameRulesCheckWinConditions = IHookChainRegistry<void>;

// CHalfLifeMultiplay::RemoveGuns hook
using ReHookGameRulesRemoveGuns = IHookChain<void>;
using ReHookRegistryGameRulesRemoveGuns = IHookChainRegistry<void>;

// CHalfLifeMultiplay::GiveC4 hook
using ReHookGameRulesGiveC4 = IHookChain<void>;
using ReHookRegistryGameRulesGiveC4 = IHookChainRegistry<void>;

// CHalfLifeMultiplay::ChangeLevel hook
using ReHookGameRulesChangeLevel = IHookChain<void>;
using ReHookRegistryGameRulesChangeLevel = IHookChainRegistry<void>;

// CHalfLifeMultiplay::GoToIntermission hook
using ReHookGameRulesGoToIntermission = IHookChain<void>;
using ReHookRegistryGameRulesGoToIntermission = IHookChainRegistry<void>;

// CHalfLifeMultiplay::BalanceTeams hook
using ReHookGameRulesBalanceTeams = IHookChain<void>;
using ReHookRegistryGameRulesBalanceTeams = IHookChainRegistry<void>;

// CHalfLifeMultiplay::OnRoundFreezeEnd hook
using ReHookGameRulesOnRoundFreezeEnd = IHookChain<void>;
using ReHookRegistryGameRulesOnRoundFreezeEnd = IHookChainRegistry<void>;

// GameRules::CanPlayerHearPlayer hook
using ReHookGameRulesCanPlayerHearPlayer = IHookChain<bool, PlayerBase*, PlayerBase*>;
using ReHookRegistryGameRulesCanPlayerHearPlayer = IHookChainRegistry<bool, PlayerBase*, PlayerBase*>;

// PM_UpdateStepSound hook
using ReHookPmUpdateStepSound = IHookChain<void>;
using ReHookRegistryPmUpdateStepSound = IHookChainRegistry<void>;

// PlayerBase::StartDeathCam hook
using ReHookPlayerStartDeathCam = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerStartDeathCam = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::SwitchTeam hook
using ReHookPlayerSwitchTeam = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerSwitchTeam = IHookChainClassRegistry<void, PlayerBase>;

// PlayerBase::CanSwitchTeam hook
using ReHookPlayerCanSwitchTeam = IHookChainClass<bool, PlayerBase, TeamName>;
using ReHookRegistryPlayerCanSwitchTeam = IHookChainClassRegistry<bool, PlayerBase, TeamName>;

// PlayerBase::ThrowGrenade hook
using ReHookPlayerThrowGrenade = IHookChainClass<Grenade*, PlayerBase, PlayerWeaponBase*, Vector&, Vector&, float, unsigned short>;
using ReHookRegistryPlayerThrowGrenade = IHookChainClassRegistry<Grenade*, PlayerBase, PlayerWeaponBase*, Vector&, Vector&, float, unsigned short>;

// WeaponBox::SetModel hook
using ReHookWeaponBoxSetModel = IHookChainClass<void, WeaponBox, const char*>;
using ReHookRegistryWeaponBoxSetModel = IHookChainClassRegistry<void, WeaponBox, const char*>;

// Grenade::DefuseBombStart hook
using ReHookGrenadeDefuseBombStart = IHookChainClass<void, Grenade, PlayerBase*>;
using ReHookRegistryGrenadeDefuseBombStart = IHookChainClassRegistry<void, Grenade, PlayerBase*>;

// Grenade::DefuseBombEnd hook
using ReHookGrenadeDefuseBombEnd = IHookChainClass<void, Grenade, PlayerBase*, bool>;
using ReHookRegistryGrenadeDefuseBombEnd = IHookChainClassRegistry<void, Grenade, PlayerBase*, bool>;

// Grenade::ExplodeHeGrenade hook
using ReHookGrenadeExplodeHeGrenade = IHookChainClass<void, Grenade, TraceResult*, int>;
using ReHookRegistryGrenadeExplodeHeGrenade = IHookChainClassRegistry<void, Grenade, TraceResult*, int>;

// Grenade::Explodeflash_bang hook
using ReHookGrenadeExplodeFlashBang = IHookChainClass<void, Grenade, TraceResult*, int>;
using ReHookRegistryGrenadeExplodeFlashBang = IHookChainClassRegistry<void, Grenade, TraceResult*, int>;

// Grenade::ExplodeSmokeGrenade hook
using ReHookGrenadeExplodeSmokeGrenade = IHookChainClass<void, Grenade>;
using ReHookRegistryGrenadeExplodeSmokeGrenade = IHookChainClassRegistry<void, Grenade>;

// Grenade::ExplodeBomb hook
using ReHookGrenadeExplodeBomb = IHookChainClass<void, Grenade, TraceResult*, int>;
using ReHookRegistryGrenadeExplodeBomb = IHookChainClassRegistry<void, Grenade, TraceResult*, int>;

// ThrowHeGrenade hook
using ReHookThrowHeGrenade = IHookChain<Grenade*, EntityVars*, Vector&, Vector&, float, int, unsigned short>;
using ReHookRegistryThrowHeGrenade = IHookChainRegistry<Grenade*, EntityVars*, Vector&, Vector&, float, int, unsigned short>;

// Throw_flash_bang hook
using ReHookThrowFlashBang = IHookChain<Grenade*, EntityVars*, Vector&, Vector&, float>;
using ReHookRegistryThrowFlashBang = IHookChainRegistry<Grenade*, EntityVars*, Vector&, Vector&, float>;

// ThrowSmokeGrenade hook
using ReHookThrowSmokeGrenade = IHookChain<Grenade*, EntityVars*, Vector&, Vector&, float, unsigned short>;
using ReHookRegistryThrowSmokeGrenade = IHookChainRegistry<Grenade*, EntityVars*, Vector&, Vector&, float, unsigned short>;

// PlantBomb hook
using ReHookPlantBomb = IHookChain<Grenade*, EntityVars*, Vector&, Vector&>;
using ReHookRegistryPlantBomb = IHookChainRegistry<Grenade*, EntityVars*, Vector&, Vector&>;

// PlayerBase::SetSpawnProtection hook
using ReHookPlayerSetSpawnProtection = IHookChainClass<void, PlayerBase, float>;
using ReHookRegistryPlayerSetSpawnProtection = IHookChainClassRegistry<void, PlayerBase, float>;

// PlayerBase::RemoveSpawnProtection hook
using ReHookPlayerRemoveSpawnProtection = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerRemoveSpawnProtection = IHookChainClassRegistry<void, PlayerBase>;

// IsPenetrableEntity hook
using ReHookIsPenetrableEntity = IHookChain<bool, Vector&, Vector&, EntityVars*, Edict*>;
using ReHookRegistryIsPenetrableEntity = IHookChainRegistry<bool, Vector&, Vector&, EntityVars*, Edict*>;

// PlayerBase::HintMessageEx hook
using ReHookPlayerHintMessageEx = IHookChainClass<bool, PlayerBase, const char*, float, bool, bool>;
using ReHookRegistryPlayerHintMessageEx = IHookChainClassRegistry<bool, PlayerBase, const char*, float, bool, bool>;

// PlayerBase::UseEmpty hook
using ReHookPlayerUseEmpty = IHookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerUseEmpty = IHookChainClassRegistry<void, PlayerBase>;

// player_baseWeapon::CanDeploy hook
using ReHookPlayerWeaponCanDeploy = IHookChainClass<qboolean, PlayerWeaponBase>;
using ReHookRegistryPlayerWeaponCanDeploy = IHookChainClassRegistry<qboolean, PlayerWeaponBase>;

// player_baseWeapon::DefaultDeploy hook
using ReHookPlayerWeaponDefaultDeploy = IHookChainClass<qboolean, PlayerWeaponBase, char*, char*, int, char*, int>;
using ReHookRegistryPlayerWeaponDefaultDeploy = IHookChainClassRegistry<qboolean, PlayerWeaponBase, char*, char*, int, char*, int>;

// player_baseWeapon::DefaultReload hook
using ReHookPlayerWeaponDefaultReload = IHookChainClass<int, PlayerWeaponBase, int, int, float>;
using ReHookRegistryPlayerWeaponDefaultReload = IHookChainClassRegistry<int, PlayerWeaponBase, int, int, float>;

// player_baseWeapon::DefaultShotgunReload hook
using ReHookPlayerWeaponDefaultShotgunReload = IHookChainClass<bool, PlayerWeaponBase, int, int, float, float, const char*, const char*>;
using ReHookRegistryPlayerWeaponDefaultShotgunReload = IHookChainClassRegistry<bool, PlayerWeaponBase, int, int, float, float, const char*, const char*>;

// PlayerBase::DropIdlePlayer hook
using ReHookPlayerDropIdlePlayer = IHookChainClass<void, PlayerBase, const char*>;
using ReHookRegistryPlayerDropIdlePlayer = IHookChainClassRegistry<void, PlayerBase, const char*>;

// CreateWeaponBox hook
using ReHookCreateWeaponBox = IHookChain<WeaponBox*, PlayerItemBase*, PlayerBase*, const char*, Vector&, Vector&, Vector&, float, bool>;
using ReHookRegistryCreateWeaponBox = IHookChainRegistry<WeaponBox*, PlayerItemBase*, PlayerBase*, const char*, Vector&, Vector&, Vector&, float, bool>;

// SpawnHeadGib hook
using ReHookSpawnHeadGib = IHookChain<Gib, EntityVars*>;
using ReHookRegistrySpawnHeadGib = IHookChainRegistry<Gib, EntityVars*>;

// SpawnRandomGibs hook
using ReHookSpawnRandomGibs = IHookChain<void, EntityVars*, int, int>;
using ReHookRegistrySpawnRandomGibs = IHookChainRegistry<void, EntityVars*, int, int>;

// Gib::Spawn hook
using ReHookGibSpawn = IHookChainClass<void, Gib, const char*>;
using ReHookRegistryGibSpawn = IHookChainClassRegistry<void, Gib, const char*>;

// Gib::BounceGibTouch hook
using ReHookGibBounceGibTouch = IHookChainClass<void, Gib, EntityBase*>;
using ReHookRegistryGibBounceGibTouch = IHookChainClassRegistry<void, Gib, EntityBase*>;

// Gib::WaitTillLand hook
using ReHookGibWaitTillLand = IHookChainClass<void, Gib>;
using ReHookRegistryGibWaitTillLand = IHookChainClassRegistry<void, Gib>;

/// <summary>
/// Class RegamedllHookChains.
/// </summary>
class RegamedllHookChains {
public:
	/// <summary>
	/// </summary>
	virtual ~RegamedllHookChains() = default;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSpawn* player_spawn() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerPrecache* player_precache() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerObjectCaps* player_object_caps() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerClassify* player_classify() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerTraceAttack* player_trace_attack() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerTakeDamage* player_take_damage() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerTakeHealth* player_take_health() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerKilled* player_killed() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerAddPoints* player_add_points() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerAddPointsToTeam* player_add_points_to_team() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerAddPlayerItem* player_add_player_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerRemovePlayerItem* player_remove_player_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerGiveAmmo* player_give_ammo() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerResetMaxSpeed* player_reset_max_speed() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerJump* player_jump() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerDuck* player_duck() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerPreThink* player_pre_think() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerPostThink* player_post_think() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerUpdateClientData* player_update_client_data() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerImpulseCommands* player_impulse_commands() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerRoundRespawn* player_round_respawn() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerBaseBlind* player_base_blind() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerObserverIsValidTarget* player_observer_is_valid_target() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSetAnimation* player_set_animation() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerGiveDefaultItems* player_give_default_items() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerGiveNamedItem* player_give_named_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerAddAccount* player_add_account() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerGiveShield* player_give_shield() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSetClientUserInfoModel* player_set_client_user_info_model() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSetClientUserInfoName* player_set_client_user_info_name() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerHasRestrictItem* player_has_restrict_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerDropPlayerItem* player_drop_player_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerDropShield* player_drop_shield() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerOnSpawnEquip* player_on_spawn_equip() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerRadio* player_radio() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerDisappear* player_disappear() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerMakeVip* player_make_vip() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerMakeBomber* player_make_bomber() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerStartObserver* player_start_observer() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerGetIntoGame* player_get_into_game() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryAnimatingResetSequenceInfo* animating_reset_sequence_info() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGetForceCamera* get_force_camera() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerBlind* player_blind() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryRadiusFlashTraceLine* radius_flash_trace_line() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryRoundEnd* round_end() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryInstallGameRules* install_game_rules() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPmInit* pm_init() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPmMove* pm_move() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPmAirMove* pm_air_move() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryHandleMenuChooseAppearance* handle_menu_choose_appearance() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryHandleMenuChooseTeam* handle_menu_choose_team() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryShowMenu* show_menu() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryShowVguiMenu* show_vgui_menu() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryBuyGunAmmo* buy_gun_ammo() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryBuyWeaponByWeaponId* buy_weapon_by_weapon_id() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryInternalCommand* internal_command() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesShouldSwitchWeapon* game_rules_should_switch_weapon() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesGetNextBestWeapon* game_rules_get_next_best_weapon() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesPlayerFallDamage* game_rules_player_fall_damage() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesPlayerCanTakeDamage* game_rules_player_can_take_damage() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesPlayerSpawn* game_rules_player_spawn() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesPlayerCanRespawn* game_rules_player_can_respawn() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesGetPlayerSpawnSpot* game_rules_get_player_spawn_spot() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesClientUserInfoChanged* game_rules_client_user_info_changed() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesPlayerKilled* game_rules_player_killed() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesDeathNotice* game_rules_death_notice() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesCanHavePlayerItem* game_rules_can_have_player_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesDeadPlayerWeapons* game_rules_dead_player_weapons() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesServerDeactivate* game_rules_server_deactivate() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesCheckMapConditions* game_rules_check_map_conditions() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesCleanUpMap* game_rules_clean_up_map() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesRestartRound* game_rules_restart_round() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesCheckWinConditions* game_rules_check_win_conditions() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesRemoveGuns* game_rules_remove_guns() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesGiveC4* game_rules_give_c4() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesChangeLevel* game_rules_change_level() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesGoToIntermission* game_rules_go_to_intermission() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesBalanceTeams* game_rules_balance_teams() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesOnRoundFreezeEnd* game_rules_on_round_freeze_end() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPmUpdateStepSound* pm_update_step_sound() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerStartDeathCam* player_start_death_cam() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSwitchTeam* player_switch_team() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerCanSwitchTeam* player_can_switch_team() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerThrowGrenade* player_throw_grenade() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesCanPlayerHearPlayer* game_rules_can_player_hear_player() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryWeaponBoxSetModel* weapon_box_set_model() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeDefuseBombStart* grenade_defuse_bomb_start() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeDefuseBombEnd* grenade_defuse_bomb_end() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeExplodeHeGrenade* grenade_explode_he_grenade() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeExplodeFlashBang* grenade_explode_flash_bang() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeExplodeSmokeGrenade* grenade_explode_smoke_grenade() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeExplodeBomb* grenade_explode_bomb() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryThrowHeGrenade* throw_he_grenade() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryThrowFlashBang* throw_flash_bang() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryThrowSmokeGrenade* throw_smoke_grenade() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlantBomb* plant_bomb() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerRemoveSpawnProtection* player_remove_spawn_protection() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSetSpawnProtection* player_set_spawn_protection() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryIsPenetrableEntity* is_penetrable_entity() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerHintMessageEx* player_hint_message_ex() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerUseEmpty* player_use_empty() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerWeaponCanDeploy* player_base_weapon_can_deploy() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerWeaponDefaultDeploy* player_base_weapon_default_deploy() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerWeaponDefaultReload* player_base_weapon_default_reload() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerWeaponDefaultShotgunReload* player_base_weapon_default_shotgun_reload() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerDropIdlePlayer* player_drop_idle_player() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryCreateWeaponBox* create_weapon_box() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySpawnHeadGib* spawn_head_gib() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistrySpawnRandomGibs* spawn_random_gibs() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGibSpawn* gib_spawn() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGibBounceGibTouch* gib_bounce_gib_touch() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGibWaitTillLand* gib_wait_till_land() = 0;
};

/// <summary>
/// </summary>
struct RegamedllFuncs {
	/// <summary>
	/// </summary>
	Edict* (*create_named_entity2)(Strind class_name){}; //-V591

	/// <summary>
	/// </summary>
	void (*change_string)(char*& dest, const char* source){}; //-V591

	/// <summary>
	/// </summary>
	void (*radius_damage)(Vector src, EntityVars* inflictor, EntityVars* attacker, float damage, float radius, int class_ignore, int damage_type){}; //-V591

	/// <summary>
	/// </summary>
	void (*clear_multi_damage)(){};

	/// <summary>
	/// </summary>
	void (*apply_multi_damage)(EntityVars* inflictor, EntityVars* attacker){}; //-V591

	/// <summary>
	/// </summary>
	void (*add_multi_damage)(EntityVars* inflictor, EntityBase* entity, float damage, int damage_type){}; //-V591

	/// <summary>
	/// </summary>
	EntityBase* (*find_entity_by_string)(EntityBase* start_entity, const char* keyword, const char* value){}; //-V591

	/// <summary>
	/// </summary>
	void (*add_entity_hash_value)(EntityVars* ent_vars, const char* value, HashType field_type){}; //-V591

	/// <summary>
	/// </summary>
	void (*remove_entity_hash_value)(EntityVars* ent_vars, const char* value, HashType field_type){}; //-V591

	/// <summary>
	/// </summary>
	int (*cmd_argc)(){};

	/// <summary>
	/// </summary>
	const char* (*cmd_argv)(int i){}; //-V591
};

/// <summary>
/// Class RegamedllApiInterface.
/// </summary>
class RegamedllApiInterface {
public:
	/// <summary>
	/// </summary>
	virtual ~RegamedllApiInterface() = default;

	/// <summary>
	/// </summary>
	virtual int get_major_version() = 0;

	/// <summary>
	/// </summary>
	virtual int get_minor_version() = 0;

	/// <summary>
	/// </summary>
	virtual const RegamedllFuncs* get_funcs() = 0;

	/// <summary>
	/// </summary>
	virtual RegamedllHookChains* get_hook_chains() = 0;

	/// <summary>
	/// </summary>
	virtual GameRules* get_game_rules() = 0;

	/// <summary>
	/// </summary>
	virtual WeaponInfoStruct* get_weapon_info(WeaponId weapon) = 0;

	/// <summary>
	/// </summary>
	virtual WeaponInfoStruct* get_weapon_info(const char* weapon) = 0;

	/// <summary>
	/// </summary>
	virtual PlayerMove* get_player_move() = 0;

	/// <summary>
	/// </summary>
	virtual WeaponSlotInfo* get_weapon_slot(WeaponId weapon) = 0;

	/// <summary>
	/// </summary>
	virtual WeaponSlotInfo* get_weapon_slot(const char* weapon) = 0;

	/// <summary>
	/// </summary>
	virtual ItemInfo* get_item_info(WeaponId weapon) = 0;

	/// <summary>
	/// </summary>
	virtual AmmoInfo* get_ammo_info(AmmoType ammo) = 0;

	/// <summary>
	/// </summary>
	virtual AmmoInfoStruct* get_ammo_info_ex(AmmoType ammo) = 0;

	/// <summary>
	/// </summary>
	virtual AmmoInfoStruct* get_ammo_info_ex(const char* ammo) = 0;

	/// <summary>
	/// </summary>
	virtual bool check_cs_entity_version(const char* version) const = 0;

	/// <summary>
	/// </summary>
	virtual bool check_game_rules_version(const char* version) const = 0;
};
