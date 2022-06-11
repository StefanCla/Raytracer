#pragma once
#include "precomp.h"
#include "BVHNode.h"

float min(float a, float b);
float max(float a, float b);

//This BVH structure was heavily inspired by Jacco's pseudo code

//default constructor
BVHNode::BVHNode() :
	m_Bounds(AABB()),
	m_isLeaf(true),
	m_Left(nullptr),
	m_Right(nullptr),
	m_First(0),
	m_Count(1),
	m_Indices(nullptr)
{}

//constructor with parameters
BVHNode::BVHNode(AABB bounds, BVHNode* left, BVHNode* right, int first, int count, unsigned int* indices, bool isLeaf) :
	m_Bounds(bounds),
	m_isLeaf(isLeaf),
	m_Left(left),
	m_Right(right),
	m_First(first),
	m_Indices(indices),
	m_Count(count)
{}

//Divide the nodes
void BVHNode::Subdivide(Primitive* primitive, BVHNode* node, int* poolPtr)
{
	if (m_Count < 3) return;
	m_Left = &node[(*poolPtr)++];
	m_Right = &node[(*poolPtr)++];
	Partition(primitive);
	m_Left->Subdivide(primitive, node, poolPtr);
	m_Right->Subdivide(primitive, node, poolPtr);
	m_isLeaf = false;
}

//Split the nodes across one axes
void BVHNode::Partition(Primitive* primitive)
{
	float lengthX = m_Bounds.max.x() - m_Bounds.min.x();
	float lengthY = m_Bounds.max.y() - m_Bounds.min.y();
	float lengthZ = m_Bounds.max.z() - m_Bounds.min.z();

	if (lengthX >= lengthY && lengthX >= lengthZ) //X
	{
		Sort((m_Bounds.min.x() + (lengthX * 0.5f)), primitive, 0);
	}
	else if (lengthY >= lengthX && lengthY >= lengthZ) //Y
	{
		Sort((m_Bounds.min.y() + (lengthY * 0.5f)), primitive, 1);
	}
	else if (lengthZ >= lengthX && lengthZ >= lengthY) //Z
	{
		Sort((m_Bounds.min.z() + (lengthZ * 0.5f)), primitive, 2);
	}

	//Recalculate bounds with split
	m_Left->CalcAABB(primitive);
	m_Right->CalcAABB(primitive);
}

//Sort the node array according to the axes it splits on
void BVHNode::Sort(float split, Primitive* primitive, int axes)
{
	int b = 0;
	unsigned int hold;
	int j = 0;

	if (axes == 0) //X axes
	{
		for (int i = m_First; i < (m_First + m_Count); i++)
		{

			if (primitive[m_Indices[i]].GetVec().x() <= split)
			{
				b++;
			}
			else
			{
				j = i + 1;
				if (j >= (m_First + m_Count))
					break;

				for (j; j < (m_First + m_Count); j++)
				{
					if (primitive[m_Indices[j]].GetVec().x() <= split)
					{
						b++;
						hold = m_Indices[i];
						m_Indices[i] = m_Indices[j];
						m_Indices[j] = hold;
						break;
					}
				}

				if (j >= (m_First + m_Count) - 1)
					break; //We know there arent any items left that are under the split
			}
		}

		m_Left->m_First = m_First;
		m_Left->m_Count = b;
		if (b == m_Count)
		{
			m_Right->m_First = 0;
			m_Right->m_Count = 0;
		}
		else
		{
			m_Right->m_First = b + m_First;
			m_Right->m_Count = m_Count - b;
		}

		m_Left->m_Indices = m_Indices;
		m_Right->m_Indices = m_Indices;
	}
	else if (axes == 1) //Y axes
	{
		for (int i = m_First; i < (m_First + m_Count); i++)
		{

			if (primitive[m_Indices[i]].GetVec().y() <= split)
			{
				b++;
			}
			else
			{
				j = i + 1;
				if (j >= (m_First + m_Count))
					break;

				for (j = i + 1; j < (m_First + m_Count); j++)
				{
					if (primitive[m_Indices[j]].GetVec().y() <= split)
					{
						b++;
						hold = m_Indices[i];
						m_Indices[i] = m_Indices[j];
						m_Indices[j] = hold;
						break;
					}
				}

				if (j >= (m_First + m_Count) - 1)
					break; //We know there arent any items left that are under the split
			}
		}

		m_Left->m_First = m_First;
		m_Left->m_Count = b;
		if (b == m_Count)
		{
			m_Right->m_First = 0;
			m_Right->m_Count = 0;
		}
		else
		{
			m_Right->m_First = b + m_First;
			m_Right->m_Count = m_Count - b;
		}

		m_Left->m_Indices = m_Indices;
		m_Right->m_Indices = m_Indices;
	}
	else if (axes == 2) //Z axes
	{
		for (int i = m_First; i < (m_First + m_Count); i++)
		{

			if (primitive[m_Indices[i]].GetVec().z() <= split)
			{
				b++;
			}
			else
			{
				j = i + 1;
				if (j >= (m_First + m_Count))
					break;

				for (j = i + 1; j < (m_First + m_Count); j++)
				{
					if (primitive[m_Indices[j]].GetVec().z() <= split)
					{
						b++;
						hold = m_Indices[i];
						m_Indices[i] = m_Indices[j];
						m_Indices[j] = hold;
						break;
					}
				}

				if (j >= (m_First + m_Count) - 1)
					break; //We know there arent any items left that are under the split
			}
		}

		m_Left->m_First = m_First;
		m_Left->m_Count = b;
		if (b == m_Count)
		{
			m_Right->m_First = 0;
			m_Right->m_Count = 0;
		}
		else
		{
			m_Right->m_First = b + m_First;
			m_Right->m_Count = m_Count - b;
		}

		m_Left->m_Indices = m_Indices;
		m_Right->m_Indices = m_Indices;
	}
}

//Calculate the max and min value of each primitive
void BVHNode::CalcAABB(Primitive* primitive)
{
	Vec3 Min = primitive[m_Indices[m_First]].GetVec();
	Vec3 Max = primitive[m_Indices[m_First]].GetVec();

	for (int i = m_First; i < (m_First + m_Count); i++)
	{
		//Min
		if (Min.x() >= (primitive[m_Indices[i]].GetVec().x() - primitive[m_Indices[i]].GetFloat()))
			Min.x((primitive[m_Indices[i]].GetVec().x() - primitive[m_Indices[i]].GetFloat()));
		if (Min.y() >= (primitive[m_Indices[i]].GetVec().y() - primitive[m_Indices[i]].GetFloat()))
			Min.y((primitive[m_Indices[i]].GetVec().y() - primitive[m_Indices[i]].GetFloat()));
		if (Min.z() >= (primitive[m_Indices[i]].GetVec().z() - primitive[m_Indices[i]].GetFloat()))
			Min.z((primitive[m_Indices[i]].GetVec().z() - primitive[m_Indices[i]].GetFloat()));

		//Max
		if (Max.x() <= (primitive[m_Indices[i]].GetVec().x() + primitive[m_Indices[i]].GetFloat()))
			Max.x((primitive[m_Indices[i]].GetVec().x() + primitive[m_Indices[i]].GetFloat()));
		if (Max.y() <= (primitive[m_Indices[i]].GetVec().y() + primitive[m_Indices[i]].GetFloat()))
			Max.y((primitive[m_Indices[i]].GetVec().y() + primitive[m_Indices[i]].GetFloat()));
		if (Max.z() <= (primitive[m_Indices[i]].GetVec().z() + primitive[m_Indices[i]].GetFloat()))
			Max.z((primitive[m_Indices[i]].GetVec().z() + primitive[m_Indices[i]].GetFloat()));
	}

	m_Bounds.min = Min;
	m_Bounds.max = Max;
}

//Traverse the nodes to check for intersection
RayResults BVHNode::Traverse(Primitive* primitive, const Vec3& origin, const Vec3& direction)
{
	if (!Intersect(origin, direction))
	{
		return RayResults();
	}

	if (m_isLeaf)
	{
		RayResults container;
		container.distance = INFINITY;
		for (int i = m_First; i < (m_First + m_Count); i++)
		{
			//primitive intersect
			float distance = primitive[m_Indices[i]].Intersection(origin, direction);

			if (distance < container.distance)
			{
				container.distance = distance;
				container.intersect = origin + container.distance * direction;
				container.color = primitive[m_Indices[i]].GetColor();
				container.specular = primitive[m_Indices[i]].GetSpecular();
				container.glass = primitive[m_Indices[i]].GetGlass();
				container.normal = (container.intersect - primitive[m_Indices[i]].GetVec()).normalize();
			}
		}

		return container;
	}
	else
	{
		RayResults one = m_Left->Traverse(primitive, origin, direction);
		RayResults two = m_Right->Traverse(primitive, origin, direction);

		if (one.distance < two.distance)
			return one;
		else
			return two;
	}
}

//Intersect with AABB
float BVHNode::Intersect(const Vec3& origin, const Vec3& direction)
{
	float tmin = -INFINITY;
	float tmax = INFINITY;

	float tx1 = (m_Bounds.min.x() - origin.x()) / direction.x();
	float tx2 = (m_Bounds.max.x() - origin.x()) / direction.x();

	tmin = max(tmin, min(tx1, tx2));
	tmax = min(tmax, max(tx1, tx2));

	float ty1 = (m_Bounds.min.y() - origin.y()) / direction.y();
	float ty2 = (m_Bounds.max.y() - origin.y()) / direction.y();

	tmin = max(tmin, min(ty1, ty2));
	tmax = min(tmax, max(ty1, ty2));

	float tz1 = (m_Bounds.min.z() - origin.z()) / direction.z();
	float tz2 = (m_Bounds.max.z() - origin.z()) / direction.z();

	tmin = max(tmin, min(tz1, tz2));
	tmax = min(tmax, max(tz1, tz2));

	return tmax >= tmin && tmax > 0;
}

//Setter
void BVHNode::SetFirst(int first)
{
	m_First = first;
}

//Setter
void BVHNode::SetCount(int count)
{
	m_Count = count;
}

//Setter
void BVHNode::SetIndices(unsigned int* indices)
{
	m_Indices = indices;
}

//Function, find min value
float min(float a, float b)
{
	if (a > b) return b;
	else return a;
}

//Function, find max value
float max(float a, float b)
{
	if (a < b) return b;
	else return a;
}
