// ***********************************************************************
// Created          : 06-02-2020
//
// Last Modified By : the_hunter
// Last Modified On : 06-02-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/entity_base.h>

/// <summary>
/// Class Gib.
/// </summary>
class Gib : public EntityBase {
public:
	/// <summary>
	/// </summary>
	int object_caps() override = 0;

	/// <summary>
	/// </summary>
	int blood_color{};

	/// <summary>
	/// </summary>
	int blood_decals{};

	/// <summary>
	/// </summary>
	int material{};

	/// <summary>
	/// </summary>
	float life_time{};
};
