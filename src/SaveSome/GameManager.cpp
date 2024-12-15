#include "GameManager.h"

using namespace sf;

GameManager& GameManager::getInstance() {
    static GameManager instance; // ���⼭ �⺻ �����ڸ� ȣ��
    return instance;
}

void GameManager::initialize() {
    window.create(VideoMode(800, 600), "Game with Features");
    player.initialize();
    map.initialize(20, 15); // 20x15 �� ����
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
    player.update(deltaTime, map.getBounds()); // map.getBounds()�� ��踦 ����
    for (auto& item : items) {
        if (item.isCollected(player.getBounds())) { // ��� üũ
            item.applyEffect(player);
        }
    }
    for (auto& obstacle : obstacles) {
        obstacle.update(deltaTime);
        if (obstacle.collidesWith(player.getBounds())) { // ��� üũ
            player.takeDamage();
        }
    }
    map.update(player.getBounds()); // �� �浹 üũ
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
    float windowWidth = static_cast<float>(window.getSize().x);  // â�� �ʺ�
    float windowHeight = static_cast<float>(window.getSize().y); // â�� ����
    items.emplace_back(Item::createRandom(windowWidth, windowHeight)); // �μ� ����
}


void GameManager::spawnObstacle() {
    obstacles.emplace_back(Obstacle::createFallingObstacle(window.getSize().x));
}
