project(child VERSION 1.2.3 LANGUAGES CXX)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(child SHARED child.cpp)
add_library(child::child ALIAS child)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    SOVERSION ${PROJECT_VERSION}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        THE_ANSWER=42
)

# 1. Install the library itself (*.so)
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)

# 2. Install the headers (include/*.hpp)
install(FILES include/child.hpp DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

# 3. Generate the "targets" file for the generated export set
install(EXPORT ${PROJECT_NAME}
    NAMESPACE ${PROJECT_NAME}::
    FILE ${PROJECT_NAME}Targets.cmake
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)

# 4. Generate the "config" file for the generated export set
configure_package_config_file(
    Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)

# 5. Generate the "version" file for the generated export set
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${${PROJECT_NAME}_VERSION}
    COMPATIBILITY SameMajorVersion
)

# 6. Finally, install the package files generated above
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/childConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/childConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/child"
)
