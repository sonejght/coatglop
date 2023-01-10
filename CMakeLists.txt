cmake_minimum_required(VERSION 3.8)
project(son8coatglop LANGUAGES C CXX)

add_library(${PROJECT_NAME} source/coatglop.cxx)

target_compile_features(${PROJECT_NAME}
    PRIVATE cxx_std_17
    PRIVATE c_std_11
)

cmake_policy(SET CMP0072 NEW)
find_package(OpenGL REQUIRED)
add_subdirectory(libs/glad)

target_link_libraries(${PROJECT_NAME} glad)
target_include_directories(${PROJECT_NAME}
    PUBLIC include
    PRIVATE source
)
