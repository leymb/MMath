#pragma once
// || M00 | M10 | M20 | M30||
// || M01 | M11 | M21 | M31||
// || M02 | M12 | M22 | M32||
// || M03 | M13 | M23 | M33||

/// <summary>
/// A column-major 4 x 4 (n x m) matrix
/// </summary>

class Vec3D;
class Mat4
{
public:
	Mat4() = default;
	Mat4(float a_Diagonal);

	//TODO Add Constructor using four Vec4s

	Mat4(float a_00, float a_10, float a_20, float a_30,
		 float a_01, float a_11, float a_21, float a_31,
		 float a_02, float a_12, float a_22, float a_32,
		 float a_03, float a_13, float a_23, float a_33
		);


	float& operator()(int n, int m);

	//TODO Add access operator as soon as Vec4D is finished
	//Vec4D& operator[](int i);

	// TODO: add mathematical operators
	Mat4& operator*=(Mat4& a_Mat4);
	Mat4& operator*=(float a_Multiplicand);
	Mat4& operator+=(Mat4& a_Mat4);
	Mat4& operator-=(Mat4& a_Mat4);
	Mat4& operator+=(float a_Addend);
	Mat4& operator-=(float a_Subtrahend);

	bool operator==(Mat4& a_Mat4) const;

	Mat4 operator*(Mat4& a_Mat4) const;
	Mat4 operator*(float a_Multiplicand) const;

	//TODO add multiplication with Vec4D as soon as it is finished
	//Vec4D operator*(Vec4D& a_Vec4D);
	Mat4 operator+(Mat4& a_Mat4) const;
	Mat4 operator+(float a_Addend) const;
	Mat4 operator-(Mat4& a_Mat4) const;
	Mat4 operator-(float a_Subtrahend) const;

	float Det();
	Mat4 Inv();

private:
	float m_NM_[4][4] = {{0.0f}};
};

