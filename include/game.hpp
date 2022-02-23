// Snake game using C++ SFML *
// * * * * * * * * * * * * * *

#ifndef GAME_HPP
#define GAME_HPP

#include "defs.hpp"
#include "interface.hpp"
#include "snake.hpp"

class Game {
  public:
    Game();

    void play();

  private:
    Interface interface;
    Snake snake;

    int apple_xi, apple_yi;

    sf::Clock timer;
    sf::RenderWindow window;

    void handleEvents();

    void randomApplePosition();
};

#endif