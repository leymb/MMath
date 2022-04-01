#pragma once
class Vec4D
{
public:

	Vec4D();
	Vec4D(float a_Value);
	Vec4D(float x, float y, float z, float w);

	float m_X;
	float m_Y;
	float m_Z;
	float m_W;

	Vec4D operator+(const Vec4D& a_Vector) const;

	Vec4D operator*(float a_Multiplier);
	Vec4D& operator*=(float a_Multiplier);

	float& operator[](int a_Index);
};

