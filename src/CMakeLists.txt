cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

set(CMAKE_VERBOSE_MAKEFILE ON)

# - Declare the build of mpags-cipher main program
add_executable(mpags-cipher
    mpags-cipher.cpp
    MPAGSCipher/TransformChar.cpp
    MPAGSCipher/ProcessCommandLine.cpp
    MPAGSCipher/RunCaesarCipher.cpp
)

set(CMAKE_CXX_EXTENSIONS off)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher PUBLIC cxx_std_17)

target_compile_features(mpags-cipher PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization)