cmake_minimum_required(VERSION 3.10)

include_directories(lib/enschin)

FILE(GLOB_RECURSE game_SRC ./*.cpp)

# enschin libraries
add_library(game ${game_SRC})


target_link_libraries(game
    enschin
)

target_include_directories (game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} lib/enschin)