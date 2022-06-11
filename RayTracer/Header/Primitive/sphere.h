#pragma once
#include "precomp.h"
#include "objects.h"

class Sphere : public Primitive
{
public:
	Sphere();
	Sphere(Vec3 center, float radius, Color color, float specular, bool glass);
	~Sphere();
	float Intersection(const Vec3& origin, const Vec3& direction) const;
	void SetValue(const Vec3& center, const float radius = 1.0f, const Color& color = Color(1.0f, 1.0f, 1.0f), const float specular = 0.0f, bool glass = false);
	Vec3 GetVec() const; //Returns center
	float GetFloat() const; //Returns radius
	Color GetColor() const;
	float GetSpecular() const;
	bool GetGlass() const;

};
