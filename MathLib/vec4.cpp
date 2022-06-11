#pragma once
#include "precomp.h"

Vec4::Vec4() :
	m_X(0.0f),
	m_Y(0.0f),
	m_Z(0.0f),
	m_W(0.0f)
{}

Vec4::Vec4(float x, float y, float z, float w) :
	m_X(x),
	m_Y(y),
	m_Z(z),
	m_W(w)
{}

Vec4::Vec4(float u) :
	m_X(u),
	m_Y(u),
	m_Z(u),
	m_W(u)
{}

Vec4::Vec4(const Vec4& b)
{
	m_X = b.m_X;
	m_Y = b.m_Y;
	m_Z = b.m_Z;
	m_W = b.m_W;
}

Vec4 Vec4::operator+(const Vec4& b) const
{
	return Vec4((m_X + b.m_X), (m_Y + b.m_Y), (m_Z + b.m_Z), (m_W + b.m_W));
}

Vec4 Vec4::operator-(const Vec4& b) const
{
	return Vec4((m_X + (-b.m_X)), (m_Y + (-b.m_Y)), (m_Z + (-b.m_Z)), (m_W + (-b.m_W)));
}

Vec4 Vec4::operator*(const Vec4& b) const
{
	return Vec4((m_X * b.m_X), (m_Y * b.m_Y), (m_Z * b.m_Z), (m_W * b.m_W));
}

Vec4 Vec4::operator*(const float b) const
{
	return Vec4((m_X * b), (m_Y * b), (m_Z * b), (m_W * b));
}

Vec4 Vec4::operator/(const Vec4& b) const
{
	if (b.x() == 0.0f || b.y() == 0.0f || b.z() == 0.0f || b.w() == 0.0f)
		return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
	else
		return Vec4((m_X / b.m_X), (m_Y / b.m_Y), (m_Z / b.m_Z), (m_W / b.m_W));
}

Vec4 Vec4::operator/(const float b) const
{
	if (b == 0.0f)
		return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
	else
		return Vec4((m_X / b), (m_Y / b), (m_Z / b), (m_W / b));
}

void Vec4::operator+=(const Vec4& b)
{
	m_X += b.m_X;
	m_Y += b.m_Y;
	m_Z += b.m_Z;
	m_W += b.m_W;
}

void Vec4::operator-=(const Vec4& b)
{
	m_X += -b.m_X;
	m_Y += -b.m_Y;
	m_Z += -b.m_Z;
	m_W += -b.m_W;
}

void Vec4::operator*=(const Vec4& b)
{
	m_X *= b.m_X;
	m_Y *= b.m_Y;
	m_Z *= b.m_Z;
	m_W *= b.m_W;
}

void Vec4::operator*=(const float b)
{
	m_X *= b;
	m_Y *= b;
	m_Z *= b;
	m_W *= b;
}

void Vec4::operator/=(const Vec4& b)
{
	if (b.x() == 0.0f || b.y() == 0.0f || b.z() == 0.0f || b.w() == 0.0f)
	{
		m_X = 0.0f;
		m_Y = 0.0f;
		m_Z = 0.0f;
		m_W = 0.0f;
	}
	else
	{
		m_X /= b.m_X;
		m_Y /= b.m_Y;
		m_Z /= b.m_Z;
		m_W /= b.m_W;
	}
}

bool Vec4::operator==(const Vec4& b) const
{
	if (m_X == b.m_X && m_Y == b.m_Y && m_Z == b.m_Z && m_W == b.m_W)
		return true;
	else
		return false;
}

bool Vec4::operator!=(const Vec4& b) const
{
	if (m_X != b.m_X || m_Y != b.m_Y || m_Z != b.m_Z || m_W != b.m_W)
		return true;
	else
		return false;
}

void Vec4::clear()
{
	m_X = 0.0f;
	m_Y = 0.0f;
	m_Z = 0.0f;
	m_W = 0.0f;
}

Vec4 Vec4::normalize()
{
	float b = length();
	if (b > 0)
	{
		m_X /= b;
		m_Y /= b;
		m_Z /= b;
		m_W /= b;
	}

	return Vec4(m_X, m_Y, m_Z, m_W);
}

float Vec4::length() const
{
	return sqrtf((m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z) + (m_W * m_W));
}

float Vec4::sqrtLength() const
{
	return (m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z) + (m_W * m_W);
}

float Vec4::distance(const Vec4& b) const
{
	float h = b.m_X - m_X;
	float i = b.m_Y - m_Y;
	float j = b.m_Z - m_Z;
	float k = b.m_W - m_W;

	return sqrtf((h * h) + (i * i) + (j * j) + (k * k));
}

float Vec4::dot(const Vec4& b) const
{
	return (m_X * b.m_X) + (m_Y * b.m_Y) + (m_Z * b.m_Z) + (m_W * b.m_W);
}

Vec4 Vec4::clamp(const float min, const float max)
{
	if (m_X < min) m_X = min;
	else if (m_X > max) m_X = max;

	if (m_Y < min) m_Y = min;
	else if (m_Y > max) m_Y = max;

	if (m_Z < min) m_Z = min;
	else if (m_Z > max) m_Z = max;

	if (m_W < min) m_W = min;
	else if (m_W > max) m_W = max;

	return Vec4(m_X, m_Y, m_Z, m_W);
}

float Vec4::x() const
{
	return m_X;
}

float Vec4::y() const
{
	return m_Y;
}

float Vec4::z() const
{
	return m_Z;
}

float Vec4::w() const
{
	return m_W;
}

void Vec4::x(const float b)
{
	m_X = b;
}

void Vec4::y(const float b)
{
	m_Y = b;
}

void Vec4::z(const float b)
{
	m_Z = b;
}

void Vec4::w(const float b)
{
	m_W = b;
}