#pragma once
#include "precomp.h"

class Ray
{
public:
	Ray();
	Ray(Vec3 O, Vec3 D);
	Ray(const Ray& ray);
	void SetOrigin(const Vec3& origin);
	void SetDirection(const Vec3& direction);
	Vec3 GetOrigin() const;
	Vec3 GetDirection() const;

private:
	Vec3 m_Origin;
	Vec3 m_Direction;
};
