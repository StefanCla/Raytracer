#pragma once
#include "precomp.h"
#include "ray.h"
#include "material.h"

class Primitive : public Material
{
public:
	Primitive();
	Primitive(Vec3 center, float point, Color color, float specular, bool glass);
	virtual ~Primitive();
	virtual float Intersection(const Vec3& origin, const Vec3& direction) const = 0;
	virtual void SetValue(const Vec3& center, const float point = 1.0f, const Color& color = Color(1.0f, 1.0f, 1.0f), const float specular = 0.0f, bool glass = false) = 0;
	virtual Vec3 GetVec() const = 0; //Returns center for sphere, normal for plane
	virtual float GetFloat() const = 0; //Returns radius for sphere, distance for plane;
	virtual Color GetColor() const = 0; 
	virtual float GetSpecular() const = 0;
	virtual bool GetGlass() const = 0;

protected:
	Vec3 m_Vec;
	float m_Float;
};