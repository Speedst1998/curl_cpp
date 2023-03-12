cmake_minimum_required(VERSION 3.16)
project(curl_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(curl_cpp)
add_subdirectory(src)

