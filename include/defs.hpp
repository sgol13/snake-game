// Snake game using C++ SFML *
// * * * * * * * * * * * * * *

#ifndef DEFS_HPP
#define DEFS_HPP

// standard library includes
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

// SFML includes
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// RESOURCES PATHS
#ifndef RESOURCES_DIR
#define RESOURCES_DIR ""
#endif

constexpr char BACKGROUND_PATH[] = RESOURCES_DIR "background.jpg";
constexpr char APPLE_PATH[] = RESOURCES_DIR "apple.png";
constexpr char FONT_PATH[] = RESOURCES_DIR "font.ttf";

// WINDOW
constexpr char GAME_WINDOW_NAME[] = "Snake";

constexpr int WINDOW_WIDTH = 1200;
constexpr int WINDOW_HEIGHT = 900;
constexpr int UPPER_BOX_HEIGHT = 100;

constexpr int NUM_COLUMNS = 24;
constexpr int NUM_ROWS = 16;

constexpr int UPPER_BOX_COLOR = 0x595959ff;

constexpr int TILE_WIDTH = WINDOW_WIDTH / NUM_COLUMNS;
constexpr int TILE_HEIGHT = (WINDOW_HEIGHT - UPPER_BOX_HEIGHT) / NUM_ROWS;

// INTERFACE
constexpr int APPLE_POS_X = UPPER_BOX_HEIGHT / 2 - TILE_HEIGHT / 2;
constexpr int APPLE_POS_Y = UPPER_BOX_HEIGHT / 2 - TILE_HEIGHT / 2;

constexpr int SCORE_POS_X = 2 * APPLE_POS_X + TILE_WIDTH;
constexpr int SCORE_POS_Y = 12;
constexpr int SCORE_COLOR = 0x202020ff;
constexpr int SCORE_FONT_SIZE = 64;

constexpr int GAME_OVER_TEXT_POS_X = 350;
constexpr int GAME_OVER_TEXT_POS_Y = WINDOW_HEIGHT / 2 - UPPER_BOX_HEIGHT;
constexpr int GAME_OVER_TEXT_COLOR = 0xd9d9d9ff;
constexpr int GAME_OVER_FONT_SIZE = 82;
constexpr char GAME_OVER_TEXT_STRING[] = "Game over";

constexpr int PRESS_ENTER_TEXT_POS_X = 380;
constexpr int PRESS_ENTER_TEXT_POS_Y = GAME_OVER_TEXT_POS_Y + 2 * GAME_OVER_FONT_SIZE;
constexpr int PRESS_ENTER_TEXT_COLOR = 0xd9d9d9ff;
constexpr int PRESS_ENTER_FONT_SIZE = 30;
constexpr char PRESS_ENTER_TEXT_STRING[] = "Press enter to continue";

// SNAKE
constexpr int SNAKE_SEGMENT_FILL_COLOR = 0x00b300ff;
constexpr int SNAKE_SEGMENT_OUTLINE_COLOR = 0x006600ff;
constexpr int SNAKE_HEAD_FILL_COLOR = 0x003300ff;
constexpr int SNAKE_HEAD_OUTLINE_COLOR = 0x006600ff;
constexpr int SNAKE_OTLINE_THICKNESS = -(TILE_WIDTH / 10);

constexpr int INITIAL_SNAKE_POS_X = NUM_COLUMNS / 2;
constexpr int INITIAL_SNAKE_POS_Y = NUM_ROWS / 2;
constexpr int NUM_INITIAL_SEGMENTS = 4;

constexpr int MOVE_TIME = 120;

#endif