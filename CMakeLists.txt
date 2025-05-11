cmake_minimum_required(VERSION 3.26)
project(jenkins_trainee_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(jenkins_trainee_1 src/main.cpp)

find_package(spdlog REQUIRED)

target_link_libraries(jenkins_trainee_1 spdlog::spdlog)

target_include_directories(jenkins_trainee_1 PUBLIC src)

add_subdirectory(src)
