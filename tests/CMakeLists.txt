cmake_minimum_required(VERSION 3.22)
project(QuantumMechSolverTests LANGUAGES CXX)

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

add_executable(runUnitTests
        ExpressionsTest/CreationTests.cpp
        ExpressionsTest/UsageTests.cpp
)

target_link_libraries(runUnitTests PRIVATE
        GTest::gtest_main
        Expressions
)

include(GoogleTest)
gtest_discover_tests(runUnitTests)
