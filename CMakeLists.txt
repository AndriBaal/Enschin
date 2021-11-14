cmake_minimum_required(VERSION 3.10)
project(Game VERSION 0.0.1)

add_subdirectory(lib/enschin)
add_subdirectory(src)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME})
file (COPY res/ DESTINATION ${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}/)
file (COPY lib/enschin/shader DESTINATION ${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}/enschin/)

# Add the executable
add_executable(Game src/main.cpp) 

target_link_libraries(Game
    enschin
    game enschin
)