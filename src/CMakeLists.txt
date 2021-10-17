
cmake_minimum_required(VERSION 3.13.4)
project(MPAGSCipher VERSION 0.1.0)
set(CMAKE_VERBOSE_MAKEFILE ON)

# set cmake standard and extensions
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

# list files to be compiled
add_executable(mpags-cipher
               mpags-cipher.cpp
               MPAGSCipher/TransformChar.cpp
               MPAGSCipher/ProcessCommandLine.cpp
               MPAGSCipher/RunCaesarCipher.cpp)

# add new directories
target_include_directories(mpags-cipher
                           PRIVATE MPAGSCipher)
# set directory for executable
set_target_properties(mpags-cipher PROPERTIES 
                      RUNTIME_OUTPUT_DIRECTORY ../src)

# add flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher PRIVATE cxx_auto_type cxx_range_for
                        cxx_uniform_initialization)

