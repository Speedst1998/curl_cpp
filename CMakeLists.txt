cmake_minimum_required(VERSION 3.16)
project(curl_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(curl_cpp)
add_subdirectory(src)
add_subdirectory(test)

include(ExternalProject)
include(FetchContent)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/spdlog/include)

ExternalProject_Add(spdlog_project
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        v1.11.0
    PREFIX         ${CMAKE_BINARY_DIR}/spdlog
    INSTALL_DIR    ${CMAKE_BINARY_DIR}/spdlog
    CMAKE_ARGS     -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/spdlog
    BUILD_BYPRODUCTS ${CMAKE_BINARY_DIR}/spdlog/lib/libspdlog.a
    BUILD_ALWAYS   OFF
    UPDATE_COMMAND ""
)

# Define a target to link with spdlog
add_library(spdlog STATIC IMPORTED GLOBAL)
set_target_properties(spdlog PROPERTIES
    IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/spdlog/lib/libspdlog.a
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_BINARY_DIR}/spdlog/include
)

# Make sure spdlog is built before building any targets that depend on it
add_dependencies(spdlog spdlog_project)
add_dependencies(curl_cpp spdlog)

target_link_libraries(curl_cpp spdlog)
