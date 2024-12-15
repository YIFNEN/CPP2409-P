#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>

class Obstacle {
public:
    Obstacle(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::Red);
    void render(sf::RenderWindow& window) const;
    void update(float deltaTime);
    bool collidesWith(const sf::FloatRect& targetBounds) const;
    sf::FloatRect getBounds() const;

    static Obstacle createFallingObstacle(float windowWidth);

private:
    sf::RectangleShape shape;
    float fallSpeed = 100.f; // 기본 낙하 속도
};

#endif // OBSTACLE_H
