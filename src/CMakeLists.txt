target_sources(curl_cpp PUBLIC main.cpp)

add_subdirectory(http)
target_link_libraries(curl_cpp http)
