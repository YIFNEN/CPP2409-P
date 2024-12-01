#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    void initialize();
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    void changeColor(sf::Color newColor);
    void losePixel();
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape;
    sf::Color color;
    float speed = 200.f; //좌우 이동 속도
    float jumpVelocity = 0.f;// 점프 속도
    float gravity = 400.f;// 중력 가속도
    bool isJumping = false;// 점프 여부
    float groundY = 500.f; //바닥의 Y좌표
    int pixels = 100; //플레이어의 체력, 공격당하면 픽셀이 깎인다.
};

#endif // PLAYER_H
