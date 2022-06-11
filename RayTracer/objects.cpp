#pragma once
#include "precomp.h"
#include "objects.h"

//Constructor
Primitive::Primitive() :
	m_Vec(Vec3(0.0f, 0.0f, 0.0f)),
	m_Float(0.0f),
	Material()
{}

//Constructor with parameter
Primitive::Primitive(Vec3 center, float point, Color color, float specular, bool glass) :
	Material(color, specular, glass),
	m_Vec(center),
	m_Float(point)
{}

//Destructor
Primitive::~Primitive()
{}
