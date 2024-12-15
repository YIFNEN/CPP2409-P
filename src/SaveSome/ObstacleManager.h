#ifndef OBSTACLE_MANAGER_H
#define OBSTACLE_MANAGER_H

#include "Obstacle.h"
#include <vector>

class ObstacleManager {
private:
    std::vector<Obstacle> obstacles;

public:
    void update(float deltaTime, const sf::FloatRect& playerBounds);
    void render(sf::RenderWindow& window);
};

#endif
