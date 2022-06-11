#pragma once
#include "precomp.h"
#include "AABB.h"
#include "objects.h"

class BVHNode
{
public:
	BVHNode();
	BVHNode(AABB bounds, BVHNode* left, BVHNode* right, int first, int count, unsigned int* indices, bool isLeaf = true);
	void Subdivide(Primitive* primitive, BVHNode* node, int* poolPtr);
	void Partition(Primitive* primitive);
	void Sort(float split, Primitive* primitive, int axes);
	void CalcAABB(Primitive* primitive);
	RayResults Traverse(Primitive* primitive,  const Vec3& origin, const Vec3& direction);
	float Intersect(const Vec3& origin, const Vec3& direction);
	void SetFirst(int first);
	void SetCount(int count);
	void SetIndices(unsigned int* indices);
		
private:
	AABB m_Bounds;
	bool m_isLeaf;
	BVHNode* m_Left;
	BVHNode* m_Right;
	int m_First;
	int m_Count;
	unsigned int* m_Indices;
};