#pragma once
#include "precomp.h"
#include "BVHNode.h"
#include "objects.h"

class BVH
{
public:
	BVH();
	~BVH();
	void ConstructBVH(Primitive* primitive, unsigned int size);
	BVHNode* GetRoot();

private:
	unsigned int* m_Indices;
	BVHNode* m_Pool;
	BVHNode* m_Root;
	int m_PoolPtr;
};
