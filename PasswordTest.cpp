/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, Three_leading_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZ123");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, single_leading_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AZZZ123");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, only_lower_case_letters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaaaa");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_upper_case_letters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AAAAA");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_numbers)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("483481");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_special_characters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("*&$!)&");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, begins_with_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Aaaaaa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, begins_with_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aAAAAA");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, randomly_placed_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaAa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, randomly_placed_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AAAAaAAA");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, ends_with_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaaaA");
	ASSERT_EQ(true, actual);
}