# CMake Examples

This repository contains a number of CMake example projects. They are
intended to illustrate certain CMake features which were presented in
a live session along with [a PowerPoint presentation](CMake.ppt) and
to provide a sandbox in which some of the features can be explored.

1. `1-basic-project` - A basic CMake project to illustrate the language.
   This example compiles a simple C++ executable with no dependencies.
2. `2-property-scopes` - An extended CMake example with a C++ static
   library and an executable that links to the library. The various
   CMake property scopes (PUBLIC, PRIVATE, INTERFACE) are exhibited.
3. `3-variable-scopes` - A CMake example which illustrates how CMake
   normal and cache variables differ and how the scope rules work.
4. `4-producing-packages` - A CMake example which illustrates how to
   to create a "package" for `find_package()`.
5. `5-consuming-packages` - A CMake example which illustrates how to
   consume a package with `find_package()`.
6. `6-fetchcontent` - A CMake example which uses the find-or-fetch
   pattern with FetchContent to automatically download and build
   dependencies.
