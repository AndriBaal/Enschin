cmake_minimum_required(VERSION 3.10)
project(Game VERSION 1.0.0)

add_subdirectory(lib/enschin)
add_subdirectory(src)

# Add the executable
add_executable(Game src/Main.cpp) 

target_link_libraries(Game
    enschin 
    game enschin
)