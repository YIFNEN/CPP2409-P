#ifndef PROTECTED_OBJECT_H
#define PROTECTED_OBJECT_H

#include <SFML/Graphics.hpp>

class ProtectedObject {
private:
    sf::CircleShape shape;  // ������Ʈ�� �ð��� ǥ��
    int pixelHealth;        // �ȼ� ü��
    float speed;            // �̵� �ӷ� (�÷��̾��� ����)
    float detectionRadius;  // Boid �˰��� Ȱ�� �Ÿ�

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
