#include <gtest/gtest.h>

#include "../include/Calculator.h"

TEST (TestSuite, TestSimpleAdd) {
	Calculator cCalc;

  EXPECT_EQ( cCalc.add(1, 2), 3.0);
}

TEST (TestSuite, TestChainAdd) {
	Calculator cCalc;

	cCalc.add(1, 2);

  EXPECT_EQ( cCalc.add(9), 12.0);
}


TEST (TestSuite, ExpectException) {
	Calculator cCalc;

  EXPECT_THROW( cCalc.add(1), std::invalid_argument);
}

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
