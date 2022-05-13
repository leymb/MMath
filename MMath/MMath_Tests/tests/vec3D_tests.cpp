#include "pch.h"
#include <gtest/gtest.h>
#include <vector_math/mma_vector.h>
#include <matrix_math/mma_mat3.h>

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

TEST_F(Vec3DTestF, Operators_MultiplicationFloar)
{
	// multiplication
	m_TestVec3D_ = { 5.f, 1.2f, 3.f };

	const Vec3D t_Product = m_TestVec3D_ * m_Multiplicator_;

	EXPECT_FLOAT_EQ(t_Product.m_X, m_TestVec3D_.m_X * m_Multiplicator_);
	EXPECT_FLOAT_EQ(t_Product.m_Y, m_TestVec3D_.m_Y * m_Multiplicator_);
	EXPECT_FLOAT_EQ(t_Product.m_Z, m_TestVec3D_.m_Z * m_Multiplicator_);
}

TEST_F(Vec3DTestF, Operators_MultiplicationAssignment_FLoat)
{
	m_TestVec3D_ = { 5.f, 1.2f, 3.f };
	const Vec3D t_TempVec = m_TestVec3D_;

	m_TestVec3D_ *= m_Multiplicator_;

	EXPECT_FLOAT_EQ(m_TestVec3D_.m_X, t_TempVec.m_X * m_Multiplicator_);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Y, t_TempVec.m_Y * m_Multiplicator_);
	EXPECT_FLOAT_EQ(m_TestVec3D_.m_Z, t_TempVec.m_Z * m_Multiplicator_);
}