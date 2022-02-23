cmake_minimum_required(VERSION 3.10.2)
project(snake-game)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wconversion -Wextra -Wshadow -Werror -g")

add_definitions(-DRESOURCES_DIR="../res/")

add_executable(game src/main.cpp src/game.cpp src/interface.cpp src/snake.cpp)

# path to header files
target_include_directories(game PRIVATE include)

# link SFML modules
target_link_libraries(game sfml-graphics sfml-audio sfml-window sfml-system)