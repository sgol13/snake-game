// Snake game using C++ SFML *
// * * * * * * * * * * * * * *

#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "defs.hpp"

class Interface {
  public:
    Interface();

    void display(sf::RenderWindow &window);

    void setApplePosition(int xi, int yi);

    void addScore();

    void printGameOver();

  private:
    int game_score;

    // resources
    sf::Texture background_texture;
    sf::Texture apple_texture;
    sf::Font font;

    // interface elements
    sf::Sprite background;
    sf::RectangleShape upper_box;
    sf::Sprite score_apple;
    sf::Sprite board_apple;
    sf::Text score_text;
    sf::Text game_over_text;
    sf::Text press_enter_text;

    bool is_game_over;
};


#endif