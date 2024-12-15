#include "ProtectedObject.h"
#include <cmath>

// ������ ����
ProtectedObject::ProtectedObject(const sf::Vector2f& startPosition, int initialHealth, float movementSpeed, float radius)
    : pixelHealth(initialHealth), speed(movementSpeed), detectionRadius(radius) {
    shape.setRadius(15.f);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(startPosition);
    shape.setOrigin(15.f, 15.f); // �߽��� �������� ȸ�� �� �̵�
}

// �÷��̾ ���� �����̴� ����
void ProtectedObject::moveTowardsPlayer(const sf::Vector2f& playerPos, float deltaTime) {
    sf::Vector2f direction = playerPos - shape.getPosition();
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 0) {
        direction /= distance; // ���� ���� ����ȭ
        shape.move(direction * speed * deltaTime);
    }
}

// ������Ʈ (�÷��̾���� �Ÿ� ��� �� �̵�)
void ProtectedObject::update(float deltaTime, const sf::Vector2f& playerPos) {
    float distanceToPlayer = std::sqrt(
        std::pow(playerPos.x - shape.getPosition().x, 2) +
        std::pow(playerPos.y - shape.getPosition().y, 2));

    if (distanceToPlayer <= detectionRadius) {
        moveTowardsPlayer(playerPos, deltaTime);
    }
}

// ������
void ProtectedObject::render(sf::RenderWindow& window) {
    window.draw(shape);
}

// ������ �Ա�
void ProtectedObject::takeDamage(int damage) {
    pixelHealth -= damage;
    if (pixelHealth < 0) {
        pixelHealth = 0;
    }
}

// �ı� ���� Ȯ��
bool ProtectedObject::isDestroyed() const {
    return pixelHealth <= 0;
}

// ��ġ ��������
sf::Vector2f ProtectedObject::getPosition() const {
    return shape.getPosition();
}

// ü�� ��������
int ProtectedObject::getHealth() const {
    return pixelHealth;
}
