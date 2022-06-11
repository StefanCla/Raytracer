#pragma once
#include "precomp.h"
#include "camera.h"
#include "scene.h"
#include "SDL.h"

class Renderer {
public:
	Renderer();
	void Render(SDL_Renderer* renderer, Matrix& RotY, Matrix& RotX, Vec3& move);
	Color Trace(Vec3 origin, Vec3 direction, int glassBounce);
	Vec3 Illumination(const RayResults& container, const Vec3& direction);
	Color SkyColor(const Vec3& direction);
	bool Occluded(const Vec3& intersect);
	float FresnelEquation(float n1, float n2, float cosI);

private:
	Camera m_Camera;
	Scene m_Scene;
	Ray m_Ray;
	Ray m_ShadowRay;
	Color m_Color;
	Vec3 m_LightPos;
	Color m_LightColor;
	int m_MirrorBounce;
};
