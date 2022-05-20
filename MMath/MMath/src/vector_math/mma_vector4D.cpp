#include "pch.h"
#include "vector_math/mma_vector4D.h"

#include "matrix_math/mma_mat4.h"

namespace mma
{

	/// <summary>	Default constructor. </summary>
	Vec4D::Vec4D() : m_X(0.0f), m_Y(0.0f), m_Z(0.0f), m_W(0.0f)
	{
	}

	/// <summary>	Constructor. </summary>
	/// <param name="a_Value">	A value that is assigned to all members. </param>

	Vec4D::Vec4D(const float a_Value) : m_X(a_Value), m_Y(a_Value), m_Z(a_Value), m_W(a_Value)
	{
	}

	/// <summary>	Constructor. </summary>
	/// <param name="a_X">	The x coordinate. </param>
	/// <param name="a_Y">	The y coordinate. </param>
	/// <param name="a_Z">	The z coordinate. </param>
	/// <param name="a_W">	The w coordinate. </param>

	Vec4D::Vec4D(const float a_X, const float a_Y, const float a_Z, const float a_W)
	: m_X(a_X), m_Y(a_Y), m_Z(a_Z), m_W(a_W)
	{
	}

	Vec4D Vec4D::operator+(const Vec4D& a_Vector) const
	{
		return {	m_X + a_Vector.m_X,
					m_Y + a_Vector.m_Y,
					m_Z + a_Vector.m_Z,
					m_W + a_Vector.m_W};
	}

	Vec4D& Vec4D::operator+=(const Vec4D& a_Vector)
	{
		m_X += a_Vector.m_X;
		m_Y += a_Vector.m_Y;
		m_Z += a_Vector.m_Z;
		m_W += a_Vector.m_W;

		return *this;
	}

	Vec4D Vec4D::operator+(const float a_Addend) const
	{
		return {
					m_X + a_Addend,
					m_Y + a_Addend,
					m_Z + a_Addend,
					m_W + a_Addend
		};
	}

	Vec4D& Vec4D::operator+=(const float a_Addend)
	{
		m_X += a_Addend;
		m_Y += a_Addend;
		m_Z += a_Addend;
		m_W += a_Addend;

		return *this;
	}

	Vec4D Vec4D::operator-(const Vec4D& a_Vector) const
	{
		return {	m_X - a_Vector.m_X,
					m_Y - a_Vector.m_Y,
					m_Z - a_Vector.m_Z,
					m_W - a_Vector.m_W};
	}

	Vec4D& Vec4D::operator-=(const Vec4D& a_Vector)
	{
		m_X -= a_Vector.m_X;
		m_Y -= a_Vector.m_Y;
		m_Z -= a_Vector.m_Z;
		m_W -= a_Vector.m_W;

		return *this;
	}

	Vec4D Vec4D::operator-(const float a_Subtrahend) const
	{
		return {
					m_X - a_Subtrahend,
					m_Y - a_Subtrahend,
					m_Z - a_Subtrahend,
					m_W - a_Subtrahend
		};
	}

	Vec4D& Vec4D::operator-=(const float a_Subtrahend)
	{
		m_X -= a_Subtrahend;
		m_Y -= a_Subtrahend;
		m_Z -= a_Subtrahend;
		m_W -= a_Subtrahend;

		return *this;
	}

	Vec4D Vec4D::operator*(const float a_Multiplier)
	{
		return {	m_X * a_Multiplier,
					m_Y * a_Multiplier,
					m_Z * a_Multiplier,
					m_W * a_Multiplier};
	}

	Vec4D& Vec4D::operator*=(const float a_Multiplier)
	{
		m_X *= a_Multiplier;
		m_Y *= a_Multiplier;
		m_Z *= a_Multiplier;
		m_W *= a_Multiplier;

		return *this;
	}

	//Vec4D Vec4D::operator*(Mat4 a_Mat4)
	//{
	//
	//}

	/// <summary>	Array indexer operator. </summary>
	/// <param name="a_Index">	Zero-based index of the Vector. </param>
	/// <returns>	The indexed value. </returns>

	float& Vec4D::operator[](const int a_Index)
	{
		return (&m_X)[a_Index];
	}

}
