#pragma once
#include "precomp.h"

Matrix::Matrix() :
	m_Matrix{0.0f}
{}

Matrix::Matrix(float n1, float n2, float n3, float n4, float n5, float n6, float n7, float n8, float n9)
{
	m_Matrix[0] = n1;
	m_Matrix[1] = n2;
	m_Matrix[2] = n3;
	m_Matrix[3] = n4;
	m_Matrix[4] = n5;
	m_Matrix[5] = n6;
	m_Matrix[6] = n7;
	m_Matrix[7] = n8;
	m_Matrix[8] = n9;
}

Matrix::Matrix(const Matrix& B)
{
	for (int i = 0; i < 9; i++)
	{
		m_Matrix[i] = B.m_Matrix[i];
	}
}

Matrix Matrix::operator+(const Matrix& b) const
{
	Matrix returnMatrix;

	for (int i = 0; i < 9; i++)
	{
		returnMatrix.m_Matrix[i] = m_Matrix[i] + b.m_Matrix[i];
	}

	return returnMatrix;
}

Matrix Matrix::operator-(const Matrix& b) const
{
	Matrix returnMatrix;

	for (int i = 0; i < 9; i++)
	{
		returnMatrix.m_Matrix[i] = m_Matrix[i] - b.m_Matrix[i];
	}

	return returnMatrix;
}

Matrix Matrix::operator*(const float b) const
{
	Matrix returnMatrix;

	for (int i = 0; i < 9; i++)
	{
		returnMatrix.m_Matrix[i] = b * m_Matrix[i];
	}

	return returnMatrix;
}

Matrix Matrix::operator*(const Matrix& b) const
{
	//The matrices are 3x3, thus the check to make sure the column of A and row of B are left out.
	Matrix returnMatrix;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			returnMatrix.m_Matrix[(r * 3) + c] = m_Matrix[(r * 3) + 0] * b.m_Matrix[c + (0 * 3)] +
				m_Matrix[(r * 3) + 1] * b.m_Matrix[c + (1 * 3)] + m_Matrix[(r * 3) + 2] * b.m_Matrix[c + (2 * 3)];
		}
	}

	return returnMatrix;
}

//Vector right side of the equation
Vec3 Matrix::operator*(const Vec3& b) const
{
	Vec3 returnVec3;

	returnVec3.x(b.x() * m_Matrix[0] + b.y() * m_Matrix[1] + b.z() * m_Matrix[2]);
	returnVec3.y(b.x() * m_Matrix[3] + b.y() * m_Matrix[4] + b.z() * m_Matrix[5]);
	returnVec3.z(b.x() * m_Matrix[6] + b.y() * m_Matrix[7] + b.z() * m_Matrix[8]);

	return returnVec3;
}

//Only used for unit testing
void Matrix::Set(float a, float b, float c, float d, float e, float f, float g, float h, float j)
{
	m_Matrix[0] = a;
	m_Matrix[1] = b;
	m_Matrix[2] = c;
	m_Matrix[3] = d;
	m_Matrix[4] = e;
	m_Matrix[5] = f;
	m_Matrix[6] = g;
	m_Matrix[7] = h;
	m_Matrix[8] = j;
}

void Matrix::Clear()
{
	for (int i = 0; i < 9; i++)
	{
		m_Matrix[i] = 0.0f;
	}
}

//Changes the matrix to become an identity matrix
void Matrix::Identity()
{
	for (int i = 0; i < 9; i++)
	{
		if (i == 0)
			m_Matrix[i] = 1.0f;
		else if (i == 4)
			m_Matrix[i] = 1.0f;
		else if (i == 8)
			m_Matrix[i] = 1.0f;
		else
			m_Matrix[i] = 0.0f;
	}
}

void Matrix::Scale(const Vec3& S)
{
	for (int i = 0; i < 9; i++)
	{
		if (i == 0)
			m_Matrix[i] = S.x();
		else if (i == 4)
			m_Matrix[i] = S.y();
		else if (i == 8)
			m_Matrix[i] = S.z();
		else
			m_Matrix[i] = 0.0f;
	}
}

Vec3 Matrix::Translation(const Vec3& T, const Vec3& b) const
{
	//Should technically be a 4x4 matrix to compute.
	//But because we know we use a 3D vector, we can simply add them and return a vector

	Vec3 returnVec3;

	returnVec3.x(T.x() + b.x());
	returnVec3.y(T.y() + b.y());
	returnVec3.z(T.z() + b.z());

	return returnVec3;
}

void Matrix::Transpose()
{
	float hold = 0.0f;

	hold = m_Matrix[1];
	m_Matrix[1] = m_Matrix[3];
	m_Matrix[3] = hold;

	hold = m_Matrix[2];
	m_Matrix[2] = m_Matrix[6];
	m_Matrix[6] = hold;

	hold = m_Matrix[5];
	m_Matrix[5] = m_Matrix[7];
	m_Matrix[7] = hold;
}

void Matrix::RotateX(const float rad)
{
	m_Matrix[0] = 1.0f;
	m_Matrix[4] = cosf(rad);
	m_Matrix[5] = -sinf(rad);
	m_Matrix[7] = sinf(rad);
	m_Matrix[8] = cosf(rad);
}

void Matrix::RotateY(const float rad)
{
	m_Matrix[0] = cosf(rad);
	m_Matrix[2] = sinf(rad);
	m_Matrix[4] = 1.0f;
	m_Matrix[6] = -sinf(rad);	
	m_Matrix[8] = cosf(rad);
}

void Matrix::RotateZ(const float rad)
{
	m_Matrix[0] = cosf(rad);
	m_Matrix[1] = -sinf(rad);
	m_Matrix[3] = sinf(rad);
	m_Matrix[4] = cosf(rad);
	m_Matrix[8] = 1.0f;
}

Matrix Matrix::Orthonormalization()
{
	//Orthogonalization is not included because i was unable to verify if my versions were correct.
	Vec3 r1(m_Matrix[0], m_Matrix[1], m_Matrix[2]);
	Vec3 r2(m_Matrix[3], m_Matrix[4], m_Matrix[5]);
	Vec3 r3(m_Matrix[6], m_Matrix[7], m_Matrix[8]);
	Matrix C;

	if (r1.dot(r1) == 0.0f) //Cant divide by 0
	{
		C.Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		return C;
	}

	r2 = r2 - r2.dot(r1) / r1.dot(r1) * r1;

	if (r2.dot(r2) == 0.0f) //Cant divide by 0
	{
		C.Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		return C;
	}

	r3 = r3 - (r3.dot(r1) / r1.dot(r1)) * r1 - (r3.dot(r2) / r2.dot(r2)) * r2;

	r1.normalize();
	r2.normalize();
	r3.normalize();

	C.Set(r1.x(), r1.y(), r1.z(), r2.x(), r2.y(), r2.z(), r3.x(), r3.y(), r3.z());

	return C;
}