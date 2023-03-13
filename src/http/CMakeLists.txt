add_library(http)

target_sources(http PUBLIC
    get_request.hpp
    get_request.cpp
    request.hpp
)

target_include_directories(http PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})