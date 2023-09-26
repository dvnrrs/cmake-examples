add_executable(standalone main.cpp)

set_target_properties(standalone PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

install(TARGETS standalone)
