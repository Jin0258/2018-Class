#pragma once

#include "stdafx.h"

struct Matrix2
{
public:
	float _11, _12;
	float _21, _22;

	Matrix2() {};
	Matrix2(float m11, float m12, float m21, float m22)
	{
		_11 = m11;
		_12 = m12;

		_21 = m21;
		_22 = m22;
	}

	

	void SetScale(float a, float b)
	{
		SetIdentity();
		_11 = a;
		_22 = b;
		// Add Code Here  _11 = a;  _22 = b; 
	}

	void SetRotate(float angle)
	{
		float Radian = Deg2Rad(angle);
		_11 = cosf(Radian);
		_12 = sinf(Radian);
		_21 = -sinf(Radian);
		_22 = cosf(Radian);
	}

	void SetIdentity()
	{
		_11 = 1.0f;
		_12 = 0.0f;
		_21 = 0.0f;
		_22 = 1.0f;
	};

	Matrix2 operator *(const Matrix2 Other) const;

};

struct Matrix3
{
public:
	float _11, _12, _13;
	float _21, _22, _23;
	float _31, _32, _33;

	Matrix3() {
		_11 = 0.0;
		_12 = 0.0;
		_13 = 0.0;
		_21 = 0.0;
		_22 = 0.0;
		_23 = 0.0;
		_31 = 0.0;
		_32 = 0.0;
		_33 = 0.0;
	};


	void SetIdentity()
	{
		_11 = 1.0;
		_12 = 0.0;
		_13 = 0.0;
		_21 = 0.0;
		_22 = 1.0;
		_23 = 0.0;
		_31 = 0.0;
		_32 = 0.0;
		_33 = 1.0;
	};

	void SetTranslate(float X, float Y) {
		_11 = 1.0;
		_12 = 0.0;
		_13 = X;
		_21 = 0.0;
		_22 = 1.0;
		_23 = Y;
		_31 = 0.0;
		_32 = 0.0;
		_33 = 1.0;
	}

	void SetScale(float a)
	{
		SetIdentity();
		_11 = a;
		_22 = a;
		// Add Code Here  _11 = a;  _22 = b; 
	}

	void SetRotate(float angle)
	{
		float Radian = Deg2Rad(angle);
		_11 = cosf(Radian);
		_12 = sinf(Radian);
		_21 = -sinf(Radian);
		_22 = cosf(Radian);
	}
};