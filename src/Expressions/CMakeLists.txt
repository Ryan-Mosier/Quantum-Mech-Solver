cmake_minimum_required(VERSION 3.28)

project("Expression Library")

set(CMAKE_CXX_STANDARD 23)

add_library(Expressions STATIC)

target_compile_features(Expressions PUBLIC cxx_std_23)

target_compile_options(Expressions PRIVATE $<$<CONFIG:Release>:-O3>)

file(GLOB_RECURSE EXPR_CPP CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE EXPR_MODULES CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cppm
)

target_sources(Expressions
        PUBLIC FILE_SET expr_modules TYPE CXX_MODULES FILES ${EXPR_MODULES}
        PRIVATE ${EXPR_CPP}
)