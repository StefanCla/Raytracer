#pragma once
#include "precomp.h"
#include "BVH.h"

//This BVH structure was heavily inspired by Jacco's pseudo code

//default constructor
BVH::BVH() :
	m_Indices(nullptr),
	m_Pool(nullptr),
	m_Root(nullptr),
	m_PoolPtr(2)
{}

//Destructor
BVH::~BVH()
{
	delete[] m_Indices;
	delete[] m_Pool;
}

//Initialize the BVH with the actual values
void BVH::ConstructBVH(Primitive* primitive, unsigned int size)
{
	m_Indices = new unsigned int[size];
	for (int i = 0; i < static_cast<int>(size); i++) m_Indices[i] = i;

	int nodeSize = size * 2 - 1;
	m_Pool = new BVHNode[nodeSize];
	m_Root = &m_Pool[0];
	m_PoolPtr = 2;

	m_Root->SetFirst(0);
	m_Root->SetCount(size);
	m_Root->SetIndices(m_Indices);
	m_Root->CalcAABB(primitive);
	m_Root->Subdivide(primitive, m_Pool, &m_PoolPtr);
}

//Getter
BVHNode* BVH::GetRoot()
{
	return m_Root;
}