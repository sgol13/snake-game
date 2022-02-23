// Snake game using C++ SFML *
// * * * * * * * * * * * * * *

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "defs.hpp"

class Snake {
  public:
    Snake();

    void display(sf::RenderWindow &window);

    bool move(int apple_xi, int apple_yi);

    void readDirection();

    bool repeatRandomApplePosition(int apple_xi, int apple_yi);

    bool checkCollision();

  private:
    enum class Direction : int { Up, Right, Down, Left };

    struct Segment {
        int xi, yi;
    };

    std::vector<Segment> segments;

    Direction move_direction;
    Direction point_direction;

    sf::RectangleShape head_rectangle;
    sf::RectangleShape segment_rectangle;
};

#endif