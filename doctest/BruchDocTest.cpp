//
// Created by hb on 30.07.21.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/Bruch.h"

TEST_SUITE("Bruch operators") {
  TEST_CASE("testing equal operator") {
    Bruch a1{3, 7};
    Bruch a2{6, 14};
    CHECK(a1 == a2);
  }

  TEST_CASE("testing greater operator") {
    Bruch a1{3, 7};
    Bruch a2{4, 14};
    CHECK(a1 > a2);
  }
}