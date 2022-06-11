#pragma once
#include "precomp.h"

class Vec4 
{
public:
	Vec4();
	Vec4(float x, float y, float z, float w);
	explicit Vec4(float u);
	Vec4(const Vec4& b);
	Vec4 operator+(const Vec4& b) const;
	Vec4 operator-(const Vec4& b) const;
	Vec4 operator*(const Vec4& b) const;
	Vec4 operator*(const float b) const;
	Vec4 operator/(const Vec4& b) const;
	Vec4 operator/(const float b) const;
	void operator+=(const Vec4& b);
	void operator-=(const Vec4& b);
	void operator*=(const Vec4& b);
	void operator*=(const float b);
	void operator/=(const Vec4& b);
	bool operator==(const Vec4& b) const;
	bool operator!=(const Vec4& b) const;
	void clear();
	Vec4 normalize();
	float length() const;
	float sqrtLength() const;
	float distance(const Vec4& b) const;
	float dot(const Vec4& b) const;
	Vec4 clamp(const float min, const float max);
	float x() const;
	float y() const;
	float z() const;
	float w() const;
	void x(const float b);
	void y(const float b);
	void z(const float b);
	void w(const float b);

private:
	float m_X;
	float m_Y;
	float m_Z;
	float m_W;
};

inline Vec4 operator*(float f, const Vec4& b)
{
	return Vec4(b.x() * f, b.y() * f, b.z() * f, b.w() * f);
}