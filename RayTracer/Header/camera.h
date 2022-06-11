#pragma once
#include "precomp.h"
#include "ray.h"

class Camera
{
public:
	Camera();
	Camera(Vec3 O, Vec3 V, float distance);
	Ray SetupRay(int x, int y, int aa, const Matrix& RotY, const Matrix& RotX, const Vec3& move);

private:
	Vec3 m_Origin;
	Vec3 m_View;
	float m_Distance;
	const float m_OffsetX[AA_RAY]{ -0.33f, 0.33f };
	const float m_OffsetY[AA_RAY]{ 0.33f, -0.33f };
	float m_ScreenWidth;
	float m_ScreenHeight;
};