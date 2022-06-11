#pragma once
#include "precomp.h"
#include "ray.h"
#include "objects.h"
#include "plane.h"
#include "sphere.h"
#include "BVH.h"

class Scene
{
public:
	Scene();
	~Scene();
	RayResults RayIntersection(const Vec3& origin, const Vec3& direction);

private:
	RayResults m_Container;
	Primitive* m_PrimArray;
	float m_Hold; //Variable that holds values temporarely 
	BVH* m_Root;
	Plane m_Plane;
};