cmake_minimum_required(VERSION 2.6)

#Project definition
project(ArbitaryPrecisionFloatingPointNumber)

#Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test
# and the GTest and pthread library

add_executable( runUnitTests UnitTests.cpp )
target_link_libraries(runUnitTests gtest gtest_main pthread)
target_compile_features(runUnitTests PRIVATE cxx_std_17)