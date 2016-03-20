#include "CppUTest/TestHarness.h"

TEST_GROUP(FailTest)
{
	void setup()
	{
	}
	void teardown()
	{
	}
};

TEST(FailTest, Fail)
{
	CHECK(false);
}
