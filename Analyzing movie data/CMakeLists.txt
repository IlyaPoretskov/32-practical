cmake_minimum_required (VERSION 3.17)
project("Analyzing_movie_data")

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory("nlohmann json")

add_executable(${PROJECT_NAME} data.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)