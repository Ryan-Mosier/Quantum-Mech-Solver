cmake_minimum_required(VERSION 3.15)

project("Expression Library")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-O3)

include_directories(include)
include_directories(.)

aux_source_directory(src SOURCE_FILES)
aux_source_directory(src/strategies SOURCE_FILES)
add_library(Expressions ${SOURCE_FILES})

