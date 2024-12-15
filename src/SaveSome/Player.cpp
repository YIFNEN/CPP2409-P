#include "Player.h"

void Player::initialize() {
    // 초기화 로직 추가
    shape.setPosition(100.f, 100.f); // 초기 위치 설정
    shape.setSize(sf::Vector2f(50.f, 50.f));  // 크기 설정
    shape.setFillColor(sf::Color::White);      // 기본 색상 설정
    health = 10;  // 기본 체력 설정
    speed = 200.f; // 기본 속도 설정
    velocityY = 0.f;  // Y 속도 초기화
    gravity = 9.8f;  // 중력 값 설정
    jumpStrength = -250.f; // 점프 힘 설정
    isJumping = false; // 점프 상태 초기화
}

Player::Player(sf::Vector2f position, sf::Vector2f size)
    : health(100), speed(200.f) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Yellow);
}

void Player::update(float deltaTime, sf::FloatRect bounds) {
    sf::Vector2f movement(0, 0);
    // 키 입력 처리 (A, S, D로 이동)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += 200 * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= 200 * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += 200 * deltaTime;
    }

    // 점프 처리
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping) {
        velocityY = jumpStrength;
        isJumping = true;
    }

    // 중력 적용 (매 프레임마다 속도에 중력을 더함)
    if (isJumping) {
        velocityY += gravity * deltaTime; // 중력 적용
    }
 
    shape.move(movement);// 이동 처리

    // Y 속도 적용 (중력에 의한 떨어짐)
    shape.move(0, velocityY * deltaTime);
    
    // 바닥에 닿았을 때 처리 (Y 좌표가 일정 이상이면)
    if (shape.getPosition().y >= bounds.height - shape.getSize().y) {
        shape.setPosition(shape.getPosition().x, bounds.height - shape.getSize().y); // 바닥에 고정
        velocityY = 0; // Y 속도를 0으로 설정 (떨어짐 멈춤)
        isJumping = false; // 점프 중이 아님
    }

    // 화면 밖으로 나가지 않도록 제한
    if (!bounds.contains(shape.getPosition())) {
        shape.move(-movement);
    }
}

void Player::render(sf::RenderWindow& window) {
    window.draw(shape);
}

void Player::takeDamage() {
    --health;
    if (health > 0) {
        shape.setFillColor(sf::Color::Yellow);
    }
    else {
        shape.setFillColor(sf::Color::Black);
    }
}

bool Player::isDestroyed() const {
    return health <= 0;
}

void Player::setColor(sf::Color color) {
    shape.setFillColor(color);
}


sf::FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();
}

void Player::changeColor(const sf::Color& newColor) {
    shape.setFillColor(newColor);  // shape는 Player의 RectangleShape
}

void Player::increaseSpeed(float multiplier) {
    speed *= multiplier; // 기존 속도에 곱셈 연산
}

// 점프 메서드: 점프를 시작하는 순간 Y 속도를 설정
void Player::jump() {
    if (!isJumping) {
        velocityY = jumpStrength; // 점프 힘을 위쪽 방향으로 설정
        isJumping = true;
    }
}