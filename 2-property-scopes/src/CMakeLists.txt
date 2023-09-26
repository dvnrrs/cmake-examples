add_executable(parent main.cpp)

set_target_properties(parent PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_link_libraries(parent child::child)

install(TARGETS parent)
