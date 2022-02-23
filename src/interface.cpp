// Snake game using C++ SFML *
// * * * * * * * * * * * * * *

#include "interface.hpp"

Interface::Interface() : game_score(0), is_game_over(false) {

    // BACKGROUND
    if (background_texture.loadFromFile(BACKGROUND_PATH)) {

        background.setTexture(background_texture);

        sf::Vector2f scale;
        scale.x = static_cast<float>(WINDOW_WIDTH) /
                  static_cast<float>(background_texture.getSize().x);
        scale.y = static_cast<float>(WINDOW_HEIGHT - UPPER_BOX_HEIGHT) /
                  static_cast<float>(background_texture.getSize().y);
        background.setScale(scale);

        background.setPosition(0, UPPER_BOX_HEIGHT);

    } else {
        std::cout << "Loading file " << BACKGROUND_PATH << " failed.\n";
    }

    // UPPER BOX
    upper_box.setPosition(0, 0);
    upper_box.setFillColor(sf::Color(UPPER_BOX_COLOR));
    upper_box.setSize(sf::Vector2f(WINDOW_WIDTH, UPPER_BOX_HEIGHT));


    if (apple_texture.loadFromFile(APPLE_PATH)) {

        // BOARD APPLE
        board_apple.setTexture(apple_texture);

        sf::Vector2f scale;
        scale.x = static_cast<float>(TILE_WIDTH) /
                  static_cast<float>(apple_texture.getSize().x);
        scale.y = static_cast<float>(TILE_HEIGHT) /
                  static_cast<float>(apple_texture.getSize().y);
        board_apple.setScale(scale);

        // SCORE APPLE
        score_apple.setTexture(apple_texture);
        score_apple.setScale(scale);
        score_apple.setPosition(APPLE_POS_Y, APPLE_POS_Y);

    } else {
        std::cout << "Loading file " << APPLE_PATH << " failed.\n";
    }

    // FONT
    if (font.loadFromFile(FONT_PATH)) {

        // SCORE TEXT
        score_text.setFont(font);
        score_text.setPosition(SCORE_POS_X, SCORE_POS_Y);
        score_text.setCharacterSize(SCORE_FONT_SIZE);
        score_text.setFillColor(sf::Color(SCORE_COLOR));
        score_text.setString("0");

        // GAME OVER TEXT
        game_over_text.setFont(font);
        game_over_text.setPosition(GAME_OVER_TEXT_POS_X, GAME_OVER_TEXT_POS_Y);
        game_over_text.setCharacterSize(GAME_OVER_FONT_SIZE);
        game_over_text.setFillColor(sf::Color(GAME_OVER_TEXT_COLOR));
        game_over_text.setString(GAME_OVER_TEXT_STRING);

        // PRESS ENTER TEXT
        press_enter_text.setFont(font);
        press_enter_text.setPosition(PRESS_ENTER_TEXT_POS_X, PRESS_ENTER_TEXT_POS_Y);
        press_enter_text.setCharacterSize(PRESS_ENTER_FONT_SIZE);
        press_enter_text.setFillColor(sf::Color(PRESS_ENTER_TEXT_COLOR));
        press_enter_text.setString(PRESS_ENTER_TEXT_STRING);
    }
}

void Interface::display(sf::RenderWindow &window) {

    window.draw(background);
    window.draw(upper_box);
    window.draw(score_apple);
    window.draw(score_text);

    if (is_game_over) {
        window.draw(game_over_text);
        window.draw(press_enter_text);
    } else {
        window.draw(board_apple);
    }
}

void Interface::setApplePosition(int xi, int yi) {

    sf::Vector2f position;
    position.x = static_cast<float>(TILE_WIDTH * xi);
    position.y = static_cast<float>(TILE_HEIGHT * yi + UPPER_BOX_HEIGHT);
    board_apple.setPosition(position);
}

void Interface::addScore() {

    game_score++;
    score_text.setString(std::to_string(game_score));
}

void Interface::printGameOver() { is_game_over = true; }