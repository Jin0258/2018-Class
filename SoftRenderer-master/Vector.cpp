
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

Vector3 Vector3::operator*(const float& scalar) const
{
	Vector3 result;
	result.X = X * scalar;
	result.Y = Y * scalar;
	result.Z = Z;
	return result;
}

Vector3 Vector3::operator*(const Matrix3 & M) const
{
	Vector3 result;
	result.X = X * M._11 + Y * M._12 + Z * M._13;
	result.Y = X * M._21 + Y * M._22 + Z * M._23;
	result.Z = 1.0f;
	return result;
}

Vector3 Vector3::operator+(const Vector3 & v) const
{
	Vector3 result;
	result.X = X + v.X;
	result.Y = Y + v.Y;
	result.Z = 0.0f;
	return result;
}

Vector3 Vector3::operator-(const Vector3 & v) const
{
	Vector3 result;
	result.X = X - v.X;
	result.Y = Y - v.Y;
	result.Z = 0.0f;
	return result;
}

float Vector3::Dist()
{
	return sqrtf(X * X + Y * Y);
}


