cmake_minimum_required(VERSION 3.10)
project(Engine VERSION 1.0.0)

#Adding GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(lib/glfw)

#Adding GLEW
add_subdirectory(lib/glew)

include_directories(lib/glfw/include)
include_directories(lib/glfw/include)

add_library(
    Color
    src/engine/graphics/Color.h
    src/engine/graphics/Color.cpp
)

add_library(
    Dimension
    src/engine/math/Dimension.h
    src/engine/math/Dimension.cpp
)

add_library(
    Vectors
    src/engine/math/Vectors.h
    src/engine/math/vectors.cpp
)

add_library(
    Mouse
    src/engine/input/Mouse.h
    src/engine/input/Mouse.cpp
)

add_library(
    Keyboard
    src/engine/input/Keyboard.h
    src/engine/input/Keyboard.cpp
)

add_library(
    Window
    src/engine/Window.h
    src/engine/Window.cpp
)

# add the executable
add_executable(Engine src/Main.cpp)


target_include_directories (Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} lib/glfw/include)
target_include_directories (Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} lib/glew/include)

# Linking GLFW & GLEW
target_link_libraries(Engine
    PUBLIC glfw
    PUBLIC libglew_static
    PUBLIC Color
    PUBLIC Dimension
    PUBLIC Vectors
    PUBLIC Mouse glfw Vectors
    PUBLIC Keyboard glfw
    PUBLIC Window glfw Mouse Keyboard Dimension Vectors
)
