//***************************************************************************
// File name:   CalculatorTests.cpp
// Author:      chadd williams
// Date:        1/27/25
// Class:       CS 485
// Assignment:  Unit test example
// Purpose:     Unit tests for class Calculator
//***************************************************************************

#include <gtest/gtest.h>

#include "../include/Calculator.h"

//***************************************************************************
// Test:    		TestSimpleAdd
//
// Description: Test a simple two operand add
//
//***************************************************************************
TEST (TestSuite, TestSimpleAdd) {
	Calculator cCalc;

  EXPECT_EQ( cCalc.add(1, 2), 3.0);
}

//***************************************************************************
// Test:    		TestChainAdd
//
// Description: Test a chain of adds, 1+2+9
//
//***************************************************************************
TEST (TestSuite, TestChainAdd) {
	Calculator cCalc;

	cCalc.add(1, 2);

  EXPECT_EQ( cCalc.add(9), 12.0);
}

//***************************************************************************
// Test:    		ExpectException
//
// Description: Test that Calculator::add(int) throws an exception if no
//							running total exists
//
//***************************************************************************
TEST (TestSuite, ExpectException) {
	Calculator cCalc;

  EXPECT_THROW( cCalc.add(1), std::invalid_argument);
}

//***************************************************************************
// Test:    		ShowFailingtest
//
// Description: Show a test failing, 0+1 != 2
//
//***************************************************************************
TEST (TestSuite, ShowFailingtest) {
	Calculator cCalc;

  EXPECT_EQ( cCalc.add(0, 1), 2.0);
}


//TEST (TestSuite, ExpectTerminate) {
//  // expect exit with code 1
//  EXPECT_EXIT(methodThatCallsExit(-1), testing::ExitedWithCode(EXIT_FAILURE), ".*");
//  // expect any nonzero exit code
//  EXPECT_DEATH(methodThatCallsExit(-100), ".*");
//}


//https://stackoverflow.com/a/22737849
// cmake --build build 
// build/test/TestsToRun
// TestsToRun is from CMakeLists.txt line 5
//    set(This TestsToRun)
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
