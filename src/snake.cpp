// Snake game using C++ SFML *
// * * * * * * * * * * * * * *

#include "snake.hpp"

Snake::Snake() {

    head_rectangle.setSize(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
    head_rectangle.setFillColor(sf::Color(SNAKE_HEAD_FILL_COLOR));
    head_rectangle.setOutlineColor(sf::Color(SNAKE_HEAD_OUTLINE_COLOR));
    head_rectangle.setOutlineThickness(SNAKE_OTLINE_THICKNESS);

    segment_rectangle.setSize(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
    segment_rectangle.setFillColor(sf::Color(SNAKE_SEGMENT_FILL_COLOR));
    segment_rectangle.setOutlineColor(sf::Color(SNAKE_SEGMENT_OUTLINE_COLOR));
    segment_rectangle.setOutlineThickness(SNAKE_OTLINE_THICKNESS);

    segments.push_back({INITIAL_SNAKE_POS_X, INITIAL_SNAKE_POS_Y});

    for (int i = 1; i < NUM_INITIAL_SEGMENTS; i++) {
        segments.push_back({INITIAL_SNAKE_POS_X, INITIAL_SNAKE_POS_Y + i});
    }

    move_direction = Direction::Up;
    point_direction = Direction::Up;
}

void Snake::display(sf::RenderWindow &window) {

    // display the head
    sf::Vector2f position;
    position.x = static_cast<float>(segments.front().xi * TILE_WIDTH);
    position.y =
        static_cast<float>(segments.front().yi * TILE_HEIGHT + UPPER_BOX_HEIGHT);
    head_rectangle.setPosition(position);

    window.draw(head_rectangle);

    // display all the segments
    for (int i = 1; i < static_cast<int>(segments.size()); i++) {

        position.x = static_cast<float>(segments[i].xi * TILE_WIDTH);
        position.y =
            static_cast<float>(segments[i].yi * TILE_HEIGHT + UPPER_BOX_HEIGHT);
        segment_rectangle.setPosition(position);

        window.draw(segment_rectangle);
    }
}

bool Snake::move(int apple_xi, int apple_yi) {

    move_direction = point_direction;
    bool eaten = false;

    // move the head
    Segment new_head = segments.front();

    switch (move_direction) {
    case Direction::Up:
        new_head.yi--;
        break;

    case Direction::Right:
        new_head.xi++;
        break;

    case Direction::Down:
        new_head.yi++;
        break;

    case Direction::Left:
        new_head.xi--;
        break;
    }

    const int last_segment = static_cast<int>(segments.size()) - 1;

    // check if has just eaten an apple
    if (new_head.xi == apple_xi && new_head.yi == apple_yi) {
        eaten = true;
        segments.push_back(segments.back());
    }

    // move all the segments
    for (int i = last_segment; i >= 1; i--) {
        segments[i] = segments[i - 1];
    }

    segments.front() = new_head;
    return eaten;
}

void Snake::readDirection() {

    Direction new_direction = point_direction;
    int num_arrows_pressed = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

        if (move_direction != Direction::Up && move_direction != Direction::Down) {
            new_direction = Direction::Up;
            num_arrows_pressed++;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

        if (move_direction != Direction::Left && move_direction != Direction::Right) {
            new_direction = Direction::Right;
            num_arrows_pressed++;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

        if (move_direction != Direction::Up && move_direction != Direction::Down) {
            new_direction = Direction::Down;
            num_arrows_pressed++;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

        if (move_direction != Direction::Left && move_direction != Direction::Right) {
            new_direction = Direction::Left;
            num_arrows_pressed++;
        }
    }

    if (num_arrows_pressed == 1) {
        point_direction = new_direction;
    }
}

bool Snake::repeatRandomApplePosition(int apple_xi, int apple_yi) {

    for (const auto &segment : segments) {
        if (segment.xi == apple_xi && segment.yi == apple_yi) {
            return true;
        }
    }

    return false;
}

bool Snake::checkCollision() {

    // get head position
    const int head_xi = segments.front().xi;
    const int head_yi = segments.front().yi;

    // check walls
    if (head_xi < 0 || head_xi >= NUM_COLUMNS || head_yi < 0 || head_yi >= NUM_ROWS) {
        return true;
    }

    // check the snake itself
    for (int i = 1; i < static_cast<int>(segments.size()); i++) {
        if (segments[i].xi == head_xi && segments[i].yi == head_yi) {
            return true;
        }
    }

    return false;
}