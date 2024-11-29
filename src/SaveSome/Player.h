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
    float speed = 200.f;
    float jumpVelocity = 0.f;
    float gravity = 400.f;
    bool isJumping = false;
    float groundY = 500.f;
    int pixels = 100;
};

#endif // PLAYER_H
