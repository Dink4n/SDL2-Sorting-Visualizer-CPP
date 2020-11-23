cmake_minimum_required(VERSION 3.10)

project(sorting-visualizer LANGUAGES CXX)

# specify the c++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# generate the compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

# set the build type
set(CMAKE_BUILD_TYPE Debug)

# set binary directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

# get the source files
file (GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# link libraries
target_link_libraries(${PROJECT_NAME} SDL2 SDL2main)

# include directories
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")

# set the default flags
if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wunreachable-code -Wpedantic)
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
    target_compile_options(${PROJECT_NAME} PRIVATE -Wweak-vtables -Wexit-time-destructors -Wglobal-constructors -Wmissing-noreturn)
endif()

# log
message(STATUS "Build type ${CMAKE_BUILD_TYPE}")
