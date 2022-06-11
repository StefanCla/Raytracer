#pragma once
#include "precomp.h"

Vec3::Vec3() :
	m_X(0.0f),
	m_Y(0.0f),
	m_Z(0.0f)
{}

Vec3::Vec3(float x, float y, float z) :
	m_X(x),
	m_Y(y),
	m_Z(z)
{}

Vec3::Vec3(float f) :
	m_X(f),
	m_Y(f),
	m_Z(f)
{}

Vec3::Vec3(const Vec3& b)
{
	m_X = b.m_X;
	m_Y = b.m_Y;
	m_Z = b.m_Z;
}

void Vec3::clear()
{
	m_X = 0.0f;
	m_Y = 0.0f;
	m_Z = 0.0f;
}

Vec3 Vec3::operator+(const Vec3& b) const
{
	return Vec3(m_X + b.m_X, m_Y + b.m_Y, m_Z + b.m_Z);
}

Vec3 Vec3::operator-(const Vec3& b) const
{
	return Vec3(m_X + (-b.m_X), m_Y + (-b.m_Y), m_Z + (-b.m_Z));
}

Vec3 Vec3::operator*(const Vec3& b) const
{
	return Vec3((m_X * b.m_X), (m_Y * b.m_Y), (m_Z * b.m_Z));
}

Vec3 Vec3::operator*(const float f) const
{
	return Vec3(m_X * f, m_Y * f, m_Z * f);
}

Vec3 Vec3::operator/(const float f) const
{
	if (f == 0.0f)
		return Vec3(0.0f, 0.0f, 0.0f);
	else
		return Vec3(m_X / f, m_Y / f, m_Z / f);
}

Vec3 Vec3::operator/(const Vec3& b) const
{
	if (b.x() == 0.0f || b.y() == 0.0f || b.z() == 0.0f)
		return Vec3(0.0f, 0.0f, 0.0f);
	else
		return Vec3(m_X / b.m_X, m_Y / b.m_Y, m_Z / b.m_Z);
}

void Vec3::operator+=(const Vec3& b)
{
	m_X += b.m_X;
	m_Y += b.m_Y;
	m_Z += b.m_Z;
}

void Vec3::operator-=(const Vec3& b)
{
	m_X -= b.m_X;
	m_Y -= b.m_Y;
	m_Z -= b.m_Z;
}

void Vec3::operator*=(const Vec3& b)
{
	m_X *= b.m_X;
	m_Y *= b.m_Y;
	m_Z *= b.m_Z;
}

void Vec3::operator*=(const float f)
{
	m_X *= f;
	m_Y *= f;
	m_Z *= f;
}

void Vec3::operator/=(const Vec3& b)
{
	if (b.x() == 0.0f || b.y() == 0.0f || b.z() == 0.0f)
	{
		m_X = 0.0f;
		m_Y = 0.0f;
		m_Z = 0.0f;
	}
	else
	{
		m_X /= b.m_X;
		m_Y /= b.m_Y;
		m_Z /= b.m_Z;
	}
}

bool Vec3::operator==(const Vec3& b) const
{
	if (m_X == b.m_X && m_Y == b.m_Y && m_Z == b.m_Z)
		return true;
	else
		return false;
}

bool Vec3::operator!=(const Vec3& b) const
{
	if (m_X != b.m_X || m_Y != b.m_Y || m_Z != b.m_Z)
		return true;
	else
		return false;
}

Vec3 Vec3::normalize()
{
	float f = length();
	if (f > 0)
	{
		f = 1 / f;
		m_X *= f;
		m_Y *= f;
		m_Z *= f;
	}

	return Vec3(m_X, m_Y, m_Z);
}

float Vec3::length() const
{
	return sqrtf((m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z));
}

float Vec3::sqrtLength() const
{
	return (m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z);
}

float Vec3::distance(const Vec3& b) const
{
	Vec3 B = b - (*this);

	return B.length();
}

float Vec3::dot(const Vec3& b) const
{
	return (m_X * b.m_X) + (m_Y * b.m_Y) + (m_Z * b.m_Z);
}

Vec3 Vec3::cross(Vec3 b)
{
	if (m_X == 0.0f && m_Y == 0.0f && m_Z == 0.0f || b.m_X == 0.0f && b.m_Y == 0.0f && b.m_Z == 0.0f) //Length is zero. 
		return Vec3(0.0f, 0.0f, 0.0f);

	//Thanks to Wessel Frijters for the idea of using dot product
	Vec3 A = (*this);
	Vec3 B = b;

	normalize();
	b.normalize();

	float dot = (*this).dot(b);

	if( dot == -1.0f)
		return Vec3(0.0f, 0.0f, 0.0f); //Both point away
	else if(dot == 1.0f)
		return Vec3(0.0f, 0.0f, 0.0f); //Both point same direction

	float x = A.m_Y * B.m_Z - A.m_Z * B.m_Y;
	float y = A.m_Z * B.m_X - A.m_X * B.m_Z;
	float z = A.m_X * B.m_Y - A.m_Y * B.m_X;

	return Vec3(x, y, z);
}

Vec3 Vec3::clamp(const float min, const float max)
{
	if (m_X < min) m_X = min;
	else if (m_X > max) m_X = max;

	if (m_Y < min) m_Y = min;
	else if (m_Y > max) m_Y = max;

	if (m_Z < min) m_Z = min;
	else if (m_Z > max) m_Z = max;

	return Vec3(m_X, m_Y, m_Z);
}

float Vec3::x() const
{
	return m_X;
}

float Vec3::y() const
{
	return m_Y;
}

float Vec3::z() const
{
	return m_Z;
}

void Vec3::x(const float f)
{
	m_X = f;
}

void Vec3::y(const float f)
{
	m_Y = f;
}

void Vec3::z(const float f)
{
	m_Z = f;
}