#include "GameManager.h"
using namespace sf;

void GameManager::initialize() {
    window.create(VideoMode(800, 600), "Game with Gravity and Jump");
    player.initialize();
}

void GameManager::processEvents() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }
    }
}

void GameManager::update(float deltaTime) {
    player.update(deltaTime); // deltaTime을 이용한 업데이트
}

void GameManager::render() {
    window.clear();
    player.render(window);
    window.display();
}
