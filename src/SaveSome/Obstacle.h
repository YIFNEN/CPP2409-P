// Obstacle.h
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>

class Obstacle {
public:
    Obstacle(sf::Vector2f position, sf::Vector2f size);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape;
};

#endif // OBSTACLE_H