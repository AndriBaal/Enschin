cmake_minimum_required(VERSION 3.10)

# Adding GLM
add_subdirectory(lib/glm)

# Adding GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(lib/glfw)

# Adding GLEW
add_subdirectory(lib/glew)

# Adding include directories for glfw & glew
include_directories(lib/glfw/include)
include_directories(lib/glew/include)
include_directories(lib/glm)


set(enschin_HEADERS ${common_HEADERS} 
    lib/stb/stb_image.h
    enschin/math/Dimension.h
    enschin/math/Vectors.h
    enschin/graphics/buffer/IndexBuffer.h
    enschin/graphics/buffer/VertexArray.h
    enschin/graphics/buffer/VertexBuffer.h
    enschin/graphics/Model.h
    enschin/graphics/ShaderProgram.h
    enschin/graphics/Texture.h
    enschin/graphics/Renderer.h
    enschin/input/Mouse.h
    enschin/input/Keyboard.h
    enschin/Window.h
)

set(enschin_SOURCES ${common_SOURCES} 
    lib/stb/stb_image.cpp
    enschin/graphics/buffer/IndexBuffer.cpp
    enschin/graphics/buffer/VertexArray.cpp
    enschin/graphics/buffer/VertexBuffer.cpp
    enschin/graphics/buffer/VertexBufferLayout.hpp
    enschin/graphics/Model.cpp
    enschin/graphics/ShaderProgram.cpp
    enschin/graphics/Texture.cpp
    enschin/graphics/Renderer.cpp
    enschin/graphics/Color.hpp
    enschin/math/Dimension.cpp
    enschin/math/Vectors.cpp
    enschin/input/Mouse.cpp
    enschin/input/Keyboard.cpp
    enschin/Window.cpp
)


# enschin libraries
add_library(enschin ${enschin_SOURCES} ${enschin_HEADERS})

target_link_libraries(enschin
    libglew_static
    glfw
    glm
)

target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} lib/glfw/include)
target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} lib/glew/include)
target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} lib/glm)
