
#include "stdafx.h"
#include "Vector.h"

float Vector2::Dist(const Vector2 &V1, const Vector2 &V2)
{
	return sqrtf(Vector2::DistSquared(V1, V2));
}

float Vector2::DistSquared(const Vector2 &V1, const Vector2 &V2)
{
	return (V2.X - V1.X) * (V2.X - V1.X) + (V2.Y - V1.Y) * (V2.Y - V1.Y);
}

Vector2 Vector2::operator*(Matrix2 Mat) const //원본보호
{
	Vector2 result;
	result.X = X * Mat._11 + Y * Mat._12;
	result.Y = X * Mat._21 + Y * Mat._22;

	return result;
}

Vector2 Vector2::operator*(const Vector2& v) const
{
	return Vector2(X*v.X, Y*v.Y);
}

Vector2 Vector2::operator+(const Vector2& v) const
{ 
	return Vector2(X + v.X, Y + v.Y);
}

Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2(X - v.X, Y - v.Y);
}

Vector2 Vector2::operator/(const Vector2& v) const
{
	return Vector2( X / v.X, Y / v.Y );
}

float Vector2::operator|(const Vector2& v) const
{
	return X * v.X + Y * v.Y;
}

float Vector2::operator^(const Vector2& v) const
{
	return X * v.Y - Y * v.X;
}

Vector2 Vector2::operator+=(const Vector2& v)
{
	X += v.X;
	Y += v.Y;
	return *this;
}

Vector2 Vector2::operator-=(const Vector2& v)
{
	X -= v.X;
	Y -= v.Y;
	return *this;
}

Vector2 Vector2::operator/=(const Vector2& v)
{
	X /= v.X;
	Y /= v.Y;
	return *this;
}

Vector2 Vector2::operator*=(const Vector2& v)
{
	X *= v.X;
	Y *= v.Y;
	return *this;
}

Vector2 Vector2::Normalize(const Vector2 & v) const
{
	Vector2 result = v;
	result.X /= sqrtf(v.X * v.X + v.Y * v.Y);
	result.Y /= sqrtf(v.X * v.X + v.Y * v.Y);
	return result;
}

