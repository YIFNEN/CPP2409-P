#include "Game.h"
#include <iostream>


Game::Game()
    : window(sf::VideoMode(800, 600), "Game"),
    currentState(GameState::ColorSelection),
    player({ 400, 300 }, { 20, 20 }),
    map(20, 15),
    isGameOver(false) {
    itemManager.spawnItems(map.getBounds());
}

void Game::run() {
    sf::Clock clock;
    
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        handleEvents();
        if (!isGameOver && currentState == GameState::MainGame) {
            update(deltaTime);
        }
        render();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    if (currentState == GameState::ColorSelection) {
        colorSelectionScene.handleInput(window);
        if (colorSelectionScene.isColorSelected()) {
            player.setColor(colorSelectionScene.getSelectedColor());
            currentState = GameState::MainGame;
        }
    }
}

void Game::update(float deltaTime) {
    player.update(deltaTime, map.getBounds());
    obstacleManager.update(deltaTime, player.getBounds());
    itemManager.update(player);
    checkGameOver();
}

void Game::render() {
    window.clear();

    if (currentState == GameState::ColorSelection) {
        colorSelectionScene.render(window);
    }
    else if (currentState == GameState::MainGame) {
        map.render(window);
        player.render(window);
        obstacleManager.render(window);
        itemManager.render(window);

        if (isGameOver) {
            sf::Font font;
            font.loadFromFile("arial.ttf");
            sf::Text gameOverText("Game Over", font, 50);
            gameOverText.setPosition(200, 250);
            gameOverText.setFillColor(sf::Color::Red);
            window.draw(gameOverText);
        }
    }

    window.display();
}

void Game::checkGameOver() {
    if (player.isDestroyed()) {
        isGameOver = true;
    }
}
