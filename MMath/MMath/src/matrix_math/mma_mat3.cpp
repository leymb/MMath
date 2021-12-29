#include "pch.h"
#include "matrix_math/mma_mat3.h"
#include "vector_math/mma_vector.h"

// || M00 | M01 | M02 ||
// || M10 | M11 | M12 ||
// || M20 | M21 | M22 ||

Mat3::Mat3(float a_Diagonal)
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
Mat3::Mat3(Vec3D& a_VecA, Vec3D& a_VecB, Vec3D& a_VecC)
{
	m_NM_[0][0] = a_VecA.m_X;
	m_NM_[1][0] = a_VecA.m_Y;
	m_NM_[2][0] = a_VecA.m_Z;

	m_NM_[0][1] = a_VecB.m_X;
	m_NM_[1][1] = a_VecB.m_Y;
	m_NM_[2][1] = a_VecB.m_Z;


	m_NM_[0][2] = a_VecC.m_X;
	m_NM_[1][2] = a_VecC.m_Y;
	m_NM_[2][2] = a_VecC.m_Z;
}

Mat3::Mat3(const float a_00, const float a_01, const float a_02,
           const float a_10, const float a_11, const float a_12,
           const float a_20, const float a_21, const float a_22)
{
	m_NM_[0][0] = a_00;
	m_NM_[0][1] = a_10;
	m_NM_[0][2] = a_20;

	m_NM_[1][0] = a_01;
	m_NM_[1][1] = a_11;
	m_NM_[1][2] = a_21;

	m_NM_[2][0] = a_02;
	m_NM_[2][1] = a_12;
	m_NM_[2][2] = a_22;
}

float& Mat3::operator()(const int n, const int m)
{
	return (m_NM_[m][n]);
}

// TODO: Make this return a vector that references the values for easy access
Vec3D Mat3::operator[](const int i)
{
	return {m_NM_[0][i], m_NM_[1][i], m_NM_[2][i]};
}
