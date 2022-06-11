#include "pch.h"
#include "..\MathLib\Header\precomp.h"

//This library contains multiple warnings.
//These template warnings have been disabled because i don't want to edit the library.
//The following erros have been disabled
//C26812 & C26495

//namespace were used to group the tests together. Thanks to Wessel Frijters for this idea
namespace Vector2
{
	//default construtor
	TEST(vector2, default_constructor)
	{
		const Vec2 v1;
		EXPECT_TRUE(v1.x() == 0.0f);
		EXPECT_TRUE(v1.y() == 0.0f);
	}

	//prameter constructor
	TEST(vector2, parameter_constructor)
	{
		const Vec2 v1(3.0f);
		EXPECT_TRUE(v1.x() == 3.0f);
		EXPECT_TRUE(v1.y() == 3.0f);
	}

	//second parameter constructor
	TEST(vector2, parameter_constructor2)
	{
		const Vec2 v1(2.5f, 0.3f);
		EXPECT_TRUE(v1.x() == 2.5f);
		EXPECT_TRUE(v1.y() == 0.3f);
	}

	//copy constructor
	TEST(vector2, copy_constructor)
	{
		const Vec2 v1(3.4f, 2.3f);
		const Vec2 v2(v1);
		EXPECT_TRUE(v2.x() == v1.x());
		EXPECT_TRUE(v2.y() == v1.y());
	}

	//clear vector2
	TEST(vector2, clear)
	{
		Vec2 v1(33.2f, 9.4f);
		v1.clear();
		EXPECT_TRUE(v1.x() == 0.0f);
		EXPECT_TRUE(v1.y() == 0.0f);
	}

	//Vector2 operators
	TEST(vector2, add)
	{
		const Vec2 v1(1.4f, 4.3f);
		const Vec2 v2(4.2f, 8.5f);
		Vec2 v3;

		v3 = v1 + v2;
		EXPECT_TRUE(v3.x() == v1.x() + v2.x());
		EXPECT_TRUE(v3.y() == v1.y() + v2.y());
	}

	TEST(vector2, substract)
	{
		const Vec2 v1(1.4f, 4.3f);
		const Vec2 v2(4.2f, 8.5f);
		Vec2 v3;

		v3 = v1 - v2;
		EXPECT_TRUE(v3.x() == v1.x() - v2.x());
		EXPECT_TRUE(v3.y() == v1.y() - v2.y());
	}

	TEST(vector2, dot_by_multiple)
	{
		const Vec2 v1(1.4f, 4.3f);
		const Vec2 v2(4.2f, 8.5f);
		float dot;

		dot = v1 * v2;
		EXPECT_TRUE(dot == v1.x() * v2.x() + v1.y() * v2.y());
	}

	TEST(vector2, scale_vector)
	{
		const Vec2 v1(1.4f, 4.3f);
		const float f = 6.4f;
		Vec2 v3;

		v3 = v1 * f;
		EXPECT_TRUE(v3.x() == v1.x() * f);
		EXPECT_TRUE(v3.y() == v1.y() * f);
	}

	TEST(vector2, float_multiplied_vector)
	{
		const Vec2 v2(4.2f, 8.5f);
		const float f = 6.4f;
		Vec2 v3;

		v3 = f * v2;
		EXPECT_TRUE(v3.x() == v2.x() * f);
		EXPECT_TRUE(v3.y() == v2.y() * f);
	}

	TEST(vector2, divide_by_vector)
	{
		const Vec2 v1(1.4f, 4.3f);
		const Vec2 v2(4.2f, 8.5f);
		Vec2 v3;

		v3 = v1 / v2;
		EXPECT_TRUE(v3.x() == v1.x() / v2.x());
		EXPECT_TRUE(v3.y() == v1.y() / v2.y());
	}

	TEST(vector2, divide_by_zero_vector)
	{
		const Vec2 v1(1.4f, 4.3f);
		const Vec2 v2(0.0f, 8.5f);
		Vec2 v3;

		v3 = v1 / v2;
		EXPECT_TRUE(v3.x() == 0.0f);
		EXPECT_TRUE(v3.y() == 0.0f);
	}

	TEST(vector2, divide_scalar)
	{
		const Vec2 v1(1.4f, 4.3f);
		const float f = 6.4f;
		Vec2 v3;

		v3 = v1 / f;
		EXPECT_TRUE(v3.x() == v1.x() / f);
		EXPECT_TRUE(v3.y() == v1.y() / f);
	}

	TEST(vector2, divide_zero_scalar)
	{
		const Vec2 v1(1.4f, 4.3f);
		const float f = 0.0f;
		Vec2 v3;

		v3 = v1 / f;
		EXPECT_TRUE(v3.x() == 0.0f);
		EXPECT_TRUE(v3.y() == 0.0f);
	}

	TEST(vector2, add_to_vector)
	{
		const Vec2 v1(1.4f, 4.3f);
		Vec2 v2(4.2f, 8.5f);

		v2 += v1;
		EXPECT_TRUE(v2.x() == v1.x() + 4.2f);
		EXPECT_TRUE(v2.y() == v1.y() + 8.5f);
	}

	TEST(vector2, substract_from_vector)
	{
		const Vec2 v1(1.4f, 4.3f);
		Vec2 v2(4.2f, 8.5f);

		v2 -= v1;
		EXPECT_TRUE(v2.x() == 4.2f - v1.x());
		EXPECT_TRUE(v2.y() == 8.5f - v1.y());
	}

	TEST(vector2, multiply_to_vector_by_vector)
	{
		const Vec2 v1(1.4f, 4.3f);
		Vec2 v2(4.2f, 8.5f);

		v2 *= v1;
		EXPECT_TRUE(v2.x() == 4.2f * v1.x());
		EXPECT_TRUE(v2.y() == 8.5f * v1.y());
	}

	TEST(vector2, multiply_to_vector)
	{
		Vec2 v2(4.2f, 8.5f);
		const float f = 6.4f;

		v2 *= f;
		EXPECT_TRUE(v2.x() == 4.2f * f);
		EXPECT_TRUE(v2.y() == 8.5f * f);
	}

	TEST(vector2, divide_by_vector2)
	{
		const Vec2 v1(2.4f, 5.4f);
		Vec2 v2(1.5f, 7.3f);

		v2 /= v1;
		EXPECT_TRUE(v2.x() == 1.5f / v1.x());
		EXPECT_TRUE(v2.y() == 7.3f / v1.y());
	}

	TEST(vector2, divide_by_zero_vector2)
	{
		const Vec2 v1(0.0f, 5.4f);
		Vec2 v2(1.5f, 7.3f);

		v2 /= v1;
		EXPECT_TRUE(v2.x() == 0.0f);
		EXPECT_TRUE(v2.y() == 0.0f);
	}

	TEST(vector2, Logical_operator_equal)
	{
		const Vec2 v1(1.4f, 4.3f);
		const Vec2 v2(1.4f, 4.3f);

		EXPECT_TRUE(v2 == v1);
	}

	TEST(vector2, Logical_operator_not_equal)
	{
		const Vec2 v1(1.4f, 4.3f);
		const Vec2 v2(6.4f, 3.3f);

		EXPECT_TRUE(v2 != v1);
	}


	//Calculations
	TEST(vector2, dot)
	{
		const Vec2 v1(1.4f, 4.3f);
		const Vec2 v2(4.2f, 8.5f);

		const float dot = v1 * v2;
		EXPECT_FLOAT_EQ(42.43f, dot);

		const float funcDot = v1.dot(v2);
		EXPECT_TRUE(dot == funcDot);
	}

	TEST(vector2, distance)
	{
		const Vec2 v1(1.4f, 4.3f);
		const Vec2 v2(4.2f, 8.5f);

		const float f = v1.distance(v2);
		EXPECT_FLOAT_EQ(5.047772f, f);
	}


	TEST(vector2, length)
	{
		const Vec2 v1(1.4f, 4.3f);

		const float f = v1.length();
		EXPECT_TRUE(f == 4.522167621838006f); //Without the full number, google test will throw an error
	}

	TEST(vector2, sqrLength)
	{
		const Vec2 v1(1.4f, 4.3f);

		const float f = v1.sqrtLength();
		EXPECT_TRUE(f == 20.45f);
	}

	TEST(vector2, normalize)
	{
		Vec2 v1(1.4f, 4.3f);
		Vec2 v2(0.0f, 0.0f);

		v1.normalize();
		v2.normalize();
		EXPECT_TRUE(v1.length() == 1.0f);
		EXPECT_TRUE(v2.length() == 0.0f);
	}

	TEST(vector2, clamp)
	{
		Vec2 v1(3.0f, -5.0f);

		v1.clamp(0.0f, 1.0f);
		EXPECT_TRUE(v1.x() == 1.0f);
		EXPECT_TRUE(v1.y() == 0.0f);
	}
}

namespace Vector3
{
	//default constructor
	TEST(vector3, default_construct)
	{
		const Vec3 v1;

		EXPECT_TRUE(v1.x() == 0.0f);
		EXPECT_TRUE(v1.y() == 0.0f);
		EXPECT_TRUE(v1.z() == 0.0f);
	}

	//parameter constructor
	TEST(vector3, parameter_construct)
	{
		Vec3 v1;
		v1.x(1.5f), v1.y(4.5f), v1.z(6.4f);

		EXPECT_TRUE(v1.x() == 1.5f);
		EXPECT_TRUE(v1.y() == 4.5f);
		EXPECT_TRUE(v1.z() == 6.4f);

		Vec3 v2(5.6f, 3.7f, 9.2f);
		EXPECT_TRUE(v2.x() == 5.6f);
		EXPECT_TRUE(v2.y() == 3.7f);
		EXPECT_TRUE(v2.z() == 9.2f);
	}

	//second parameter constructor
	TEST(vector3, parameter_construct2)
	{
		Vec3 v1(4.8f);

		EXPECT_TRUE(v1.x() == 4.8f);
		EXPECT_TRUE(v1.y() == 4.8f);
		EXPECT_TRUE(v1.z() == 4.8f);
	}

	//copy constructor
	TEST(vector3, copy_construct)
	{
		const Vec3 v1(7.5f, 1.4f, 6.3f);
		const Vec3 v2(v1);

		EXPECT_TRUE(v2.x() == v1.x());
		EXPECT_TRUE(v2.y() == v1.y());
		EXPECT_TRUE(v2.z() == v1.z());
	}

	//clear vector3
	TEST(vector3, clear)
	{
		Vec3 v1(7.6f, 2.2f, 19.4f);

		v1.clear();
		EXPECT_TRUE(v1.x() == 0.0f);
		EXPECT_TRUE(v1.y() == 0.0f);
		EXPECT_TRUE(v1.z() == 0.0f);
	}

	//operators
	TEST(vector3, add)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		const Vec3 v2(8.2f, 6.4f, 3.9f);
		Vec3 v3;

		v3 = v1 + v2;
		EXPECT_TRUE(v3.x() == v1.x() + v2.x());
		EXPECT_TRUE(v3.y() == v1.y() + v2.y());
		EXPECT_TRUE(v3.z() == v1.z() + v2.z());
	}

	TEST(vector3, substract)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		const Vec3 v2(8.2f, 6.4f, 3.9f);
		Vec3 v3;

		v3 = v1 - v2;
		EXPECT_TRUE(v3.x() == v1.x() - v2.x());
		EXPECT_TRUE(v3.y() == v1.y() - v2.y());
		EXPECT_TRUE(v3.z() == v1.z() - v2.z());
	}

	TEST(vector3, multiplied)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		const Vec3 v2(8.2f, 6.4f, 3.9f);
		Vec3 v3;

		v3 = v1 * v2;
		EXPECT_TRUE(v3.x() == v1.x() * v2.x());
		EXPECT_TRUE(v3.y() == v1.y() * v2.y());
		EXPECT_TRUE(v3.z() == v1.z() * v2.z());
	}

	TEST(vector3, scaled_vector)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		const float f = 8.3f;
		Vec3 v3;

		v3 = v1 * f;
		EXPECT_TRUE(v3.x() == v1.x() * f);
		EXPECT_TRUE(v3.y() == v1.y() * f);
		EXPECT_TRUE(v3.z() == v1.z() * f);
	}


	TEST(vector3, float_multiplied_vector)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		const float f = 8.3f;
		Vec3 v3;

		v3 = f * v1;
		EXPECT_TRUE(v3.x() == v1.x() * f);
		EXPECT_TRUE(v3.y() == v1.y() * f);
		EXPECT_TRUE(v3.z() == v1.z() * f);
	}


	TEST(vector3, divide_by_scalar)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		const float f = 8.3f;
		Vec3 v3;

		v3 = v1 / f;
		EXPECT_TRUE(v3.x() == v1.x() / f);
		EXPECT_TRUE(v3.y() == v1.y() / f);
		EXPECT_TRUE(v3.z() == v1.z() / f);
	}

	TEST(vector3, divide_by_zero_scalar)
	{
		const Vec3 v1(5.8f, 3.1f, 0.0f);
		const float f = 0.0f;
		Vec3 v3;

		v3 = v1 / f;
		EXPECT_TRUE(v3.x() == 0.0f);
		EXPECT_TRUE(v3.y() == 0.0f);
		EXPECT_TRUE(v3.z() == 0.0f);
	}

	TEST(vector3, divide_by_vector)
	{
		const Vec3 v1(0.0f, 3.1f, 4.6f);
		const Vec3 v2(8.2f, 6.4f, 3.9f);
		Vec3 v3;

		v3 = v1 / v2;
		EXPECT_TRUE(v3.x() == v1.x() / v2.x());
		EXPECT_TRUE(v3.y() == v1.y() / v2.y());
		EXPECT_TRUE(v3.z() == v1.z() / v2.z());
	}

	TEST(vector3, divide_by_zero_vector)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		const Vec3 v2(8.2f, 0.0f, 3.9f);
		Vec3 v3;

		v3 = v1 / v2;
		EXPECT_TRUE(v3.x() == 0.0f);
		EXPECT_TRUE(v3.y() == 0.0f);
		EXPECT_TRUE(v3.z() == 0.0f);
	}

	TEST(vector3, add_to_vector)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		Vec3 v2(8.2f, 6.4f, 3.9f);

		v2 += v1;
		EXPECT_TRUE(v2.x() == 8.2f + v1.x());
		EXPECT_TRUE(v2.y() == 6.4f + v1.y());
		EXPECT_TRUE(v2.z() == 3.9f + v1.z());
	}

	TEST(vector3, substract_from_vector)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		Vec3 v2(8.2f, 6.4f, 3.9f);

		v2 -= v1;
		EXPECT_TRUE(v2.x() == 8.2f - v1.x());
		EXPECT_TRUE(v2.y() == 6.4f - v1.y());
		EXPECT_TRUE(v2.z() == 3.9f - v1.z());
	}

	TEST(vector3, multiply_to_vector_by_vector)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		Vec3 v2(8.2f, 6.4f, 3.9f);

		v2 *= v1;
		EXPECT_TRUE(v2.x() == 8.2f * v1.x());
		EXPECT_TRUE(v2.y() == 6.4f * v1.y());
		EXPECT_TRUE(v2.z() == 3.9f * v1.z());
	}

	TEST(vector3, multiply_to_vector)
	{
		Vec3 v1(5.8f, 3.1f, 4.6f);
		const float f = 8.3f;

		v1 *= f;
		EXPECT_TRUE(v1.x() == 5.8f * f);
		EXPECT_TRUE(v1.y() == 3.1f * f);
		EXPECT_TRUE(v1.z() == 4.6f * f);
	}

	TEST(vector3, divide_by_vector2)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		Vec3 v2(8.2f, 6.4f, 3.9f);

		v2 /= v1;
		EXPECT_TRUE(v2.x() == 8.2f / v1.x());
		EXPECT_TRUE(v2.y() == 6.4f / v1.y());
		EXPECT_TRUE(v2.z() == 3.9f / v1.z());
	}

	TEST(vector3, divide_by_zero_vector2)
	{
		const Vec3 v1(0.0f, 88.0f, -3.9f);
		Vec3 v2(8.2f, 6.4f, 3.9f);

		v2 /= v1;
		EXPECT_TRUE(v2.x() == 0.0f);
		EXPECT_TRUE(v2.y() == 0.0f);
		EXPECT_TRUE(v2.z() == 0.0f);
	}

	TEST(vector3, logical_operator_equal)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		const Vec3 v2(5.8f, 3.1f, 4.6f);

		EXPECT_TRUE(v2 == v1);

		const Vec3 v3(4.2f, 2.3f, 5.2f);

		EXPECT_FALSE(v3 == v2);
	}

	TEST(vector3, logical_operator_not_equal)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		const Vec3 v2(5.9f, 3.1f, 4.6f);

		EXPECT_TRUE(v2 != v1);

		const Vec3 v3(5.9f, 3.1f, 4.6f);

		EXPECT_FALSE(v3 != v2);
	}

	//Calculations
	TEST(vector3, normalize)
	{
		Vec3 v1(5.8f, 3.1f, 4.6f);
		Vec3 v2; //0.0f / 0.0f / 0.0f

		v1.normalize();
		v2.normalize();

		EXPECT_TRUE(v1.length() == 1.0f);
		EXPECT_TRUE(v2.length() == 0.0f);
	}

	TEST(vector3, length)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);

		const float f = v1.length();
		EXPECT_TRUE(f == 8.025584090893322f);
	}

	TEST(vector3, sqrtLength)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);

		const float f = v1.sqrtLength();
		EXPECT_TRUE(f == 64.41f);
	}

	TEST(vector3, distance)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		const Vec3 v2(8.2f, 6.4f, 3.9f);

		const float f = v1.distance(v2);
		EXPECT_TRUE(f == 4.140048f);
	}

	TEST(vector3, dot)
	{
		const Vec3 v1(5.8f, 3.1f, 4.6f);
		const Vec3 v2(8.2f, 6.4f, 3.9f);

		const float funcDot = v1.dot(v2);
		EXPECT_FLOAT_EQ(85.34f, funcDot);
	}

	TEST(vector3, cross)
	{
		Vec3 v1(5.8f, 3.1f, 4.6f);
		Vec3 v2(8.2f, 6.4f, 3.9f);
		Vec3 v3;

		v3 = v1.cross(v2);
		EXPECT_FLOAT_EQ(-17.35f, v3.x());
		EXPECT_FLOAT_EQ(15.1f, v3.y());
		EXPECT_FLOAT_EQ(11.700005f, v3.z()); //answer is 11.7f, but due to floats its 11.700005f. Google test throws an error
	}

	TEST(vector3, cross_zero_length)
	{
		Vec3 v1(5.8f, 3.1f, 4.6f);
		Vec3 v2(0.0f, 0.0f, 0.0f);
		Vec3 v3;

		v3 = v1.cross(v2);
		EXPECT_FLOAT_EQ(0.0f, v3.x());
		EXPECT_FLOAT_EQ(0.0f, v3.y());
		EXPECT_FLOAT_EQ(0.0f, v3.z());
	}

	TEST(vector3, cross_directions)
	{
		//They can both point to the same direction. Or away from eachother
		Vec3 v1(5.8f, 3.1f, 4.6f);
		Vec3 v2(5.8f, 3.1f, 4.6f);
		Vec3 v3(-5.8f, -3.1f, -4.6f);
		Vec3 v4;

		v4 = v1.cross(v2);
		EXPECT_FLOAT_EQ(0.0f, v4.x());
		EXPECT_FLOAT_EQ(0.0f, v4.y());
		EXPECT_FLOAT_EQ(0.0f, v4.z());

		v4 = v1.cross(v3);
		EXPECT_FLOAT_EQ(0.0f, v4.x());
		EXPECT_FLOAT_EQ(0.0f, v4.y());
		EXPECT_FLOAT_EQ(0.0f, v4.z());
	}

	TEST(vector3, clamp)
	{
		Vec3 v1(4.0f, -8.0f, 1.5f);

		v1.clamp(0.0f, 2.0f);
		EXPECT_FLOAT_EQ(2.0f, v1.x());
		EXPECT_FLOAT_EQ(0.0f, v1.y());
		EXPECT_FLOAT_EQ(1.5f, v1.z());
	}
}

namespace Vector4 {
	
	//Default constructor
	TEST(vector4, default_construct)
	{
		const Vec4 v1;

		EXPECT_TRUE(v1.x() == 0.0f);
		EXPECT_TRUE(v1.y() == 0.0f);
		EXPECT_TRUE(v1.z() == 0.0f);
		EXPECT_TRUE(v1.w() == 0.0f);
	}

	//Parameter constructor
	TEST(vector4, parameter_construct)
	{
		Vec4 v1(0.4f, 11.5f, -2.555f, 8.2f);

		EXPECT_TRUE(v1.x() == 0.4f);
		EXPECT_TRUE(v1.y() == 11.5f);
		EXPECT_TRUE(v1.z() == -2.555f);
		EXPECT_TRUE(v1.w() == 8.2f);

		Vec4 v2;
		v2.x(5.3f), v2.y(-5.2f), v2.z(88.4f), v2.w(0.3f);

		EXPECT_TRUE(v2.x() == 5.3f);
		EXPECT_TRUE(v2.y() == -5.2f);
		EXPECT_TRUE(v2.z() == 88.4f);
		EXPECT_TRUE(v2.w() == 0.3f);
	}

	//second parameter constructor
	TEST(vector4, parameter_construct2)
	{
		Vec4 v1(8.4f);

		EXPECT_TRUE(v1.x() == 8.4f);
		EXPECT_TRUE(v1.y() == 8.4f);
		EXPECT_TRUE(v1.z() == 8.4f);
		EXPECT_TRUE(v1.w() == 8.4f);
	}

	//Copy constructor
	TEST(vector4, copy_constructor)
	{
		const Vec4 v1(5.3f, 8.3f, -11.3f, 8.33f);
		const Vec4 v2(v1);

		EXPECT_TRUE(v2.x() == 5.3f);
		EXPECT_TRUE(v2.y() == 8.3f);
		EXPECT_TRUE(v2.z() == -11.3f);
		EXPECT_TRUE(v2.w() == 8.33f);
	}

	//Clear vector4
	TEST(vector4, clear)
	{
		Vec4 v1(84.4f, -9.3f, 77.333f, 0.0f);
		v1.clear();

		EXPECT_TRUE(v1.x() == 0.0f);
		EXPECT_TRUE(v1.y() == 0.0f);
		EXPECT_TRUE(v1.z() == 0.0f);
		EXPECT_TRUE(v1.w() == 0.0f);
	}

	//operators
	TEST(vector4, add)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const Vec4 v2(-0.22f, 8.3f, 72.0f, 8.33f);
		Vec4 v3;

		v3 = v1 + v2;
		EXPECT_TRUE(v3.x() == v1.x() + v2.x());
		EXPECT_TRUE(v3.y() == v1.y() + v2.y());
		EXPECT_TRUE(v3.z() == v1.z() + v2.z());
		EXPECT_TRUE(v3.w() == v1.w() + v2.w());
	}

	TEST(vector4, substract)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const Vec4 v2(-0.22f, 8.3f, 72.0f, 8.33f);
		Vec4 v3;

		v3 = v1 - v2;
		EXPECT_TRUE(v3.x() == v1.x() - v2.x());
		EXPECT_TRUE(v3.y() == v1.y() - v2.y());
		EXPECT_TRUE(v3.z() == v1.z() - v2.z());
		EXPECT_TRUE(v3.w() == v1.w() - v2.w());
	}

	TEST(vector4, multiplied)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const Vec4 v2(-0.22f, 8.3f, 72.0f, 8.33f);
		Vec4 v3;

		v3 = v1 * v2;
		EXPECT_TRUE(v3.x() == v1.x() * v2.x());
		EXPECT_TRUE(v3.y() == v1.y() * v2.y());
		EXPECT_TRUE(v3.z() == v1.z() * v2.z());
		EXPECT_TRUE(v3.w() == v1.w() * v2.w());
	}

	TEST(vector4, scaled_vector)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const float f = 8.11f;
		Vec4 v3;

		v3 = v1 * f;
		EXPECT_TRUE(v3.x() == v1.x() * f);
		EXPECT_TRUE(v3.y() == v1.y() * f);
		EXPECT_TRUE(v3.z() == v1.z() * f);
		EXPECT_TRUE(v3.w() == v1.w() * f);
	}

	TEST(vector4, float_multiplied_vector)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const float f = 8.11f;
		Vec4 v3;

		v3 = f * v1;
		EXPECT_TRUE(v3.x() == f * v1.x());
		EXPECT_TRUE(v3.y() == f * v1.y());
		EXPECT_TRUE(v3.z() == f * v1.z());
		EXPECT_TRUE(v3.w() == f * v1.w());
	}

	TEST(vector4, divide_by_vector)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const Vec4 v2(-0.22f, 8.3f, 72.0f, 8.33f);
		Vec4 v3;

		v3 = v1 / v2;
		EXPECT_TRUE(v3.x() == v1.x() / v2.x());
		EXPECT_TRUE(v3.y() == v1.y() / v2.y());
		EXPECT_TRUE(v3.z() == v1.z() / v2.z());
		EXPECT_TRUE(v3.w() == v1.w() / v2.w());
	}

	TEST(vector4, divide_by_zero_vector)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const Vec4 v2(0.0f, 6.0f, -2.0f, 0.88f);
		Vec4 v3;

		v3 = v1 / v2;
		EXPECT_TRUE(v3.x() == 0.0f);
		EXPECT_TRUE(v3.y() == 0.0f);
		EXPECT_TRUE(v3.z() == 0.0f);
		EXPECT_TRUE(v3.w() == 0.0f);
	}

	TEST(vector4, divide_by_scalar)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const float f = 8.11f;
		Vec4 v3;

		v3 = v1 / f;
		EXPECT_TRUE(v3.x() == v1.x() / f);
		EXPECT_TRUE(v3.y() == v1.y() / f);
		EXPECT_TRUE(v3.z() == v1.z() / f);
		EXPECT_TRUE(v3.w() == v1.w() / f);
	}

	TEST(vector4, divide_by_zero_scalar)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const float f = 0.0f;
		Vec4 v3;

		v3 = v1 / f;
		EXPECT_TRUE(v3.x() == 0.0f);
		EXPECT_TRUE(v3.y() == 0.0f);
		EXPECT_TRUE(v3.z() == 0.0f);
		EXPECT_TRUE(v3.w() == 0.0f);
	}

	TEST(vector4, add_to_vector)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		Vec4 v2(-0.22f, 8.3f, 72.0f, 8.33f);

		v2 += v1;
		EXPECT_TRUE(v2.x() == -0.22f + v1.x());
		EXPECT_TRUE(v2.y() == 8.3f + v1.y());
		EXPECT_TRUE(v2.z() == 72.0f + v1.z());
		EXPECT_TRUE(v2.w() == 8.33f + v1.w());
	}

	TEST(vector4, substract_from_vector)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		Vec4 v2(-0.22f, 8.3f, 72.0f, 8.33f);

		v2 -= v1;
		EXPECT_TRUE(v2.x() == -0.22f - v1.x());
		EXPECT_TRUE(v2.y() == 8.3f - v1.y());
		EXPECT_TRUE(v2.z() == 72.0f - v1.z());
		EXPECT_TRUE(v2.w() == 8.33f - v1.w());
	}

	TEST(vector4, multiply_to_vector_by_vector)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		Vec4 v2(-0.22f, 8.3f, 72.0f, 8.33f);

		v2 *= v1;
		EXPECT_TRUE(v2.x() == -0.22f * v1.x());
		EXPECT_TRUE(v2.y() == 8.3f * v1.y());
		EXPECT_TRUE(v2.z() == 72.0f * v1.z());
		EXPECT_TRUE(v2.w() == 8.33f * v1.w());
	}

	TEST(vector4, multiply_to_vector)
	{
		Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const float f = 3.22f;

		v1 *= f;
		EXPECT_TRUE(v1.x() == 5.3f * f);
		EXPECT_TRUE(v1.y() == -11.9f * f);
		EXPECT_TRUE(v1.z() == 9.33f * f);
		EXPECT_TRUE(v1.w() == 4.3f * f);
	}

	TEST(vector4, divide_by_vector2)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		Vec4 v2(-0.22f, 8.3f, 72.0f, 8.33f);

		v2 /= v1;
		EXPECT_TRUE(v2.x() == -0.22f / v1.x());
		EXPECT_TRUE(v2.y() == 8.3f / v1.y());
		EXPECT_TRUE(v2.z() == 72.0f / v1.z());
		EXPECT_TRUE(v2.w() == 8.33f / v1.w());
	}

	TEST(vector4, divide_by_zero_vector2)
	{
		const Vec4 v1;
		Vec4 v2(5.3f, -11.9f, 9.33f, 4.3f);

		v2 /= v1;
		EXPECT_TRUE(v2.x() == 0.0f);
		EXPECT_TRUE(v2.y() == 0.0f);
		EXPECT_TRUE(v2.z() == 0.0f);
		EXPECT_TRUE(v2.w() == 0.0f);
	}
	TEST(vector4, logical_operator_equal)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const Vec4 v2(5.3f, -11.9f, 9.33f, 4.3f);

		EXPECT_TRUE(v1 == v2);
	}

	TEST(vector4, logical_operator_not_equal)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const Vec4 v2(-0.22f, 8.3f, 72.0f, 8.33f);

		EXPECT_TRUE(v1 != v2);
	}

	//Calculations
	TEST(vector4, normalize)
	{
		Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		Vec4 v2; //0.0f, 0.0f, 0.0f, 0.0f

		v1.normalize();
		v2.normalize();

		EXPECT_TRUE(v1.length() == 1.0f);
		EXPECT_TRUE(v2.length() == 0.0f);
	}

	TEST(vector4, length)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);

		const float f = v1.length();
		EXPECT_FLOAT_EQ(16.590324f, f);
	}

	TEST(vector4, sqrtLength)
	{
		Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);

		const float f = v1.sqrtLength();
		EXPECT_FLOAT_EQ(275.2389f, f);
	}

	TEST(vector4, distance)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const Vec4 v2(-0.22f, 8.3f, 72.0f, 8.33f);

		const float f = v1.distance(v2);
		EXPECT_FLOAT_EQ(66.19879304f, f);
	}

	TEST(vector4, dot)
	{
		const Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);
		const Vec4 v2(-0.22f, 8.3f, 72.0f, 8.33f);

		const float dot = v1.dot(v2);
		EXPECT_FLOAT_EQ(607.643f, dot);
	}

	TEST(vector4, clamp)
	{
		Vec4 v1(5.3f, -11.9f, 9.33f, 4.3f);

		v1.clamp(0.0f, 6.0f);
		EXPECT_TRUE(v1.x() == 5.3f);
		EXPECT_TRUE(v1.y() == 0.0f);
		EXPECT_TRUE(v1.z() == 6.0f);
		EXPECT_TRUE(v1.w() == 4.3f);
	}
}

//The values have been verified using https://www.geogebra.org/3d with Y axes veritcal & 10 decimals
namespace Ray{

	Vec3 O(0.0f, 1.0f, 0.0f); //Origin
	Vec3 P(0.0f, 0.0f, 0.0f); //Screen position
	Vec3 D(0.0f, 0.0f, 0.0f); //Ray direction //D=(-0.29916169,-0.7906416,0.5342173)

	TEST(Ray, Point_On_Screen)
	{
		Vec3 P0(-1.0f, 1.0f, 1.0f);		//Top left
		Vec3 P1(1.0f, 1.0f, 1.0f);		//Top right
		Vec3 P2(-1.0f, -1.0f, 1.0f);	//Bottom left
		float u = 0.22f; //Screen Y
		float v = 0.74f; //Screen X

		P = P0 + u * (P1 - P0) + v * (P2 - P0);
		EXPECT_FLOAT_EQ(-0.56f, P.x());
		EXPECT_FLOAT_EQ(-0.48f, P.y());
		EXPECT_FLOAT_EQ(1.0f, P.z());
	}

	TEST(Ray, Direction)
	{
		D = P - O;
		D.normalize();
		EXPECT_FLOAT_EQ(-0.29916169f, D.x());
		EXPECT_FLOAT_EQ(-0.79064160f, D.y());
		EXPECT_FLOAT_EQ(0.53421730f, D.z());
	}

	TEST(Ray, Plane_Intersection)
	{
		Vec3 N(0.0f, 1.0f, 0.0f); //Normal
		float d = 0.0f;

		float t = -(O.dot(N) + d) / (D.dot(N));
		EXPECT_FLOAT_EQ(1.26479557f, t);

		Vec3 I = O + t * D;
		EXPECT_FLOAT_EQ(-0.37837838f, I.x());
		EXPECT_FLOAT_EQ(0.0f, I.y());
		EXPECT_FLOAT_EQ(0.67567567f, I.z());
	}

	TEST(Ray, Sphere_Intersection_Fast)
	{
		Vec3 C(2.3f, 2.4f, 3.2f);
		float r = 5.0f;

		Vec3 c = C - O;
		float t = c.dot(D);
		Vec3 q = c - t * D;
		float p = q.dot(q);
		if (p > (r * r))
		{
			t = INFINITY;
			EXPECT_FLOAT_EQ(INFINITY, t);
		}

		t -= sqrtf((r * r) - p);

		EXPECT_FLOAT_EQ(-2.82724535f, t);		
	}

	TEST(Ray, Sphere_Intersection_Slow)
	{
		Vec3 C(2.3f, 2.4f, 3.2f);
		float r = 5.0f;

		float a = D.dot(D);
		float b = 2 * D.dot((O - C));
		float c = (O - C).dot((O - C)) - (r * r);

		float root = sqrtf((b * b) - 4 * a * c);
		if (root >= 0)
		{
			float t = (-b - root) / (2 * a);
			EXPECT_FLOAT_EQ(-2.82724538f, t);

			float t2 = (-b + root) / (2 * a);
			EXPECT_FLOAT_EQ(2.65629584f, t2);

			Vec3 I = O + t * D;
			EXPECT_FLOAT_EQ(0.84580350f, I.x());
			EXPECT_FLOAT_EQ(3.23533781f, I.y());
			EXPECT_FLOAT_EQ(-1.51036339f, I.z());

			Vec3 I2 = O + t2 * D;
			EXPECT_FLOAT_EQ(-0.79466195f, I2.x());
			EXPECT_FLOAT_EQ(-1.10017799f, I2.y());
			EXPECT_FLOAT_EQ(1.41903919f, I2.z());
		}
		else//Tool can't root negative numbers because its not really possible
		{
			float t = INFINITY;
			EXPECT_FLOAT_EQ(INFINITY, t);
		}
	}

	TEST(Ray, Reflection)
	{
		Vec3 N(0.0f, 1.0f, 0.0f);

		Vec3 R = D - 2 * (D.dot(N)) * N;
		EXPECT_FLOAT_EQ(-0.29916169f, R.x());
		EXPECT_FLOAT_EQ(0.7906416f, R.y());
		EXPECT_FLOAT_EQ(0.5342173f, R.z());
	}

	TEST(Ray, Refraction)
	{
		float n1 = 1.0f;
		float n2 = 2.0f;
		Vec3 N(0.0f, 1.0f, 0.0f);

		float dotI = N.dot((D * -1.0f));

		if (dotI < 0)
		{
			n1 = 2.0f;
			n1 = 1.0f;
			N = N * -1.0f;
			dotI = N.dot((D * -1.0f));
		}

		float div = n1 / n2;

		if (sinf(acosf(dotI)) > n2 / n1)
		{
			//Unable to compute
		}
		else
		{
			float k = 1 - (div * div) * (1 - (dotI * dotI));

			if (k < 0)
			{
				//Unable to compute
			}
			else
			{
				Vec3 T = div * D + N * (div * dotI - sqrtf(k));
				EXPECT_FLOAT_EQ(-0.14958084f, T.x());
				EXPECT_FLOAT_EQ(-0.95198662f, T.y());
				EXPECT_FLOAT_EQ(0.26710865f, T.z());
			}
		}
	}

	TEST(Ray, Fresnel)
	{
		float n1 = 1.0f;
		float n2 = 2.0f;
		Vec3 N(0.0f, 1.0f, 0.0f);

		float dotI = N.dot((D * -1.0f));

		if (dotI < 0)
		{
			n1 = 2.0f;
			n1 = 1.0f;
			N = N * -1.0f;
			dotI = N.dot((D * -1.0f));
		}

		float cosT = sqrtf(1 - (powf(n1 / n2 * sinf(acosf(dotI)), 2)));
		EXPECT_FLOAT_EQ(0.95198662f, cosT);

		float F = 
			   (((n1 * dotI - n2 * cosT) / (n1 * dotI + n2 * cosT)) *
				((n1 * dotI - n2 * cosT) / (n1 * dotI + n2 * cosT)) +
				((n1 * cosT - n2 * dotI) / (n1 * cosT + n2 * dotI)) *
				((n1 * cosT - n2 * dotI) / (n1 * cosT + n2 * dotI))) * 0.5f;

		EXPECT_FLOAT_EQ(0.11620881f, F);
	}
}

namespace Matrices{
	//The following websites has been used as an external tool:
	//https://matrixcalc.org/en/
	//https://onlinemschool.com/math/assistance/matrix/multiply1/
	//https://keisan.casio.com/exec/system/15362817755710

	Matrix A;
	//{ 1.0f,	5.0f,	8.0f}
	//{ 22.0f,	0.5f,	-0.22f}
	//{ 1.2f,	-1.6f,	8.92f}

	Matrix B;
	//{ -5.0f,	0.0f,	2.0f}
	//{ 5.0f,	0.33f,	9.0f}
	//{ 9.2f,	-4.0f,	3.0f} 

	//Constructor
	TEST(Matrice, default_constructor)
	{
		Matrix C;

		for (int i = 0; i < 9; i++)
		{
			EXPECT_TRUE(C.m_Matrix[i] == 0.0f);
		}
	}

	TEST(Matrice, parameter_constructor)
	{
		Matrix C(0.0f, 2.0f, 5.0f, -4.0f, 2.22f, 0.0f, 3.0f, 2.0f, 1.0f);

		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[0]);
		EXPECT_FLOAT_EQ(2.0f, C.m_Matrix[1]);
		EXPECT_FLOAT_EQ(5.0f, C.m_Matrix[2]);
		EXPECT_FLOAT_EQ(-4.0f, C.m_Matrix[3]);
		EXPECT_FLOAT_EQ(2.22f, C.m_Matrix[4]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[5]);
		EXPECT_FLOAT_EQ(3.0f, C.m_Matrix[6]);
		EXPECT_FLOAT_EQ(2.0f, C.m_Matrix[7]);
		EXPECT_FLOAT_EQ(1.0f, C.m_Matrix[8]);
	}

	TEST(Matrice, copy_constructor)
	{
		Matrix C(0.0f, 2.0f, 5.0f, -4.0f, 2.22f, 0.0f, 3.0f, 2.0f, 1.0f);
		Matrix D(C);

		EXPECT_FLOAT_EQ(0.0f, D.m_Matrix[0]);
		EXPECT_FLOAT_EQ(2.0f, D.m_Matrix[1]);
		EXPECT_FLOAT_EQ(5.0f, D.m_Matrix[2]);
		EXPECT_FLOAT_EQ(-4.0f, D.m_Matrix[3]);
		EXPECT_FLOAT_EQ(2.22f, D.m_Matrix[4]);
		EXPECT_FLOAT_EQ(0.0f, D.m_Matrix[5]);
		EXPECT_FLOAT_EQ(3.0f, D.m_Matrix[6]);
		EXPECT_FLOAT_EQ(2.0f, D.m_Matrix[7]);
		EXPECT_FLOAT_EQ(1.0f, D.m_Matrix[8]);
	}
	
	//Operators
	TEST(Matrice, Add)
	{
		A.Set(1.0f, 5.0f, 8.0f, 22.0f, 0.5f, -0.22f, 1.2f, -1.6f, 8.92f);
		B.Set(-5.0f, 0.0f, 2.0f, 5.0f, 0.33f, 9.0f, 9.2f, -4.0f, 3.0f);

		Matrix C = A + B;
		
		EXPECT_FLOAT_EQ(-4.0f, C.m_Matrix[0]);
		EXPECT_FLOAT_EQ(5.0f, C.m_Matrix[1]);
		EXPECT_FLOAT_EQ(10.0f, C.m_Matrix[2]);
		EXPECT_FLOAT_EQ(27.0f, C.m_Matrix[3]);
		EXPECT_FLOAT_EQ(0.83f, C.m_Matrix[4]);
		EXPECT_FLOAT_EQ(8.78f, C.m_Matrix[5]);
		EXPECT_FLOAT_EQ(10.4f, C.m_Matrix[6]);
		EXPECT_FLOAT_EQ(-5.6f, C.m_Matrix[7]);
		EXPECT_FLOAT_EQ(11.92f, C.m_Matrix[8]);
	}

	TEST(Matrice, Substract)
	{
		Matrix C = A - B;

		EXPECT_FLOAT_EQ(6.0f, C.m_Matrix[0]);
		EXPECT_FLOAT_EQ(5.0f, C.m_Matrix[1]);
		EXPECT_FLOAT_EQ(6.0f, C.m_Matrix[2]);
		EXPECT_FLOAT_EQ(17.0f, C.m_Matrix[3]);
		EXPECT_FLOAT_EQ(0.17f, C.m_Matrix[4]);
		EXPECT_FLOAT_EQ(-9.22f, C.m_Matrix[5]);
		EXPECT_FLOAT_EQ(-8.0f, C.m_Matrix[6]);
		EXPECT_FLOAT_EQ(2.4f, C.m_Matrix[7]);
		EXPECT_FLOAT_EQ(5.92f, C.m_Matrix[8]);
	}

	TEST(Matrice, Scalar_Multiplication)
	{
		float b = 7.9f;

		Matrix C = A * b;

		EXPECT_FLOAT_EQ(7.9f, C.m_Matrix[0]);
		EXPECT_FLOAT_EQ(39.5f, C.m_Matrix[1]);
		EXPECT_FLOAT_EQ(63.2f, C.m_Matrix[2]);
		EXPECT_FLOAT_EQ(173.8f, C.m_Matrix[3]);
		EXPECT_FLOAT_EQ(3.95f, C.m_Matrix[4]);
		EXPECT_FLOAT_EQ(-1.738f, C.m_Matrix[5]);
		EXPECT_FLOAT_EQ(9.48f, C.m_Matrix[6]);
		EXPECT_FLOAT_EQ(-12.64f, C.m_Matrix[7]);
		EXPECT_FLOAT_EQ(70.468f, C.m_Matrix[8]);
	}

	TEST(Matrice, Matrix_Multiplication)
	{
		Matrix C = A * B;

		EXPECT_FLOAT_EQ(93.6f, C.m_Matrix[0]);
		EXPECT_FLOAT_EQ(-30.35f, C.m_Matrix[1]);
		EXPECT_FLOAT_EQ(71.0f, C.m_Matrix[2]);
		EXPECT_FLOAT_EQ(-109.524f, C.m_Matrix[3]);
		EXPECT_FLOAT_EQ(1.045f, C.m_Matrix[4]);
		EXPECT_FLOAT_EQ(47.84f, C.m_Matrix[5]);
		EXPECT_FLOAT_EQ(68.064f, C.m_Matrix[6]);
		EXPECT_FLOAT_EQ(-36.208f, C.m_Matrix[7]);
		EXPECT_FLOAT_EQ(14.76f, C.m_Matrix[8]);
	}

	TEST(Matrice, Vector_Multiplication_Right)
	{
		Vec3 b(0.6f, -0.4f, 22.4f);	

		Vec3 C = A * b;

		EXPECT_FLOAT_EQ(177.8f, C.x());
		EXPECT_FLOAT_EQ(8.072f, C.y());
		EXPECT_FLOAT_EQ(201.168f, C.z());
	}

	TEST(Matrice, Vector_Multiplication_Left)
	{
		Vec3 b(0.6f, -0.4f, 22.4f);

		Vec3 C = b * A;

		EXPECT_FLOAT_EQ(18.68f, C.x());
		EXPECT_FLOAT_EQ(-33.04f, C.y());
		EXPECT_FLOAT_EQ(204.696f, C.z());
	}

	TEST(Matrice, Identity)
	{
		Matrix C(-5.0f, 0.0f, 2.0f, 5.0f, 0.33f, 9.0f, 9.2f, -4.0f, 3.0f);
		C.Identity();

		EXPECT_FLOAT_EQ(1.0f, C.m_Matrix[0]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[1]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[2]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[3]);
		EXPECT_FLOAT_EQ(1.0f, C.m_Matrix[4]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[5]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[6]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[7]);
		EXPECT_FLOAT_EQ(1.0f, C.m_Matrix[8]);
	}

	TEST(Matrice, RotateX)
	{
		float rad = 0.62831853072f; //36 degree
		Vec3 b(5.3f, -20.7f, 0.33f);

		Matrix C;
		C.Identity();
		C.RotateX(rad);

		Vec3 D = C * b;

		EXPECT_FLOAT_EQ(5.3f, D.x());
		EXPECT_FLOAT_EQ(-16.940621f, D.y());
		EXPECT_FLOAT_EQ(-11.900179f, D.z());
	}

	TEST(Matrice, RotateY)
	{
		float rad = 0.62831853072f; //36 degree
		Vec3 b(5.3f, -20.7f, 0.33f);

		Matrix C;
		C.Identity();
		C.RotateY(rad);

		Vec3 D = C * b;

		EXPECT_FLOAT_EQ(4.4817592f, D.x());
		EXPECT_FLOAT_EQ(-20.7f, D.y());
		EXPECT_FLOAT_EQ(-2.8482862f, D.z());
	}

	TEST(Matrice, RotateZ)
	{
		float rad = 0.62831853072f; //36 degree
		Vec3 b(5.3f, -20.7f, 0.33f);

		Matrix C;
		C.Identity();
		C.RotateZ(rad);

		Vec3 D = C * b;

		EXPECT_FLOAT_EQ(16.454945f, D.x());
		EXPECT_FLOAT_EQ(-13.631390f, D.y());
		EXPECT_FLOAT_EQ(0.33f, D.z());
	}

	TEST(Matrice, Scale)
	{
		Vec3 b(0.6f, -0.4f, 22.4f);
		Vec3 f(2.5f, 8.1f, -3.6f);
		Matrix d;

		d.Scale(b);

		Vec3 C = d * f;

		EXPECT_FLOAT_EQ(1.5f, C.x());
		EXPECT_FLOAT_EQ(-3.24f, C.y());
		EXPECT_FLOAT_EQ(-80.64f, C.z());
	}

	TEST(Matrice, Translation)
	{
		Vec3 b(0.6f, -0.4f, 22.4f);
		Vec3 f(2.5f, 8.1f, -3.6f);
		Matrix d;

		Vec3 C = d.Translation(b, f);

		EXPECT_FLOAT_EQ(3.1f, C.x());
		EXPECT_FLOAT_EQ(7.7f, C.y());
		EXPECT_FLOAT_EQ(18.8f, C.z());
	}

	TEST(Matrice, Orthonormalization)
	{
		//The following calculator was used:
		//https://www.omnicalculator.com/math/gram-schmidt

		Matrix C;
		C = A.Orthonormalization();

		EXPECT_NEAR(0.1054f, C.m_Matrix[0], 0.0005f); //0.0005f error margin
		EXPECT_NEAR(0.5271f, C.m_Matrix[1], 0.0005f);
		EXPECT_NEAR(0.8433f, C.m_Matrix[2], 0.0005f);
		EXPECT_NEAR(0.9941f, C.m_Matrix[3], 0.0005f);
		EXPECT_NEAR(-0.0349f, C.m_Matrix[4], 0.0005f);
		EXPECT_NEAR(-0.1025f, C.m_Matrix[5], 0.0005f);
		EXPECT_NEAR(0.0246f, C.m_Matrix[6], 0.0005f);
		EXPECT_NEAR(-0.8491f, C.m_Matrix[7], 0.0005f);
		EXPECT_NEAR(0.5276f, C.m_Matrix[8], 0.0005f);
	}

	TEST(Matrice, Orthonormalization_divde_by_zero)
	{
		Matrix C;
		C.Set(0.0f, 0.0f, 0.0f, 1.0f, 39.0f, -43.0f, 9.22f, 4.0f, -3.44f);

		C = C.Orthonormalization();

		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[0]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[1]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[2]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[3]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[4]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[5]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[6]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[7]);
		EXPECT_FLOAT_EQ(0.0f, C.m_Matrix[8]);
	}

	TEST(Matrice, Transpose)
	{
		A.Transpose();

		EXPECT_FLOAT_EQ(1.0f, A.m_Matrix[0]);
		EXPECT_FLOAT_EQ(22.0f, A.m_Matrix[1]);
		EXPECT_FLOAT_EQ(1.2f, A.m_Matrix[2]);
		EXPECT_FLOAT_EQ(5.0f, A.m_Matrix[3]);
		EXPECT_FLOAT_EQ(0.5f, A.m_Matrix[4]);
		EXPECT_FLOAT_EQ(-1.6f, A.m_Matrix[5]);
		EXPECT_FLOAT_EQ(8.0f, A.m_Matrix[6]);
		EXPECT_FLOAT_EQ(-0.22f, A.m_Matrix[7]);
		EXPECT_FLOAT_EQ(8.92f, A.m_Matrix[8]);
	}
}