#pragma once

// || M00 | M01 | M02 ||
// || M10 | M11 | M12 ||
// || M20 | M21 | M22 ||

/// <summary>
/// A column-major 3 x 3 (n x m) matrix
/// </summary>

class Vec3D;
class Mat3
{
public:
	Mat3() = default;
	Mat3(float a_Diagonal);
	Mat3(Vec3D& a_VecA, Vec3D& a_VecB, Vec3D& a_VecC);
	Mat3(float a_00, float a_01, float a_02,
		 float a_10, float a_11, float a_12,
		 float a_20, float a_21, float a_22);


	float& operator()(int n, int m);
	Vec3D operator[](int i);

	// TODO: add mathematical operators

private:
	float m_NM_[3][3] = {0.0f};
};