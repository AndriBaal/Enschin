cmake_minimum_required(VERSION 3.10)

include_directories(lib/enschin)


set(game_HEADERS ${common_HEADERS} 
    scenes/GameScene.h
    MyGame.h
)

set(game_SOURCES ${common_SOURCES} 
    scenes/GameScene.cpp
    MyGame.cpp
)

# enschin libraries
add_library(game ${game_SOURCES} ${game_HEADERS})


target_link_libraries(game
    enschin
)

target_include_directories (game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} lib/enschin)