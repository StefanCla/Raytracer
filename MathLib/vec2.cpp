#pragma once
#include "precomp.h"

Vec2::Vec2() :
	m_X(0.0f),
	m_Y(0.0f)
{}

Vec2::Vec2(float x, float y) :
	m_X(x),
	m_Y(y)
{}

Vec2::Vec2(float f) :
	m_X(f),
	m_Y(f)
{}

Vec2::Vec2(const Vec2& b)
{
	m_X = b.m_X;
	m_Y = b.m_Y;
}

void Vec2::clear()
{
	m_X = 0.0f;
	m_Y = 0.0f;
}

Vec2 Vec2::normalize()
{
	float f = length();
	if (f > 0)
	{
		float inv = 1 / f;
		m_X *= inv;
		m_Y *= inv;
	}

	return Vec2(m_X, m_Y);
}

float Vec2::length() const
{
	return sqrtf((m_X * m_X) + (m_Y * m_Y));
}

float Vec2::sqrtLength() const
{
	return (m_X * m_X) + (m_Y * m_Y);
}

float Vec2::distance(const Vec2& b) const
{
	float v = b.m_X - m_X;
	float u = b.m_Y - m_Y;
	return sqrtf((v * v) + (u * u));
}

float Vec2::dot(const Vec2& b) const
{
	return (m_X * b.m_X + m_Y * b.m_Y);
}

Vec2 Vec2::clamp(const float min, const float max)
{
	if (m_X < min) m_X = min;
	else if (m_X > max) m_X = max;

	if (m_Y < min) m_Y = min;
	else if (m_Y > max) m_Y = max;

	return Vec2(m_X, m_Y);
}

Vec2 Vec2::operator+(const Vec2& b) const
{
	return Vec2(m_X + b.m_X, m_Y + b.m_Y);
}

Vec2 Vec2::operator-(const Vec2& b) const
{
	return Vec2(m_X + (-b.m_X), m_Y + (-b.m_Y));
}

float Vec2::operator*(const Vec2& b) const
{
	return (m_X * b.m_X + m_Y * b.m_Y);
}

Vec2 Vec2::operator*(const float f) const
{
	return Vec2(m_X * f, m_Y * f);
}

Vec2 Vec2::operator/(const Vec2& b) const
{
	if (b.m_X == 0.0f || b.m_Y == 0.0f)
		return Vec2(0.0f, 0.0f);
	else
		return Vec2((m_X / b.m_X), (m_Y / b.m_Y));
}

Vec2 Vec2::operator/(const float f) const
{
	if (f == 0.0f)
		return Vec2(0.0f, 0.0f);
	else
		return Vec2(m_X / f, m_Y / f);
}


void Vec2::operator+=(const Vec2& b)
{
	m_X += b.m_X;
	m_Y += b.m_Y;
}

void Vec2::operator-=(const Vec2& b)
{
	m_X -= b.m_X;
	m_Y -= b.m_Y;
}

void Vec2::operator*=(const Vec2& b)
{
	m_X *= b.m_X;
	m_Y *= b.m_Y;
}

void Vec2::operator*=(const float f)
{
	m_X *= f;
	m_Y *= f;
}

void Vec2::operator/=(const Vec2& b)
{
	if (b.x() == 0.0f || b.y() == 0.0f)
	{
		m_X = 0.0f;
		m_Y = 0.0f;
	}
	else
	{
		m_X /= b.m_X;
		m_Y /= b.m_Y;
	}
}

bool Vec2::operator==(const Vec2& b) const
{
	if (m_X == b.m_X && m_Y == b.m_Y)
		return true;
	else
		return false;
}

bool Vec2::operator!=(const Vec2& b) const
{
	if (m_X != b.m_X || m_Y != m_Y)
		return true;
	else
		return false;
}

float Vec2::x() const
{
	return m_X;
}

float Vec2::y() const
{
	return m_Y;
}

void Vec2::x(const float f)
{
	m_X = f;
}

void Vec2::y(const float f)
{
	m_Y = f;
}
