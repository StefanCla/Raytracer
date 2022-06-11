#pragma once
#include "precomp.h"
#include "ray.h"

//Constructor
Ray::Ray() :
	m_Origin(Vec3(0.0f, 0.0f, 0.0f)),
	m_Direction(Vec3(0.0f, 0.0f, 0.0f))
{}

//Constructor with parameters
Ray::Ray(Vec3 O, Vec3 D) :
	m_Origin(O),
	m_Direction(D)
{}

//Copy constructor
Ray::Ray(const Ray& ray)
{
	m_Origin = ray.m_Origin;
	m_Direction = ray.m_Direction;
}

//Setter
void Ray::SetOrigin(const Vec3& origin)
{
	m_Origin = origin;
}

//Setter
void Ray::SetDirection(const Vec3& direction)
{
	m_Direction = direction;
}

//Getter
Vec3 Ray::GetOrigin() const
{
	return m_Origin;
}

//Getter
Vec3 Ray::GetDirection() const
{
	return m_Direction;
}