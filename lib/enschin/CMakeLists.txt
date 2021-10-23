cmake_minimum_required(VERSION 3.10)

# Adding GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(dep/glfw)

# Adding GLEW
add_subdirectory(dep/glew)

# Adding enschin 
FILE(GLOB_RECURSE enschin_SRC enschin/*.cpp)

# enschin libraries
add_library(enschin 
dep/stb/stb_image.cpp
    ${enschin_SRC}
)

target_link_libraries(enschin
    libglew_static
    glfw
)

target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} dep/glfw/include)
target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} dep/glew/include)
