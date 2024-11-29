#include "Obstacle.h"

using namespace sf;

Obstacle::Obstacle(Vector2f position, Vector2f size, Color color) {
    shape.setSize(size);
    shape.setFillColor(color);
    shape.setPosition(position);
}

void Obstacle::render(RenderWindow& window) {
    window.draw(shape);
}

void Obstacle::update(float deltaTime) {
    // 아래로 낙하
    shape.move(0, fallSpeed * deltaTime);
}

bool Obstacle::collidesWith(const FloatRect& targetBounds) const {
    return shape.getGlobalBounds().intersects(targetBounds);
}

FloatRect Obstacle::getBounds() const {
    return shape.getGlobalBounds();
}

Obstacle Obstacle::createFallingObstacle(float windowWidth) {
    // 랜덤 위치에서 생성되는 장애물
    float x = static_cast<float>(rand() % static_cast<int>(windowWidth - 20.f)); // 20.f는 장애물 너비 보정
    Vector2f position(x, 0.f); // 화면 상단에서 시작
    Vector2f size(20.f, 20.f); // 기본 크기
    return Obstacle(position, size);
}

