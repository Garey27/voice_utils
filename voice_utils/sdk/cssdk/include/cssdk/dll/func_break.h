// ***********************************************************************
// Created          : 07-28-2020
//
// Last Modified By : the_hunter
// Last Modified On : 07-28-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/entity_base.h>

/// <summary>
/// <para>This many shards spawned when breakable objects break.</para>
/// </summary>
constexpr auto NUM_SHARDS = 6;

/// <summary>
/// <para>May only be broken by trigger.</para>
/// </summary>
constexpr auto SF_BREAK_TRIGGER_ONLY = 1 << 0;

/// <summary>
/// <para>Can be 'crashed through' by running player (plate glass).</para>
/// </summary>
constexpr auto SF_BREAK_TOUCH = 1 << 1;

/// <summary>
/// <para>Can be broken by a player standing on it.</para>
/// </summary>
constexpr auto SF_BREAK_PRESSURE = 1 << 2;

/// <summary>
/// <para>func_pushable (it's also func_breakable, so don't collide with those flags).</para>
/// </summary>
constexpr auto SF_PUSH_BREAKABLE = 1 << 7;

/// <summary>
/// <para>Instant break if hit with crowbar.</para>
/// </summary>
constexpr auto SF_BREAK_CROWBAR = 1 << 8;

/// <summary>
/// </summary>
enum class Explosions {
	/// <summary>
	/// </summary>
	Random = 0,

	/// <summary>
	/// </summary>
	Directed
};

/// <summary>
/// </summary>
enum class Materials {
	/// <summary>
	/// </summary>
	Glass = 0,

	/// <summary>
	/// </summary>
	Wood,

	/// <summary>
	/// </summary>
	Metal,

	/// <summary>
	/// </summary>
	Flesh,

	/// <summary>
	/// </summary>
	CinderBlock,

	/// <summary>
	/// </summary>
	CeilingTile,

	/// <summary>
	/// </summary>
	Computer,

	/// <summary>
	/// </summary>
	UnbreakableGlass,

	/// <summary>
	/// </summary>
	Rocks,

	/// <summary>
	/// </summary>
	None
};

/// <summary>
/// Class Breakable.
/// </summary>
class Breakable : public DelayBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	void restart() override = 0;

	/// <summary>
	/// </summary>
	void key_value(KeyValueData* data) override = 0;

	/// <summary>
	/// </summary>
	qboolean save(Save& save) override = 0;

	/// <summary>
	/// </summary>
	qboolean restore(Restore& restore) override = 0;

	/// <summary>
	/// </summary>
	int object_caps() override = 0;

	/// <summary>
	/// <para>To spark when hit.</para>
	/// </summary>
	void trace_attack(EntityVars* attacker, float damage, Vector direction, TraceResult* result, int damage_type) override = 0;

	/// <summary>
	/// <para>Breakables use an overridden take damage.</para>
	/// </summary>
	qboolean take_damage(EntityVars* inflictor, EntityVars* attacker, float damage, int damage_type) override = 0;

	/// <summary>
	/// </summary>
	Decal damage_decal(int damage_type) override = 0;

	/// <summary>
	/// </summary>
	void use(EntityBase* activator, EntityBase* caller, UseType type, float value) override = 0;

	/// <summary>
	/// </summary>
	Materials material;

	/// <summary>
	/// </summary>
	Explosions explosion;

	/// <summary>
	/// </summary>
	int id_shard;

	/// <summary>
	/// </summary>
	float angle;

	/// <summary>
	/// </summary>
	int gib_model;

	/// <summary>
	/// </summary>
	int spawn_object;

	/// <summary>
	/// </summary>
	float health;
};

/// <summary>
/// Class Pushable.
/// </summary>
class Pushable : public Breakable {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	void key_value(KeyValueData* data) override = 0;

	/// <summary>
	/// </summary>
	qboolean save(Save& save) override = 0;

	/// <summary>
	/// </summary>
	qboolean restore(Restore& restore) override = 0;

	/// <summary>
	/// </summary>
	int object_caps() override = 0;

	/// <summary>
	/// </summary>
	qboolean take_damage(EntityVars* inflictor, EntityVars* attacker, float damage, int damage_type) override = 0;

	/// <summary>
	/// </summary>
	void touch(EntityBase* other) override = 0;

	/// <summary>
	/// </summary>
	void use(EntityBase* activator, EntityBase* caller, UseType type, float value) override = 0;

#ifdef REGAMEDLL_FIXES
	/// <summary>
	/// </summary>
	void restart() override = 0;
#endif

	/// <summary>
	/// </summary>
	int last_sound;

	/// <summary>
	/// </summary>
	float max_speed;

	/// <summary>
	/// </summary>
	float sound_time;
};
