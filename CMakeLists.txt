cmake_minimum_required(VERSION 3.15)

project("Quantum Mech Solver")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-O3)

add_subdirectory(src/Expressions)

add_executable(interpreter src/interpreter.cpp
        src/Parser.cpp)
target_link_libraries(interpreter PRIVATE Expressions)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE Expressions)
