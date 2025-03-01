#include <gtest/gtest.h>

#include "../include/placeholder.h"

TEST (TestSuite, FirstTest) {

  EXPECT_EQ(1, 1);
}

//TEST (TestSuite, ExpectException) {
//  EXPECT_THROW( methodThatThrows( 'A'), std::invalid_argument);
//}

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
