cmake_minimum_required(VERSION 3.28)

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

file(GLOB_RECURSE PARSER_CPP CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE PARSER_MODULES CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cppm
)

# Remove main.cpp from the library sources
list(FILTER PARSER_CPP EXCLUDE REGEX "src/main.cpp$")
# Also exclude Expressions subdirectory
list(FILTER PARSER_CPP EXCLUDE REGEX "src/Expressions/.*")
list(FILTER PARSER_MODULES EXCLUDE REGEX "src/Expressions/.*")

add_library(parser)
target_sources(parser
        PUBLIC FILE_SET parser_modules TYPE CXX_MODULES FILES ${PARSER_MODULES}
        PRIVATE ${PARSER_CPP}
)
target_link_libraries(parser PRIVATE Expressions)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE Expressions parser)

if (BUILD_TESTING)
    add_custom_target(run_tests
            COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIG>
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            USES_TERMINAL
    )
endif()
