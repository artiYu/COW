/*
* © Yuliya S. Artishevskaya
* e-mail: lapl4rt@gmail.com
*/

#include "CWString.h"
#include "gtest\gtest.h"
#include <iostream>

TEST (FirstTest, CreateStringsWithVariousConstructors) {
	CWString s1 = "Perpetuum mobile";
	CWString s2 (s1);
	EXPECT_STREQ ("Perpetuum mobile", s2);
}

TEST (SecondTest, MuteStringBySquareBracketsIfOneReference) {
	CWString s1 = "Perpetuum mobile";
	for (int i = 0; i < 10; ++i)
		s1[i] = 'Y';
	EXPECT_STREQ ("YYYYYYYYYYmobile", s1);
}

TEST (ThirdTest, MuteStringBySquareBracketsIfMoreThanOneReference) {
	CWString s1 = "Perpetuum mobile";
	CWString s2 = s1;
	CWString s3 (s1);
	for (int i = 0; i < 10; ++i) 
		s3[i] = 'Y';
	EXPECT_STREQ ("YYYYYYYYYYmobile", s3);
	EXPECT_STREQ ("Perpetuum mobile", s1);
	EXPECT_STREQ ("Perpetuum mobile", s2);
}

TEST (ForthTest, CheckOfOperationSquareBrackets) {
	CWString s1 = "Perpetuum mobile";
	EXPECT_EQ ('P', s1[0]);
}


TEST (FifthTest, CheckSomeArithmeticOperations) {
	CWString s1 = "1", s2 = "2", s3 = "3", s4, s5, s6;
	s3 += s1;
	s4 = s1 + s2;
	s5 = s4 + "4";
	s6 = "5" + s5;
	EXPECT_STREQ ("1", s1);
	EXPECT_STREQ ("2", s2);
	EXPECT_STREQ ("31", s3);
	EXPECT_STREQ ("12", s4);
	EXPECT_STREQ ("124", s5);
	EXPECT_STREQ ("5124", s6);
}

TEST (SixthTest, CheckForMathingFieldsSum) {
	CWString s1 = "Opa", s2;
	s1 += s1;
	s2 += s2;
	EXPECT_STREQ ("OpaOpa", s1);
	EXPECT_STREQ ("", s2);
}

TEST (SeventhTest, CheckForMathingFieldsAssignment) {
	CWString s1 = "Perpetuum mobile";
	s1 = s1;
	EXPECT_STREQ ("Perpetuum mobile", s1);
}

GTEST_API_ int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 
}

