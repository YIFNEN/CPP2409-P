#include "Player.h"
using namespace sf;

void Player::initialize() {
    shape.setSize(Vector2f(20.f, 20.f));//플레이어 크기 설정
    shape.setFillColor(Color::Red);
    shape.setPosition(100.f, groundY); //플레이어 초기 위치 설정
    color = Color::Red;
}

void Player::update(float deltaTime) {
    Vector2f movement(0.f, 0.f);

    //플레이어의 좌 우 이동
    if (Keyboard::isKeyPressed(Keyboard::Left)) movement.x -= speed * deltaTime;
    if (Keyboard::isKeyPressed(Keyboard::Right)) movement.x += speed * deltaTime;

    //플레이어의 점프
    if (Keyboard::isKeyPressed(Keyboard::Space) && !isJumping) {
        jumpVelocity = -250.f;
        isJumping = true;
    }

    // 중력 설정
    jumpVelocity += gravity * deltaTime; 
    movement.y += jumpVelocity * deltaTime;

    shape.move(movement);


    //화면 경계 체크
    Vector2f position = shape.getPosition();
    if (position.x < 0) position.x = 0; //왼쪽 경계
    if (position.x + shape.getSize().x > 800) position.x = 800 - shape.getSize().x; //화면 너비를 기준으로 경계 체크
    if (position.y >= groundY) {
        position.y = groundY;
        isJumping = false;
        jumpVelocity = 0.f;
    }
    shape.setPosition(position);
}

void Player::render(RenderWindow& window) {
    window.draw(shape);
}

void Player::changeColor(Color newColor) {
    color = newColor;
    shape.setFillColor(color);
}

void Player::losePixel() {
    Vector2f size = shape.getSize();
    if (size.x > 1.f && size.y > 1.f) {
        shape.setSize(size - Vector2f(1.f, 1.f));
    }
}

FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();
}
