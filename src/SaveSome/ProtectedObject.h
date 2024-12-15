#ifndef PROTECTED_OBJECT_H
#define PROTECTED_OBJECT_H

#include <SFML/Graphics.hpp>

class ProtectedObject {
private:
    sf::CircleShape shape;  // 오브젝트의 시각적 표현
    int pixelHealth;        // 픽셀 체력
    float speed;            // 이동 속력 (플레이어의 절반)
    float detectionRadius;  // Boid 알고리즘 활성 거리

    void moveTowardsPlayer(const sf::Vector2f& playerPos, float deltaTime);

public:
    ProtectedObject(const sf::Vector2f& startPosition, int initialHealth, float movementSpeed, float radius);

    void update(float deltaTime, const sf::Vector2f& playerPos);
    void render(sf::RenderWindow& window);
    void takeDamage(int damage);
    bool isDestroyed() const;

    sf::Vector2f getPosition() const;
    int getHealth() const;
};

#endif
