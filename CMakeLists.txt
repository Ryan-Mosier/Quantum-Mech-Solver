cmake_minimum_required(VERSION 3.15)

project("Quantum Mech Solver")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-O3)
# for testing
#add_compile_options(-O0)

add_subdirectory(src/Expressions)

include(CTest)
if (BUILD_TESTING)
    add_subdirectory(tests)
endif()


add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE Expressions parser)

add_library(parser src/Parser.cpp)
target_link_libraries(parser PRIVATE Expressions)

if (BUILD_TESTING)
    add_custom_target(run_tests
            COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIG>
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            USES_TERMINAL
    )
endif()
