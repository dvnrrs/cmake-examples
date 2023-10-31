cmake_minimum_required(VERSION 3.22)

project(2-property-scopes LANGUAGES CXX)

# It's tempting to put something like this here... but DON'T, or at least
# be very careful! These affect ALL targets defined in this directory or
# its subdirectories, INCLUDING external ones fetched via FetchContent!
#
# https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD.html
# https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD_REQUIRED.html
# https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_EXTENSIONS.html
#
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lib)
add_subdirectory(src)
