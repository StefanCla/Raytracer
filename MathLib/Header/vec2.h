#pragma once
#include "precomp.h"

class Vec2
{
public:
	Vec2();
	Vec2(float x, float y);
	explicit Vec2(float f);
	Vec2(const Vec2& b);
	Vec2 operator+ (const Vec2& b) const;
	Vec2 operator- (const Vec2& b) const;
	float operator* (const Vec2& b) const;
	Vec2 operator* (const float f) const;
	Vec2 operator/ (const Vec2& b) const;
	Vec2 operator/ (const float f) const;
	void operator+= (const Vec2& b);
	void operator-= (const Vec2& b);
	void operator*= (const Vec2& b);
	void operator*= (const float f);
	void operator/= (const Vec2& b);
	bool operator== (const Vec2& b) const;
	bool operator!= (const Vec2& b) const;
	void clear();
	Vec2 normalize();
	float length() const;
	float sqrtLength() const;
	float distance(const Vec2& b) const;
	float dot(const Vec2& b) const;
	Vec2 clamp(const float min, const float max);
	float x() const;
	float y() const;
	void x(const float f);
	void y(const float f);

private:
	float m_X;
	float m_Y;
};


inline Vec2 operator*(float f, const Vec2& b)
{
	return Vec2(b.x() * f, b.y() * f);
}

