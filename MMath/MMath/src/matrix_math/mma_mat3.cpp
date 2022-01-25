#include "pch.h"
#include "matrix_math/mma_mat3.h"
#include "vector_math/mma_vector.h"

// || M00 | M10 | M20 ||
// || M01 | M11 | M21 ||
// || M02 | M12 | M22 ||

Mat3::Mat3(const float a_Diagonal)
{
	m_NM_[0][0] = a_Diagonal;
	m_NM_[1][1] = a_Diagonal;
	m_NM_[2][2] = a_Diagonal;
}

/// <summary>
/// Creates a new Matrix from three Vec3Ds.
/// </summary>
/// <param name="a_VecA">Vec3D making up the first column of the Mat3</param>
/// <param name="a_VecB">Vec3D making up the second column of the Mat3</param>
/// <param name="a_VecC">Vec3D making up the third column of the Mat3</param>
Mat3::Mat3(const Vec3D& a_VecA, const Vec3D& a_VecB, const Vec3D& a_VecC)
{
	m_NM_[0][0] = a_VecA.m_X;
	m_NM_[0][1] = a_VecA.m_Y;
	m_NM_[0][2] = a_VecA.m_Z;

	m_NM_[1][0] = a_VecB.m_X;
	m_NM_[1][1] = a_VecB.m_Y;
	m_NM_[1][2] = a_VecB.m_Z;

	m_NM_[2][0] = a_VecC.m_X;
	m_NM_[2][1] = a_VecC.m_Y;
	m_NM_[2][2] = a_VecC.m_Z;
}

Mat3::Mat3(const float a_00, const float a_10, const float a_20,
           const float a_01, const float a_11, const float a_21,
           const float a_02, const float a_12, const float a_22)
{
	m_NM_[0][0] = a_00;
	m_NM_[0][1] = a_01;
	m_NM_[0][2] = a_02;

	m_NM_[1][0] = a_10;
	m_NM_[1][1] = a_11;
	m_NM_[1][2] = a_12;

	m_NM_[2][0] = a_20;
	m_NM_[2][1] = a_21;
	m_NM_[2][2] = a_22;
}

float& Mat3::operator()(const int n, const int m)
{
	return (m_NM_[n][m]);
}

// TODO: Make this return a vector that references the values for easy access
Vec3D& Mat3::operator[](const int i)
{
	return *reinterpret_cast<Vec3D *>(m_NM_[i]);
}

Mat3& Mat3::operator*=(Mat3& a_Mat3)
{
	const float t_00 =	  m_NM_[0][0] * a_Mat3[0][0]
						+ m_NM_[1][0] * a_Mat3[0][1]
						+ m_NM_[2][0] * a_Mat3[0][2];
	const float t_01 =    m_NM_[0][1] * a_Mat3[0][0]
						+ m_NM_[1][1] * a_Mat3[0][1]
						+ m_NM_[2][1] * a_Mat3[0][2];
	const float t_02 =    m_NM_[0][2] * a_Mat3[0][0]
						+ m_NM_[1][2] * a_Mat3[0][1]
						+ m_NM_[2][2] * a_Mat3[0][2];

	const float t_10 =    m_NM_[0][0] * a_Mat3[1][0]
						+ m_NM_[1][0] * a_Mat3[1][1]
						+ m_NM_[2][0] * a_Mat3[1][2];
	const float t_11 =    m_NM_[0][1] * a_Mat3[1][0]
						+ m_NM_[1][1] * a_Mat3[1][1]
						+ m_NM_[2][1] * a_Mat3[1][2];
	const float t_12 =    m_NM_[0][2] * a_Mat3[1][0]
						+ m_NM_[1][2] * a_Mat3[1][1]
						+ m_NM_[2][2] * a_Mat3[1][2];

	const float t_20 =    m_NM_[0][0] * a_Mat3[2][0]
						+ m_NM_[1][0] * a_Mat3[2][1]
						+ m_NM_[2][0] * a_Mat3[2][2];
	const float t_21 =    m_NM_[0][1] * a_Mat3[2][0]
						+ m_NM_[1][1] * a_Mat3[2][1]
						+ m_NM_[2][1] * a_Mat3[2][2];
	const float t_22 =    m_NM_[0][2] * a_Mat3[2][0]
						+ m_NM_[1][2] * a_Mat3[2][1]
						+ m_NM_[2][2] * a_Mat3[2][2];


	m_NM_[0][0] = t_00;
	m_NM_[0][1] = t_01;
	m_NM_[0][2] = t_02;

	m_NM_[1][0] = t_10;
	m_NM_[1][1] = t_11;
	m_NM_[1][2] = t_12;

	m_NM_[2][0] = t_20;
	m_NM_[2][1] = t_21;
	m_NM_[2][2] = t_22;


	return *this;
}

Mat3& Mat3::operator*=(const float a_Multiplicand)
{
	m_NM_[0][0] *= a_Multiplicand;
	m_NM_[0][1] *= a_Multiplicand;
	m_NM_[0][2] *= a_Multiplicand;

	m_NM_[1][0] *= a_Multiplicand;
	m_NM_[1][1] *= a_Multiplicand;
	m_NM_[1][2] *= a_Multiplicand;

	m_NM_[2][0] *= a_Multiplicand;
	m_NM_[2][1] *= a_Multiplicand;
	m_NM_[2][2] *= a_Multiplicand;

	return *this;
}

Mat3& Mat3::operator+=(Mat3& a_Mat3)
{
	m_NM_[0][0] += a_Mat3[0][0];
	m_NM_[0][1] += a_Mat3[0][1];
	m_NM_[0][2] += a_Mat3[0][2];

	m_NM_[1][0] += a_Mat3[1][0];
	m_NM_[1][1] += a_Mat3[1][1];
	m_NM_[1][2] += a_Mat3[1][2];

	m_NM_[2][0] += a_Mat3[2][0];
	m_NM_[2][1] += a_Mat3[2][1];
	m_NM_[2][2] += a_Mat3[2][2];

	return *this;
}

Mat3& Mat3::operator-=(Mat3& a_Mat3)
{
	m_NM_[0][0] -= a_Mat3[0][0];
	m_NM_[0][1] -= a_Mat3[0][1];
	m_NM_[0][2] -= a_Mat3[0][2];

	m_NM_[1][0] -= a_Mat3[1][0];
	m_NM_[1][1] -= a_Mat3[1][1];
	m_NM_[1][2] -= a_Mat3[1][2];

	m_NM_[2][0] -= a_Mat3[2][0];
	m_NM_[2][1] -= a_Mat3[2][1];
	m_NM_[2][2] -= a_Mat3[2][2];

	return *this;
}

Mat3& Mat3::operator+=(float a_Addend)
{
	m_NM_[0][0] += a_Addend;
	m_NM_[0][1] += a_Addend;
	m_NM_[0][2] += a_Addend;

	m_NM_[1][0] += a_Addend;
	m_NM_[1][1] += a_Addend;
	m_NM_[1][2] += a_Addend;

	m_NM_[2][0] += a_Addend;
	m_NM_[2][1] += a_Addend;
	m_NM_[2][2] += a_Addend;

	return *this;
}

Mat3& Mat3::operator-=(float a_Subtrahend)
{
	m_NM_[0][0] -= a_Subtrahend;
	m_NM_[0][1] -= a_Subtrahend;
	m_NM_[0][2] -= a_Subtrahend;

	m_NM_[1][0] -= a_Subtrahend;
	m_NM_[1][1] -= a_Subtrahend;
	m_NM_[1][2] -= a_Subtrahend;

	m_NM_[2][0] -= a_Subtrahend;
	m_NM_[2][1] -= a_Subtrahend;
	m_NM_[2][2] -= a_Subtrahend;

	return *this;
}

Mat3 Mat3::operator*(Mat3& a_Mat3)
{
	const float t_00 =	  m_NM_[0][0] * a_Mat3[0][0]
						+ m_NM_[1][0] * a_Mat3[0][1]
						+ m_NM_[2][0] * a_Mat3[0][2];
	const float t_01 =    m_NM_[0][1] * a_Mat3[0][0]
						+ m_NM_[1][1] * a_Mat3[0][1]
						+ m_NM_[2][1] * a_Mat3[0][2];
	const float t_02 =    m_NM_[0][2] * a_Mat3[0][0]
						+ m_NM_[1][2] * a_Mat3[0][1]
						+ m_NM_[2][2] * a_Mat3[0][2];

	const float t_10 =    m_NM_[0][0] * a_Mat3[1][0]
						+ m_NM_[1][0] * a_Mat3[1][1]
						+ m_NM_[2][0] * a_Mat3[1][2];
	const float t_11 =    m_NM_[0][1] * a_Mat3[1][0]
						+ m_NM_[1][1] * a_Mat3[1][1]
						+ m_NM_[2][1] * a_Mat3[1][2];
	const float t_12 =    m_NM_[0][2] * a_Mat3[1][0]
						+ m_NM_[1][2] * a_Mat3[1][1]
						+ m_NM_[2][2] * a_Mat3[1][2];

	const float t_20 =    m_NM_[0][0] * a_Mat3[2][0]
						+ m_NM_[1][0] * a_Mat3[2][1]
						+ m_NM_[2][0] * a_Mat3[2][2];
	const float t_21 =    m_NM_[0][1] * a_Mat3[2][0]
						+ m_NM_[1][1] * a_Mat3[2][1]
						+ m_NM_[2][1] * a_Mat3[2][2];
	const float t_22 =    m_NM_[0][2] * a_Mat3[2][0]
						+ m_NM_[1][2] * a_Mat3[2][1]
						+ m_NM_[2][2] * a_Mat3[2][2];

	return {
				t_00, t_10, t_20,
				t_01, t_11, t_21,
				t_02, t_12, t_22
			};
}

Mat3 Mat3::operator*(const float a_Multiplicand)
{
	float t_00 = m_NM_[0][0] * a_Multiplicand;
	float t_01 = m_NM_[0][1] * a_Multiplicand;
	float t_02 = m_NM_[0][2] * a_Multiplicand;

	float t_10 = m_NM_[1][0] * a_Multiplicand;
	float t_11 = m_NM_[1][1] * a_Multiplicand;
	float t_12 = m_NM_[1][2] * a_Multiplicand;

	float t_20 = m_NM_[2][0] * a_Multiplicand;
	float t_21 = m_NM_[2][1] * a_Multiplicand;
	float t_22 = m_NM_[2][2] * a_Multiplicand;

	return	{
					t_00, t_10, t_20,
					t_01, t_11, t_21,
					t_02, t_12, t_22
				};
}

Vec3D Mat3::operator*(Vec3D& a_Vec3D)
{
	float t_X =   m_NM_[0][0] * a_Vec3D.m_X
				+ m_NM_[1][0] * a_Vec3D.m_Y
				+ m_NM_[2][0] * a_Vec3D.m_Z;

	float t_Y =   m_NM_[0][1] * a_Vec3D.m_X
				+ m_NM_[1][1] * a_Vec3D.m_Y
				+ m_NM_[2][1] * a_Vec3D.m_Z;

	float t_Z =   m_NM_[0][2] * a_Vec3D.m_X
				+ m_NM_[1][2] * a_Vec3D.m_Y
				+ m_NM_[2][2] * a_Vec3D.m_Z;

	return {t_X, t_Y, t_Z};
}

Mat3 Mat3::operator+(Mat3& a_Mat3)
{
	float t_00 = m_NM_[0][0] + a_Mat3[0][0];
	float t_10 = m_NM_[1][0] + a_Mat3[1][0];
	float t_20 = m_NM_[2][0] + a_Mat3[2][0];

	float t_01 = m_NM_[0][1] + a_Mat3[0][1];
	float t_11 = m_NM_[1][1] + a_Mat3[1][1];
	float t_21 = m_NM_[2][1] + a_Mat3[2][1];

	float t_02 = m_NM_[0][2] + a_Mat3[0][2];
	float t_12 = m_NM_[1][2] + a_Mat3[1][2];
	float t_22 = m_NM_[2][2] + a_Mat3[2][2];

	return {
				t_00, t_10, t_20,
				t_01, t_11, t_21,
				t_02, t_12, t_22
			};
}

Mat3 Mat3::operator+(const float a_Addend)
{
	
	float t_00 = m_NM_[0][0] + a_Addend;
	float t_10 = m_NM_[1][0] + a_Addend;
	float t_20 = m_NM_[2][0] + a_Addend;

	float t_01 = m_NM_[0][1] + a_Addend;
	float t_11 = m_NM_[1][1] + a_Addend;
	float t_21 = m_NM_[2][1] + a_Addend;

	float t_02 = m_NM_[0][2] + a_Addend;
	float t_12 = m_NM_[1][2] + a_Addend;
	float t_22 = m_NM_[2][2] + a_Addend;

	return {
				t_00, t_10, t_20,
				t_01, t_11, t_21,
				t_02, t_12, t_22
			};
}

Mat3 Mat3::operator-(Mat3& a_Mat3)
{
	float t_00 = m_NM_[0][0] - a_Mat3[0][0];
	float t_10 = m_NM_[1][0] - a_Mat3[1][0];
	float t_20 = m_NM_[2][0] - a_Mat3[2][0];

	float t_01 = m_NM_[0][1] - a_Mat3[0][1];
	float t_11 = m_NM_[1][1] - a_Mat3[1][1];
	float t_21 = m_NM_[2][1] - a_Mat3[2][1];

	float t_02 = m_NM_[0][2] - a_Mat3[0][2];
	float t_12 = m_NM_[1][2] - a_Mat3[1][2];
	float t_22 = m_NM_[2][2] - a_Mat3[2][2];

	return {
				t_00, t_10, t_20,
				t_01, t_11, t_21,
				t_02, t_12, t_22
			};
}

Mat3 Mat3::operator-(float a_Subtrahend)
{
	float t_00 = m_NM_[0][0] - a_Subtrahend;
	float t_10 = m_NM_[1][0] - a_Subtrahend;
	float t_20 = m_NM_[2][0] - a_Subtrahend;

	float t_01 = m_NM_[0][1] - a_Subtrahend;
	float t_11 = m_NM_[1][1] - a_Subtrahend;
	float t_21 = m_NM_[2][1] - a_Subtrahend;

	float t_02 = m_NM_[0][2] - a_Subtrahend;
	float t_12 = m_NM_[1][2] - a_Subtrahend;
	float t_22 = m_NM_[2][2] - a_Subtrahend;

	return {
				t_00, t_10, t_20,
				t_01, t_11, t_21,
				t_02, t_12, t_22
			};
}
