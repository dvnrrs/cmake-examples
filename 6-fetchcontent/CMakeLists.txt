cmake_minimum_required(VERSION 3.24)

include(FetchContent)

project(6-fetchcontent LANGUAGES CXX)

set(libcppwrap_REQUIRED_VERSION 1.3.4)
set(libcppwrap_PREFERRED_VERSION 1.3.4)

find_package(libcppwrap ${libcppwrap_REQUIRED_VERSION} QUIET)

if(NOT libcppwrap_FOUND)

    # Fetch a tarball...
    FetchContent_Declare(libcppwrap
        URL https://github.com/dvnrrs/libcppwrap/archive/refs/tags/v${libcppwrap_REQUIRED_VERSION}.tar.gz
    )

    # Fetch a Git repository, using a branch name, tag name, or (PREFERRED) commit hash
    # NOTE: GIT_SHALLOW can be used (with branch/tag names only) to avoid checking out
    # the entire Git history (so it's similar to a tarball).
    #
    # FetchContent_Declare(libcppwrap
    #     GIT_REPOSITORY https://github.com/dvnrrs/libcppwrap
    #     GIT_TAG origin/main
    # )

    FetchContent_MakeAvailable(libcppwrap)

endif()

add_executable(test main.cpp)

# COMMON PITFALLS: Make SURE the name you give here is A TARGET NAME! Otherwise
# CMake will silently interpret it as a library name to give the linker via -l.
# Sometimes this ACCIDENTALLY works and can lead to nasty issues!

target_link_libraries(test cppwrap)
