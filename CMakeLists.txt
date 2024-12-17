file(GLOB SOURCES
    src/*.cpp
)

cmake_minimum_required(VERSION 3.5)

# Set the project name and version
project(Lunify VERSION 1.0 LANGUAGES CXX)

# Add the executable target
add_executable(Lunify ${SOURCES})

# Link against the Qt5 libraries
target_link_libraries(Lunify PRIVATE)
target_include_directories(Lunify PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_compile_features(Lunify PUBLIC cxx_std_23)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)

# Set clangd++ as the compiler
set(CMAKE_CXX_COMPILER "clang++")
