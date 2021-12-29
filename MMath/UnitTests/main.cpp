#include <gtest/gtest.h>
#include <vector_math/mma_vector.h>
#include <matrix_math/mma_mat3.h>

TEST(Vector_Basic_Ops, Constructors)
{
	Vec3D t_TestVector = {};
	EXPECT_FLOAT_EQ(t_TestVector.m_X, 0.0f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 0.0f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 0.0f);
	EXPECT_FLOAT_EQ(t_TestVector.m_W, 0.0f);

	t_TestVector = {4.5f};
	EXPECT_FLOAT_EQ(t_TestVector.m_X, 4.5f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 4.5f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 4.5f);
	EXPECT_FLOAT_EQ(t_TestVector.m_W, 0.0f);

	t_TestVector = {3.6f, 14.2f, 4.5f};
	EXPECT_FLOAT_EQ(t_TestVector.m_X, 3.6f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 14.2f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 4.5f);
	EXPECT_FLOAT_EQ(t_TestVector.m_W, 0.0f);

	t_TestVector = {3.6f, 14.2f, 4.5f, 1.f};
	EXPECT_FLOAT_EQ(t_TestVector.m_X, 3.6f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 14.2f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 4.5f);
	EXPECT_FLOAT_EQ(t_TestVector.m_W, 1.f);
}

TEST(Vector_Basic_Ops, Operators)
{
	// division 
	Vec3D t_TestVector{1.5f, 2.f, 1.f};
	const float t_Divisior = 2.0f;

	Vec3D t_Quotient = t_TestVector / t_Divisior;

	t_TestVector /= 2;

	EXPECT_FLOAT_EQ(t_TestVector.m_X, 1.5f / t_Divisior);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 2.f / t_Divisior);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 1.f / t_Divisior);
	EXPECT_FLOAT_EQ(t_TestVector.m_W, 0.0f);

	EXPECT_FLOAT_EQ(t_Quotient.m_X, 1.5f / t_Divisior);
	EXPECT_FLOAT_EQ(t_Quotient.m_Y, 2.f / t_Divisior);
	EXPECT_FLOAT_EQ(t_Quotient.m_Z, 1.f / t_Divisior);
	EXPECT_FLOAT_EQ(t_Quotient.m_W, 0.0f);

	// multiplication
	t_TestVector = {5.f, 1.2f, 3.f};
	float t_Multiplicator = 10.f;

	Vec3D t_Product = t_TestVector * t_Multiplicator;

	t_TestVector *= t_Multiplicator;

	EXPECT_FLOAT_EQ(t_TestVector.m_X, 5.f * t_Multiplicator);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 1.2f * t_Multiplicator);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 3.f * t_Multiplicator);
	EXPECT_FLOAT_EQ(t_TestVector.m_W, 0.0f);

	EXPECT_FLOAT_EQ(t_Product.m_X, 5.f * t_Multiplicator);
	EXPECT_FLOAT_EQ(t_Product.m_Y, 1.2f * t_Multiplicator);
	EXPECT_FLOAT_EQ(t_Product.m_Z, 3.f * t_Multiplicator);
	EXPECT_FLOAT_EQ(t_Product.m_W, 0.0f);

	// addition
	t_TestVector = {2.f, 10.2f, 4.f};
	Vec3D t_Addend = 4.5f;

	Vec3D t_Sum = t_TestVector + t_Addend;

	t_TestVector += t_Addend;

	EXPECT_FLOAT_EQ(t_TestVector.m_X, 2.f + t_Addend.m_X);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 10.2f + t_Addend.m_Y);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 4.f + t_Addend.m_Z);
	EXPECT_FLOAT_EQ(t_TestVector.m_W, 0.0f);

	EXPECT_FLOAT_EQ(t_Sum.m_X, 2.f + t_Addend.m_X);
	EXPECT_FLOAT_EQ(t_Sum.m_Y, 10.2f + t_Addend.m_Y);
	EXPECT_FLOAT_EQ(t_Sum.m_Z, 4.f + t_Addend.m_Z);
	EXPECT_FLOAT_EQ(t_Sum.m_W, 0.0f);

	// subtraction
	t_TestVector = {5.f, 2.f, 3.14159265358979f};
	Vec3D t_Subtrahend = 2.35f;

	Vec3D t_Difference = t_TestVector - t_Subtrahend;
	t_TestVector -= t_Subtrahend;

	EXPECT_FLOAT_EQ(t_TestVector.m_X, 5.f - t_Subtrahend.m_X);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 2.f - t_Subtrahend.m_Y);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 3.14159265358979f - t_Subtrahend.m_Z);
	EXPECT_FLOAT_EQ(t_TestVector.m_W, 0.0f);

	EXPECT_FLOAT_EQ(t_Difference.m_X, 5.f - t_Subtrahend.m_X);
	EXPECT_FLOAT_EQ(t_Difference.m_Y, 2.f - t_Subtrahend.m_Y);
	EXPECT_FLOAT_EQ(t_Difference.m_Z, 3.14159265358979f - t_Subtrahend.m_Z);
	EXPECT_FLOAT_EQ(t_Difference.m_W, 0.0f);

	// access
	t_TestVector = {5.f, 2.f, 10.2f};
	EXPECT_FLOAT_EQ(t_TestVector[0], t_TestVector.m_X);
	EXPECT_FLOAT_EQ(t_TestVector[1], t_TestVector.m_Y);
	EXPECT_FLOAT_EQ(t_TestVector[2], t_TestVector.m_Z);
	EXPECT_FLOAT_EQ(t_TestVector[3], t_TestVector.m_W);
}

TEST(Vector_Basic_Ops, Basic_Calculations)
{
	Vec3D t_TestVector = {8.5f, 3.3f, 6.8f};
	Vec3D t_Temp = {2.5f, 10.f, 1.f};

	// magnitude
	EXPECT_FLOAT_EQ(t_TestVector.SquaredMagnitude(), 129.38f);
	EXPECT_FLOAT_EQ(t_TestVector.Magnitude(), 11.37453295744f);

	// dot product
	const float t_DotProduct = t_TestVector.Dot(t_Temp);
	EXPECT_FLOAT_EQ(t_DotProduct, 61.05f);

	// cross product
	Vec3D t_CrossProduct = t_TestVector.Cross(t_Temp);

	EXPECT_FLOAT_EQ(t_CrossProduct.m_X, -64.7f);
	EXPECT_FLOAT_EQ(t_CrossProduct.m_Y, 8.50f);
	EXPECT_FLOAT_EQ(t_CrossProduct.m_Z, 76.75);
	EXPECT_FLOAT_EQ(t_CrossProduct.m_W, 0.0f);

	// normalization
	t_TestVector.Normalize();
	EXPECT_FLOAT_EQ(t_TestVector.Magnitude(), 1.0f);

	t_TestVector = {10000000000000.f, 200000000000.f, 98734928734.f};
	t_TestVector.Normalize();
	EXPECT_FLOAT_EQ(t_TestVector.Magnitude(), 1.0f);

	t_TestVector = {0.00001f, 0.0000032f, 0.98734928734f};
	t_TestVector.Normalize();
	EXPECT_FLOAT_EQ(t_TestVector.Magnitude(), 1.0f);

	// scalar triple product
	Vec3D t_VecA = {5.f, 6.f, 2.f};
	Vec3D t_VecB = {10000000000000.f, 200000000000.f, 98734928734.f};
	const Vec3D t_VecC = {0.00001f, 0.0000032f, 0.98734928734f};

	const float t_ScalarTriple = t_VecA.ScalarTriple(t_VecB, t_VecC);
	
	EXPECT_FLOAT_EQ(t_ScalarTriple, -5.82535458f * powf(10.0, 13.f));

	// projection
	t_VecA = {5.f, 6.7f, 10.f};
	t_VecB = {10.f, 0.0f, 0.0f};

	Vec3D t_Projection = t_VecA.ProjectOn(t_VecB);
	EXPECT_FLOAT_EQ(t_Projection.m_X, 5.0f);
	EXPECT_FLOAT_EQ(t_Projection.m_Y, 0.0f);
	EXPECT_FLOAT_EQ(t_Projection.m_Z, 0.0f);
	EXPECT_FLOAT_EQ(t_Projection.m_W, 0.0f);

	// rejection
	Vec3D t_Rejection = t_VecA.Reject(t_VecB);
	EXPECT_FLOAT_EQ(t_Rejection.m_X, 0.f);
	EXPECT_FLOAT_EQ(t_Rejection.m_Y, 6.7f);
	EXPECT_FLOAT_EQ(t_Rejection.m_Z, 10.0f);
	EXPECT_FLOAT_EQ(t_Rejection.m_W, 0.0f);

}

TEST(Matrix_Basic_Ops, Constructors)
{
	// default constructor
	Mat3 t_TestMat = {};
	{
		EXPECT_FLOAT_EQ(t_TestMat(0,0), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(0,1), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(0,2), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(1,0), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(1,1), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(1,2), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,0), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,1), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,2), 0.0f);
	}

	// diagonal constructor
	float t_Diagonal = 1.0f;
	t_TestMat = {t_Diagonal};

	{
		EXPECT_FLOAT_EQ(t_TestMat(0,0), t_Diagonal);
		EXPECT_FLOAT_EQ(t_TestMat(0,1), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(0,2), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(1,0), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(1,1), t_Diagonal);
		EXPECT_FLOAT_EQ(t_TestMat(1,2), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,0), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,1), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,2), t_Diagonal);

		t_Diagonal = 10000000000000000.0f;
		t_TestMat = {t_Diagonal};
		EXPECT_FLOAT_EQ(t_TestMat(0,0), t_Diagonal);
		EXPECT_FLOAT_EQ(t_TestMat(0,1), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(0,2), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(1,0), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(1,1), t_Diagonal);
		EXPECT_FLOAT_EQ(t_TestMat(1,2), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,0), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,1), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,2), t_Diagonal);

		t_Diagonal = 0.00000000008f;
		t_TestMat = {t_Diagonal};
		EXPECT_FLOAT_EQ(t_TestMat(0,0), t_Diagonal);
		EXPECT_FLOAT_EQ(t_TestMat(0,1), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(0,2), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(1,0), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(1,1), t_Diagonal);
		EXPECT_FLOAT_EQ(t_TestMat(1,2), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,0), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,1), 0.0f);
		EXPECT_FLOAT_EQ(t_TestMat(2,2), t_Diagonal);
	}

	// individual values constructor
	float t_00 = 1000000000.f;
	float t_01 = 999999999.f;
	float t_02 = 8080808089090.f;
	float t_10 = 0.000000000098f;
	float t_11 = 0.000000000001f;
	float t_12 = 0.5f;
	float t_20 = 10.f;
	float t_21 = 3.14159265358979f;
	float t_22 = 50.f;

	t_TestMat = {
						t_00, t_01, t_02,
						t_10, t_11, t_12,
						t_20, t_21, t_22
	};
	{
		EXPECT_FLOAT_EQ(t_TestMat(0,0), t_00);
		EXPECT_FLOAT_EQ(t_TestMat(0,1), t_01);
		EXPECT_FLOAT_EQ(t_TestMat(0,2), t_02);
		EXPECT_FLOAT_EQ(t_TestMat(1,0), t_10);
		EXPECT_FLOAT_EQ(t_TestMat(1,1), t_11);
		EXPECT_FLOAT_EQ(t_TestMat(1,2), t_12);
		EXPECT_FLOAT_EQ(t_TestMat(2,0), t_20);
		EXPECT_FLOAT_EQ(t_TestMat(2,1), t_21);
		EXPECT_FLOAT_EQ(t_TestMat(2,2), t_22);
	}

	// three Vec3Ds constructor
	Vec3D t_VecA = {5.f, 6.f, 7.f};
	Vec3D t_VecB = {1000000.f, 6009605.f, 999999999.f};
	Vec3D t_VecC = {0.0000123f, 0000989980.f, 0.0000000001f};

	t_TestMat = {t_VecA, t_VecB, t_VecC};
	{
		EXPECT_FLOAT_EQ(t_TestMat(0,0), t_VecA.m_X);
		EXPECT_FLOAT_EQ(t_TestMat(0,1), t_VecA.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat(0,2), t_VecA.m_Z);

		EXPECT_FLOAT_EQ(t_TestMat(1,0), t_VecB.m_X);
		EXPECT_FLOAT_EQ(t_TestMat(1,1), t_VecB.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat(1,2), t_VecB.m_Z);

		EXPECT_FLOAT_EQ(t_TestMat(2,0), t_VecC.m_X);
		EXPECT_FLOAT_EQ(t_TestMat(2,1), t_VecC.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat(2,2), t_VecC.m_Z);
	}
}

TEST(Matrix_Basic_Ops, Operators)
{
	Vec3D t_VecA = {5.f, 6.f, 7.f};
	Vec3D t_VecB = {1000000.f, 6009605.f, 999999999.f};
	Vec3D t_VecC = {0.0000123f, 0000989980.f, 0.0000000001f};

	Mat3 t_TestMat = {t_VecA, t_VecB, t_VecC};

	// () operator
	{
		EXPECT_FLOAT_EQ(t_TestMat(0,0), t_VecA.m_X);
		EXPECT_FLOAT_EQ(t_TestMat(0,1), t_VecA.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat(0,2), t_VecA.m_Z);

		EXPECT_FLOAT_EQ(t_TestMat(1,0), t_VecB.m_X);
		EXPECT_FLOAT_EQ(t_TestMat(1,1), t_VecB.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat(1,2), t_VecB.m_Z);

		EXPECT_FLOAT_EQ(t_TestMat(2,0), t_VecC.m_X);
		EXPECT_FLOAT_EQ(t_TestMat(2,1), t_VecC.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat(2,2), t_VecC.m_Z);
	}

	// [] operator
	{
		EXPECT_FLOAT_EQ(t_TestMat[0].m_X, t_VecA.m_X);
		EXPECT_FLOAT_EQ(t_TestMat[0].m_Y, t_VecA.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat[0].m_Z, t_VecA.m_Z);

		EXPECT_FLOAT_EQ(t_TestMat[1].m_X, t_VecB.m_X);
		EXPECT_FLOAT_EQ(t_TestMat[1].m_Y, t_VecB.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat[1].m_Z, t_VecB.m_Z);

		EXPECT_FLOAT_EQ(t_TestMat[2].m_X, t_VecC.m_X);
		EXPECT_FLOAT_EQ(t_TestMat[2].m_Y, t_VecC.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat[2].m_Z, t_VecC.m_Z);
	}

	// [][] operator
	{
		EXPECT_FLOAT_EQ(t_TestMat[0][0], t_VecA.m_X);
		EXPECT_FLOAT_EQ(t_TestMat[0][1], t_VecA.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat[0][2], t_VecA.m_Z);

		EXPECT_FLOAT_EQ(t_TestMat[1][0], t_VecB.m_X);
		EXPECT_FLOAT_EQ(t_TestMat[1][1], t_VecB.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat[1][2], t_VecB.m_Z);

		EXPECT_FLOAT_EQ(t_TestMat[2][0], t_VecC.m_X);
		EXPECT_FLOAT_EQ(t_TestMat[2][1], t_VecC.m_Y);
		EXPECT_FLOAT_EQ(t_TestMat[2][2], t_VecC.m_Z);
	}
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest();

	RUN_ALL_TESTS();

	return 0;
}