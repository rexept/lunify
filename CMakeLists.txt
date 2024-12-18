file(GLOB SOURCES
    src/*.cpp
)

cmake_minimum_required(VERSION 3.5)

# Set the project name and version
project(lunify VERSION 1.0.0 LANGUAGES CXX)

# Add the executable target
add_executable(lunify ${SOURCES})

target_include_directories(lunify PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_compile_features(lunify PUBLIC cxx_std_23)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Building in Release mode")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -Wall")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building in Debug mode")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall")
endif()

install(TARGETS lunify DESTINATION /usr/local/bin)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)

# Set clangd++ as the compiler
set(CMAKE_CXX_COMPILER "clang++")
