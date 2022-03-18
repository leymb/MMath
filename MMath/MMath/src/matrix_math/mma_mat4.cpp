#include "pch.h"
#include "matrix_math/mma_mat4.h"

// || M00 | M10 | M20 | M30||
// || M01 | M11 | M21 | M31||
// || M02 | M12 | M22 | M32||
// || M03 | M13 | M23 | M33||

Mat4::Mat4(const float a_Diagonal)
{
	m_NM_[0][0] = a_Diagonal;
	m_NM_[1][1] = a_Diagonal;
	m_NM_[2][2] = a_Diagonal;
	m_NM_[3][3] = a_Diagonal;
}

Mat4::Mat4(const float a_00, const float a_10, const float a_20, const float a_30,
           const float a_01, const float a_11, const float a_21, const float a_31,
           const float a_02, const float a_12, const float a_22, const float a_32,
           const float a_03, const float a_13, const float a_23, const float a_33
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

float& Mat4::operator()(const int n, const int m)
{
	return m_NM_[n][m];
}

Mat4& Mat4::operator*=(Mat4& a_Mat4)
{
	m_NM_[0][0] *= a_Mat4(0,0);
	m_NM_[0][1] *= a_Mat4(0, 1);
	m_NM_[0][2] *= a_Mat4(0, 2);
	m_NM_[0][3] *= a_Mat4(0, 3);

	m_NM_[1][0] *= a_Mat4(1, 0);
	m_NM_[1][1] *= a_Mat4(1, 1);
	m_NM_[1][2] *= a_Mat4(1, 2);
	m_NM_[1][3] *= a_Mat4(1, 3);

	m_NM_[2][0] *= a_Mat4(2, 0);
	m_NM_[2][1] *= a_Mat4(2, 1);
	m_NM_[2][2] *= a_Mat4(2, 2);
	m_NM_[2][3] *= a_Mat4(2, 3);

	m_NM_[3][0] *= a_Mat4(3, 0);
	m_NM_[3][1] *= a_Mat4(3, 1);
	m_NM_[3][2] *= a_Mat4(3, 2);
	m_NM_[3][3] *= a_Mat4(3, 3);

	return *this;
}

Mat4& Mat4::operator*=(const float a_Multiplicand)
{
	// todo replace with vec4& as soon as its implemented
	Vec3D& t_Column0 = reinterpret_cast<Vec3D&>(m_NM_[0]);
	Vec3D& t_Column1 = reinterpret_cast<Vec3D&>(m_NM_[1]);
	Vec3D& t_Column2 = reinterpret_cast<Vec3D&>(m_NM_[2]);
	Vec3D& t_Column3 = reinterpret_cast<Vec3D&>(m_NM_[3]);

	t_Column0	*= a_Multiplicand;
	m_NM_[0][3] *= a_Multiplicand;

	t_Column1	*= a_Multiplicand;
	m_NM_[1][3] *= a_Multiplicand;

	t_Column2	*= a_Multiplicand;
	m_NM_[2][3] *= a_Multiplicand;

	t_Column3	*= a_Multiplicand;
	m_NM_[3][3] *= a_Multiplicand;

	return *this;
}

Mat4& Mat4::operator+=(Mat4& a_Mat4)
{
	m_NM_[0][0] += a_Mat4(0,0);
	m_NM_[0][1] += a_Mat4(0, 1);
	m_NM_[0][2] += a_Mat4(0, 2);
	m_NM_[0][3] += a_Mat4(0, 3);

	m_NM_[1][0] += a_Mat4(1, 0);
	m_NM_[1][1] += a_Mat4(1, 1);
	m_NM_[1][2] += a_Mat4(1, 2);
	m_NM_[1][3] += a_Mat4(1, 3);

	m_NM_[2][0] += a_Mat4(2, 0);
	m_NM_[2][1] += a_Mat4(2, 1);
	m_NM_[2][2] += a_Mat4(2, 2);
	m_NM_[2][3] += a_Mat4(2, 3);

	m_NM_[3][0] += a_Mat4(3, 0);
	m_NM_[3][1] += a_Mat4(3, 1);
	m_NM_[3][2] += a_Mat4(3, 2);
	m_NM_[3][3] += a_Mat4(3, 3);

	return *this;
}

Mat4& Mat4::operator-=(Mat4& a_Mat4)
{
	m_NM_[0][0] -= a_Mat4(0,0);
	m_NM_[0][1] -= a_Mat4(0, 1);
	m_NM_[0][2] -= a_Mat4(0, 2);
	m_NM_[0][3] -= a_Mat4(0, 3);

	m_NM_[1][0] -= a_Mat4(1, 0);
	m_NM_[1][1] -= a_Mat4(1, 1);
	m_NM_[1][2] -= a_Mat4(1, 2);
	m_NM_[1][3] -= a_Mat4(1, 3);

	m_NM_[2][0] -= a_Mat4(2, 0);
	m_NM_[2][1] -= a_Mat4(2, 1);
	m_NM_[2][2] -= a_Mat4(2, 2);
	m_NM_[2][3] -= a_Mat4(2, 3);

	m_NM_[3][0] -= a_Mat4(3, 0);
	m_NM_[3][1] -= a_Mat4(3, 1);
	m_NM_[3][2] -= a_Mat4(3, 2);
	m_NM_[3][3] -= a_Mat4(3, 3);

	return *this;
}

Mat4& Mat4::operator+=(const float a_Addend)
{
	// todo replace with vec4& as soon as its implemented
	Vec3D& t_Column0 = reinterpret_cast<Vec3D&>(m_NM_[0]);
	Vec3D& t_Column1 = reinterpret_cast<Vec3D&>(m_NM_[1]);
	Vec3D& t_Column2 = reinterpret_cast<Vec3D&>(m_NM_[2]);
	Vec3D& t_Column3 = reinterpret_cast<Vec3D&>(m_NM_[3]);

	t_Column0 += a_Addend;
	m_NM_[0][3] += a_Addend;

	t_Column1 += a_Addend;
	m_NM_[1][3] += a_Addend;

	t_Column2 += a_Addend;
	m_NM_[2][3] += a_Addend;

	t_Column3 += a_Addend;
	m_NM_[3][3] += a_Addend;

	return *this;
}

Mat4& Mat4::operator-=(const float a_Subtrahend)
{
	// todo replace with vec4& as soon as its implemented
	Vec3D& t_Column0 = reinterpret_cast<Vec3D&>(m_NM_[0]);
	Vec3D& t_Column1 = reinterpret_cast<Vec3D&>(m_NM_[1]);
	Vec3D& t_Column2 = reinterpret_cast<Vec3D&>(m_NM_[2]);
	Vec3D& t_Column3 = reinterpret_cast<Vec3D&>(m_NM_[3]);

	t_Column0 -= a_Subtrahend;
	m_NM_[0][3] -= a_Subtrahend;

	t_Column1 -= a_Subtrahend;
	m_NM_[1][3] -= a_Subtrahend;

	t_Column2 -= a_Subtrahend;
	m_NM_[2][3] -= a_Subtrahend;

	t_Column3 -= a_Subtrahend;
	m_NM_[3][3] -= a_Subtrahend;

	return *this;
}

bool Mat4::operator==(Mat4& a_Mat4) const
{
	if (
			m_NM_[0][0] == a_Mat4(0, 0)
		&&	m_NM_[0][1] == a_Mat4(0, 1)
		&&	m_NM_[0][2] == a_Mat4(0, 2)
		&&	m_NM_[0][3] == a_Mat4(0, 3)

		&&	m_NM_[1][0] == a_Mat4(1, 0)
		&&	m_NM_[1][1] == a_Mat4(1, 1)
		&&	m_NM_[1][2] == a_Mat4(1, 2)
		&&	m_NM_[1][3] == a_Mat4(1, 3)

		&&	m_NM_[2][0] == a_Mat4(2, 0)
		&&	m_NM_[2][1] == a_Mat4(2, 1)
		&&	m_NM_[2][2] == a_Mat4(2, 2)
		&&	m_NM_[2][3] == a_Mat4(2, 3)

		&&	m_NM_[3][0] == a_Mat4(3, 0)
		&&	m_NM_[3][1] == a_Mat4(3, 1)
		&&	m_NM_[3][2] == a_Mat4(3, 2)
		&&	m_NM_[3][3] == a_Mat4(3, 3)
		)
	{
		return true;
	}

	return false;
}

Mat4 Mat4::operator+(Mat4& a_Mat4) const
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

