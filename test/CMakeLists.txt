# CMakeLists.txt for test directory

cmake_minimum_required(VERSION 3.0)

set(This TestsToRun)

# Add unit test .cpp files which are in directory test
set(Sources
    Tests.cpp
)

add_executable(${This} ${Sources})

# The TestSuite name comes from the name set(This TestSuite) 
# in the root CMakeLists.txt. Nothing else to add here even if you add
# additional classes for testing.
target_link_libraries(${This} PUBLIC
    gtest_main
	TestSuite
)

add_test(
    NAME ${This}
    COMMAND ${This} 
)
