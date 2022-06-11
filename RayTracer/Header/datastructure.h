#pragma once
#include "precomp.h"

struct RayResults {
	Vec3 intersect = Vec3(0.0f, 0.0f, 0.0f); //Instersection position
	Vec3 normal = Vec3(0.0f, 0.0f, 0.0f); //Normal of the object
	float distance = INFINITY; //T value of the ray

	//Material values
	Color color = Vec3(0.0f, 0.0f, 0.0f); 
	float specular = 0.0f;
	bool glass = false;
};