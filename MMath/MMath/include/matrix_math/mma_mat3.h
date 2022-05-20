#pragma once

namespace mma
{
	// || M00 | M10 | M20 ||
	// || M01 | M11 | M21 ||
	// || M02 | M12 | M22 ||

	/// <summary>
	/// A column-major 3 x 3 (n x m) matrix
	/// </summary>

	class Vec3D;
	class Mat3
	{
	public:
		Mat3() = default;
		Mat3(float a_Diagonal);
		Mat3(const Vec3D& a_VecA, const Vec3D& a_VecB, const Vec3D& a_VecC);
		Mat3(float a_00, float a_10, float a_20,
			 float a_01, float a_11, float a_21,
			 float a_02, float a_12, float a_22);


		float& operator()(int n, int m);
		Vec3D& operator[](int i);

		// TODO: add mathematical operators
		Mat3& operator*=(Mat3& a_Mat3);
		Mat3& operator*=(float a_Multiplicand);
		Mat3& operator+=(Mat3& a_Mat3);
		Mat3& operator-=(Mat3& a_Mat3);
		Mat3& operator+=(float a_Addend);
		Mat3& operator-=(float a_Subtrahend);

		bool operator==(Mat3& a_Mat3) const;

		Mat3 operator*(Mat3& a_Mat3) const;
		Mat3 operator*(float a_Multiplicand) const;
		Vec3D operator*(const Vec3D& a_Vec3D) const;
		Mat3 operator+(Mat3& a_Mat3) const;
		Mat3 operator+(float a_Addend) const;
		Mat3 operator-(Mat3& a_Mat3) const;
		Mat3 operator-(float a_Subtrahend) const;

		float Det() const;
		Mat3 Inv();


	private:
		float m_NM_[3][3] = {0.0f};
	};
}
