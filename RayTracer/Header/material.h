#pragma once
#include "precomp.h"

class Material
{
public:
	Material(Color color = Color(1.0f, 1.0f, 1.0f), float specular = 0.0f, bool glass = false);
	virtual ~Material();

protected:
	Color m_Color;
	float m_Specularity;
	bool m_Glass;
};