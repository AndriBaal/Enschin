cmake_minimum_required(VERSION 3.10)
project(Enschin VERSION 0.0.1)


# Adding GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(deps/glfw)

# Adding GLEW
add_subdirectory(deps/glew)

# Adding jsoncpp
add_subdirectory(deps/jsoncpp)

#Adding Box2d for physics
add_subdirectory(deps/box2d)

# Adding enschin 
FILE(GLOB_RECURSE enschin_SRC src/*.cpp)

# enschin libraries
add_library(enschin
    deps/stb/stb_image.cpp
    ${enschin_SRC}
)

target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)
target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} deps/glfw/include)
target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} deps/glew/include)
target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} deps/jsoncpp/include)
target_include_directories (enschin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} deps/box2d/include)

target_link_libraries(enschin
    libglew_static
    glfw
    jsoncpp_object
)

