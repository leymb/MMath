#include "pch.h"
#include <gtest/gtest.h>
#include <vector_math/mma_vector3D.h>
#include <matrix_math/mma_mat3.h>

using namespace mma;

class Vec3DTestF : public ::testing::Test
{
protected:
	Vec3DTestF()
	{
	}

	void SetUp() override
	{
		Test::SetUp();
	}

	void TearDown() override
	{
		Test::TearDown();
	}

	Vec3D m_TestVec3D_ = {};

	float m_Divisor_ = 2.0f;
	float m_Multiplicator_ = 10.f;
};

TEST_F(Vec3DTestF, Constructor_Empty)
{
	m_TestVec3D_ = {};
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_X, 0.0f);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Y, 0.0f);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Z, 0.0f);
}

TEST_F(Vec3DTestF, Constructor_OneFloat)
{
	m_TestVec3D_ = { 4.5f };
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_X, 4.5f);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Y, 4.5f);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Z, 4.5f);
}

TEST_F(Vec3DTestF, Constructor_ThreeFloats)
{
	m_TestVec3D_ = { 3.6f, 14.2f, 4.5f };
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_X, 3.6f);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Y, 14.2f);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Z, 4.5f);
}

TEST_F(Vec3DTestF, Operators_Division)
{
	// division 
	m_TestVec3D_ = { 1.5f, 2.f, 1.f };

	Vec3D t_Quotient = m_TestVec3D_ / m_Divisor_;

	EXPECT_FLOAT_EQ(t_Quotient.m_X, m_TestVec3D_.m_X / m_Divisor_);
	EXPECT_FLOAT_EQ(t_Quotient.m_Y, m_TestVec3D_.m_Y / m_Divisor_);
	EXPECT_FLOAT_EQ(t_Quotient.m_Z, m_TestVec3D_.m_Z / m_Divisor_);
}

TEST_F(Vec3DTestF, Operators_DivisionAssignment)
{
	// division 
	m_TestVec3D_ = { 1.5f, 2.f, 1.f };
	Vec3D t_TempVec = m_TestVec3D_;

	// call to MUT
	m_TestVec3D_ /= m_Divisor_;

	EXPECT_FLOAT_EQ(m_TestVec3D_.m_X, t_TempVec.m_X / m_Divisor_);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Y, t_TempVec.m_Y / m_Divisor_);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Z, t_TempVec.m_Z / m_Divisor_);
}

TEST_F(Vec3DTestF, Operators_Multiplication_Float)
{
	// multiplication
	m_TestVec3D_ = { 5.f, 1.2f, 3.f };

	const Vec3D t_Product = m_TestVec3D_ * m_Multiplicator_;

	EXPECT_FLOAT_EQ(t_Product.m_X, m_TestVec3D_.m_X * m_Multiplicator_);
	EXPECT_FLOAT_EQ(t_Product.m_Y, m_TestVec3D_.m_Y * m_Multiplicator_);
	EXPECT_FLOAT_EQ(t_Product.m_Z, m_TestVec3D_.m_Z * m_Multiplicator_);
}

TEST_F(Vec3DTestF, Operators_MultiplicationAssignment_Float)
{
	m_TestVec3D_ = { 5.f, 1.2f, 3.f };
	const Vec3D t_TempVec = m_TestVec3D_;

	m_TestVec3D_ *= m_Multiplicator_;

	EXPECT_FLOAT_EQ(m_TestVec3D_.m_X, t_TempVec.m_X * m_Multiplicator_);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Y, t_TempVec.m_Y * m_Multiplicator_);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Z, t_TempVec.m_Z * m_Multiplicator_);
}

TEST_F(Vec3DTestF, Operators_MultiplicationMat)
{
	Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

	const Vec3D t_Vec3D = 
						{
							10.0f,
							666.66f,
							0.00009f
						};

	const Vec3D t_Product = t_Vec3D * t_MatA;

		EXPECT_FLOAT_EQ(t_Product[0], 4049.96063f);
		EXPECT_FLOAT_EQ(t_Product[1], 2676.64072f);
		EXPECT_FLOAT_EQ(t_Product[2], 6019.9400f);
}

TEST_F(Vec3DTestF, Operators_MultiplicationAssignment_Mat)
{
	Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		Vec3D t_Vec3D = 
						{
							10.0f,
							666.66f,
							0.00009f
						};

		t_Vec3D *= t_MatA;

		EXPECT_FLOAT_EQ(t_Vec3D[0], 4049.96063f);
		EXPECT_FLOAT_EQ(t_Vec3D[1], 2676.64072f);
		EXPECT_FLOAT_EQ(t_Vec3D[2], 6019.9400f);
}


//	// subtraction
//	t_TestVector = {5.f, 2.f, 3.14159265358979f};
//	Vec3D t_Subtrahend = 2.35f;
//
//	Vec3D t_Difference = t_TestVector - t_Subtrahend;
//	t_TestVector -= t_Subtrahend;
//
//	EXPECT_FLOAT_EQ(t_TestVector.m_X, 5.f - t_Subtrahend.m_X);
//	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 2.f - t_Subtrahend.m_Y);
//	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 3.14159265358979f - t_Subtrahend.m_Z);
//
//	EXPECT_FLOAT_EQ(t_Difference.m_X, 5.f - t_Subtrahend.m_X);
//	EXPECT_FLOAT_EQ(t_Difference.m_Y, 2.f - t_Subtrahend.m_Y);
//	EXPECT_FLOAT_EQ(t_Difference.m_Z, 3.14159265358979f - t_Subtrahend.m_Z);
//
//	// subtraction (float)
//	{
//		Vec3D t_Temp = {15.f, 6.f, 3.5f};
//		float t_SubtrahendF = 5.0f;
//
//		Vec3D t_Diff = t_Temp - t_SubtrahendF;
//
//		EXPECT_FLOAT_EQ(t_Diff.m_X, t_Temp.m_X - t_SubtrahendF);
//		EXPECT_FLOAT_EQ(t_Diff.m_Y, t_Temp.m_Y - t_SubtrahendF);
//		EXPECT_FLOAT_EQ(t_Diff.m_Z, t_Temp.m_Z - t_SubtrahendF);
//	}
//
//	{
//		Vec3D t_Temp = {15.f, 6.f, 3.5f};
//		float t_SubtrahendF = 5.0f;
//
//		t_Temp -= t_SubtrahendF;
//
//		EXPECT_FLOAT_EQ(t_Temp.m_X, 15.f - t_SubtrahendF);
//		EXPECT_FLOAT_EQ(t_Temp.m_Y, 6.f - t_SubtrahendF);
//		EXPECT_FLOAT_EQ(t_Temp.m_Z, 3.5f - t_SubtrahendF);
//	}
//
//	// access
//	t_TestVector = {5.f, 2.f, 10.2f};
//	EXPECT_FLOAT_EQ(t_TestVector[0], t_TestVector.m_X);
//	EXPECT_FLOAT_EQ(t_TestVector[1], t_TestVector.m_Y);
//	EXPECT_FLOAT_EQ(t_TestVector[2], t_TestVector.m_Z);