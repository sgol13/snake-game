// Snake game using C++ SFML *
// * * * * * * * * * * * * * *

#include "game.hpp"

Game::Game() {

    sf::VideoMode window_size(WINDOW_WIDTH, WINDOW_HEIGHT);
    auto window_style = sf::Style::Titlebar | sf::Style::Close;
    window.create(window_size, GAME_WINDOW_NAME, window_style);
    window.setVerticalSyncEnabled(true);
    window.setPosition(sf::Vector2i(0, 0));

    srand(static_cast<unsigned int>(time(0)));
}

void Game::play() {

    randomApplePosition();

    // game loop
    while (window.isOpen()) {

        handleEvents();
        snake.readDirection();

        // execute the move when enough time passed
        if (timer.getElapsedTime().asMilliseconds() > MOVE_TIME) {
            timer.restart();

            if (snake.move(apple_xi, apple_yi)) {

                randomApplePosition();
                interface.addScore();
            }

            if (snake.checkCollision())
                break;
        }

        window.clear(sf::Color::Black);

        interface.display(window);
        snake.display(window);

        window.display();
    }

    interface.printGameOver();

    // post-game loop
    while (window.isOpen()) {

        handleEvents();

        window.clear(sf::Color::Black);

        interface.display(window);

        window.display();
    }
}

void Game::handleEvents() {

    sf::Event event;
    while (window.pollEvent(event)) {

        switch (event.type) {

        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::C) {
                window.close();
            } else if (event.key.code == sf::Keyboard::Return) {
                window.close();
            }
            break;

        default:
            break;
        }
    }
}

void Game::randomApplePosition() {

    do {
        apple_xi = rand() % NUM_COLUMNS;
        apple_yi = rand() % NUM_ROWS;
    } while (snake.repeatRandomApplePosition(apple_xi, apple_yi));

    interface.setApplePosition(apple_xi, apple_yi);
}