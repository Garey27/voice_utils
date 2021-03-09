// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 05-25-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/engine/global_vars.h>
#include <cstring>

//-V::122

/// <summary>
/// <para>String index.</para>
/// </summary>
class Strind final {
public:
	/// <summary>
	/// </summary>
	Strind() = default;

	/// <summary>
	/// </summary>
	~Strind() = default;

	/// <summary>
	/// </summary>
	Strind(Strind&&) = default;

	/// <summary>
	/// </summary>
	Strind(const Strind&) = default;

	/// <summary>
	/// </summary>
	explicit Strind(std::size_t index);

	/// <summary>
	/// </summary>
	[[nodiscard]] const char* c_str() const;

	/// <summary>
	/// </summary>
	[[nodiscard]] auto index() const noexcept;

	/// <summary>
	/// </summary>
	[[nodiscard]] bool is_null_or_empty() const;

	/// <summary>
	/// </summary>
	char operator[](std::size_t index) const;

	/// <summary>
	/// </summary>
	Strind& operator=(Strind&& rhs) = default;

	/// <summary>
	/// </summary>
	Strind& operator=(const Strind& rhs) = default;

	/// <summary>
	/// </summary>
	bool operator==(const Strind& strind) const noexcept;

	/// <summary>
	/// </summary>
	bool operator!=(const Strind& strind) const noexcept;

	/// <summary>
	/// </summary>
	bool operator==(const char* string) const;

	/// <summary>
	/// </summary>
	bool operator!=(const char* string) const;

	/// <summary>
	/// </summary>
	bool operator==(std::size_t index) const noexcept;

	/// <summary>
	/// </summary>
	bool operator!=(std::size_t index) const noexcept;

private:
	/// <summary>
	/// </summary>
	std::size_t string_index_ = 0;
};

inline Strind::Strind(const std::size_t index)
	: string_index_(index)
{
}

inline const char* Strind::c_str() const
{
	return &g_global_vars->string_base[string_index_];
}

inline auto Strind::index() const noexcept
{
	return string_index_;
}

inline bool Strind::is_null_or_empty() const
{
	return !string_index_ || (&g_global_vars->string_base[string_index_])[0] == '\0';
}

inline char Strind::operator[](const std::size_t index) const
{
	return (&g_global_vars->string_base[string_index_])[index];
}

inline bool Strind::operator==(const Strind& strind) const noexcept
{
	return string_index_ == strind.string_index_;
}

inline bool Strind::operator!=(const Strind& strind) const noexcept
{
	return string_index_ != strind.string_index_;
}

inline bool Strind::operator==(const char* string) const
{
	return std::strcmp(c_str(), string) == 0;
}

inline bool Strind::operator!=(const char* string) const
{
	return !operator==(string);
}

inline bool Strind::operator==(const std::size_t index) const noexcept
{
	return string_index_ == index;
}

inline bool Strind::operator!=(const std::size_t index) const noexcept
{
	return string_index_ != index;
}
