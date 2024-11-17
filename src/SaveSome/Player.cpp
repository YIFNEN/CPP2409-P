#include "Player.h"
using namespace sf;

void Player::initialize() {
    shape.setSize(Vector2f(20.f, 20.f)); // 레드 픽셀 플레이어 크기 설정
    shape.setFillColor(Color::Red);
    shape.setPosition(100.f, groundY);      // 초기 위치는 바닥
}

void Player::update(float deltaTime) {
    Vector2f movement(0.f, 0.f);

    // 좌우 이동
    if (Keyboard::isKeyPressed(Keyboard::Left))
        movement.x -= speed * deltaTime;
    if (Keyboard::isKeyPressed(Keyboard::Right))
        movement.x += speed * deltaTime;

    // 점프 처리
    if (Keyboard::isKeyPressed(Keyboard::Space) && !isJumping) {
        jumpVelocity = -250.f; // 점프 속도
        isJumping = true;      // 점프 상태로 전환
    }

    // 중력 적용
    jumpVelocity += gravity * deltaTime;
    movement.y += jumpVelocity * deltaTime;

    // 플레이어 이동
    shape.move(movement);

    // 화면 경계 체크 (화면 바깥으로 나가지 않도록 위치 조정)
    Vector2f position = shape.getPosition();
    if (position.x < 0) {
        position.x = 0; // 왼쪽 경계
    }
    if (position.x + shape.getSize().x > 800) { // 화면 너비(800)를 기준으로 경계 체크
        position.x = 800 - shape.getSize().x; // 오른쪽 경계
    }
    shape.setPosition(position);

    // 바닥 충돌 처리
    if (shape.getPosition().y >= groundY) {
        shape.setPosition(shape.getPosition().x, groundY);
        isJumping = false;    // 점프 상태 초기화
        jumpVelocity = 0.f;   // 속도 초기화
    }
}

void Player::render(RenderWindow& window) {
    window.draw(shape);
}

FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();
}
