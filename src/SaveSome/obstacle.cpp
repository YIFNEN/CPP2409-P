#include "Obstacle.h"
using namespace sf;

Obstacle::Obstacle(Vector2f position, Vector2f size) {
    shape.setSize(size);
    shape.setFillColor(Color::Red);
    shape.setPosition(position);
}

void Obstacle::render(RenderWindow& window) {
    window.draw(shape);
}

FloatRect Obstacle::getBounds() const {
    return shape.getGlobalBounds();
}
