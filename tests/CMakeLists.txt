include(CTest)
enable_testing()

include_directories("../src/Expressions")

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

add_executable(runUnitTests
        ExpressionTests/CreationTests.cpp
        ExpressionTests/UsageTests.cpp
        ParserTests/tests.cpp
)

target_link_libraries(runUnitTests PRIVATE
        GTest::gtest_main
        Expressions
        parser
)

include(GoogleTest)
gtest_add_tests(TARGET runUnitTests)
