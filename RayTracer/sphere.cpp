#pragma once
#include "precomp.h"
#include "sphere.h"

//Constructor
Sphere::Sphere() :
	Primitive(Vec3(-2.0f, 1.5f, 5.0f), 1.0f, Color(1.0f, 1.0f, 1.0f), 1.0f, false)
{}

//Constructor with parameters
Sphere::Sphere(Vec3 center, float radius, Color color, float specular, bool glass) :
	Primitive(center, radius, color, specular, glass)
{}

//Destructor
Sphere::~Sphere()
{}

//Intersection check
float Sphere::Intersection(const Vec3& origin, const Vec3& direction) const
{
	//Sphere intersection Jaccos slides.
	//Not the fastest one, but acts correctly with rays inside a sphere
	float a = direction.dot(direction);
	float b = 2 * direction.dot((origin - m_Vec));
	float c = (origin - m_Vec).dot((origin - m_Vec)) - (m_Float * m_Float);

	float t0 = (-b - sqrtf((b * b) - 4 * a * c)) / (2 * a);
	float t1 = (-b + sqrtf((b * b) - 4 * a * c)) / (2 * a);

	if (t0 >= 0)
		return t0;
	if (t1 >= 0)
		return t1;

	return INFINITY;
}

//Setter
void Sphere::SetValue(const Vec3& center, const float radius, const Color& color, const float specular, bool glass)
{
	m_Vec = center;
	m_Float = radius;
	m_Color = color;
	m_Specularity = specular;
	m_Glass = glass;
}

//Getter
Vec3 Sphere::GetVec() const
{
	return m_Vec; //Center
}

//Getter
float Sphere::GetFloat() const
{
	return m_Float; //Radius
}

//Getter
Color Sphere::GetColor() const
{
	return m_Color;
}

//Getter
float Sphere::GetSpecular() const
{
	return m_Specularity;
}

//Getter
bool Sphere::GetGlass() const
{
	return m_Glass;
}