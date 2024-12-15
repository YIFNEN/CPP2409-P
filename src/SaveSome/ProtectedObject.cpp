#include "ProtectedObject.h"
#include <cmath>

// 생성자 구현
ProtectedObject::ProtectedObject(const sf::Vector2f& startPosition, int initialHealth, float movementSpeed, float radius)
    : pixelHealth(initialHealth), speed(movementSpeed), detectionRadius(radius) {
    shape.setRadius(15.f);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(startPosition);
    shape.setOrigin(15.f, 15.f); // 중심을 기준으로 회전 및 이동
}

// 플레이어를 향해 움직이는 로직
void ProtectedObject::moveTowardsPlayer(const sf::Vector2f& playerPos, float deltaTime) {
    sf::Vector2f direction = playerPos - shape.getPosition();
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 0) {
        direction /= distance; // 방향 벡터 정규화
        shape.move(direction * speed * deltaTime);
    }
}

// 업데이트 (플레이어와의 거리 계산 및 이동)
void ProtectedObject::update(float deltaTime, const sf::Vector2f& playerPos) {
    float distanceToPlayer = std::sqrt(
        std::pow(playerPos.x - shape.getPosition().x, 2) +
        std::pow(playerPos.y - shape.getPosition().y, 2));

    if (distanceToPlayer <= detectionRadius) {
        moveTowardsPlayer(playerPos, deltaTime);
    }
}

// 렌더링
void ProtectedObject::render(sf::RenderWindow& window) {
    window.draw(shape);
}

// 데미지 입기
void ProtectedObject::takeDamage(int damage) {
    pixelHealth -= damage;
    if (pixelHealth < 0) {
        pixelHealth = 0;
    }
}

// 파괴 여부 확인
bool ProtectedObject::isDestroyed() const {
    return pixelHealth <= 0;
}

// 위치 가져오기
sf::Vector2f ProtectedObject::getPosition() const {
    return shape.getPosition();
}

// 체력 가져오기
int ProtectedObject::getHealth() const {
    return pixelHealth;
}
