#pragma once

#include "stdafx.h"
#include "Matrix.h"
struct Vector2
{
public:
	float X;
	float Y;
public:
	Vector2() : X(0), Y(0) {}
	Vector2(float InX, float InY) : X(InX), Y(InY) {}

	static float Dist(const Vector2 &V1, const Vector2 &V2);
	static float DistSquared(const Vector2 &V1, const Vector2 &V2);

	Vector2 operator *(const Matrix2 Mat) const;
	bool Equals(const Vector2& v, float Tolerance = KINDA_SMALL_NUMBER) const;

	Vector2 operator +(const Vector2& v) const;
	Vector2 operator -(const Vector2& v) const;
	Vector2 operator *(const Vector2& v) const;
	Vector2 operator /(const Vector2& v) const;

	float operator |(const Vector2& v) const; //내적
	float operator ^(const Vector2& v) const; //외적

	Vector2 operator +=(const Vector2& v);
	Vector2 operator -=(const Vector2& v);
	Vector2 operator /=(const Vector2& v);
	Vector2 operator *=(const Vector2& v);

	Vector2 Normalize(const Vector2& v) const;
};

FORCEINLINE bool Vector2::Equals(const Vector2 & v, float Tolerance) const
{
	return  fabs(X - v.X) <= Tolerance && fabs(Y - v.Y) <= Tolerance;
}
