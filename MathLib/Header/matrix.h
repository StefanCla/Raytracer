#pragma once
#include "precomp.h"

class Matrix
{
public:
	Matrix();
	Matrix(float n1, float n2, float n3, float n4, float n5, float n6, float n7, float n8, float n9);
	Matrix(const Matrix& B);
	Matrix operator+ (const Matrix& b) const;
	Matrix operator- (const Matrix& b) const;
	Matrix operator* (const float b) const;
	Matrix operator* (const Matrix& b) const;
	Vec3 operator* (const Vec3& b) const;
	void Set(float a, float b, float c, float d, float e, float f, float g, float h, float j);
	void Clear();
	void Identity();
	void Scale(const Vec3& S);
	Vec3 Translation(const Vec3& T, const Vec3& b) const;
	void Transpose();
	void RotateX(const float rad);
	void RotateY(const float rad);
	void RotateZ(const float rad);
	Matrix Orthonormalization();
	float m_Matrix[9]; //Row Major
};

//Vector left side of the equation
inline Vec3 operator*(const Vec3& b, const Matrix& c)
{
	Vec3 returnVec3;
	
	returnVec3.x(b.x() * c.m_Matrix[0] + b.y() * c.m_Matrix[3] + b.z() * c.m_Matrix[6]);
	returnVec3.y(b.x() * c.m_Matrix[1] + b.y() * c.m_Matrix[4] + b.z() * c.m_Matrix[7]);
	returnVec3.z(b.x() * c.m_Matrix[2] + b.y() * c.m_Matrix[5] + b.z() * c.m_Matrix[8]);

	return returnVec3;
}
