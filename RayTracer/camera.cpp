#pragma once
#include "precomp.h"
#include "camera.h"

//Constructor
Camera::Camera() :
	m_Origin(Vec3(0.0f, 2.0f, 0.0f)),
	m_View(Vec3(0.0f, 0.0f, 1.0f)),
	m_Distance(1.0f),
	m_ScreenWidth(1.0f / SCREENWIDTH), //Thanks to Dragos for pointing out that 1 needed to be a float instead of int
	m_ScreenHeight(1.0f / SCREENHEIGHT)
{}

//Constructor with parameters
Camera::Camera(Vec3 O, Vec3 V, float direction) :
	m_Origin(O),
	m_View(V),
	m_Distance(direction),
	m_ScreenWidth(1.0f / SCREENWIDTH),
	m_ScreenHeight(1.0f / SCREENHEIGHT)
{}

//Create rays
Ray Camera::SetupRay(int x, int y, int aa, const Matrix& RotY, const Matrix& RotX, const Vec3& move)
{
	//Thanks to Wessel Frijters, Dragos Popescu & Phil de Groot
	//for helping me create the moving camera, since i had no knowledge & prior experience before this
	Matrix empty;

	Vec3 view = RotY * RotX * m_View;
	Vec3 origin = empty.Translation(move, m_Origin);

	Vec3 center = origin + m_Distance * view;

	Vec3 P0(-1.0f, 1.0f, 0.0f);
	Vec3 P1(1.0f, 1.0f, 0.0f);
	Vec3 P2(-1.0f, -1.0f, 0.0f);

	P0 = RotY * RotX * P0;
	P1 = RotY * RotX * P1;
	P2 = RotY * RotX * P2;

	Vec3 topLeft = center + P0;
	Vec3 topRight = center + P1;
	Vec3 bottomLeft = center + P2;


	float u = (static_cast<float>(x) + m_OffsetX[aa]) * m_ScreenWidth;
	float v = (static_cast<float>(y) + m_OffsetY[aa]) * m_ScreenHeight; 

	Vec3 position = (topLeft + u * (topRight - topLeft) + v * (bottomLeft - topLeft) - origin).normalize();

	return Ray(origin, position);
}