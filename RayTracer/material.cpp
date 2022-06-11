#pragma once
#include "precomp.h"
#include "material.h"

//Constructor
Material::Material(Color color, float specular, bool glass) :
	m_Color(color),
	m_Specularity(specular),
	m_Glass(glass)
{}

//Destructor
Material::~Material()
{}