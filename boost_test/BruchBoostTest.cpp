//
// Created by hb on 30.07.21.
//
#define BOOST_TEST_MODULE BruchTest
#include <boost/test/unit_test.hpp>
#include "../src/Bruch.h"

//int add( int i, int j ) { return i+j; }

BOOST_AUTO_TEST_CASE( bruch_test ) {
  Bruch a1{1, 2};
  Bruch a2{3, 6};

  // seven ways to detect and report the same error:
  BOOST_CHECK( a1 == a2 );        // #1 continues on error

  BOOST_REQUIRE( a1 == a2 );      // #2 throws on error

  if( a1 != a2 )
    BOOST_ERROR( "Ouch..." );            // #3 continues on error

  if( a1 != a2 )
    BOOST_FAIL( "Ouch..." );             // #4 throws on error

  if( a1 != a2 ) throw "Ouch..."; // #5 throws on error

  BOOST_CHECK_MESSAGE( a1 == a2,  // #6 continues on error
                       "add(..) result: ");

  BOOST_CHECK_EQUAL( a1, a2 );	  // #7 continues on error
}