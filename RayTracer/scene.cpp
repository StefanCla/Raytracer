#pragma once
#include "precomp.h"
#include "scene.h"

//Constructor
Scene::Scene() :
	m_Hold(0.0f),
	m_Container(RayResults())
{
	m_Plane.SetValue(Vec3(0.0f, 1.0f, 0.0f), 0.0f, Color(1.0f, 1.0f, 1.0f), 0.0f, false);

	int size = 6;
	m_PrimArray = new Sphere[size];

	m_PrimArray[0].SetValue(Vec3(2.0f, 1.5f, 5.0f), 1.0f, Color(1.0f, 1.0f, 1.0f), 0.0f, true);
	m_PrimArray[1].SetValue(Vec3(-2.0f, 1.5f, 5.0f), 1.0f, Color(1.0f, 1.0f, 0.0f), 1.0f, false);
	m_PrimArray[2].SetValue(Vec3(4.0f, 1.5f, 10.0f), 1.0f, Color(1.0f, 0.0f, 1.0f), 0.0f, false);
	m_PrimArray[3].SetValue(Vec3(-2.0f, 5.0f, 5.0f), 1.0f, Color(0.0f, 0.5f, 0.0f), 0.5f, false);
	m_PrimArray[4].SetValue(Vec3(0.0f, 3.0f, 5.0f), 1.0f, Color(1.0f, 0.0f, 0.0f), 0.0f, true);
	m_PrimArray[5].SetValue(Vec3(0.0f, 1.0f, 5.0f), 0.2f, Color(1.0f, 0.0f, 0.0f), 0.0f, true);

	m_Root = new BVH();
	m_Root->ConstructBVH(m_PrimArray, size);
}

//Destructor
Scene::~Scene()
{
	delete[] m_PrimArray;
	delete m_Root;
}

//Check scene for intersections
RayResults Scene::RayIntersection(const Vec3& origin, const Vec3& direction)
{
	float planeDistance = INFINITY;

	m_Container = m_Root->GetRoot()->Traverse(m_PrimArray, origin, direction);

	//Could loop through multiple planes here, but we only have one
	m_Hold = m_Plane.Intersection(origin, direction);

	if (m_Hold > 0.0f && m_Hold < m_Container.distance)
	{
		m_Container.distance = m_Hold;
		planeDistance = m_Hold;
	}

	if (m_Container.distance == INFINITY) //Ray misses
	{
		m_Container.specular = 0.0f;
		m_Container.glass = false;
		return m_Container;
	}

	if (m_Container.distance == planeDistance) //Plane has been hit
	{
		m_Container.specular = m_Plane.GetSpecular();
		m_Container.intersect = origin + m_Container.distance * direction;
		m_Container.glass = m_Plane.GetGlass();

		//Checkerboard pattern, with thanks to Weesel Frijters
		int num = static_cast<int>(m_Container.intersect.x()) + static_cast<int>(m_Container.intersect.z());

		if (m_Container.intersect.x() < 0)
		{
			if (num % 2 == 0)
			{
				m_Container.color = Vec3(0.1f, 0.1f, 0.1f);
			}
			else
			{
				m_Container.color = Vec3(1.0f, 1.0f, 1.0f);
			}
		}
		else
		{
			if (num % 2 == 0)
			{
				m_Container.color = Vec3(1.0f, 1.0f, 1.0f);
			}
			else
			{
				m_Container.color = Vec3(0.1f, 0.1f, 0.1f);
			}
		}

		m_Container.normal = m_Plane.GetVec();
	}

	return m_Container;
}