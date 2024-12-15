#include "ObstacleManager.h"

void ObstacleManager::update(float deltaTime, const sf::FloatRect& playerBounds) {
    for (auto it = obstacles.begin(); it != obstacles.end();) {
        it->update(deltaTime);

        if (it->collidesWith(playerBounds)) {
            // 충돌 로직 (플레이어 피해 등)
            it = obstacles.erase(it);
        }
        else if (it->getBounds().top > 600) {
            it = obstacles.erase(it);
        }
        else {
            ++it;
        }
    }

    // 랜덤하게 새로운 장애물 생성
    if (std::rand() % 100 < 10) {
        obstacles.push_back(Obstacle::createFallingObstacle(800));
    }
}

void ObstacleManager::render(sf::RenderWindow& window) {
    for (const auto& obstacle : obstacles) {
        obstacle.render(window);
    }
}
