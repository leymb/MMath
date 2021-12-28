#include <gtest/gtest.h>
#include <vector_math/mma_vector.h>

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
	const Vec3D t_VecA = {5.f, 6.f, 2.f};
	const Vec3D t_VecB = {10000000000000.f, 200000000000.f, 98734928734.f};
	const Vec3D t_VecC = {0.00001f, 0.0000032f, 0.98734928734f};

	const float t_ScalarTriple = t_VecA.ScalarTriple(t_VecB, t_VecC);
	
	EXPECT_FLOAT_EQ(t_ScalarTriple, -5.82535458f * powf(10.0, 13.f));
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest();

	RUN_ALL_TESTS();

	return 0;
}