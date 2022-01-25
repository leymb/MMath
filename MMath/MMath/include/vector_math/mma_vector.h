#pragma once

class Mat3;
class Vec3D
{
public:

	Vec3D();
	Vec3D(float a_Value);
	Vec3D(float x, float y, float z);


	float m_X;
	float m_Y;
	float m_Z;

	Vec3D operator + (const Vec3D& a_Vector) const;
	Vec3D operator - (const Vec3D& a_Vector) const;
	Vec3D operator * (float a_Multiplier) const;
	Vec3D operator * (Mat3& a_Mat3D) const;
	Vec3D operator / (float a_Divisor) const;

	Vec3D& operator += (const Vec3D& a_Vector);
	Vec3D& operator -= (const Vec3D& a_Vector);
	Vec3D& operator *= (float a_Multiplier);
	Vec3D& operator *= (Mat3& a_Mat3D);
	Vec3D& operator /= (float a_Divisor);

	float operator [] (int a_Index) const;

	float SquaredMagnitude() const;
	float Magnitude();

	// TODO: pass by reference where possible
	float Dot(Vec3D a_Vec3D) const;
	Vec3D Cross(Vec3D a_Vec3D) const;
	float ScalarTriple(Vec3D a_VecB, Vec3D a_VecC) const;

	void Normalize();

	Vec3D ProjectOn(Vec3D a_VecB) const;
	Vec3D Reject(const Vec3D& a_Vec3D) const;
};
