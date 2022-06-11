#pragma once
#include "precomp.h"
#include "plane.h"

//Constructor
Plane::Plane() :
	Primitive(Vec3(0.0f, 1.0f, 0.0f), 0.0f, Vec3(1.0f, 1.0f, 1.0f), 0.0f, false)
{}

//Destructor
Plane::~Plane()
{}

//Constructor with parameters
Plane::Plane(Vec3 normal, float distance, Vec3 color, float specular, bool glass) :
	Primitive(normal, distance, color, specular, glass)
{}

//Intersection check
float Plane::Intersection(const Vec3& origin, const Vec3& direction) const
{
	//Intersection formula from Jacco's slides
	float t = -(origin.dot(m_Vec) + m_Float) / (direction.dot(m_Vec)); //m_Vec = normal, m_Float = distance
	return t;
}

//Setter
void Plane::SetValue(const Vec3& normal, const float distance, const Color& color, const float specular, bool glass)
{
	m_Vec = normal;
	m_Float = distance;
	m_Color = color;
	m_Specularity = specular;
	m_Glass = glass;
}

//Getter
Vec3 Plane::GetVec() const
{
	return m_Vec; //Normal
}

//Getter
float Plane::GetFloat() const
{
	return m_Float; //Distance
}

//Getter
Color Plane::GetColor() const
{
	return m_Color;
}

//Getter
float Plane::GetSpecular() const
{
	return m_Specularity;
}

//Getter
bool Plane::GetGlass() const
{
	return m_Glass;
}