#include <gtest/gtest.h>
#include <vector_math/mma_vector.h>
#include <matrix_math/mma_mat3.h>
#include <matrix_math/mma_mat4.h>

TEST(Vector_Basic_Ops, Constructors)
{
	Vec3D t_TestVector = {};
	EXPECT_FLOAT_EQ(t_TestVector.m_X, 0.0f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 0.0f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 0.0f);

	t_TestVector = {4.5f};
	EXPECT_FLOAT_EQ(t_TestVector.m_X, 4.5f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 4.5f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 4.5f);

	t_TestVector = {3.6f, 14.2f, 4.5f};
	EXPECT_FLOAT_EQ(t_TestVector.m_X, 3.6f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 14.2f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 4.5f);

	t_TestVector = {3.6f, 14.2f, 4.5f};
	EXPECT_FLOAT_EQ(t_TestVector.m_X, 3.6f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 14.2f);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 4.5f);
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

	EXPECT_FLOAT_EQ(t_Quotient.m_X, 1.5f / t_Divisior);
	EXPECT_FLOAT_EQ(t_Quotient.m_Y, 2.f / t_Divisior);
	EXPECT_FLOAT_EQ(t_Quotient.m_Z, 1.f / t_Divisior);

	// multiplication
	t_TestVector = {5.f, 1.2f, 3.f};
	float t_Multiplicator = 10.f;

	Vec3D t_Product = t_TestVector * t_Multiplicator;

	t_TestVector *= t_Multiplicator;

	EXPECT_FLOAT_EQ(t_TestVector.m_X, 5.f * t_Multiplicator);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 1.2f * t_Multiplicator);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 3.f * t_Multiplicator);

	EXPECT_FLOAT_EQ(t_Product.m_X, 5.f * t_Multiplicator);
	EXPECT_FLOAT_EQ(t_Product.m_Y, 1.2f * t_Multiplicator);
	EXPECT_FLOAT_EQ(t_Product.m_Z, 3.f * t_Multiplicator);

	// * operator (Mat3)
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

		Vec3D t_Product = t_Vec3D * t_MatA;

		EXPECT_FLOAT_EQ(t_Product[0], 4049.96063f);
		EXPECT_FLOAT_EQ(t_Product[1], 2676.64072f);
		EXPECT_FLOAT_EQ(t_Product[2], 6019.9400f);
	}

	// *= operator (Mat3)
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

	// addition
	t_TestVector = {2.f, 10.2f, 4.f};
	Vec3D t_Addend = 4.5f;

	Vec3D t_Sum = t_TestVector + t_Addend;

	t_TestVector += t_Addend;

	EXPECT_FLOAT_EQ(t_TestVector.m_X, 2.f + t_Addend.m_X);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 10.2f + t_Addend.m_Y);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 4.f + t_Addend.m_Z);

	EXPECT_FLOAT_EQ(t_Sum.m_X, 2.f + t_Addend.m_X);
	EXPECT_FLOAT_EQ(t_Sum.m_Y, 10.2f + t_Addend.m_Y);
	EXPECT_FLOAT_EQ(t_Sum.m_Z, 4.f + t_Addend.m_Z);

	// subtraction
	t_TestVector = {5.f, 2.f, 3.14159265358979f};
	Vec3D t_Subtrahend = 2.35f;

	Vec3D t_Difference = t_TestVector - t_Subtrahend;
	t_TestVector -= t_Subtrahend;

	EXPECT_FLOAT_EQ(t_TestVector.m_X, 5.f - t_Subtrahend.m_X);
	EXPECT_FLOAT_EQ(t_TestVector.m_Y, 2.f - t_Subtrahend.m_Y);
	EXPECT_FLOAT_EQ(t_TestVector.m_Z, 3.14159265358979f - t_Subtrahend.m_Z);

	EXPECT_FLOAT_EQ(t_Difference.m_X, 5.f - t_Subtrahend.m_X);
	EXPECT_FLOAT_EQ(t_Difference.m_Y, 2.f - t_Subtrahend.m_Y);
	EXPECT_FLOAT_EQ(t_Difference.m_Z, 3.14159265358979f - t_Subtrahend.m_Z);

	// access
	t_TestVector = {5.f, 2.f, 10.2f};
	EXPECT_FLOAT_EQ(t_TestVector[0], t_TestVector.m_X);
	EXPECT_FLOAT_EQ(t_TestVector[1], t_TestVector.m_Y);
	EXPECT_FLOAT_EQ(t_TestVector[2], t_TestVector.m_Z);
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

	// rejection
	Vec3D t_Rejection = t_VecA.Reject(t_VecB);
	EXPECT_FLOAT_EQ(t_Rejection.m_X, 0.f);
	EXPECT_FLOAT_EQ(t_Rejection.m_Y, 6.7f);
	EXPECT_FLOAT_EQ(t_Rejection.m_Z, 10.0f);

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

	t_TestMat = Mat3(
						t_00, t_10, t_20,
						t_01, t_11, t_21,
						t_02, t_12, t_22
	);
	{
		EXPECT_FLOAT_EQ(t_TestMat(0,0), t_00);
		EXPECT_FLOAT_EQ(t_TestMat(1,0), t_10);
		EXPECT_FLOAT_EQ(t_TestMat(2,0), t_20);
		EXPECT_FLOAT_EQ(t_TestMat(0,1), t_01);
		EXPECT_FLOAT_EQ(t_TestMat(1,1), t_11);
		EXPECT_FLOAT_EQ(t_TestMat(2,1), t_21);
		EXPECT_FLOAT_EQ(t_TestMat(0,2), t_02);
		EXPECT_FLOAT_EQ(t_TestMat(1,2), t_12);
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

	// + operator (Mat3)
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};


		Mat3 t_MatB =	{
							22.3f, 10.0f, 66.33f,
							13.2f, 11.0f, 12.6f,
							45.5f, 78.7f, 99.9f
						};

		Mat3 t_Sum = t_MatA + t_MatB;

		EXPECT_FLOAT_EQ(t_Sum[0][0], 5.f + 22.3f);
		EXPECT_FLOAT_EQ(t_Sum[0][1], 1.f + 13.2f);
		EXPECT_FLOAT_EQ(t_Sum[0][2], 2.f + 45.5f);

		EXPECT_FLOAT_EQ(t_Sum[1][0], 6.f + 10.0f);
		EXPECT_FLOAT_EQ(t_Sum[1][1], 4.f + 11.0f);
		EXPECT_FLOAT_EQ(t_Sum[1][2], 9.f + 78.7f);

		EXPECT_FLOAT_EQ(t_Sum[2][0], 7.f + 66.33f);
		EXPECT_FLOAT_EQ(t_Sum[2][1], 8.f + 12.6f);
		EXPECT_FLOAT_EQ(t_Sum[2][2], 0.f + 99.9f);
	}

	// + operator (float)
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		float t_Addend = 2.0;

		Mat3 t_Sum = t_MatA + t_Addend;

		EXPECT_FLOAT_EQ(t_Sum[0][0], t_MatA[0][0] + t_Addend);
		EXPECT_FLOAT_EQ(t_Sum[0][1], t_MatA[0][1] + t_Addend);
		EXPECT_FLOAT_EQ(t_Sum[0][2], t_MatA[0][2] + t_Addend);

		EXPECT_FLOAT_EQ(t_Sum[1][0], t_MatA[1][0] + t_Addend);
		EXPECT_FLOAT_EQ(t_Sum[1][1], t_MatA[1][1] + t_Addend);
		EXPECT_FLOAT_EQ(t_Sum[1][2], t_MatA[1][2] + t_Addend);

		EXPECT_FLOAT_EQ(t_Sum[2][0], t_MatA[2][0] + t_Addend);
		EXPECT_FLOAT_EQ(t_Sum[2][1], t_MatA[2][1] + t_Addend);
		EXPECT_FLOAT_EQ(t_Sum[2][2], t_MatA[2][2] + t_Addend);
	}

	// += operator
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		Mat3 t_MatB =	{
							22.3f, 10.0f, 66.33f,
							13.2f, 11.0f, 12.6f,
							45.5f, 78.7f, 99.9f
						};

		t_MatA += t_MatB;

		EXPECT_FLOAT_EQ(t_MatA[0][0], 5.f + 22.3f);
		EXPECT_FLOAT_EQ(t_MatA[0][1], 1.f + 13.2f);
		EXPECT_FLOAT_EQ(t_MatA[0][2], 2.f + 45.5f);

		EXPECT_FLOAT_EQ(t_MatA[1][0], 6.f + 10.0f);
		EXPECT_FLOAT_EQ(t_MatA[1][1], 4.f + 11.0f);
		EXPECT_FLOAT_EQ(t_MatA[1][2], 9.f + 78.7f);

		EXPECT_FLOAT_EQ(t_MatA[2][0], 7.f + 66.33f);
		EXPECT_FLOAT_EQ(t_MatA[2][1], 8.f + 12.6f);
		EXPECT_FLOAT_EQ(t_MatA[2][2], 0.f + 99.9f);
	}

	// += operator (float)
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		float t_Multiplicand = 2.0;

		t_MatA += t_Multiplicand;

		EXPECT_FLOAT_EQ(t_MatA[0][0], 7.f);
		EXPECT_FLOAT_EQ(t_MatA[0][1], 3.f);
		EXPECT_FLOAT_EQ(t_MatA[0][2], 4.f);

		EXPECT_FLOAT_EQ(t_MatA[1][0], 8.f);
		EXPECT_FLOAT_EQ(t_MatA[1][1], 6.f);
		EXPECT_FLOAT_EQ(t_MatA[1][2], 11.f);

		EXPECT_FLOAT_EQ(t_MatA[2][0], 9.f);
		EXPECT_FLOAT_EQ(t_MatA[2][1], 10.f);
		EXPECT_FLOAT_EQ(t_MatA[2][2], 2.f);
	}

	// - operator
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		Mat3 t_MatB =	{
							22.3f, 10.0f, 66.33f,
							13.2f, 11.0f, 12.6f,
							45.5f, 78.7f, 99.9f
						};

		Mat3 t_Sum = t_MatA - t_MatB;

		EXPECT_FLOAT_EQ(t_Sum[0][0], 5.f - 22.3f);
		EXPECT_FLOAT_EQ(t_Sum[0][1], 1.f - 13.2f);
		EXPECT_FLOAT_EQ(t_Sum[0][2], 2.f - 45.5f);

		EXPECT_FLOAT_EQ(t_Sum[1][0], 6.f - 10.0f);
		EXPECT_FLOAT_EQ(t_Sum[1][1], 4.f - 11.0f);
		EXPECT_FLOAT_EQ(t_Sum[1][2], 9.f - 78.7f);

		EXPECT_FLOAT_EQ(t_Sum[2][0], 7.f - 66.33f);
		EXPECT_FLOAT_EQ(t_Sum[2][1], 8.f - 12.6f);
		EXPECT_FLOAT_EQ(t_Sum[2][2], 0.f - 99.9f);
	}

	// -= operator
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		Mat3 t_MatB =	{
							22.3f, 10.0f, 66.33f,
							13.2f, 11.0f, 12.6f,
							45.5f, 78.7f, 99.9f
						};

		t_MatA -= t_MatB;

		EXPECT_FLOAT_EQ(t_MatA[0][0], 5.f - 22.3f);
		EXPECT_FLOAT_EQ(t_MatA[0][1], 1.f - 13.2f);
		EXPECT_FLOAT_EQ(t_MatA[0][2], 2.f - 45.5f);

		EXPECT_FLOAT_EQ(t_MatA[1][0], 6.f - 10.0f);
		EXPECT_FLOAT_EQ(t_MatA[1][1], 4.f - 11.0f);
		EXPECT_FLOAT_EQ(t_MatA[1][2], 9.f - 78.7f);

		EXPECT_FLOAT_EQ(t_MatA[2][0], 7.f - 66.33f);
		EXPECT_FLOAT_EQ(t_MatA[2][1], 8.f - 12.6f);
		EXPECT_FLOAT_EQ(t_MatA[2][2], 0.f - 99.9f);
	}

	// -= operator (float)
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		float t_Subtrahend = 10;

		t_MatA -= t_Subtrahend;

		EXPECT_FLOAT_EQ(t_MatA[0][0], 5.f - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_MatA[0][1], 1.f - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_MatA[0][2], 2.f - t_Subtrahend);

		EXPECT_FLOAT_EQ(t_MatA[1][0], 6.f - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_MatA[1][1], 4.f - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_MatA[1][2], 9.f - t_Subtrahend);

		EXPECT_FLOAT_EQ(t_MatA[2][0], 7.f - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_MatA[2][1], 8.f - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_MatA[2][2], 0.f - t_Subtrahend);
	}

	// - operator (float)
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		float t_Subtrahend = 2.0;

		Mat3 t_Sum = t_MatA - t_Subtrahend;

		EXPECT_FLOAT_EQ(t_Sum[0][0], t_MatA[0][0] - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_Sum[0][1], t_MatA[0][1] - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_Sum[0][2], t_MatA[0][2] - t_Subtrahend);

		EXPECT_FLOAT_EQ(t_Sum[1][0], t_MatA[1][0] - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_Sum[1][1], t_MatA[1][1] - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_Sum[1][2], t_MatA[1][2] - t_Subtrahend);

		EXPECT_FLOAT_EQ(t_Sum[2][0], t_MatA[2][0] - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_Sum[2][1], t_MatA[2][1] - t_Subtrahend);
		EXPECT_FLOAT_EQ(t_Sum[2][2], t_MatA[2][2] - t_Subtrahend);
	}



	// *= operator
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		Mat3 t_MatB =	{
							22.3f, 10.0f, 66.33f,
							13.2f, 11.0f, 12.6f,
							45.5f, 78.7f, 99.9f
						};

		t_MatA *= t_MatB;

		EXPECT_FLOAT_EQ(t_MatA[0][0], 509.2f);
		EXPECT_FLOAT_EQ(t_MatA[0][1], 439.1f);
		EXPECT_FLOAT_EQ(t_MatA[0][2], 163.4f);

		EXPECT_FLOAT_EQ(t_MatA[1][0], 666.9f);
		EXPECT_FLOAT_EQ(t_MatA[1][1], 683.6f);
		EXPECT_FLOAT_EQ(t_MatA[1][2], 119.f);

		EXPECT_FLOAT_EQ(t_MatA[2][0], 1106.55f);
		EXPECT_FLOAT_EQ(t_MatA[2][1], 915.93f);
		EXPECT_FLOAT_EQ(t_MatA[2][2], 246.06f);
	}

	// * operator
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		Mat3 t_MatB =	{
							22.3f, 10.0f, 66.33f,
							13.2f, 11.0f, 12.6f,
							45.5f, 78.7f, 99.9f
						};

		Mat3 t_Product = t_MatA * t_MatB;

		EXPECT_FLOAT_EQ(t_Product[0][0], 509.2f);
		EXPECT_FLOAT_EQ(t_Product[0][1], 439.1f);
		EXPECT_FLOAT_EQ(t_Product[0][2], 163.4f);

		EXPECT_FLOAT_EQ(t_Product[1][0], 666.9f);
		EXPECT_FLOAT_EQ(t_Product[1][1], 683.6f);
		EXPECT_FLOAT_EQ(t_Product[1][2], 119.f);

		EXPECT_FLOAT_EQ(t_Product[2][0], 1106.55f);
		EXPECT_FLOAT_EQ(t_Product[2][1], 915.93f);
		EXPECT_FLOAT_EQ(t_Product[2][2], 246.06f);
	}

	// * operator (Vec3D)
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

		Vec3D t_Product = t_MatA * t_Vec3D;

		EXPECT_FLOAT_EQ(t_Product[0], 4049.96063f);
		EXPECT_FLOAT_EQ(t_Product[1], 2676.64072f);
		EXPECT_FLOAT_EQ(t_Product[2], 6019.9400f);
	}

	// * operator (float)
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		float t_Multiplicand = 2.0;

		Mat3 t_Product = t_MatA * t_Multiplicand;

		EXPECT_FLOAT_EQ(t_Product[0][0], t_MatA[0][0] * t_Multiplicand);
		EXPECT_FLOAT_EQ(t_Product[0][1], t_MatA[0][1] * t_Multiplicand);
		EXPECT_FLOAT_EQ(t_Product[0][2], t_MatA[0][2] * t_Multiplicand);

		EXPECT_FLOAT_EQ(t_Product[1][0], t_MatA[1][0] * t_Multiplicand);
		EXPECT_FLOAT_EQ(t_Product[1][1], t_MatA[1][1] * t_Multiplicand);
		EXPECT_FLOAT_EQ(t_Product[1][2], t_MatA[1][2] * t_Multiplicand);

		EXPECT_FLOAT_EQ(t_Product[2][0], t_MatA[2][0] * t_Multiplicand);
		EXPECT_FLOAT_EQ(t_Product[2][1], t_MatA[2][1] * t_Multiplicand);
		EXPECT_FLOAT_EQ(t_Product[2][2], t_MatA[2][2] * t_Multiplicand);
	}

	// *= operator (float)
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		float t_Multiplicand = 2.0;

		t_MatA *= t_Multiplicand;

		EXPECT_FLOAT_EQ(t_MatA[0][0], 10.0f);
		EXPECT_FLOAT_EQ(t_MatA[0][1], 2.f);
		EXPECT_FLOAT_EQ(t_MatA[0][2], 4.f);

		EXPECT_FLOAT_EQ(t_MatA[1][0], 12.f);
		EXPECT_FLOAT_EQ(t_MatA[1][1], 8.f);
		EXPECT_FLOAT_EQ(t_MatA[1][2], 18.f);

		EXPECT_FLOAT_EQ(t_MatA[2][0], 14.f);
		EXPECT_FLOAT_EQ(t_MatA[2][1], 16.f);
		EXPECT_FLOAT_EQ(t_MatA[2][2], 0.f);
	}

	// == operator
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};
		Mat3 t_MatB = t_MatA;

		EXPECT_EQ(t_MatA == t_MatB, true);
	}
}

TEST(Matrix_Basic_Ops, Basic_Calculations)
{
	// Determinant
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		EXPECT_FLOAT_EQ(t_MatA.Det(), -257.f);

		Mat3 t_MatB =	{
							0.03f, 0.001f, 0.2f,
							0.7f, 0.099f, 1.f,
							2.33f, 4.f, 6.77f	
						};

		EXPECT_FLOAT_EQ(t_MatB.Det(), 0.4115639f);

		Mat3 t_MatC =	{
							99999999.9999f, 4239487.9f, 9832748.f,
							1010010.19910f, 10000000.f, 45000.f,
							6000000.f, 1000000.99988f, 420.f	
						};

		EXPECT_FLOAT_EQ(t_MatC.Det(), -5.829708355f * powf(10.f, 20.f));
	}

	// Inverse
	{
		Mat3 t_MatA =	{
							5.f, 6.f, 7.f,
							1.f, 4.f, 8.f,
							2.f, 9.f, 0.f
						};

		Mat3 t_MatInv = t_MatA.Inv();

		EXPECT_FLOAT_EQ(t_MatInv[0][0], 0.280155642f);
		EXPECT_FLOAT_EQ(t_MatInv[0][1], -0.0622568093f);
		EXPECT_FLOAT_EQ(t_MatInv[0][2], -0.00389105058f);

		EXPECT_FLOAT_EQ(t_MatInv[1][0], -0.245136187f);
		EXPECT_FLOAT_EQ(t_MatInv[1][1], 0.0544747082f);
		EXPECT_FLOAT_EQ(t_MatInv[1][2], 0.128404669f);

		EXPECT_FLOAT_EQ(t_MatInv[2][0], -0.0778210117f);
		EXPECT_FLOAT_EQ(t_MatInv[2][1], 0.128404669f);
		EXPECT_FLOAT_EQ(t_MatInv[2][2], -0.0544747082f);
	}
}

TEST(Martix4D_Basic_Ops, Constructors)
{
	// default constructor
	{
		Mat4 t_Test;

		EXPECT_FLOAT_EQ(t_Test(0, 0), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(0, 1), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(0, 2), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(0, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(1, 0), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(1, 1), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(1, 2), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(1, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(2, 0), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(2, 1), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(2, 2), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(2, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(3, 0), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(3, 1), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(3, 2), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(3, 3), 0.0f);
	}

	// diagonal constructor
	{
		Mat4 t_Test(1.0f);

		EXPECT_FLOAT_EQ(t_Test(0, 0), 1.0f);
		EXPECT_FLOAT_EQ(t_Test(0, 1), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(0, 2), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(0, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(1, 0), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(1, 1), 1.0f);
		EXPECT_FLOAT_EQ(t_Test(1, 2), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(1, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(2, 0), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(2, 1), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(2, 2), 1.0f);
		EXPECT_FLOAT_EQ(t_Test(2, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(3, 0), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(3, 1), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(3, 2), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(3, 3), 1.0f);
	}

	// 16-float constructor
	{
		Mat4 t_Test = {
							4.0f, 1.3f, 6.0f, 8.0f,
							6.7f, 4.0f, 6.6f, 10.f,
							12.f, 2.4f, 3.0f, 6.6f,
							0.0f, 0.0f, 0.0f, 1.0f
		};

		EXPECT_FLOAT_EQ(t_Test(0, 0), 4.0f);
		EXPECT_FLOAT_EQ(t_Test(0, 1), 6.7f);
		EXPECT_FLOAT_EQ(t_Test(0, 2), 12.f);
		EXPECT_FLOAT_EQ(t_Test(0, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(1, 0), 1.3f);
		EXPECT_FLOAT_EQ(t_Test(1, 1), 4.0f);
		EXPECT_FLOAT_EQ(t_Test(1, 2), 2.4f);
		EXPECT_FLOAT_EQ(t_Test(1, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(2, 0), 6.0f);
		EXPECT_FLOAT_EQ(t_Test(2, 1), 6.6f);
		EXPECT_FLOAT_EQ(t_Test(2, 2), 3.0f);
		EXPECT_FLOAT_EQ(t_Test(2, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(3, 0), 8.0f);
		EXPECT_FLOAT_EQ(t_Test(3, 1), 10.f);
		EXPECT_FLOAT_EQ(t_Test(3, 2), 6.6f);
		EXPECT_FLOAT_EQ(t_Test(3, 3), 1.0f);
	}
}

TEST(Matrix4D_Basic_Ops, Operators)
{
	// () operator
	{
		Mat4 t_Test;

		EXPECT_FLOAT_EQ(t_Test(0, 0), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(0, 1), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(0, 2), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(0, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(1, 0), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(1, 1), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(1, 2), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(1, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(2, 0), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(2, 1), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(2, 2), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(2, 3), 0.0f);

		EXPECT_FLOAT_EQ(t_Test(3, 0), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(3, 1), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(3, 2), 0.0f);
		EXPECT_FLOAT_EQ(t_Test(3, 3), 0.0f);
	}

	// + operator
	{
		Mat4 t_MatA = {
							4.0f, 1.3f, 6.0f, 8.0f,
							6.7f, 4.0f, 6.6f, 10.f,
							12.f, 2.4f, 3.0f, 6.6f,
							0.0f, 0.0f, 0.0f, 1.0f
						};

		Mat4 t_MatB = {
							2.0f, 1.4f, 7.8f, 5.5f,
							4.7f, 5.6f, 6.3f, 3.2f,
							8.0f, 2.4f, 2.8f, 4.0f,
							1.0f, 5.6f, 2.6f, 1.5f
						};

		Mat4 t_Sum = t_MatA + t_MatB;

		EXPECT_FLOAT_EQ(t_Sum(0, 0), t_MatA(0,0) + t_MatB(0,0));
		EXPECT_FLOAT_EQ(t_Sum(0, 1), t_MatA(0,1) + t_MatB(0,1));
		EXPECT_FLOAT_EQ(t_Sum(0, 2), t_MatA(0,2) + t_MatB(0,2));
		EXPECT_FLOAT_EQ(t_Sum(0, 3), t_MatA(0,3) + t_MatB(0,3));

		EXPECT_FLOAT_EQ(t_Sum(1, 0), t_MatA(1,0) + t_MatB(1,0));
		EXPECT_FLOAT_EQ(t_Sum(1, 1), t_MatA(1,1) + t_MatB(1,1));
		EXPECT_FLOAT_EQ(t_Sum(1, 2), t_MatA(1,2) + t_MatB(1,2));
		EXPECT_FLOAT_EQ(t_Sum(1, 3), t_MatA(1,3) + t_MatB(1,3));

		EXPECT_FLOAT_EQ(t_Sum(2, 0), t_MatA(2,0) + t_MatB(2,0));
		EXPECT_FLOAT_EQ(t_Sum(2, 1), t_MatA(2,1) + t_MatB(2,1));
		EXPECT_FLOAT_EQ(t_Sum(2, 2), t_MatA(2,2) + t_MatB(2,2));
		EXPECT_FLOAT_EQ(t_Sum(2, 3), t_MatA(2,3) + t_MatB(2,3));

		EXPECT_FLOAT_EQ(t_Sum(3, 0), t_MatA(3,0) + t_MatB(3,0));
		EXPECT_FLOAT_EQ(t_Sum(3, 1), t_MatA(3,1) + t_MatB(3,1));
		EXPECT_FLOAT_EQ(t_Sum(3, 2), t_MatA(3,2) + t_MatB(3,2));
		EXPECT_FLOAT_EQ(t_Sum(3, 3), t_MatA(3,3) + t_MatB(3,3));
	}
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest();

	RUN_ALL_TESTS();

	return 0;
}