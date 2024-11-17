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

    // 물리 관련 변수
    float speed = 200.f;       // 좌우 이동 속도
    float jumpVelocity = 0.f;  // 점프 속도
    float gravity = 400.f;     // 중력 가속도
    bool isJumping = false;    // 점프 여부

    float groundY = 500.f;     // 플레이어가 설 수 있는 바닥 Y 좌표
};

#endif // PLAYER_H