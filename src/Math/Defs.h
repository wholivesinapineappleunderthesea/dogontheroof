#pragma once

struct aposVec2;
struct aposVec3;
struct aposVec4;
struct aposQuat;
struct aposMat4x4;

namespace apostate
{
	namespace Math
	{
		static inline constexpr auto k_pi = 3.14159265358979323846f;
		static inline constexpr auto k_twoPi = 2.0f * k_pi;
		static inline constexpr auto k_halfPi = 0.5f * k_pi;

		static inline constexpr auto k_radToDeg = 180.0f / k_pi;
		static inline constexpr auto k_degToRad = k_pi / 180.0f;
	}; // namespace Math
}; // namespace aposgen

inline constexpr auto operator-(const aposVec2 &a) -> aposVec2;
inline constexpr auto operator+(const aposVec2 &a, const aposVec2 &b) -> aposVec2;
inline constexpr auto operator-(const aposVec2 &a, const aposVec2 &b) -> aposVec2;
inline constexpr auto operator*(const aposVec2 &a, const aposVec2 &b) -> aposVec2;
inline constexpr auto operator/(const aposVec2 &a, const aposVec2 &b) -> aposVec2;
inline constexpr auto operator*(const aposVec2 &a, aposF32 b) -> aposVec2;
inline constexpr auto operator/(const aposVec2 &a, aposF32 b) -> aposVec2;

inline constexpr auto operator-(const aposVec3 &a) -> aposVec3;
inline constexpr auto operator+(const aposVec3 &a, const aposVec3 &b) -> aposVec3;
inline constexpr auto operator-(const aposVec3 &a, const aposVec3 &b) -> aposVec3;
inline constexpr auto operator*(const aposVec3 &a, const aposVec3 &b) -> aposVec3;
inline constexpr auto operator/(const aposVec3 &a, const aposVec3 &b) -> aposVec3;
inline constexpr auto operator*(const aposVec3 &a, aposF32 b) -> aposVec3;
inline constexpr auto operator/(const aposVec3 &a, aposF32 b) -> aposVec3;

inline constexpr auto operator-(const aposVec4 &a) -> aposVec4;
inline constexpr auto operator+(const aposVec4 &a, const aposVec4 &b) -> aposVec4;
inline constexpr auto operator-(const aposVec4 &a, const aposVec4 &b) -> aposVec4;
inline constexpr auto operator*(const aposVec4 &a, const aposVec4 &b) -> aposVec4;
inline constexpr auto operator/(const aposVec4 &a, const aposVec4 &b) -> aposVec4;
inline constexpr auto operator*(const aposVec4 &a, aposF32 b) -> aposVec4;
inline constexpr auto operator/(const aposVec4 &a, aposF32 b) -> aposVec4;
inline constexpr auto operator*(const aposVec4 &a,
								const aposMat4x4 &b) -> aposVec4;

inline constexpr auto operator*(const aposMat4x4 &a,
								const aposMat4x4 &b) -> aposMat4x4;
inline constexpr auto operator*(const aposMat4x4 &a, aposF32 b) -> aposMat4x4;
inline constexpr auto operator*(const aposMat4x4 &a,
								const aposVec4 &b) -> aposVec4;

inline constexpr auto operator*(const aposQuat &a, const aposQuat &b) -> aposQuat;
inline constexpr auto operator*(const aposQuat &a, const aposVec3 &b) -> aposVec3;
inline constexpr auto operator*(const aposQuat &a, aposF32 b) -> aposQuat;
inline constexpr auto operator-(const aposQuat &a) -> aposQuat;
inline constexpr auto operator*(const aposQuat &a,
								const aposMat4x4 &b) -> aposMat4x4;

struct aposVec2
{
	constexpr aposVec2() : x(0), y(0)
	{
	}
	constexpr aposVec2(aposF32 x, aposF32 y) : x(x), y(y)
	{
	}

	aposF32 x, y;

	constexpr auto MagnitudeSquared() const -> aposF32
	{
		return x * x + y * y;
	}
	auto Magnitude() const -> aposF32
	{
		return std::sqrtf(x * x + y * y);
	}

	auto Normalized() const -> aposVec2
	{
		aposF32 mag = Magnitude();
		return {x / mag, y / mag};
	}
	auto Normalize() -> aposVec2 &
	{
		aposF32 mag = Magnitude();
		x /= mag;
		y /= mag;
		return *this;
	}

	constexpr auto DotProduct(const aposVec2 &other) const -> aposF32
	{
		return x * other.x + y * other.y;
	}

	constexpr auto CrossProduct(const aposVec2 &other) const -> aposF32
	{
		return x * other.y - y * other.x;
	}

	constexpr auto Conjugate() const -> aposVec2
	{
		return {-x, -y};
	}

	constexpr auto Inversed() const -> aposVec2
	{
		return Conjugate() / (x * x + y * y);
	}
	constexpr auto Inverse() -> aposVec2 &
	{
		*this = Inversed();
		return *this;
	}

	constexpr auto operator+=(const aposVec2 &other) -> aposVec2 &
	{
		*this = *this + other;
		return *this;
	}
	constexpr auto operator-=(const aposVec2 &other) -> aposVec2 &
	{
		*this = *this - other;
		return *this;
	}
	constexpr auto operator*=(const aposVec2 &other) -> aposVec2 &
	{
		*this = *this * other;
		return *this;
	}
	constexpr auto operator/=(const aposVec2 &other) -> aposVec2 &
	{
		*this = *this / other;
		return *this;
	}
	constexpr auto operator*=(aposF32 other) -> aposVec2 &
	{
		*this = *this * other;
		return *this;
	}
	constexpr auto operator/=(aposF32 other) -> aposVec2 &
	{
		*this = *this / other;
		return *this;
	}
};

struct aposVec3
{
	constexpr aposVec3() : x(0), y(0), z(0)
	{
	}
	constexpr aposVec3(aposF32 x, aposF32 y, aposF32 z) : x(x), y(y), z(z)
	{
	}
	constexpr aposVec3(const aposVec2 &v, aposF32 z) : x(v.x), y(v.y), z(z)
	{
	}
	aposF32 x, y, z;

	operator aposVec2() const
	{
		return {x, y};
	}

	constexpr auto MagnitudeSquared() const -> aposF32
	{
		return x * x + y * y + z * z;
	}
	auto Magnitude() const -> aposF32
	{
		return std::sqrtf(x * x + y * y + z * z);
	}

	auto Normalized() const -> aposVec3
	{
		const auto mag = Magnitude();
		return {x / mag, y / mag, z / mag};
	}
	auto Normalize() -> aposVec3 &
	{
		const auto mag = Magnitude();
		x /= mag;
		y /= mag;
		z /= mag;
		return *this;
	}

	constexpr auto DotProduct(const aposVec3 &other) const -> aposF32
	{
		return x * other.x + y * other.y + z * other.z;
	}

	constexpr auto CrossProduct(const aposVec3 &other) const -> aposVec3
	{
		return {y * other.z - z * other.y, z * other.x - x * other.z,
				x * other.y - y * other.x};
	}

	constexpr auto Conjugate() const -> aposVec3
	{
		return {-x, -y, z};
	}

	constexpr auto Inversed() const -> aposVec3
	{
		return Conjugate() / (x * x + y * y + z * z);
	}
	constexpr auto Inverse() -> aposVec3 &
	{
		*this = Inversed();
		return *this;
	}

	constexpr auto operator+=(const aposVec3 &other) -> aposVec3 &
	{
		*this = *this + other;
		return *this;
	}
	constexpr auto operator-=(const aposVec3 &other) -> aposVec3 &
	{
		*this = *this - other;
		return *this;
	}
	constexpr auto operator*=(const aposVec3 &other) -> aposVec3 &
	{
		*this = *this * other;
		return *this;
	}
	constexpr auto operator/=(const aposVec3 &other) -> aposVec3 &
	{
		*this = *this / other;
		return *this;
	}
	constexpr auto operator*=(aposF32 other) -> aposVec3 &
	{
		*this = *this * other;
		return *this;
	}
	constexpr auto operator/=(aposF32 other) -> aposVec3 &
	{
		*this = *this / other;
		return *this;
	}
};

struct aposVec4
{
	constexpr aposVec4() : x(0), y(0), z(0), w(0)
	{
	}
	constexpr aposVec4(aposF32 x, aposF32 y, aposF32 z, aposF32 w)
		: x(x), y(y), z(z), w(w)
	{
	}
	constexpr aposVec4(const aposVec3 &v, aposF32 w) : x(v.x), y(v.y), z(v.z), w(w)
	{
	}
	constexpr aposVec4(const aposVec2 &v, aposF32 z, aposF32 w)
		: x(v.x), y(v.y), z(z), w(w)
	{
	}
	aposF32 x, y, z, w;

	operator aposVec3() const
	{
		return {x, y, z};
	}
	operator aposVec2() const
	{
		return {x, y};
	}

	constexpr auto MagnitudeSquared() const -> aposF32
	{
		return x * x + y * y + z * z + w * w;
	}
	auto Magnitude() const -> aposF32
	{
		return std::sqrtf(x * x + y * y + z * z + w * w);
	}

	auto Normalized() const -> aposVec4
	{
		const auto mag = Magnitude();
		return {x / mag, y / mag, z / mag, w / mag};
	}
	auto Normalize() -> aposVec4 &
	{
		const auto mag = Magnitude();
		x /= mag;
		y /= mag;
		z /= mag;
		w /= mag;
		return *this;
	}

	constexpr auto DotProduct(const aposVec4 &other) const -> aposF32
	{
		return x * other.x + y * other.y + z * other.z + w * other.w;
	}

	constexpr auto Conjugate() const -> aposVec4
	{
		return {-x, -y, -z, w};
	}

	constexpr auto Inversed() const -> aposVec4
	{
		return Conjugate() / (x * x + y * y + z * z + w * w);
	}
	constexpr auto Inverse() -> aposVec4 &
	{
		*this = Inversed();
		return *this;
	}
	constexpr auto CrossProduct(const aposVec4 &other) const -> aposVec4
	{
		return {y * other.z - z * other.y, z * other.x - x * other.z,
				x * other.y - y * other.x, 0};
	}

	constexpr auto operator+=(const aposVec4 &other) -> aposVec4 &
	{
		*this = *this + other;
		return *this;
	}
	constexpr auto operator-=(const aposVec4 &other) -> aposVec4 &
	{
		*this = *this - other;
		return *this;
	}
	constexpr auto operator*=(const aposVec4 &other) -> aposVec4 &
	{
		*this = *this * other;
		return *this;
	}
	constexpr auto operator/=(const aposVec4 &other) -> aposVec4 &
	{
		*this = *this / other;
		return *this;
	}
	constexpr auto operator*=(aposF32 other) -> aposVec4 &
	{
		*this = *this * other;
		return *this;
	}
	constexpr auto operator/=(aposF32 other) -> aposVec4 &
	{
		*this = *this / other;
		return *this;
	}
};

struct aposMat4x4
{
	aposF32 m[4][4];

	constexpr auto Determinant() const -> aposF32
	{
		return m[0][0] * m[1][1] * m[2][2] * m[3][3] +
			   m[0][0] * m[1][2] * m[2][3] * m[3][1] +
			   m[0][0] * m[1][3] * m[2][1] * m[3][2] +
			   m[0][1] * m[1][0] * m[2][3] * m[3][2] +
			   m[0][1] * m[1][2] * m[2][0] * m[3][3] +
			   m[0][1] * m[1][3] * m[2][2] * m[3][0] +
			   m[0][2] * m[1][0] * m[2][1] * m[3][3] +
			   m[0][2] * m[1][1] * m[2][3] * m[3][0] +
			   m[0][2] * m[1][3] * m[2][0] * m[3][1] +
			   m[0][3] * m[1][0] * m[2][2] * m[3][1] +
			   m[0][3] * m[1][1] * m[2][0] * m[3][2] +
			   m[0][3] * m[1][2] * m[2][1] * m[3][0] -
			   m[0][0] * m[1][1] * m[2][3] * m[3][2] -
			   m[0][0] * m[1][2] * m[2][1] * m[3][3] -
			   m[0][0] * m[1][3] * m[2][2] * m[3][1] -
			   m[0][1] * m[1][0] * m[2][2] * m[3][3] -
			   m[0][1] * m[1][2] * m[2][3] * m[3][0] -
			   m[0][1] * m[1][3] * m[2][0] * m[3][2] -
			   m[0][2] * m[1][0] * m[2][3] * m[3][1] -
			   m[0][2] * m[1][1] * m[2][0] * m[3][3] -
			   m[0][2] * m[1][3] * m[2][1] * m[3][0] -
			   m[0][3] * m[1][0] * m[2][1] * m[3][2] -
			   m[0][3] * m[1][1] * m[2][2] * m[3][0] -
			   m[0][3] * m[1][2] * m[2][0] * m[3][1];
	}

	constexpr auto Transposed() const -> aposMat4x4
	{
		aposMat4x4 result{};
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				result.m[i][j] = m[j][i];
			}
		}
		return result;
	}
	constexpr auto Transpose() -> aposMat4x4 &
	{
		*this = Transposed();
		return *this;
	}

	constexpr auto operator[](int i) -> aposF32 *
	{
		return m[i];
	}
	constexpr auto operator[](int i) const -> const aposF32 *
	{
		return m[i];
	}

	constexpr auto operator*=(const aposMat4x4 &other) -> aposMat4x4 &
	{
		*this = *this * other;
		return *this;
	}

	static inline constexpr auto Identity() -> aposMat4x4
	{
		aposMat4x4 result{};
		result.m[0][0] = 1;
		result.m[1][1] = 1;
		result.m[2][2] = 1;
		result.m[3][3] = 1;
		return result;
	}
};

struct aposQuat
{
	aposF32 x{0.0f}, y{0.0f}, z{0.0f}, w{1.0f};

	constexpr auto MagnitudeSquared() const -> aposF32
	{
		return x * x + y * y + z * z + w * w;
	}
	auto Magnitude() const -> aposF32
	{
		return std::sqrtf(x * x + y * y + z * z + w * w);
	}

	auto Normalized() const -> aposQuat
	{
		const auto mag = Magnitude();
		return {x / mag, y / mag, z / mag, w / mag};
	}
	auto Normalize() -> aposQuat &
	{
		const auto mag = Magnitude();
		x /= mag;
		y /= mag;
		z /= mag;
		w /= mag;
		return *this;
	}

	constexpr auto DotProduct(const aposQuat &other) const -> aposF32
	{
		return x * other.x + y * other.y + z * other.z + w * other.w;
	}

	constexpr auto Conjugate() const -> aposQuat
	{
		return {-x, -y, -z, w};
	}

	auto Inversed() const -> aposQuat
	{
		const auto conj = Conjugate();
		const auto magsq = MagnitudeSquared();
		return {conj.x / magsq, conj.y / magsq, conj.z / magsq, conj.w / magsq};
	}
	auto Inverse() -> aposQuat &
	{
		*this = Inversed();
		return *this;
	}

	constexpr auto operator*=(const aposQuat &other) -> aposQuat &
	{
		*this = *this * other;
		return *this;
	}
};

inline constexpr auto operator-(const aposVec2 &a) -> aposVec2
{
	return {-a.x, -a.y};
}
inline constexpr auto operator+(const aposVec2 &a, const aposVec2 &b) -> aposVec2
{
	return {a.x + b.x, a.y + b.y};
}
inline constexpr auto operator-(const aposVec2 &a, const aposVec2 &b) -> aposVec2
{
	return {a.x - b.x, a.y - b.y};
}
inline constexpr auto operator*(const aposVec2 &a, const aposVec2 &b) -> aposVec2
{
	return {a.x * b.x, a.y * b.y};
}
inline constexpr auto operator/(const aposVec2 &a, const aposVec2 &b) -> aposVec2
{
	return {a.x / b.x, a.y / b.y};
}
inline constexpr auto operator*(const aposVec2 &a, aposF32 b) -> aposVec2
{
	return {a.x * b, a.y * b};
}
inline constexpr auto operator/(const aposVec2 &a, aposF32 b) -> aposVec2
{
	return {a.x / b, a.y / b};
}

inline constexpr auto operator-(const aposVec3 &a) -> aposVec3
{
	return {-a.x, -a.y, -a.z};
}
inline constexpr auto operator+(const aposVec3 &a, const aposVec3 &b) -> aposVec3
{
	return {a.x + b.x, a.y + b.y, a.z + b.z};
}
inline constexpr auto operator-(const aposVec3 &a, const aposVec3 &b) -> aposVec3
{
	return {a.x - b.x, a.y - b.y, a.z - b.z};
}
inline constexpr auto operator*(const aposVec3 &a, const aposVec3 &b) -> aposVec3
{
	return {a.x * b.x, a.y * b.y, a.z * b.z};
}
inline constexpr auto operator/(const aposVec3 &a, const aposVec3 &b) -> aposVec3
{
	return {a.x / b.x, a.y / b.y, a.z / b.z};
}
inline constexpr auto operator*(const aposVec3 &a, aposF32 b) -> aposVec3
{
	return {a.x * b, a.y * b, a.z * b};
}
inline constexpr auto operator/(const aposVec3 &a, aposF32 b) -> aposVec3
{
	return {a.x / b, a.y / b, a.z / b};
}

inline constexpr auto operator-(const aposVec4 &a) -> aposVec4
{
	return {-a.x, -a.y, -a.z, -a.w};
}
inline constexpr auto operator+(const aposVec4 &a, const aposVec4 &b) -> aposVec4
{
	return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
inline constexpr auto operator-(const aposVec4 &a, const aposVec4 &b) -> aposVec4
{
	return {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}
inline constexpr auto operator*(const aposVec4 &a, const aposVec4 &b) -> aposVec4
{
	return {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}
inline constexpr auto operator/(const aposVec4 &a, const aposVec4 &b) -> aposVec4
{
	return {a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w};
}
inline constexpr auto operator*(const aposVec4 &a, aposF32 b) -> aposVec4
{
	return {a.x * b, a.y * b, a.z * b, a.w * b};
}
inline constexpr auto operator/(const aposVec4 &a, aposF32 b) -> aposVec4
{
	return {a.x / b, a.y / b, a.z / b, a.w / b};
}
inline constexpr auto operator*(const aposVec4 &a, const aposMat4x4 &b) -> aposVec4
{
	return {
		a.x * b.m[0][0] + a.y * b.m[1][0] + a.z * b.m[2][0] + a.w * b.m[3][0],
		a.x * b.m[0][1] + a.y * b.m[1][1] + a.z * b.m[2][1] + a.w * b.m[3][1],
		a.x * b.m[0][2] + a.y * b.m[1][2] + a.z * b.m[2][2] + a.w * b.m[3][2],
		a.x * b.m[0][3] + a.y * b.m[1][3] + a.z * b.m[2][3] + a.w * b.m[3][3]};
}

inline constexpr auto operator*(const aposMat4x4 &a,
								const aposMat4x4 &b) -> aposMat4x4
{
	aposMat4x4 result{};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m[1][j] +
							 a.m[i][2] * b.m[2][j] + a.m[i][3] * b.m[3][j];
		}
	}
	return result;
}
inline constexpr auto operator*(const aposMat4x4 &a, aposF32 b) -> aposMat4x4
{
	aposMat4x4 result = a;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.m[i][j] *= b;
		}
	}
	return result;
}
inline constexpr auto operator*(const aposMat4x4 &a, const aposVec4 &b) -> aposVec4
{
	aposVec4 result;
	for (int i = 0; i < 4; i++)
	{
		result.x += a.m[i][0] * b.x;
		result.y += a.m[i][1] * b.y;
		result.z += a.m[i][2] * b.z;
		result.w += a.m[i][3] * b.w;
	}
	return result;
}

inline constexpr auto operator*(const aposQuat &a, const aposQuat &b) -> aposQuat
{
	return {a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
			a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
			a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w,
			a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z};
}
inline constexpr auto operator*(const aposQuat &a, const aposVec3 &b) -> aposVec3
{
	aposQuat v = {b.x, b.y, b.z, 0};
	aposQuat result = a * v * a.Conjugate();
	return {result.x, result.y, result.z};
}
inline constexpr auto operator*(const aposQuat &a, aposF32 b) -> aposQuat
{
	return {a.x * b, a.y * b, a.z * b, a.w * b};
}
inline constexpr auto operator-(const aposQuat &a) -> aposQuat
{
	return {-a.x, -a.y, -a.z, -a.w};
}
inline constexpr auto operator*(const aposQuat &a,
								const aposMat4x4 &b) -> aposMat4x4
{
	aposMat4x4 result{};
	result.m[0][0] = 1 - 2 * a.y * a.y - 2 * a.z * a.z;
	result.m[0][1] = 2 * a.x * a.y - 2 * a.z * a.w;
	result.m[0][2] = 2 * a.x * a.z + 2 * a.y * a.w;
	result.m[0][3] = 0;
	result.m[1][0] = 2 * a.x * a.y + 2 * a.z * a.w;
	result.m[1][1] = 1 - 2 * a.x * a.x - 2 * a.z * a.z;
	result.m[1][2] = 2 * a.y * a.z - 2 * a.x * a.w;
	result.m[1][3] = 0;
	result.m[2][0] = 2 * a.x * a.z - 2 * a.y * a.w;
	result.m[2][1] = 2 * a.y * a.z + 2 * a.x * a.w;
	result.m[2][2] = 1 - 2 * a.x * a.x - 2 * a.y * a.y;
	result.m[2][3] = 0;
	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;
	return result * b;
}

namespace aposgen
{
	namespace Math
	{
		inline constexpr auto Translate(const aposMat4x4 &m,
										const aposVec3 &v) -> aposMat4x4
		{
			aposMat4x4 result = m;
			result.m[3][0] += v.x;
			result.m[3][1] += v.y;
			result.m[3][2] += v.z;
			return result;
		}
		inline constexpr auto Rotate(const aposMat4x4 &m,
									 const aposQuat &q) -> aposMat4x4
		{
			aposMat4x4 result{};
			result.m[0][0] = 1 - 2 * q.y * q.y - 2 * q.z * q.z;
			result.m[0][1] = 2 * q.x * q.y - 2 * q.z * q.w;
			result.m[0][2] = 2 * q.x * q.z + 2 * q.y * q.w;
			result.m[0][3] = 0;
			result.m[1][0] = 2 * q.x * q.y + 2 * q.z * q.w;
			result.m[1][1] = 1 - 2 * q.x * q.x - 2 * q.z * q.z;
			result.m[1][2] = 2 * q.y * q.z - 2 * q.x * q.w;
			result.m[1][3] = 0;
			result.m[2][0] = 2 * q.x * q.z - 2 * q.y * q.w;
			result.m[2][1] = 2 * q.y * q.z + 2 * q.x * q.w;
			result.m[2][2] = 1 - 2 * q.x * q.x - 2 * q.y * q.y;
			result.m[2][3] = 0;
			result.m[3][0] = 0;
			result.m[3][1] = 0;
			result.m[3][2] = 0;
			result.m[3][3] = 1;
			return result * m;
		}
		inline auto Rotate(const aposMat4x4 &m, aposF32 angle,
						   const aposVec3 &axis) -> aposMat4x4
		{
			const auto halfAngle = angle / 2;
			const auto s = std::sinf(halfAngle);
			const auto q = aposQuat{axis.x * s, axis.y * s, axis.z * s,
									std::cosf(halfAngle)};
			return Rotate(m, q);
		}
		inline constexpr auto Scale(const aposMat4x4 &m,
									const aposVec3 &v) -> aposMat4x4
		{
			aposMat4x4 result = m;
			result.m[0][0] *= v.x;
			result.m[1][1] *= v.y;
			result.m[2][2] *= v.z;
			return result;
		}
		inline auto LookAt(const aposVec3 &eye, const aposVec3 &center,
						   const aposVec3 &up) -> aposMat4x4
		{
			const auto f = (center - eye).Normalized();
			const auto s = up.CrossProduct(f).Normalized();
			const auto u = f.CrossProduct(s);
			aposMat4x4 result{};
			result[0][0] = s.x;
			result[1][0] = s.y;
			result[2][0] = s.z;
			result[0][1] = u.x;
			result[1][1] = u.y;
			result[2][1] = u.z;
			result[0][2] = f.x;
			result[1][2] = f.y;
			result[2][2] = f.z;
			result[3][0] = -s.DotProduct(eye);
			result[3][1] = -u.DotProduct(eye);
			result[3][2] = -f.DotProduct(eye);
			result[3][3] = 1;
			return result;
		}
		inline auto Perspective(aposF32 fovy, aposF32 aspect, aposF32 near,
								aposF32 far) -> aposMat4x4
		{
			const auto tanHalfFovy = std::tanf(fovy / 2.f);
			aposMat4x4 result{};
			result[0][0] = 1.f / (aspect * tanHalfFovy);
			result[1][1] = 1.f / tanHalfFovy;
			result[2][2] = far / (far - near);
			result[2][3] = 1.f;
			result[3][2] = -(far * near) / (far - near);
			return result;
		}
		inline auto InverseMatrix(const aposMat4x4 &m) -> aposMat4x4
		{
			aposMat4x4 result;
			const auto det = m.Determinant();
			if (det == 0)
				return result;
			const auto invDet = 1 / det;
			result[0][0] =
				invDet *
				(m[1][1] * m[2][2] * m[3][3] + m[1][2] * m[2][3] * m[3][1] +
				 m[1][3] * m[2][1] * m[3][2] - m[1][1] * m[2][3] * m[3][2] -
				 m[1][2] * m[2][1] * m[3][3] - m[1][3] * m[2][2] * m[3][1]);
			result[0][1] =
				invDet *
				(m[0][1] * m[2][3] * m[3][2] + m[0][2] * m[2][1] * m[3][3] +
				 m[0][3] * m[2][2] * m[3][1] - m[0][1] * m[2][2] * m[3][3] -
				 m[0][2] * m[2][3] * m[3][1] - m[0][3] * m[2][1] * m[3][2]);
			result[0][2] =
				invDet *
				(m[0][1] * m[1][2] * m[3][3] + m[0][2] * m[1][3] * m[3][1] +
				 m[0][3] * m[1][1] * m[3][2] - m[0][1] * m[1][3] * m[3][2] -
				 m[0][2] * m[1][1] * m[3][3] - m[0][3] * m[1][2] * m[3][1]);
			result[0][3] =
				invDet *
				(m[0][1] * m[1][3] * m[2][2] + m[0][2] * m[1][1] * m[2][3] +
				 m[0][3] * m[1][2] * m[2][1] - m[0][1] * m[1][2] * m[2][3] -
				 m[0][2] * m[1][3] * m[2][1] - m[0][3] * m[1][1] * m[2][2]);

			result[1][0] =
				invDet *
				(m[1][0] * m[2][3] * m[3][2] + m[1][2] * m[2][0] * m[3][3] +
				 m[1][3] * m[2][2] * m[3][0] - m[1][0] * m[2][2] * m[3][3] -
				 m[1][2] * m[2][3] * m[3][0] - m[1][3] * m[2][0] * m[3][2]);
			result[1][1] =
				invDet *
				(m[0][0] * m[2][2] * m[3][3] + m[0][2] * m[2][3] * m[3][0] +
				 m[0][3] * m[2][0] * m[3][2] - m[0][0] * m[2][3] * m[3][2] -
				 m[0][2] * m[2][0] * m[3][3] - m[0][3] * m[2][2] * m[3][0]);
			result[1][2] =
				invDet *
				(m[0][0] * m[1][3] * m[3][2] + m[0][2] * m[1][0] * m[3][3] +
				 m[0][3] * m[1][2] * m[3][0] - m[0][0] * m[1][2] * m[3][3] -
				 m[0][2] * m[1][3] * m[3][0] - m[0][3] * m[1][0] * m[3][2]);
			result[1][3] =
				invDet *
				(m[0][0] * m[1][2] * m[2][3] + m[0][1] * m[1][3] * m[2][0] +
				 m[0][3] * m[1][0] * m[2][2] - m[0][0] * m[1][3] * m[2][2] -
				 m[0][1] * m[1][0] * m[2][3] - m[0][3] * m[1][2] * m[2][0]);

			result[2][0] =
				invDet *
				(m[1][0] * m[2][3] * m[3][1] + m[1][1] * m[2][0] * m[3][3] +
				 m[1][3] * m[2][1] * m[3][0] - m[1][0] * m[2][1] * m[3][3] -
				 m[1][1] * m[2][3] * m[3][0] - m[1][3] * m[2][0] * m[3][1]);
			result[2][1] =
				invDet *
				(m[0][0] * m[2][1] * m[3][3] + m[0][1] * m[2][3] * m[3][0] +
				 m[0][3] * m[2][0] * m[3][1] - m[0][0] * m[2][3] * m[3][1] -
				 m[0][1] * m[2][0] * m[3][3] - m[0][3] * m[2][1] * m[3][0]);
			result[2][2] =
				invDet *
				(m[0][0] * m[1][1] * m[3][3] + m[0][1] * m[1][3] * m[3][0] +
				 m[0][3] * m[1][0] * m[3][1] - m[0][0] * m[1][3] * m[3][1] -
				 m[0][1] * m[1][0] * m[3][3] - m[0][3] * m[1][1] * m[3][0]);
			result[2][3] =
				invDet *
				(m[0][0] * m[1][1] * m[2][3] + m[0][1] * m[1][3] * m[2][0] +
				 m[0][2] * m[1][0] * m[2][1] - m[0][0] * m[1][3] * m[2][1] -
				 m[0][1] * m[1][0] * m[2][3] - m[0][2] * m[1][1] * m[2][0]);

			result[3][0] =
				invDet *
				(m[1][0] * m[2][1] * m[3][2] + m[1][1] * m[2][2] * m[3][0] +
				 m[1][2] * m[2][0] * m[3][1] - m[1][0] * m[2][2] * m[3][1] -
				 m[1][1] * m[2][0] * m[3][2] - m[1][2] * m[2][1] * m[3][0]);
			result[3][1] =
				invDet *
				(m[0][0] * m[2][2] * m[3][1] + m[0][1] * m[2][0] * m[3][2] +
				 m[0][2] * m[2][1] * m[3][0] - m[0][0] * m[2][1] * m[3][2] -
				 m[0][1] * m[2][2] * m[3][0] - m[0][2] * m[2][0] * m[3][1]);
			result[3][2] =
				invDet *
				(m[0][0] * m[1][1] * m[3][0] + m[0][1] * m[1][0] * m[3][2] +
				 m[0][2] * m[1][2] * m[3][1] - m[0][0] * m[1][2] * m[3][1] -
				 m[0][1] * m[1][2] * m[3][0] - m[0][2] * m[1][0] * m[3][1]);
			result[3][3] =
				invDet *
				(m[0][0] * m[1][1] * m[2][0] + m[0][1] * m[1][0] * m[2][1] +
				 m[0][2] * m[1][1] * m[2][2] - m[0][0] * m[1][1] * m[2][1] -
				 m[0][1] * m[1][2] * m[2][0] - m[0][2] * m[1][0] * m[2][1]);
			return result;
		}
		inline auto RotationMatrixToEuler(const aposMat4x4 &m) -> aposVec3
		{
			aposVec3 result;
			result.y = std::asin(-m[2][0]);
			if (std::cos(result.y) != 0)
			{
				result.x = std::atan2(m[2][1], m[2][2]);
				result.z = std::atan2(m[1][0], m[0][0]);
			}
			else
			{
				result.x = 0;
				result.z = std::atan2(-m[0][1], m[1][1]);
			}
			return result;
		}
		inline auto Slerp(const aposQuat &a, const aposQuat &b,
						  aposF32 t) -> aposQuat
		{
			const auto dot = a.DotProduct(b);
			const auto angle = std::acosf(dot);
			const auto denom = std::sinf(angle);
			if (denom == 0)
				return a;
			const auto s0 = std::sinf((1 - t) * angle) / denom;
			const auto s1 = std::sinf(t * angle) / denom;
			const auto sa = a * s0;
			const auto sb = b * s1;
			return aposQuat{sa.x + sb.x, sa.y + sb.y, sa.z + sb.z, sa.w + sb.w};
		}
		inline auto AngleAxisToQuat(const aposF32 angle,
									const aposVec3 &axis) -> aposQuat
		{
			const auto halfAngle = angle / 2;
			const auto s = std::sinf(halfAngle);
			return {axis.x * s, axis.y * s, axis.z * s, std::cos(halfAngle)};
		}
		inline auto QuatToEulerAngles(const aposQuat &q) -> aposVec3
		{
			aposVec3 result;
			result.x = std::atan2(2 * (q.w * q.x + q.y * q.z),
								  1 - 2 * (q.x * q.x + q.y * q.y));
			result.y = std::asin(2 * (q.w * q.y - q.z * q.x));
			result.z = std::atan2(2 * (q.w * q.z + q.x * q.y),
								  1 - 2 * (q.y * q.y + q.z * q.z));
			return result;
		}
		inline auto EulerAnglesToQuat(const aposVec3 &v) -> aposQuat
		{
			const auto pitch = AngleAxisToQuat(v.x, {1, 0, 0});
			const auto yaw = AngleAxisToQuat(v.y, {0, 1, 0});
			const auto roll = AngleAxisToQuat(v.z, {0, 0, 1});
			return pitch * yaw * roll;
		}
		inline auto QuatLookAt(const aposVec3 &position,
							   const aposVec3 &where) -> aposQuat
		{
			const auto direction = (where - position).Normalized();
			const auto forward = aposVec3{0, 0, 1};
			const auto axis = forward.CrossProduct(direction);
			const auto angle = std::acosf(forward.DotProduct(direction));
			return AngleAxisToQuat(angle, axis);
		}
		inline auto EulerForward(const aposVec3 &euler) -> aposVec3
		{
			return aposVec3{std::cosf(euler.z) * std::cosf(euler.x),
							std::sinf(euler.z) * std::cosf(euler.x),
							std::sinf(euler.x)};
		}
	}; // namespace Math
}; // namespace apostate