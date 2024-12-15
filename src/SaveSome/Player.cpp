#include "Player.h"

void Player::initialize() {
    // �ʱ�ȭ ���� �߰�
    shape.setPosition(100.f, 100.f); // �ʱ� ��ġ ����
    shape.setSize(sf::Vector2f(50.f, 50.f));  // ũ�� ����
    shape.setFillColor(sf::Color::White);      // �⺻ ���� ����
    health = 10;  // �⺻ ü�� ����
    speed = 200.f; // �⺻ �ӵ� ����
    velocityY = 0.f;  // Y �ӵ� �ʱ�ȭ
    gravity = 9.8f;  // �߷� �� ����
    jumpStrength = -250.f; // ���� �� ����
    isJumping = false; // ���� ���� �ʱ�ȭ
}

Player::Player(sf::Vector2f position, sf::Vector2f size)
    : health(100), speed(200.f) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Yellow);
}

void Player::update(float deltaTime, sf::FloatRect bounds) {
    sf::Vector2f movement(0, 0);
    // Ű �Է� ó�� (A, S, D�� �̵�)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += 200 * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= 200 * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += 200 * deltaTime;
    }

    // ���� ó��
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping) {
        velocityY = jumpStrength;
        isJumping = true;
    }

    // �߷� ���� (�� �����Ӹ��� �ӵ��� �߷��� ����)
    if (isJumping) {
        velocityY += gravity * deltaTime; // �߷� ����
    }
 
    shape.move(movement);// �̵� ó��

    // Y �ӵ� ���� (�߷¿� ���� ������)
    shape.move(0, velocityY * deltaTime);
    
    // �ٴڿ� ����� �� ó�� (Y ��ǥ�� ���� �̻��̸�)
    if (shape.getPosition().y >= bounds.height - shape.getSize().y) {
        shape.setPosition(shape.getPosition().x, bounds.height - shape.getSize().y); // �ٴڿ� ����
        velocityY = 0; // Y �ӵ��� 0���� ���� (������ ����)
        isJumping = false; // ���� ���� �ƴ�
    }

    // ȭ�� ������ ������ �ʵ��� ����
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
    shape.setFillColor(newColor);  // shape�� Player�� RectangleShape
}

void Player::increaseSpeed(float multiplier) {
    speed *= multiplier; // ���� �ӵ��� ���� ����
}

// ���� �޼���: ������ �����ϴ� ���� Y �ӵ��� ����
void Player::jump() {
    if (!isJumping) {
        velocityY = jumpStrength; // ���� ���� ���� �������� ����
        isJumping = true;
    }
}