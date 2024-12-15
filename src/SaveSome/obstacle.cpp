#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(color);
}

void Obstacle::render(sf::RenderWindow& window) const{
    window.draw(shape);
}

void Obstacle::update(float deltaTime) {
    shape.move(0, fallSpeed * deltaTime); // ¾Æ·¡·Î ³«ÇÏ
}

bool Obstacle::collidesWith(const sf::FloatRect& targetBounds) const {
    return shape.getGlobalBounds().intersects(targetBounds);
}

sf::FloatRect Obstacle::getBounds() const {
    return shape.getGlobalBounds();
}

Obstacle Obstacle::createFallingObstacle(float windowWidth) {
    float x = static_cast<float>(std::rand() % static_cast<int>(windowWidth));
    return Obstacle({ x, 0 }, { 20, 20 }, sf::Color::Red);
}
