// ***********************************************************************
// Created          : 08-13-2020
//
// Last Modified By : the_hunter
// Last Modified On : 08-13-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/public/vector.h>

//-V::112

/// <summary>
/// </summary>
constexpr auto MAX_STUDIO_TRIANGLES = 20000;

/// <summary>
/// </summary>
constexpr auto MAX_STUDIO_VERTS = 2048;

/// <summary>
/// <para>Total animation sequences -- KSH incremented.</para>
/// </summary>
constexpr auto MAX_STUDIO_SEQUENCES = 2048;

/// <summary>
/// <para>Total textures.</para>
/// </summary>
constexpr auto MAX_STUDIO_SKINS = 100;

/// <summary>
/// <para>Bones allowed at source movement.</para>
/// </summary>
constexpr auto MAX_STUDIO_SRC_BONES = 512;

/// <summary>
/// <para>Total bones actually used.</para>
/// </summary>
constexpr auto MAX_STUDIO_BONES = 128;

/// <summary>
/// <para>Sub-models per model.</para>
/// </summary>
constexpr auto MAX_STUDIO_MODELS = 32;

/// <summary>
/// </summary>
constexpr auto MAX_STUDIO_BODY_PARTS = 32;

/// <summary>
/// </summary>
constexpr auto MAX_STUDIO_GROUPS = 16;

/// <summary>
/// </summary>
constexpr auto MAX_STUDIO_ANIMATIONS = 2048;

/// <summary>
/// </summary>
constexpr auto MAX_STUDIO_MESHES = 256;

/// <summary>
/// </summary>
constexpr auto MAX_STUDIO_EVENTS = 1024;

/// <summary>
/// </summary>
constexpr auto MAX_STUDIO_PIVOTS = 256;

/// <summary>
/// </summary>
constexpr auto MAX_STUDIO_CONTROLLERS = 8;

//
// Lighting options.
//

/// <summary>
/// </summary>
constexpr auto STUDIO_NF_FLAT_SHADE = 0x0001;

/// <summary>
/// </summary>
constexpr auto STUDIO_NF_CHROME = 0x0002;

/// <summary>
/// </summary>
constexpr auto STUDIO_NF_FULL_BRIGHT = 0x0004;

/// <summary>
/// </summary>
constexpr auto STUDIO_NF_NO_MIPS = 0x0008;

/// <summary>
/// </summary>
constexpr auto STUDIO_NF_ALPHA = 0x0010;

/// <summary>
/// </summary>
constexpr auto STUDIO_NF_ADDITIVE = 0x0020;

/// <summary>
/// </summary>
constexpr auto STUDIO_NF_MASKED = 0x0040;

//
// Motion flags.
//

/// <summary>
/// </summary>
constexpr auto STUDIO_X = 0x0001;

/// <summary>
/// </summary>
constexpr auto STUDIO_Y = 0x0002;

/// <summary>
/// </summary>
constexpr auto STUDIO_Z = 0x0004;

/// <summary>
/// </summary>
constexpr auto STUDIO_XR = 0x0008;

/// <summary>
/// </summary>
constexpr auto STUDIO_YR = 0x0010;

/// <summary>
/// </summary>
constexpr auto STUDIO_ZR = 0x0020;

/// <summary>
/// </summary>
constexpr auto STUDIO_LX = 0x0040;

/// <summary>
/// </summary>
constexpr auto STUDIO_LY = 0x0080;

/// <summary>
/// </summary>
constexpr auto STUDIO_LZ = 0x0100;

/// <summary>
/// </summary>
constexpr auto STUDIO_AX = 0x0200;

/// <summary>
/// </summary>
constexpr auto STUDIO_AY = 0x0400;

/// <summary>
/// </summary>
constexpr auto STUDIO_AZ = 0x0800;

/// <summary>
/// </summary>
constexpr auto STUDIO_AXR = 0x1000;

/// <summary>
/// </summary>
constexpr auto STUDIO_AYR = 0x2000;

/// <summary>
/// </summary>
constexpr auto STUDIO_AZR = 0x4000;

/// <summary>
/// </summary>
constexpr auto STUDIO_TYPES = 0x7FFF;

/// <summary>
/// <para>Controller that wraps shortest distance.</para>
/// </summary>
constexpr auto STUDIO_RLOOP = 0x8000;

//
// Sequence flags.
// 

constexpr auto STUDIO_LOOPING = 0x0001;

//
// Bone flags.
// 

/// <summary>
/// </summary>
constexpr auto STUDIO_HAS_NORMALS = 0x0001;

/// <summary>
/// </summary>
constexpr auto STUDIO_HAS_VERTICES = 0x0002;

/// <summary>
/// </summary>
constexpr auto STUDIO_HAS_BBOX = 0x0004;

/// <summary>
/// <para>If any of the textures have chrome on them.</para>
/// </summary>
constexpr auto STUDIO_HAS_CHROME = 0x0008;

/// <summary>
/// </summary>
struct StudioHdr {
	/// <summary>
	/// </summary>
	int id{};

	/// <summary>
	/// </summary>
	int version{};

	/// <summary>
	/// </summary>
	char name[64]{};

	/// <summary>
	/// </summary>
	int length{};

	/// <summary>
	/// <para>Ideal eye position.</para>
	/// </summary>
	Vector eye_position{};

	/// <summary>
	/// <para>Ideal movement hull size.</para>
	/// </summary>
	Vector min{};

	/// <summary>
	/// </summary>
	Vector max{};

	/// <summary>
	/// <para>Clipping bounding box.</para>
	/// </summary>
	Vector bb_min{};

	/// <summary>
	/// </summary>
	Vector bb_max{};

	/// <summary>
	/// </summary>
	int flags{};

	/// <summary>
	/// </summary>
	int num_bones{};

	/// <summary>
	/// </summary>
	int bone_index{};

	/// <summary>
	/// </summary>
	int num_bone_controllers{};

	/// <summary>
	/// </summary>
	int bone_controller_index{};

	/// <summary>
	/// <para>Complex bounding boxes.</para>
	/// </summary>
	int num_hitboxes{};

	/// <summary>
	/// </summary>
	int hitbox_index{};

	/// <summary>
	/// <para>Animation sequences.</para>
	/// </summary>
	int num_seq{};

	/// <summary>
	/// </summary>
	int seq_index{};

	/// <summary>
	/// <para>Demand loaded sequences.</para>
	/// </summary>
	int num_seq_groups{};

	/// <summary>
	/// </summary>
	int seq_group_index{};

	/// <summary>
	/// <para>Raw textures.</para>
	/// </summary>
	int num_textures{};

	/// <summary>
	/// </summary>
	int texture_index{};

	/// <summary>
	/// </summary>
	int texture_data_index{};

	/// <summary>
	/// <para>Replaceable textures.</para>
	/// </summary>
	int num_skin_ref{};

	/// <summary>
	/// </summary>
	int num_skin_families{};

	/// <summary>
	/// </summary>
	int skin_index{};

	/// <summary>
	/// </summary>
	int num_bodyparts{};

	/// <summary>
	/// </summary>
	int bodypart_index{};

	/// <summary>
	/// <para>Queryable attachable points.</para>
	/// </summary>
	int num_attachments{};

	/// <summary>
	/// </summary>
	int attachment_index{};

	/// <summary>
	/// </summary>
	int sound_table{};

	/// <summary>
	/// </summary>
	int sound_index{};

	/// <summary>
	/// </summary>
	int sound_groups{};

	/// <summary>
	/// </summary>
	int sound_group_index{};

	/// <summary>
	/// <para>Animation node to animation node transition graph.</para>
	/// </summary>
	int num_transitions{};

	/// <summary>
	/// </summary>
	int transition_index{};
};

/// <summary>
/// </summary>
struct StudioSeqDesc {

	/// <summary>
	/// <para>Sequence label.</para>
	/// </summary>
	char label[32]{};

	/// <summary>
	/// <para>Frames per second.</para>
	/// </summary>
	float fps{};

	/// <summary>
	/// <para>Looping/non-looping flags.</para>
	/// </summary>
	int flags{};

	/// <summary>
	/// </summary>
	int activity{};

	/// <summary>
	/// </summary>
	int act_weight{};

	/// <summary>
	/// </summary>
	int num_events{};

	/// <summary>
	/// </summary>
	int event_index{};

	/// <summary>
	/// <para>Number of frames per sequence.</para>
	/// </summary>
	int num_frames{};

	/// <summary>
	/// <para>Number of foot pivots.</para>
	/// </summary>
	int num_pivots{};

	/// <summary>
	/// </summary>
	int pivot_index{};

	/// <summary>
	/// </summary>
	int motion_type{};

	/// <summary>
	/// </summary>
	int motion_bone{};

	/// <summary>
	/// </summary>
	Vector linear_movement{};

	/// <summary>
	/// </summary>
	int auto_move_pos_index{};

	/// <summary>
	/// </summary>
	int auto_move_angle_index{};

	/// <summary>
	/// <para>Per sequence bounding box.</para>
	/// </summary>
	Vector bb_min{};

	/// <summary>
	/// </summary>
	Vector bb_max{};

	/// <summary>
	/// </summary>
	int num_blends{};

	/// <summary>
	/// <para><c>StudioAnim</c> pointer relative to start of sequence group data<br/>
	/// [blend][bone][X, Y, Z, XR, YR, ZR].</para>
	/// </summary>
	int anim_index{};

	/// <summary>
	/// <para>X, Y, Z, XR, YR, ZR.</para>
	/// </summary>
	int blend_type[2]{};

	/// <summary>
	/// <para>Starting value.</para>
	/// </summary>
	float blend_start[2]{};

	/// <summary>
	/// <para>Ending value.</para>
	/// </summary>
	float blend_end[2]{};

	/// <summary>
	/// </summary>
	int blend_parent{};

	/// <summary>
	/// <para>Sequence group for demand loading.</para>
	/// </summary>
	int seq_group{};

	/// <summary>
	/// <para>Transition node at entry.</para>
	/// </summary>
	int entry_node{};

	/// <summary>
	/// <para>Transition node at exit.</para>
	/// </summary>
	int exit_node{};

	/// <summary>
	/// <para>Transition rules.</para>
	/// </summary>
	int node_flags{};

	/// <summary>
	/// <para>Auto advancing sequences.</para>
	/// </summary>
	int next_seq{};
};

/// <summary>
/// </summary>
struct StudioEvent {
	/// <summary>
	/// </summary>
	int frame{};

	/// <summary>
	/// </summary>
	int event{};

	/// <summary>
	/// </summary>
	int type{};

	/// <summary>
	/// </summary>
	char options[64]{};
};
