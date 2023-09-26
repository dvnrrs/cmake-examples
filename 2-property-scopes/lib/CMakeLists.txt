add_library(child child.cpp)
add_library(child::child ALIAS child)

set_target_properties(child PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# This won't work if we install libchild and an external project (CMake-based
# or otherwise) tries to use it! We need to install the headers somewhere, and
# use "generator expressions" to point to the right thing! We'll do this later
# in the package deployment example.
target_include_directories(child
    PUBLIC
        include
)

# Do this...
target_compile_definitions(child
    PUBLIC
        THE_ANSWER=42
)

# NOT this! This would be global and affect all children! ALWAYS use the
# target-specific CMake commands!
#
# add_compile_definitions(THE_ANSWER=42)

install(TARGETS child)
