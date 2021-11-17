cmake_minimum_required(VERSION 3.10)
project(Game VERSION 0.0.1)

add_subdirectory(lib/enschin)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME})
file (COPY res/ DESTINATION ${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}/)
file (COPY lib/enschin/shader DESTINATION ${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}/enschin/)

# Add the executable
FILE(GLOB_RECURSE game_SRC ./src/*.cpp)
add_executable(game
    src/main.cpp
    ${game_SRC}
)

target_link_libraries(game
    enschin
)


target_include_directories (game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} lib/enschin/include)
target_include_directories (game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)