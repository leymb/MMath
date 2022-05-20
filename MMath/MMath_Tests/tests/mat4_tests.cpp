#include "pch.h"
#include "gtest/gtest.h"
#include "matrix_math/mma_mat4.h"
#include "vector_math/mma_vector4D.h"

using namespace mma;

class Mat4TestF : public ::testing::Test
{
protected:
	Mat4TestF()
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

	Mat4 m_TestMat_ = {0.f};
};

//TEST_F(Mat4TestF, Inverse)
//{
//	m_TestMat_ = {
//							4.0f, 1.3f, 6.0f, 8.0f,
//							6.7f, 4.0f, 6.6f, 10.f,
//							12.f, 2.4f, 3.0f, 6.6f,
//							0.0f, 0.0f, 0.0f, 1.0f
//						};
//
//	Mat4 t_Correct = {
//							 0.0295f, -0.0807f, 0.1186f, -0.2114f,
//									-0.4544f, 0.4614f, -0.1061f, -0.2777f,
//									0.2454f, -0.0461f, -0.0561f, -1.1322f,
//										0.f,	0.f,		0.f,	1.f
//						};
//
//	Mat4 t_Inverse = m_TestMat_.Inv();
//
//	EXPECT_FLOAT_EQ(t_Inverse[0][0], t_Correct[0][0]);
//	EXPECT_FLOAT_EQ(t_Inverse[0][1], t_Correct[0][1]);
//	EXPECT_FLOAT_EQ(t_Inverse[0][2], t_Correct[0][2]);
//	EXPECT_FLOAT_EQ(t_Inverse[0][3], t_Correct[0][3]);
//
//	EXPECT_FLOAT_EQ(t_Inverse[1][0], t_Correct[1][0]);
//	EXPECT_FLOAT_EQ(t_Inverse[1][1], t_Correct[1][1]);
//	EXPECT_FLOAT_EQ(t_Inverse[1][2], t_Correct[1][2]);
//	EXPECT_FLOAT_EQ(t_Inverse[1][3], t_Correct[1][3]);
//
//	EXPECT_FLOAT_EQ(t_Inverse[2][0], t_Correct[2][0]);
//	EXPECT_FLOAT_EQ(t_Inverse[2][1], t_Correct[2][1]);
//	EXPECT_FLOAT_EQ(t_Inverse[2][2], t_Correct[2][2]);
//	EXPECT_FLOAT_EQ(t_Inverse[2][3], t_Correct[2][3]);
//
//	EXPECT_FLOAT_EQ(t_Inverse[3][0], t_Correct[3][0]);
//	EXPECT_FLOAT_EQ(t_Inverse[3][1], t_Correct[3][1]);
//	EXPECT_FLOAT_EQ(t_Inverse[3][2], t_Correct[3][2]);
//	EXPECT_FLOAT_EQ(t_Inverse[3][3], t_Correct[3][3]);
//}