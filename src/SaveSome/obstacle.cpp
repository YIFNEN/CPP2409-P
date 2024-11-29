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
    // �Ʒ��� ����
    shape.move(0, fallSpeed * deltaTime);
}

bool Obstacle::collidesWith(const FloatRect& targetBounds) const {
    return shape.getGlobalBounds().intersects(targetBounds);
}

FloatRect Obstacle::getBounds() const {
    return shape.getGlobalBounds();
}

Obstacle Obstacle::createFallingObstacle(float windowWidth) {
    // ���� ��ġ���� �����Ǵ� ��ֹ�
    float x = static_cast<float>(rand() % static_cast<int>(windowWidth - 20.f)); // 20.f�� ��ֹ� �ʺ� ����
    Vector2f position(x, 0.f); // ȭ�� ��ܿ��� ����
    Vector2f size(20.f, 20.f); // �⺻ ũ��
    return Obstacle(position, size);
}

