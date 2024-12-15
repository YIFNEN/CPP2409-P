#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    sf::RectangleShape shape;
    int health;
    float speed;
    bool isJumping; // ���� ������ Ȯ��
    float velocityY; // Y �ӵ� (�߷� ����)
    float gravity; // �߷� ��
    float jumpStrength; // ���� ��


public:
    Player() // �⺻ ������ 
        : shape(sf::Vector2f(50.f, 50.f)), // �⺻ ũ�� ���� (��: 50x50)
        health(100), // �⺻ ü��
        speed(200.f) // �⺻ �ӵ�
    {}

    void initialize();
    Player(sf::Vector2f position, sf::Vector2f size);
    void update(float deltaTime, sf::FloatRect bounds);
    void render(sf::RenderWindow& window);
    void takeDamage();
    bool isDestroyed() const;
    void setColor(sf::Color color);
    void changeColor(const sf::Color& newColor);
    void increaseSpeed(float multiplier);
    sf::FloatRect getBounds() const;
    void jump(); // ���� �޼���
};
#endif