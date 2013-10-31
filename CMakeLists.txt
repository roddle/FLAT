# cmake for FLAT (https://github.com/Cheeseness/FLAT)
# created by Marcus Møller (https://github.com/marcusmoller)

cmake_minimum_required (VERSION 2.6)

project (FLAT)

# project version
set (FLAT_VERSION_MAJOR 1)
set (FLAT_VERSION_MINOR 0)

# set compiler flags
set( CMAKE_CXX_FLAGS "-Wall -Wno-switch" CACHE STRING "C++ compiler flags" FORCE )

# add src directory
add_subdirectory(src)
