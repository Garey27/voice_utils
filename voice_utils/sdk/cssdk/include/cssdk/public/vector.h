// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/public/base_types.h>
#include <cmath>
#include <limits>

/// <summary>
/// <para>Converts radians to degrees.<br/></para>
/// </summary>
inline vec_t radians_to_degrees(const vec_t radians)
{
	constexpr auto degrees_per_radian = 57.29577951308232F;
	return radians * degrees_per_radian;
}

/// <summary>
/// <para>Used for many path finding and many other operations that are treated as planar rather than 3D.</para>
/// </summary>
class Vector2D {
	/// <summary>
	/// </summary>
	static constexpr float epsilon_ = std::numeric_limits<float>::epsilon();

public:
	/// <summary>
	/// </summary>
	Vector2D() : x(0.0f), y(0.0f) {}

	/// <summary>
	/// </summary>
	Vector2D(const vec_t x_axis, const vec_t y_axis) : x(x_axis), y(y_axis) {}

	/// <summary>
	/// </summary>
	explicit Vector2D(const vec_t scalar) : x(scalar), y(scalar) {}

	/// <summary>
	/// </summary>
	explicit Vector2D(const vec_t vec_2d[2]) : x(vec_2d[0]), y(vec_2d[1]) {}

	/// <summary>
	/// </summary>
	Vector2D& operator=(const vec_t rhs)
	{
		x = y = rhs;
		return *this;
	}

	/// <summary>
	/// </summary>
	bool operator==(const vec_t rhs) const
	{
		return std::fabs(x - rhs) < epsilon_ && std::fabs(y - rhs) < epsilon_;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const vec_t rhs) const
	{
		return !operator==(rhs);
	}

	/// <summary>
	/// </summary>
	bool operator==(const Vector2D& rhs) const
	{
		return std::fabs(x - rhs.x) < epsilon_ && std::fabs(y - rhs.y) < epsilon_;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const Vector2D& rhs) const
	{
		return !(*this == rhs);
	}

	/// <summary>
	/// </summary>
	Vector2D operator+(const vec_t rhs) const
	{
		return Vector2D(x + rhs, y + rhs);
	}

	/// <summary>
	/// </summary>
	Vector2D operator-(const vec_t rhs) const
	{
		return Vector2D(x - rhs, y - rhs);
	}

	/// <summary>
	/// </summary>
	Vector2D operator*(const vec_t rhs) const
	{
		return Vector2D(x * rhs, y * rhs);
	}

	/// <summary>
	/// </summary>
	Vector2D operator/(const vec_t rhs) const
	{
		return Vector2D(x / rhs, y / rhs);
	}

	/// <summary>
	/// </summary>
	Vector2D operator+(const Vector2D& rhs) const
	{
		return Vector2D(x + rhs.x, y + rhs.y);
	}

	/// <summary>
	/// </summary>
	Vector2D operator-(const Vector2D& rhs) const
	{
		return Vector2D(x - rhs.x, y - rhs.y);
	}

	/// <summary>
	/// </summary>
	Vector2D operator*(const Vector2D& rhs) const
	{
		return Vector2D(x * rhs.x, y * rhs.y);
	}

	/// <summary>
	/// </summary>
	Vector2D operator/(const Vector2D& rhs) const
	{
		return Vector2D(x / rhs.x, y / rhs.y);
	}

	/// <summary>
	/// </summary>
	Vector2D& operator+=(const vec_t rhs)
	{
		x += rhs;
		y += rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator-=(const vec_t rhs)
	{
		x -= rhs;
		y -= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator*=(const vec_t rhs)
	{
		x *= rhs;
		y *= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator/=(const vec_t rhs)
	{
		x /= rhs;
		y /= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator+=(const Vector2D& rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator-=(const Vector2D& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator*=(const Vector2D& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator/=(const Vector2D& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;

		return *this;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] vec_t length() const
	{
		return std::sqrt(x * x + y * y);
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] Vector2D normalize() const
	{
		auto len = length();

		if (std::fabs(len) < epsilon_) {
			return Vector2D(0.0f, 0.0f);
		}

		len = 1.0f / len;

		return Vector2D(x * len, y * len);
	}

	/// <summary>
	/// </summary>
	void copy_to_array(vec_t vec_2d[2]) const
	{
		vec_2d[0] = x;
		vec_2d[1] = y;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] bool is_zero(const vec_t tolerance = 0.01f) const
	{
		return x > -tolerance && x < tolerance && y > -tolerance && y < tolerance;
	}

	/// <summary>
	/// </summary>
	void clear()
	{
		x = y = 0.0f;
	}

	/// <summary>
	/// </summary>
	vec_t x;

	/// <summary>
	/// </summary>
	vec_t y;
};

/// <summary>
/// Class Vector
/// </summary>
class Vector {
	/// <summary>
	/// </summary>
	static constexpr float epsilon_ = std::numeric_limits<float>::epsilon();

public:
	/// <summary>
	/// </summary>
	Vector() : x(0.0f), y(0.0f), z(0.0f) {}

	/// <summary>
	/// </summary>
	Vector(const vec_t x_axis, const vec_t y_axis, const vec_t z_axis) : x(x_axis), y(y_axis), z(z_axis) {}

	/// <summary>
	/// </summary>
	explicit Vector(const vec_t scalar) : x(scalar), y(scalar), z(scalar) {}

	/// <summary>
	/// </summary>
	explicit Vector(const vec_t vec_3d[3]) : x(vec_3d[0]), y(vec_3d[1]), z(vec_3d[2]) {}

	/// <summary>
	/// </summary>
	Vector& operator=(const vec_t rhs)
	{
		x = y = z = rhs;
		return *this;
	}

	/// <summary>
	/// </summary>
	bool operator==(const vec_t rhs) const
	{
		return std::fabs(x - rhs) < epsilon_ && std::fabs(y - rhs) < epsilon_ && std::fabs(z - rhs) < epsilon_;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const vec_t rhs) const
	{
		return !operator==(rhs);
	}

	/// <summary>
	/// </summary>
	bool operator==(const Vector& rhs) const
	{
		return std::fabs(x - rhs.x) < epsilon_ && std::fabs(y - rhs.y) < epsilon_ && std::fabs(z - rhs.z) < epsilon_;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const Vector& rhs) const
	{
		return !(*this == rhs);
	}

	/// <summary>
	/// </summary>
	Vector operator+(const vec_t rhs) const
	{
		return Vector(x + rhs, y + rhs, z + rhs);
	}

	/// <summary>
	/// </summary>
	Vector operator-(const vec_t rhs) const
	{
		return Vector(x - rhs, y - rhs, z - rhs);
	}

	/// <summary>
	/// </summary>
	Vector operator*(const vec_t rhs) const
	{
		return Vector(x * rhs, y * rhs, z * rhs);
	}

	/// <summary>
	/// </summary>
	Vector operator/(const vec_t rhs) const
	{
		return Vector(x / rhs, y / rhs, z / rhs);
	}

	/// <summary>
	/// </summary>
	Vector operator+(const Vector& rhs) const
	{
		return Vector(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	/// <summary>
	/// </summary>
	Vector operator-(const Vector& rhs) const
	{
		return Vector(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	/// <summary>
	/// </summary>
	Vector operator*(const Vector& rhs) const
	{
		return Vector(x * rhs.x, y * rhs.y, z * rhs.z);
	}

	/// <summary>
	/// </summary>
	Vector operator/(const Vector& rhs) const
	{
		return Vector(x / rhs.x, y / rhs.y, z / rhs.z);
	}

	/// <summary>
	/// </summary>
	Vector& operator+=(const vec_t rhs)
	{
		x += rhs;
		y += rhs;
		z += rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector& operator-=(const vec_t rhs)
	{
		x -= rhs;
		y -= rhs;
		z -= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector& operator*=(const vec_t rhs)
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector& operator/=(const vec_t rhs)
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector& operator+=(const Vector& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector& operator-=(const Vector& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector& operator*=(const Vector& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector& operator/=(const Vector& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;

		return *this;
	}

	/// <summary>
	/// <para>Vectors will now automatically convert to vec_t* when needed.</para>
	/// </summary>
	operator vec_t*()
	{
		return &x;
	}

	/// <summary>
	/// <para>Vectors will now automatically convert to vec_t* when needed.</para>
	/// </summary>
	operator const vec_t*() const
	{
		return &x;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] Vector2D make_2d() const
	{
		Vector2D vec;
		vec.x = x;
		vec.y = y;

		return vec;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] vec_t length() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] vec_t length_2d() const
	{
		return std::sqrt(x * x + y * y);
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] Vector normalize() const
	{
		auto len = length();

		if (std::fabs(len) < epsilon_) {
			return Vector(0.0f, 0.0f, 1.0f);
		}

		len = 1.0f / len;

		return Vector(x * len, y * len, z * len);
	}

	/// <summary>
	/// <para>Normalizes the vector's components.<br/></para>
	/// </summary>
	/// <returns>Old length.<br/></returns>
	vec_t normalize_in_place()
	{
		const auto len = length();

		if (std::fabs(len) < epsilon_) {
			x = y = 0.0f;
			z = 1.0f;
		}
		else {
			x = 1.0f / len * x;
			y = 1.0f / len * y;
			z = 1.0f / len * z;
		}

		return len;
	}

	/// <summary>
	/// <para>Computes the distance between two vectors (points).<br/></para>
	/// </summary>
	/// <returns>The distance between two vectors.<br/></returns>
	[[nodiscard]] vec_t distance(const Vector& other) const
	{
		return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
	}

	/// <summary>
	/// <para>Computes the distance between two 2D vectors (points).<br/></para>
	/// </summary>
	/// <returns>The distance between two vectors.<br/></returns>
	[[nodiscard]] vec_t distance_2d(const Vector& other) const
	{
		return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
	}

	/// <summary>
	/// <para>Computes the cross product of two vectors.<br/></para>
	/// </summary>
	[[nodiscard]] Vector cross(const Vector& other) const
	{
		return Vector(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	}

	/// <summary>
	/// <para>Computes the dot product of two vectors.<br/></para>
	/// </summary>
	/// <returns>The dot product of two vectors.<br/></returns>
	[[nodiscard]] vec_t dot_product(const Vector& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	/// <summary>
	/// <para>Negates a vector.<br/></para>
	/// </summary>
	[[nodiscard]] Vector negate() const
	{
		return Vector(-x, -y, -z);
	}

	/// <summary>
	/// <para>Computes the angle between two vectors.<br/></para>
	/// </summary>
	/// <returns>The angle between two vectors in degrees.<br/></returns>
	[[nodiscard]] vec_t angle(const Vector& other) const
	{
		return radians_to_degrees(std::cos(dot_product(other)));
	}

	/// <summary>
	/// <para>Reflects a vector about a normal.<br/></para>
	/// </summary>
	/// <returns>Reflected vector.<br/></returns>
	[[nodiscard]] Vector reflect(const Vector& normal) const
	{
		const auto tmp1 = normalize();

		auto tmp2 = normal * 2.0F;
		tmp2 *= tmp1.dot_product(normal);
		tmp2 *= length();

		return tmp1 - tmp2;
	}

	/// <summary>
	/// </summary>
	void copy_to_array(vec_t vec_3d[3]) const
	{
		vec_3d[0] = x;
		vec_3d[1] = y;
		vec_3d[2] = z;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] bool is_zero(const vec_t tolerance = epsilon_) const
	{
		return x > -tolerance && x < tolerance && y > -tolerance && y < tolerance && z > -tolerance && z < tolerance;
	}

	/// <summary>
	/// </summary>
	void clear()
	{
		x = y = z = 0.0f;
	}

	/// <summary>
	/// </summary>
	vec_t x;

	/// <summary>
	/// </summary>
	vec_t y;

	/// <summary>
	/// </summary>
	vec_t z;
};

/// <summary>
/// Class Vector4D
/// </summary>
class Vector4D {
	/// <summary>
	/// </summary>
	static constexpr float epsilon_ = std::numeric_limits<float>::epsilon();

public:
	/// <summary>
	/// </summary>
	Vector4D() : x(0.0F), y(0.0F), z(0.0F), w(0.0F) {}

	/// <summary>
	/// </summary>
	Vector4D(const vec_t x_axis, const vec_t y_axis, const vec_t z_axis, const vec_t w_axis)
		: x(x_axis), y(y_axis), z(z_axis), w(w_axis) {}

	/// <summary>
	/// </summary>
	explicit Vector4D(const vec_t scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}

	/// <summary>
	/// </summary>
	explicit Vector4D(const Vector& vector) : x(vector.x), y(vector.y), z(vector.z), w(0.0F) {}

	/// <summary>
	/// </summary>
	explicit Vector4D(const vec_t vec_4d[4]) : x(vec_4d[0]), y(vec_4d[1]), z(vec_4d[2]), w(vec_4d[3]) {}

	/// <summary>
	/// </summary>
	Vector4D& operator=(const vec_t rhs)
	{
		x = y = z = w = rhs;
		return *this;
	}

	/// <summary>
	/// </summary>
	bool operator==(const vec_t rhs) const
	{
		return std::fabs(x - rhs) < epsilon_ && std::fabs(y - rhs) < epsilon_
			&& std::fabs(z - rhs) < epsilon_ && std::fabs(w - rhs) < epsilon_;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const vec_t rhs) const
	{
		return !operator==(rhs);
	}

	/// <summary>
	/// </summary>
	bool operator==(const Vector4D& rhs) const
	{
		return std::fabs(x - rhs.x) < epsilon_ && std::fabs(y - rhs.y) < epsilon_
			&& std::fabs(z - rhs.z) < epsilon_ && std::fabs(w - rhs.w) < epsilon_;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const Vector4D& rhs) const
	{
		return !(*this == rhs);
	}

	/// <summary>
	/// </summary>
	Vector4D operator+(const vec_t rhs) const
	{
		return Vector4D(x + rhs, y + rhs, z + rhs, w + rhs);
	}

	/// <summary>
	/// </summary>
	Vector4D operator-(const vec_t rhs) const
	{
		return Vector4D(x - rhs, y - rhs, z - rhs, w - rhs);
	}

	/// <summary>
	/// </summary>
	Vector4D operator*(const vec_t rhs) const
	{
		return Vector4D(x * rhs, y * rhs, z * rhs, w * rhs);
	}

	/// <summary>
	/// </summary>
	Vector4D operator/(const vec_t rhs) const
	{
		return Vector4D(x / rhs, y / rhs, z / rhs, w / rhs);
	}

	/// <summary>
	/// </summary>
	Vector4D operator+(const Vector4D& rhs) const
	{
		return Vector4D(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
	}

	/// <summary>
	/// </summary>
	Vector4D operator-(const Vector4D& rhs) const
	{
		return Vector4D(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
	}

	/// <summary>
	/// </summary>
	Vector4D operator*(const Vector4D& rhs) const
	{
		return Vector4D(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
	}

	/// <summary>
	/// </summary>
	Vector4D operator/(const Vector4D& rhs) const
	{
		return Vector4D(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
	}

	/// <summary>
	/// </summary>
	Vector4D& operator+=(const vec_t rhs)
	{
		x += rhs;
		y += rhs;
		z += rhs;
		w += rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector4D& operator-=(const vec_t rhs)
	{
		x -= rhs;
		y -= rhs;
		z -= rhs;
		w -= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector4D& operator*=(const vec_t rhs)
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		w *= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector4D& operator/=(const vec_t rhs)
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
		w /= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector4D& operator+=(const Vector4D& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector4D& operator-=(const Vector4D& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector4D& operator*=(const Vector4D& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		w *= rhs.w;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector4D& operator/=(const Vector4D& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		w /= rhs.w;

		return *this;
	}

	/// <summary>
	/// <para>Vectors will now automatically convert to vec_t* when needed.</para>
	/// </summary>
	operator vec_t*()
	{
		return &x;
	}

	/// <summary>
	/// <para>Vectors will now automatically convert to vec_t* when needed.</para>
	/// </summary>
	operator const vec_t*() const
	{
		return &x;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] Vector make_3d() const
	{
		return Vector(x, y, z);
	}

	/// <summary>
	/// <para>Constructs a plane out of 4 points in space.<br/></para>
	/// </summary>
	static Vector4D plane_3p(const Vector& point1, const Vector& point2, const Vector& point3)
	{
		const auto normal_a = (point3 - point1).normalize();
		const auto normal_b = (point3 - point2).normalize();
		const auto normal_c = normal_a.cross(normal_b).normalize();

		Vector4D plane(normal_c);
		plane.w = normal_c.negate().dot_product(point1);

		return plane;
	}

	/// <summary>
	/// <para>Computes the distance between a plane and a point.<br/></para>
	/// </summary>
	/// <returns>The distance between the plane and point.<br/></returns>
	[[nodiscard]] vec_t plane_distance(const Vector& point) const
	{
		return make_3d().dot_product(point) + w;
	}

	/// <summary>
	/// <para>Checks whether a plane intersects with the ray starting at <c>ray_start</c> and going to <c>ray_dir</c> direction.<br/>
	/// If it does intersect, outputs the intersection point in <c>intersection</c>.<br/></para>
	/// </summary>
	/// <returns>True if they intersect, false otherwise.<br/></returns>
	bool plane_ray_intersect(const Vector& ray_start, const Vector& ray_dir, Vector& intersection) const
	{
		const auto a = make_3d().dot_product(ray_dir);

		if (std::fabs(a) < epsilon_) {
			return false; // Ray is parallel to plane.
		}

		const auto distance1 = plane_distance(ray_start + ray_dir);
		const auto distance2 = plane_distance(ray_start);

		if (std::fabs(distance1) > std::fabs(distance2) && std::signbit(distance1) == std::signbit(distance2)) {
			return false;
		}

		intersection = ray_start - ray_dir * (distance2 / a);

		return true;
	}

	/// <summary>
	/// <para>Checks if a point is on a plane.<br/></para>
	/// </summary>
	/// <returns>True if the point is on the plane, false otherwise.<br/></returns>
	[[nodiscard]] bool point_on_plane(const Vector& point) const
	{
		return std::fabs(plane_distance(point)) < epsilon_;
	}

	/// <summary>
	/// <para>Projects a point on the plane.<br/></para>
	/// </summary>
	/// <returns>The projected point.<br/></returns>
	[[nodiscard]] Vector proj_point_on_plane(const Vector& point) const
	{
		return point - make_3d() * plane_distance(point);
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] bool is_zero(const vec_t tolerance = epsilon_) const
	{
		return x > -tolerance && x < tolerance && y > -tolerance && y < tolerance &&
			z > -tolerance && z < tolerance && w > -tolerance && w < tolerance;
	}

	/// <summary>
	/// </summary>
	void clear()
	{
		x = y = z = w = 0.0F;
	}

	/// <summary>
	/// </summary>
	vec_t x;

	/// <summary>
	/// </summary>
	vec_t y;

	/// <summary>
	/// </summary>
	vec_t z;

	/// <summary>
	/// </summary>
	vec_t w;
};
