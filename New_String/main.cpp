#include "NewString.h"
#include "gtest\gtest.h"
#include <iostream>

TEST (FirstTest, CreateStringsWithVariousConstructors) {
	NewString s1 = "Perpetuum mobile";
	NewString s2 (s1);
	EXPECT_STREQ ("Perpetuum mobile", s2);
}

TEST (SecondTest, MuteStringBySquareBracketsIfOneReference) {
	NewString s1 = "Perpetuum mobile";
	for (int i = 0; i < 10; ++i)
		s1[i] = 'Y';
	EXPECT_STREQ ("YYYYYYYYYYmobile", s1);
}

TEST (ThirdTest, MuteStringBySquareBracketsIfMoreThanOneReference) {
	NewString s1 = "Perpetuum mobile";
	NewString s2 = s1;
	NewString s3 (s1);
	for (int i = 0; i < 10; ++i) 
		s3[i] = 'Y';
	EXPECT_STREQ ("YYYYYYYYYYmobile", s3);
	EXPECT_STREQ ("Perpetuum mobile", s1);
	EXPECT_STREQ ("Perpetuum mobile", s2);
}

TEST (ForthTest, CheckOfOperationSquareBrackets) {
	NewString s1 = "Perpetuum mobile";
	EXPECT_EQ ('P', s1[0]);
}


TEST (FifthTest, CheckSomeArithmeticOperations) {
	NewString s1 = "1", s2 = "2", s3 = "3", s4, s5, s6;
	s3 += s1;
	s4 = s1 + s2;
	s5 = s4 + "4";
	s6 = "5" + s5;
	EXPECT_STREQ ("31", s3);
	EXPECT_STREQ ("12", s4);
	EXPECT_STREQ ("124", s5);
	EXPECT_STREQ ("5124", s6);
}

GTEST_API_ int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 
}

