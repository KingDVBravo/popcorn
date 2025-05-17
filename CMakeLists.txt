cmake_minimum_required(VERSION 3.10)
project(popcorn C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enable strict warnings
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Recursively gather all C source files in src/
file(GLOB_RECURSE SOURCES src/*.c)

# Find SDL2 and SDL2_image via pkg-config
find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)

# Create executable target
add_executable(popcorn ${SOURCES})

# Add include directories from pkg-config and your own headers
target_include_directories(popcorn PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
)

# Link SDL2 and SDL2_image libraries
target_link_libraries(popcorn PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
)
