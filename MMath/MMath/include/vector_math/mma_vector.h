#pragma once

namespace mma
{

	template <int Length, typename T>
	class Vec
	{
	public:
		Vec(T a_X);

		T m_Data_[Length] = {};
	};

	template <int Length, typename T>
	Vec<Length, T>::Vec(T a_X)
	{
		for (int i = 0; i < Length; i++)
		{
			m_Data_[i] = a_X;
		}
	}


	// 3 float specialization
	template<>
	class Vec <3, float>
	{
	public:
		Vec(float x, float y, float z);

		float m_X, m_Y, m_Z;

		Vec operator + (const Vec<3, float>& a_Vector) const;
		Vec operator + (const float a_Addend) const;
		Vec operator - (const Vec<3, float>& a_Vector) const;
		Vec operator - (const float a_Subtrahend) const;
		Vec operator * (float a_Multiplier) const;
		//Vec operator * (Mat3& a_Mat3D) const;
		Vec operator / (float a_Divisor) const;

		Vec& operator += (const Vec<3, float>& a_Vector);
		Vec& operator += (const float a_Addend);
		Vec& operator -= (const Vec<3, float>& a_Vector);
		Vec& operator -= (const float a_Subtrahend);
		Vec& operator *= (float a_Multiplier);
		//Vec& operator *= (Mat3& a_Mat3D);
		Vec& operator /= (float a_Divisor);

		float operator [] (int a_Index) const;


		// these will be turned into templated functions 
		// outside of the class later on
		float SquaredMagnitude() const;
		float Magnitude();
	};

	inline Vec<3, float>::Vec(float x, float y, float z)
		: m_X(x), m_Y(y), m_Z(z)
	{
	}

	inline Vec<3, float> Vec<3, float>::operator+(const Vec<3, float>& a_Vector) const
	{
		return {
				this->m_X + a_Vector.m_X,
				this->m_Y + a_Vector.m_Y,
				this->m_Z + a_Vector.m_Z
				};
	}

	inline Vec<3, float> Vec<3, float>::operator+(const float a_Addend) const
	{
		return {m_X + a_Addend, m_Y + a_Addend, m_Z + a_Addend};
	}

	/// <summary>Calculates the Dot Product.</summary>
	/// <param name="a_VecA">	Vector A.</param>
	/// <param name="a_VecB">	Vector B.</param>
	/// <returns>Returns the Dot Product A dot B.</returns>

	inline float Dot(const Vec<3, float>& a_VecA, const Vec<3, float>& a_VecB)
	{
		return
				  a_VecA.m_X * a_VecB.m_X
				+ a_VecA.m_Y * a_VecB.m_Y
				+ a_VecA.m_Z * a_VecB.m_Z;
	}

	/// <summary>Calculates the Cross Product of Vector A and Vector B</summary>
	/// <param name="a_VecA">	Vector A.</param>
	/// <param name="a_VecB">	Vector B.</param>
	/// <returns>A Vec3F</returns>

	inline Vec<3, float> Cross(const Vec<3, float>& a_VecA, const Vec<3, float>& a_VecB)
	{
		return{
			a_VecA.m_Y * a_VecB.m_Z - a_VecA.m_Z * a_VecB.m_Y,
			a_VecA.m_Z * a_VecB.m_X - a_VecA.m_X * a_VecB.m_Z,
			a_VecA.m_X * a_VecB.m_Y - a_VecA.m_Y * a_VecB.m_X
		};
	}

	/// <summary>Calculates the scalar triple product in the form of [VecA, VecB, VecC] =
	/// 	Dot(VecA, Cross(VecB, VecC))</summary>
	/// <param name="a_VecA">	Vector A.</param>
	/// <param name="a_VecB">	Vector B.</param>
	/// <param name="a_VecC">	Vector C.</param>
	/// <returns>The scalar triple product.</returns>

	inline float ScalarTriple(const Vec<3, float>& a_VecA, const Vec<3, float>& a_VecB, const Vec<3, float>& a_VecC)
	{
		return Dot(a_VecA, Cross(a_VecB, a_VecC));
	}

	/*void Normalize();

	Vec ProjectOn(const Vec3D& a_VecB) const;
	Vec Perpendicular(const Vec3D& a_Vec3D) const;*/

	// typedefs
	typedef Vec<3, float> Vec3F;
}
