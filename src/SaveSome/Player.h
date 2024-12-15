#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    sf::RectangleShape shape;
    int health;
    float speed;
    bool isJumping; // 점프 중인지 확인
    float velocityY; // Y 속도 (중력 적용)
    float gravity; // 중력 값
    float jumpStrength; // 점프 힘


public:
    Player() // 기본 생성자 
        : shape(sf::Vector2f(50.f, 50.f)), // 기본 크기 설정 (예: 50x50)
        health(100), // 기본 체력
        speed(200.f) // 기본 속도
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
    void jump(); // 점프 메서드
};
#endif