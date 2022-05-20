#pragma once
namespace mma
{
	class Mat4;

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
		Vec4D& operator+=(const Vec4D& a_Vector);
		Vec4D operator+(const float a_Addend) const;
		Vec4D& operator+=(const float a_Addend);

		Vec4D operator-(const Vec4D& a_Vector) const;
		Vec4D& operator-=(const Vec4D& a_Vector);
		Vec4D operator-(const float a_Subtrahend) const;
		Vec4D& operator-=(const float a_Subtrahend);

		Vec4D operator*(float a_Multiplier);
		Vec4D& operator*=(float a_Multiplier);
		Vec4D operator*(Mat4 a_Mat4);

		float& operator[](int a_Index);
	};
}

