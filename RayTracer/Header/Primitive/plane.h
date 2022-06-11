#pragma once
#include "precomp.h"
#include "objects.h"

class Plane : public Primitive
{
public:
	Plane();
	Plane(Vec3 normal, float distance, Color color, float specular, bool glass);
	~Plane();
	float Intersection(const Vec3& origin, const Vec3& direction) const;
	void SetValue(const Vec3& normal, const float distance = 1.0f, const Color& color = Color(1.0f, 1.0f, 1.0f), const float specular = 0.0f, bool glass = false);
	Vec3 GetVec() const; //Return normal
	float GetFloat() const; //Return distance;
	Color GetColor() const;
	float GetSpecular() const;
	bool GetGlass() const;
	
};