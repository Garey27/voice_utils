// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <amxx/string.h>
#include <cstring>

//-V::112

namespace amx
{
	/// <summary>
	/// </summary>
	static char* init(const cell* const address, const std::size_t max_length)
	{
		auto* const string = new char[max_length + 1];
		std::size_t i = 0;

		for (; i < max_length && address[i]; ++i) {
			string[i] = static_cast<char>(address[i]);
		}

		string[i] = '\0';

		return string;
	}

	/// <summary>
	/// </summary>
	static std::size_t check_valid_char(const char* c) // Stolen from AMXX Mod X
	{
		std::size_t count = 1;
		std::size_t byte_count = 0;

		for (; (*c & 0xC0) == 0x80; count++) {
			c--;
		}

		switch (*c & 0xF0) {
		case 0xC0:
		case 0xD0:
			byte_count = 2;
			break;

		case 0xE0:
			byte_count = 3;
			break;

		case 0xF0:
			byte_count = 4;
			break;

		default:
			byte_count = 1;
			break;
		}

		if (byte_count != count) {
			return count;
		}

		return 0;
	}

	/// <summary>
	/// </summary>
	String::String(cell* address, const std::size_t max_length)
		: address_(address), max_length_(max_length), c_str_(nullptr)
	{
		c_str_ = init(address_, max_length_);
	}

	/// <summary>
	/// </summary>
	String::String(const Amx* amx, const ucell address, const std::size_t max_length)
		: address_(amx_address(amx, address)), max_length_(max_length), c_str_(nullptr)
	{
		c_str_ = init(address_, max_length_);
	}

	/// <summary>
	/// </summary>
	String::String(String&& rhs) noexcept
		: address_(rhs.address_), max_length_(rhs.max_length_), c_str_(rhs.c_str_)
	{
		rhs.max_length_ = 0;
		rhs.address_ = nullptr;
		rhs.c_str_ = nullptr;
	}

	/// <summary>
	/// </summary>
	String::String(const String& rhs)
		: address_(rhs.address_), max_length_(rhs.max_length_), c_str_(nullptr)
	{
		c_str_ = new char[max_length_ + 1];
		std::memcpy(static_cast<void*>(c_str_), rhs.c_str_, (max_length_ + 1) * sizeof(char));
	}

#ifdef __INTEL_COMPILER
#pragma warning(push)
#pragma warning(disable: 2017)
#endif

	/// <summary>
	/// </summary>
	String::~String()
	{
		delete[] c_str_;
	}

#ifdef __INTEL_COMPILER
#pragma warning(pop)
#endif

	/// <summary>
	/// </summary>
	std::size_t String::length() const
	{
		return c_str_ ? std::strlen(c_str_) : 0;
	}

	/// <summary>
	/// </summary>
	char String::operator[](const std::size_t index) const
	{
		return c_str_ ? c_str_[index] : '\0';
	}

	/// <summary>
	/// </summary>
	String& String::operator=(String&& rhs) noexcept
	{
		if (&rhs != this) {
			delete[] c_str_;

			max_length_ = rhs.max_length_;
			address_ = rhs.address_;
			c_str_ = rhs.c_str_;

			rhs.max_length_ = 0;
			rhs.address_ = nullptr;
			rhs.c_str_ = nullptr;
		}

		return *this;
	}

	/// <summary>
	/// </summary>
	String& String::operator=(const String& rhs)
	{
		if (&rhs != this) {
			delete[] c_str_;

			max_length_ = rhs.max_length_;
			address_ = rhs.address_;

			c_str_ = new char[max_length_ + 1];
			std::memcpy(static_cast<void*>(c_str_), rhs.c_str_, (max_length_ + 1) * sizeof(char));
		}

		return *this;
	}

	/// <summary>
	/// </summary>
	String& String::operator=(const char* rhs)
	{
		if (c_str_ && rhs) {
			auto c = *rhs;
			std::size_t i = 0;

			while (i < max_length_ && c) {
				address_[i] = static_cast<unsigned char>(c_str_[i] = c);
				c = rhs[++i];
			}

			i -= check_valid_char(&c_str_[i - 1]);
			address_[i] = c_str_[i] = '\0'; // NOLINT(bugprone-signed-char-misuse)
		}

		return *this;
	}

	/// <summary>
	/// </summary>
	bool String::operator==(const char* rhs) const
	{
		return c_str_ ? std::strcmp(c_str_, rhs) == 0 : false;
	}

	/// <summary>
	/// </summary>
	bool String::operator==(const String& rhs) const
	{
		return c_str_ ? std::strcmp(c_str_, rhs.c_str_) == 0 : false;
	}

	/// <summary>
	/// </summary>
	bool String::operator!=(const char* rhs) const
	{
		return !(*this == rhs);
	}

	/// <summary>
	/// </summary>
	bool String::operator!=(const String& rhs) const
	{
		return !(*this == rhs);
	}
}
