#include "pch.h"
#include "matrix_math/mma_mat4.h"
#include "vector_math/mma_vector4D.h"
#include "vector_math/mma_vector3D.h"

namespace mma
{
	// 	|| M00 | M10 | M20 | M30||
	// 	|| M01 | M11 | M21 | M31||
	// 	|| M02 | M12 | M22 | M32||
	// 	|| M03 | M13 | M23 | M33||.

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

	Vec4D& Mat4::operator[](int i)
	{
		return *reinterpret_cast<Vec4D*>(m_NM_[i]);
	}

	//TODO: Fix this
	Mat4& Mat4::operator*=(Mat4& a_Mat4)
	{
		float t_00 =  m_NM_[0][0] * a_Mat4[0][0]
					+ m_NM_[1][0] * a_Mat4[0][1]
					+ m_NM_[2][0] * a_Mat4[0][2]
					+ m_NM_[3][0] * a_Mat4[0][3];
		float t_01 =  m_NM_[0][1] * a_Mat4[0][0]
					+ m_NM_[1][1] * a_Mat4[0][1]
					+ m_NM_[2][1] * a_Mat4[0][2]
					+ m_NM_[3][1] * a_Mat4[0][3];
		float t_02 =  m_NM_[0][2] * a_Mat4[0][0]
					+ m_NM_[1][2] * a_Mat4[0][1]
					+ m_NM_[2][2] * a_Mat4[0][2]
					+ m_NM_[3][2] * a_Mat4[0][3];
		float t_03 =  m_NM_[0][3] * a_Mat4[0][0]
					+ m_NM_[1][3] * a_Mat4[0][1]
					+ m_NM_[2][3] * a_Mat4[0][2]
					+ m_NM_[3][3] * a_Mat4[0][3];

		float t_10 =  m_NM_[0][0] * a_Mat4[1][0]
					+ m_NM_[1][0] * a_Mat4[1][1]
					+ m_NM_[2][0] * a_Mat4[1][2]
					+ m_NM_[3][0] * a_Mat4[1][3];
		float t_11 =  m_NM_[0][1] * a_Mat4[1][0]
					+ m_NM_[1][1] * a_Mat4[1][1]
					+ m_NM_[2][1] * a_Mat4[1][2]
					+ m_NM_[3][1] * a_Mat4[1][3];
		float t_12 =  m_NM_[0][2] * a_Mat4[1][0]
					+ m_NM_[1][2] * a_Mat4[1][1]
					+ m_NM_[2][2] * a_Mat4[1][2]
					+ m_NM_[3][2] * a_Mat4[1][3];
		float t_13 =  m_NM_[0][3] * a_Mat4[1][0]
					+ m_NM_[1][3] * a_Mat4[1][1]
					+ m_NM_[2][3] * a_Mat4[1][2]
					+ m_NM_[3][3] * a_Mat4[1][3];

		float t_20 =  m_NM_[0][0] * a_Mat4[2][0]
					+ m_NM_[1][0] * a_Mat4[2][1]
					+ m_NM_[2][0] * a_Mat4[2][2]
					+ m_NM_[3][0] * a_Mat4[2][3];
		float t_21 =  m_NM_[0][1] * a_Mat4[2][0]
					+ m_NM_[1][1] * a_Mat4[2][1]
					+ m_NM_[2][1] * a_Mat4[2][2]
					+ m_NM_[3][1] * a_Mat4[2][3];
		float t_22 =  m_NM_[0][2] * a_Mat4[2][0]
					+ m_NM_[1][2] * a_Mat4[2][1]
					+ m_NM_[2][2] * a_Mat4[2][2]
					+ m_NM_[3][2] * a_Mat4[2][3];
		float t_23 =  m_NM_[0][3] * a_Mat4[2][0]
					+ m_NM_[1][3] * a_Mat4[2][1]
					+ m_NM_[2][3] * a_Mat4[2][2]
					+ m_NM_[3][3] * a_Mat4[2][3];

		float t_30 =  m_NM_[0][0] * a_Mat4[3][0]
					+ m_NM_[1][0] * a_Mat4[3][1]
					+ m_NM_[2][0] * a_Mat4[3][2]
					+ m_NM_[3][0] * a_Mat4[3][3];
		float t_31 =  m_NM_[0][1] * a_Mat4[3][0]
					+ m_NM_[1][1] * a_Mat4[3][1]
					+ m_NM_[2][1] * a_Mat4[3][2]
					+ m_NM_[3][1] * a_Mat4[3][3];
		float t_32 =  m_NM_[0][2] * a_Mat4[3][0]
					+ m_NM_[1][2] * a_Mat4[3][1]
					+ m_NM_[2][2] * a_Mat4[3][2]
					+ m_NM_[3][2] * a_Mat4[3][3];
		float t_33 =  m_NM_[0][3] * a_Mat4[3][0]
					+ m_NM_[1][3] * a_Mat4[3][1]
					+ m_NM_[2][3] * a_Mat4[3][2]
					+ m_NM_[3][3] * a_Mat4[3][3];

		m_NM_[0][0] = t_00;
		m_NM_[0][1] = t_01;
		m_NM_[0][2] = t_02;
		m_NM_[0][3] = t_03;

		m_NM_[1][0] = t_10;
		m_NM_[1][1] = t_11;
		m_NM_[1][2] = t_12;
		m_NM_[1][3] = t_13;

		m_NM_[2][0] = t_20;
		m_NM_[2][1] = t_21;
		m_NM_[2][2] = t_22;
		m_NM_[2][3] = t_23;

		m_NM_[3][0] = t_30;
		m_NM_[3][1] = t_31;
		m_NM_[3][2] = t_32;
		m_NM_[3][3] = t_33;

		return *this;
	}

	Mat4& Mat4::operator*=(float a_Multiplicand)
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

	//TODO: Fix this (t_11)
	Mat4 Mat4::operator*(Mat4& a_Mat4) const
	{
		float t_00 =  m_NM_[0][0] * a_Mat4[0][0]
					+ m_NM_[1][0] * a_Mat4[0][1]
					+ m_NM_[2][0] * a_Mat4[0][2]
					+ m_NM_[3][0] * a_Mat4[0][3];
		float t_01 =  m_NM_[0][1] * a_Mat4[0][0]
					+ m_NM_[1][1] * a_Mat4[0][1]
					+ m_NM_[2][1] * a_Mat4[0][2]
					+ m_NM_[3][1] * a_Mat4[0][3];
		float t_02 =  m_NM_[0][2] * a_Mat4[0][0]
					+ m_NM_[1][2] * a_Mat4[0][1]
					+ m_NM_[2][2] * a_Mat4[0][2]
					+ m_NM_[3][2] * a_Mat4[0][3];
		float t_03 =  m_NM_[0][3] * a_Mat4[0][0]
					+ m_NM_[1][3] * a_Mat4[0][1]
					+ m_NM_[2][3] * a_Mat4[0][2]
					+ m_NM_[3][3] * a_Mat4[0][3];

		float t_10 =  m_NM_[0][0] * a_Mat4[1][0]
					+ m_NM_[1][0] * a_Mat4[1][1]
					+ m_NM_[2][0] * a_Mat4[1][2]
					+ m_NM_[3][0] * a_Mat4[1][3];
		float t_11 =  m_NM_[0][1] * a_Mat4[1][0]
					+ m_NM_[1][1] * a_Mat4[1][1]
					+ m_NM_[2][1] * a_Mat4[1][2]
					+ m_NM_[3][1] * a_Mat4[1][3];
		float t_12 =  m_NM_[0][2] * a_Mat4[1][0]
					+ m_NM_[1][2] * a_Mat4[1][1]
					+ m_NM_[2][2] * a_Mat4[1][2]
					+ m_NM_[3][2] * a_Mat4[1][3];
		float t_13 =  m_NM_[0][3] * a_Mat4[1][0]
					+ m_NM_[1][3] * a_Mat4[1][1]
					+ m_NM_[2][3] * a_Mat4[1][2]
					+ m_NM_[3][3] * a_Mat4[1][3];

		float t_20 =  m_NM_[0][0] * a_Mat4[2][0]
					+ m_NM_[1][0] * a_Mat4[2][1]
					+ m_NM_[2][0] * a_Mat4[2][2]
					+ m_NM_[3][0] * a_Mat4[2][3];
		float t_21 =  m_NM_[0][1] * a_Mat4[2][0]
					+ m_NM_[1][1] * a_Mat4[2][1]
					+ m_NM_[2][1] * a_Mat4[2][2]
					+ m_NM_[3][1] * a_Mat4[2][3];
		float t_22 =  m_NM_[0][2] * a_Mat4[2][0]
					+ m_NM_[1][2] * a_Mat4[2][1]
					+ m_NM_[2][2] * a_Mat4[2][2]
					+ m_NM_[3][2] * a_Mat4[2][3];
		float t_23 =  m_NM_[0][3] * a_Mat4[2][0]
					+ m_NM_[1][3] * a_Mat4[2][1]
					+ m_NM_[2][3] * a_Mat4[2][2]
					+ m_NM_[3][3] * a_Mat4[2][3];

		float t_30 =  m_NM_[0][0] * a_Mat4[3][0]
					+ m_NM_[1][0] * a_Mat4[3][1]
					+ m_NM_[2][0] * a_Mat4[3][2]
					+ m_NM_[3][0] * a_Mat4[3][3];
		float t_31 =  m_NM_[0][1] * a_Mat4[3][0]
					+ m_NM_[1][1] * a_Mat4[3][1]
					+ m_NM_[2][1] * a_Mat4[3][2]
					+ m_NM_[3][1] * a_Mat4[3][3];
		float t_32 =  m_NM_[0][2] * a_Mat4[3][0]
					+ m_NM_[1][2] * a_Mat4[3][1]
					+ m_NM_[2][2] * a_Mat4[3][2]
					+ m_NM_[3][2] * a_Mat4[3][3];
		float t_33 =  m_NM_[0][3] * a_Mat4[3][0]
					+ m_NM_[1][3] * a_Mat4[3][1]
					+ m_NM_[2][3] * a_Mat4[3][2]
					+ m_NM_[3][3] * a_Mat4[3][3];

		return {
					t_00, t_10, t_20, t_30,
					t_01, t_11, t_21, t_31,
					t_02, t_12, t_22, t_32,
					t_03, t_13, t_23, t_33
				};
	}

	Mat4 Mat4::operator*(const float a_Multiplicand) const
	{
		float t_00 = m_NM_[0][0] * a_Multiplicand;
		float t_01 = m_NM_[0][1] * a_Multiplicand;
		float t_02 = m_NM_[0][2] * a_Multiplicand;
		float t_03 = m_NM_[0][3] * a_Multiplicand;

		float t_10 = m_NM_[1][0] * a_Multiplicand;
		float t_11 = m_NM_[1][1] * a_Multiplicand;
		float t_12 = m_NM_[1][2] * a_Multiplicand;
		float t_13 = m_NM_[1][3] * a_Multiplicand;

		float t_20 = m_NM_[2][0] * a_Multiplicand;
		float t_21 = m_NM_[2][1] * a_Multiplicand;
		float t_22 = m_NM_[2][2] * a_Multiplicand;
		float t_23 = m_NM_[2][3] * a_Multiplicand;

		float t_30 = m_NM_[3][0] * a_Multiplicand;
		float t_31 = m_NM_[3][1] * a_Multiplicand;
		float t_32 = m_NM_[3][2] * a_Multiplicand;
		float t_33 = m_NM_[3][3] * a_Multiplicand;

		return {
					t_00, t_10, t_20, t_30,
					t_01, t_11, t_21, t_31,
					t_02, t_12, t_22, t_32,
					t_03, t_13, t_23, t_33
				};
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

	Mat4 Mat4::operator+(const float a_Addend) const
	{
		float t_00 = m_NM_[0][0] + a_Addend;
		float t_01 = m_NM_[0][1] + a_Addend;
		float t_02 = m_NM_[0][2] + a_Addend;
		float t_03 = m_NM_[0][3] + a_Addend;

		float t_10 = m_NM_[1][0] + a_Addend;
		float t_11 = m_NM_[1][1] + a_Addend;
		float t_12 = m_NM_[1][2] + a_Addend;
		float t_13 = m_NM_[1][3] + a_Addend;

		float t_20 = m_NM_[2][0] + a_Addend;
		float t_21 = m_NM_[2][1] + a_Addend;
		float t_22 = m_NM_[2][2] + a_Addend;
		float t_23 = m_NM_[2][3] + a_Addend;

		float t_30 = m_NM_[3][0] + a_Addend;
		float t_31 = m_NM_[3][1] + a_Addend;
		float t_32 = m_NM_[3][2] + a_Addend;
		float t_33 = m_NM_[3][3] + a_Addend;

		return {
					t_00, t_10, t_20, t_30,
					t_01, t_11, t_21, t_31,
					t_02, t_12, t_22, t_32,
					t_03, t_13, t_23, t_33
				};
	}

	Mat4 Mat4::operator-(Mat4& a_Mat4) const
	{
		float t_00 = m_NM_[0][0] - a_Mat4(0,0);
		float t_01 = m_NM_[0][1] - a_Mat4(0, 1);
		float t_02 = m_NM_[0][2] - a_Mat4(0, 2);
		float t_03 = m_NM_[0][3] - a_Mat4(0, 3);

		float t_10 = m_NM_[1][0] - a_Mat4(1, 0);
		float t_11 = m_NM_[1][1] - a_Mat4(1, 1);
		float t_12 = m_NM_[1][2] - a_Mat4(1, 2);
		float t_13 = m_NM_[1][3] - a_Mat4(1, 3);

		float t_20 = m_NM_[2][0] - a_Mat4(2, 0);
		float t_21 = m_NM_[2][1] - a_Mat4(2, 1);
		float t_22 = m_NM_[2][2] - a_Mat4(2, 2);
		float t_23 = m_NM_[2][3] - a_Mat4(2, 3);

		float t_30 = m_NM_[3][0] - a_Mat4(3, 0);
		float t_31 = m_NM_[3][1] - a_Mat4(3, 1);
		float t_32 = m_NM_[3][2] - a_Mat4(3, 2);
		float t_33 = m_NM_[3][3] - a_Mat4(3, 3);

		return {
					t_00, t_10, t_20, t_30,
					t_01, t_11, t_21, t_31,
					t_02, t_12, t_22, t_32,
					t_03, t_13, t_23, t_33
				};
	}

	Mat4 Mat4::operator-(const float a_Subtrahend) const
	{
		float t_00 = m_NM_[0][0] - a_Subtrahend;
		float t_01 = m_NM_[0][1] - a_Subtrahend;
		float t_02 = m_NM_[0][2] - a_Subtrahend;
		float t_03 = m_NM_[0][3] - a_Subtrahend;

		float t_10 = m_NM_[1][0] - a_Subtrahend;
		float t_11 = m_NM_[1][1] - a_Subtrahend;
		float t_12 = m_NM_[1][2] - a_Subtrahend;
		float t_13 = m_NM_[1][3] - a_Subtrahend;

		float t_20 = m_NM_[2][0] - a_Subtrahend;
		float t_21 = m_NM_[2][1] - a_Subtrahend;
		float t_22 = m_NM_[2][2] - a_Subtrahend;
		float t_23 = m_NM_[2][3] - a_Subtrahend;

		float t_30 = m_NM_[3][0] - a_Subtrahend;
		float t_31 = m_NM_[3][1] - a_Subtrahend;
		float t_32 = m_NM_[3][2] - a_Subtrahend;
		float t_33 = m_NM_[3][3] - a_Subtrahend;

		return {
					t_00, t_10, t_20, t_30,
					t_01, t_11, t_21, t_31,
					t_02, t_12, t_22, t_32,
					t_03, t_13, t_23, t_33
				};
	}

	/// <summary>	Calculates the determinant of a given matrix. </summary>
	/// <returns>	The Determinant. </returns>

	float Mat4::Det() const
	{
		return		m_NM_[0][0] * m_NM_[1][1] * m_NM_[2][2] * m_NM_[3][3]
				+	m_NM_[0][0] * m_NM_[1][2] * m_NM_[2][3] * m_NM_[3][1]
				+	m_NM_[0][0] * m_NM_[1][3] * m_NM_[2][1] * m_NM_[3][2]
				-	m_NM_[0][0] * m_NM_[1][3] * m_NM_[2][2] * m_NM_[3][1]
				-	m_NM_[0][0] * m_NM_[1][2] * m_NM_[2][1] * m_NM_[3][3]
				-	m_NM_[0][0] * m_NM_[1][1] * m_NM_[2][3] * m_NM_[3][2]
				-	m_NM_[0][1] * m_NM_[1][0] * m_NM_[2][2] * m_NM_[3][3]
				-	m_NM_[0][2] * m_NM_[1][0] * m_NM_[2][3] * m_NM_[3][1]
				-	m_NM_[0][3] * m_NM_[1][0] * m_NM_[2][1] * m_NM_[3][2]
				+	m_NM_[0][3] * m_NM_[1][0] * m_NM_[2][2] * m_NM_[3][1]
				+	m_NM_[0][2] * m_NM_[1][0] * m_NM_[2][1] * m_NM_[3][3]
				+	m_NM_[0][1] * m_NM_[1][0] * m_NM_[2][3] * m_NM_[3][2]
				+	m_NM_[0][1] * m_NM_[1][2] * m_NM_[2][0] * m_NM_[3][3]
				+	m_NM_[0][2] * m_NM_[1][3] * m_NM_[2][0] * m_NM_[3][1]
				+	m_NM_[0][3] * m_NM_[1][1] * m_NM_[2][0] * m_NM_[3][2]
				-	m_NM_[0][3] * m_NM_[1][2] * m_NM_[2][0] * m_NM_[3][1]
				-	m_NM_[0][2] * m_NM_[1][1] * m_NM_[2][0] * m_NM_[3][3]
				-	m_NM_[0][1] * m_NM_[1][3] * m_NM_[2][0] * m_NM_[3][2]
				-	m_NM_[0][1] * m_NM_[1][2] * m_NM_[2][3] * m_NM_[3][0]
				-	m_NM_[0][2] * m_NM_[1][3] * m_NM_[2][1] * m_NM_[3][0]
				-	m_NM_[0][3] * m_NM_[1][1] * m_NM_[2][2] * m_NM_[3][0]
				+	m_NM_[0][3] * m_NM_[1][2] * m_NM_[2][1] * m_NM_[3][0]
				+	m_NM_[0][2] * m_NM_[1][1] * m_NM_[2][3] * m_NM_[3][0]
				+	m_NM_[0][1] * m_NM_[1][3] * m_NM_[2][2] * m_NM_[3][0]
				;
	}


	// TODO: Fix this
	/// <summary>Gets the inverse.</summary>
	/// <returns>A Mat4.</returns>
	// this was taken from http://foundationsofgameenginedev.com/FGED1-code.cpp
	Mat4 Mat4::Inv()
	{
		const Vec3D& t_VecA = reinterpret_cast<const Vec3D&>(m_NM_[0]);
		const Vec3D& t_VecB = reinterpret_cast<const Vec3D&>(m_NM_[1]);
		const Vec3D& t_VecC = reinterpret_cast<const Vec3D&>(m_NM_[2]);
		const Vec3D& t_VecD = reinterpret_cast<const Vec3D&>(m_NM_[3]);

		const float& t_X = m_NM_[3][0];
		const float& t_Y = m_NM_[3][1];
		const float& t_Z = m_NM_[3][2];
		const float& t_W = m_NM_[3][3];

		Vec3D t_S = t_VecA.Cross(t_VecB);
		Vec3D t_T = t_VecC.Cross(t_VecD);
		Vec3D t_U = t_VecA * t_Y - t_VecB * t_X;
		Vec3D t_V = t_VecC * t_W - t_VecD * t_Z;

		float t_InverseDet = 1.f / (t_S.Dot(t_V) + t_T.Dot(t_U));
		t_S *= t_InverseDet;
		t_T *= t_InverseDet;
		t_U *= t_InverseDet;
		t_V *= t_InverseDet;

		Vec3D t_R0 = t_VecB.Cross(t_V) + t_T * t_Y;
		Vec3D t_R1 = t_V.Cross(t_VecA) - t_T * t_X;
		Vec3D t_R2 = t_VecD.Cross(t_U) + t_S * t_W;
		Vec3D t_R3 = t_U.Cross(t_VecC) - t_S * t_Z;

		return Mat4
				{
					t_R0.m_X, t_R0.m_Y, t_R0.m_Z, -(t_VecB.Dot(t_T)),
					t_R1.m_X, t_R1.m_Y, t_R1.m_Z, t_VecA.Dot(t_T),
					t_R2.m_X, t_R2.m_Y, t_R2.m_Z, -(t_VecD.Dot(t_S)),
					t_R3.m_X, t_R3.m_Y, t_R3.m_Z, t_VecC.Dot(t_S)
				};
		
	}
}
