#include "pch.h"
#include "matrix_math/mma_mat4.h"

// || M00 | M10 | M20 | M30||
// || M01 | M11 | M21 | M31||
// || M02 | M12 | M22 | M32||
// || M03 | M13 | M23 | M33||

Mat4::Mat4(float a_Diagonal)
{
	m_NM_[0][0] = a_Diagonal;
	m_NM_[1][1] = a_Diagonal;
	m_NM_[2][2] = a_Diagonal;
	m_NM_[3][3] = a_Diagonal;
}

Mat4::Mat4(	float a_00, float a_10, float a_20, float a_30, 
			float a_01, float a_11, float a_21, float a_31, 
			float a_02, float a_12, float a_22, float a_32, 
			float a_03, float a_13, float a_23, float a_33
		  )
{
	m_NM_[0][0] = a_00;
	m_NM_[0][1] = a_01;
	m_NM_[0][2] = a_02;
	m_NM_[0][3] = a_03;

	m_NM_[1][0] = a_10;
	m_NM_[1][1] = a_11;
	m_NM_[1][2] = a_12;
	m_NM_[1][3] = a_13;

	m_NM_[2][0] = a_20;
	m_NM_[2][1] = a_21;
	m_NM_[2][2] = a_22;
	m_NM_[2][3] = a_23;

	m_NM_[3][0] = a_30;
	m_NM_[3][1] = a_31;
	m_NM_[3][2] = a_32;
	m_NM_[3][3] = a_33;
}

float& Mat4::operator()(int n, int m)
{
	return m_NM_[n][m];
}

Mat4 Mat4::operator+(Mat4& a_Mat4)
{
	float t_00 = m_NM_[0][0] + a_Mat4(0,0);
	float t_01 = m_NM_[0][1] + a_Mat4(0, 1);
	float t_02 = m_NM_[0][2] + a_Mat4(0, 2);
	float t_03 = m_NM_[0][3] + a_Mat4(0, 3);

	float t_10 = m_NM_[1][0] + a_Mat4(1, 0);
	float t_11 = m_NM_[1][1] + a_Mat4(1, 1);
	float t_12 = m_NM_[1][2] + a_Mat4(1, 2);
	float t_13 = m_NM_[1][3] + a_Mat4(1, 3);

	float t_20 = m_NM_[2][0] + a_Mat4(2, 0);
	float t_21 = m_NM_[2][1] + a_Mat4(2, 1);
	float t_22 = m_NM_[2][2] + a_Mat4(2, 2);
	float t_23 = m_NM_[2][3] + a_Mat4(2, 3);

	float t_30 = m_NM_[3][0] + a_Mat4(3, 0);
	float t_31 = m_NM_[3][1] + a_Mat4(3, 1);
	float t_32 = m_NM_[3][2] + a_Mat4(3, 2);
	float t_33 = m_NM_[3][3] + a_Mat4(3, 3);

	return {
				t_00, t_10, t_20, t_30,
				t_01, t_11, t_21, t_31,
				t_02, t_12, t_22, t_32,
				t_03, t_13, t_23, t_33
			};
}

