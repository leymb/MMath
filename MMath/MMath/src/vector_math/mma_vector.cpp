#include "pch.h"
#include "vector_math/mma_vector.h"

#include <cmath>

Vec3D::Vec3D() : m_X(0.0f), m_Y(0.0f), m_Z(0.0f), m_W(0.0f)
{
}

Vec3D::Vec3D(float a_Value) : m_X(a_Value), m_Y(a_Value), m_Z(a_Value), m_W(0.0f)
{
}

Vec3D::Vec3D(float x, float y, float z) : m_X(x), m_Y(y), m_Z(z), m_W(0.0f)
{
}

Vec3D::Vec3D(float x, float y, float z, float w) :  m_X(x), m_Y(y), m_Z(z), m_W(w)
{
}

Vec3D Vec3D::operator+(const Vec3D& a_Vector) const
{
	return {
			this->m_X + a_Vector.m_X,
			this->m_Y + a_Vector.m_Y,
			this->m_Z + a_Vector.m_Z
			};
}

Vec3D Vec3D::operator-(const Vec3D& a_Vector) const
{
	return {
			this->m_X - a_Vector.m_X,
			this->m_Y - a_Vector.m_Y,
			this->m_Z - a_Vector.m_Z
			};
}

Vec3D Vec3D::operator*(const float a_Multiplier) const
{
	return {
			this->m_X * a_Multiplier,
			this->m_Y * a_Multiplier,
			this->m_Z * a_Multiplier
			};
}

Vec3D Vec3D::operator/(const float a_Divisor) const
{
	return {
			this->m_X / a_Divisor,
			this->m_Y / a_Divisor,
			this->m_Z / a_Divisor
			};
}

Vec3D& Vec3D::operator+=(const Vec3D& a_Vector)
{
	this->m_X += a_Vector.m_X;
	this->m_Y += a_Vector.m_Y;
	this->m_Z += a_Vector.m_Z;

	return *this;
}

Vec3D& Vec3D::operator-=(const Vec3D& a_Vector)
{
	this->m_X -= a_Vector.m_X;
	this->m_Y -= a_Vector.m_Y;
	this->m_Z -= a_Vector.m_Z;

	return *this;
}

Vec3D& Vec3D::operator*=(const float a_Multiplier)
{
	this->m_X *= a_Multiplier;
	this->m_Y *= a_Multiplier;
	this->m_Z *= a_Multiplier;

	return *this;
}

Vec3D& Vec3D::operator/=(const float a_Divisor)
{
	this->m_X /= a_Divisor;
	this->m_Y /= a_Divisor;
	this->m_Z /= a_Divisor;

	return *this;
}

float Vec3D::operator[](int a_Index)
{
	return (&m_X)[a_Index];
}

float Vec3D::SquaredMagnitude()
{
	return m_X * m_X + m_Y * m_Y + m_Z * m_Z;
}

float Vec3D::Magnitude()
{
	return sqrt(SquaredMagnitude());
}

float Vec3D::Dot(Vec3D a_Vec3D) const
{
	return
			  this->m_X * a_Vec3D.m_X
			+ this->m_Y * a_Vec3D.m_Y
			+ this->m_Z * a_Vec3D.m_Z;
}

Vec3D Vec3D::Cross(Vec3D a_Vec3D) const
{
	return{
		this->m_Y * a_Vec3D.m_Z - this->m_Z * a_Vec3D.m_Y,
		this->m_Z * a_Vec3D.m_X - this->m_X * a_Vec3D.m_Z,
		this->m_X * a_Vec3D.m_Y - this->m_Y * a_Vec3D.m_X
	};
}

/// <summary>
/// Calculates the scalar triple product in the form of
///	[this, VecB, VecC] = this.Dot(VecB.Cross(VecC))
/// </summary>
/// <param name="a_VecB">The second Vector</param>
/// <param name="a_VecC">The third Vector</param>
/// <returns></returns>
float Vec3D::ScalarTriple(Vec3D a_VecB, Vec3D a_VecC) const
{
	return this->Dot(a_VecB.Cross(a_VecC));
}

void Vec3D::Normalize()
{
	const float t_Divisor = 1.f/Magnitude();
	*this *= t_Divisor;
}

