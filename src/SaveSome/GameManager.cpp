#include "GameManager.h"

using namespace sf;

GameManager& GameManager::getInstance() {
    static GameManager instance; // 여기서 기본 생성자를 호출
    return instance;
}

void GameManager::initialize() {
    window.create(VideoMode(800, 600), "Game with Features");
    player.initialize();
    map.initialize(20, 15); // 20x15 맵 생성
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
    player.update(deltaTime, map.getBounds()); // map.getBounds()로 경계를 전달
    for (auto& item : items) {
        if (item.isCollected(player.getBounds())) { // 경계 체크
            item.applyEffect(player);
        }
    }
    for (auto& obstacle : obstacles) {
        obstacle.update(deltaTime);
        if (obstacle.collidesWith(player.getBounds())) { // 경계 체크
            player.takeDamage();
        }
    }
    map.update(player.getBounds()); // 맵 충돌 체크
}

void GameManager::render() {
    window.clear();
    map.render(window);
    player.render(window);
    for (auto& item : items) {
        item.render(window);
    }
    for (auto& obstacle : obstacles) {
        obstacle.render(window);
    }
    window.display();
}

void GameManager::spawnItem() {
    float windowWidth = static_cast<float>(window.getSize().x);  // 창의 너비
    float windowHeight = static_cast<float>(window.getSize().y); // 창의 높이
    items.emplace_back(Item::createRandom(windowWidth, windowHeight)); // 인수 전달
}


void GameManager::spawnObstacle() {
    obstacles.emplace_back(Obstacle::createFallingObstacle(window.getSize().x));
}
