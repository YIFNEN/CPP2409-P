#include "Player.h"
using namespace sf;

void Player::initialize() {
    shape.setSize(Vector2f(20.f, 20.f));
    shape.setFillColor(Color::Red);
    shape.setPosition(100.f, groundY);
    color = Color::Red;
}

void Player::update(float deltaTime) {
    Vector2f movement(0.f, 0.f);
    if (Keyboard::isKeyPressed(Keyboard::Left)) movement.x -= speed * deltaTime;
    if (Keyboard::isKeyPressed(Keyboard::Right)) movement.x += speed * deltaTime;

    if (Keyboard::isKeyPressed(Keyboard::Space) && !isJumping) {
        jumpVelocity = -250.f;
        isJumping = true;
    }

    jumpVelocity += gravity * deltaTime;
    movement.y += jumpVelocity * deltaTime;

    shape.move(movement);

    Vector2f position = shape.getPosition();
    if (position.x < 0) position.x = 0;
    if (position.x + shape.getSize().x > 800) position.x = 800 - shape.getSize().x;
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
