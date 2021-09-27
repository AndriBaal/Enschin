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

# Adding enschin 
FILE(GLOB_RECURSE enschin_SRC enschin/*.cpp)

# enschin libraries
add_library(enschin 
    lib/stb/stb_image.cpp
    ${enschin_SRC}
)

target_link_libraries(enschin
    libglew_static
    glfw
    glm
)

target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} lib/glfw/include)
target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} lib/glew/include)
target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} lib/glm)
