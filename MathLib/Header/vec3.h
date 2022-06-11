#pragma once
#include "precomp.h"

class Vec3
{
public:
	Vec3();
	Vec3(float x, float y, float z);
	explicit Vec3(float u); //Caused an issue when implicit. Didn't know about this problem until Phil de Groot pointed it out.
	Vec3(const Vec3& b);
	Vec3 operator+ (const Vec3& b) const;
	Vec3 operator- (const Vec3& b) const;
	Vec3 operator* (const Vec3& b) const;
	Vec3 operator* (const float f) const;
	Vec3 operator/ (const float f) const;
	Vec3 operator/ (const Vec3& b) const;
	void operator+= (const Vec3& b);
	void operator-= (const Vec3& b);
	void operator*= (const Vec3& b);
	void operator*= (const float f);
	void operator/= (const Vec3& b);
	bool operator== (const Vec3& b) const;
	bool operator!= (const Vec3& b) const;
	void clear();
	Vec3 normalize();
	float length() const;
	float sqrtLength() const;
	float distance(const Vec3& b) const;
	float dot(const Vec3& b) const;
	Vec3 cross(Vec3 b);
	Vec3 clamp(const float min, const float max);
	float x() const;
	float y() const;
	float z() const;
	void x(const float f);
	void y(const float f);
	void z(const float f);

private:
	float m_X;
	float m_Y;
	float m_Z;
};

inline Vec3 operator*(float f, const Vec3& b)
{
	return Vec3(b.x() * f, b.y() * f, b.z() * f);
}

using Color = Vec3;