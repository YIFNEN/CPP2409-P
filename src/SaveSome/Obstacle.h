#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>

class Obstacle {
public:
    Obstacle(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::Red);//장애물의 위치, 크기, 색상 설정
    void render(sf::RenderWindow& window);
    void update(float deltaTime);
    bool collidesWith(const sf::FloatRect& targetBounds) const;
    sf::FloatRect getBounds() const;

    static Obstacle createFallingObstacle(float windowWidth);

private:
    sf::RectangleShape shape;
    float fallSpeed = 100.f; // 기본 낙하 속도
};

#endif // OBSTACLE_H
