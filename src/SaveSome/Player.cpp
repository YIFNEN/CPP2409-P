#include "Player.h"
using namespace sf;

void Player::initialize() {
    shape.setSize(Vector2f(20.f, 20.f)); // ���� �ȼ� �÷��̾� ũ�� ����
    shape.setFillColor(Color::Red);
    shape.setPosition(100.f, groundY);      // �ʱ� ��ġ�� �ٴ�
}

void Player::update(float deltaTime) {
    Vector2f movement(0.f, 0.f);

    // �¿� �̵�
    if (Keyboard::isKeyPressed(Keyboard::Left))
        movement.x -= speed * deltaTime;
    if (Keyboard::isKeyPressed(Keyboard::Right))
        movement.x += speed * deltaTime;

    // ���� ó��
    if (Keyboard::isKeyPressed(Keyboard::Space) && !isJumping) {
        jumpVelocity = -250.f; // ���� �ӵ�
        isJumping = true;      // ���� ���·� ��ȯ
    }

    // �߷� ����
    jumpVelocity += gravity * deltaTime;
    movement.y += jumpVelocity * deltaTime;

    // �÷��̾� �̵�
    shape.move(movement);

    // ȭ�� ��� üũ (ȭ�� �ٱ����� ������ �ʵ��� ��ġ ����)
    Vector2f position = shape.getPosition();
    if (position.x < 0) {
        position.x = 0; // ���� ���
    }
    if (position.x + shape.getSize().x > 800) { // ȭ�� �ʺ�(800)�� �������� ��� üũ
        position.x = 800 - shape.getSize().x; // ������ ���
    }
    shape.setPosition(position);

    // �ٴ� �浹 ó��
    if (shape.getPosition().y >= groundY) {
        shape.setPosition(shape.getPosition().x, groundY);
        isJumping = false;    // ���� ���� �ʱ�ȭ
        jumpVelocity = 0.f;   // �ӵ� �ʱ�ȭ
    }
}

void Player::render(RenderWindow& window) {
    window.draw(shape);
}

FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();
}
