#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    void initialize();
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape;

    // ���� ���� ����
    float speed = 200.f;       // �¿� �̵� �ӵ�
    float jumpVelocity = 0.f;  // ���� �ӵ�
    float gravity = 400.f;     // �߷� ���ӵ�
    bool isJumping = false;    // ���� ����

    float groundY = 500.f;     // �÷��̾ �� �� �ִ� �ٴ� Y ��ǥ
};

#endif // PLAYER_H