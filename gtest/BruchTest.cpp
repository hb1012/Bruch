//
// Created by hbill on 29.07.2021.
//
#include <gtest/gtest.h>
//#include "../lib/include/gtest/gtest.h"
#include "../src/Bruch.h"

/*
TEST(BruchTest, Equal) {
  Bruch a1{3, 7};
  Bruch a2{6, 14};
  EXPECT_TRUE(a1 == a2);
}

TEST(BruchTest, UnEqual) {
  Bruch a1{ 2, 4 };
  Bruch a2{ 3, 6 };
  EXPECT_FALSE(a1 != a2);
}

TEST(BruchTest, Greater) {
  Bruch a1{ 2, 4 };
  Bruch a2{ 2, 6 };
  EXPECT_TRUE(a1 > a2);
}

TEST(BruchTest, Lesser) {
  Bruch a1{ 2, 4 };
  Bruch a2{ 5, 6 };
  EXPECT_TRUE(a1 < a2);
}

TEST(BruchTes, AddMethodt) {
    Bruch a1{ 1, 4 };
    Bruch a2{ 1, 6 };
    Bruch a3{ 5, 12 };
    EXPECT_TRUE(a1 + a2 == a3);
}
*/

// The fixture for testing class Bruch.
class BruchTest : public ::testing::Test {
protected:
  Bruch a1{ 1, 4 };
  Bruch a2{ 2, 8 };
  Bruch a3{ 4, 8 };
};

TEST_F(BruchTest, Equal) {
  EXPECT_TRUE(a1 == a2);
}

TEST_F(BruchTest, UnEqual) {
  EXPECT_FALSE(a1 != a2);
}

TEST_F(BruchTest, Greater) {
  EXPECT_TRUE(a3 > a2);
}

TEST_F(BruchTest, Lesser) {
  EXPECT_TRUE(a1 < a3);
}

TEST_F(BruchTest, AddMethod) {
  EXPECT_TRUE(a1 + a2 == a3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
