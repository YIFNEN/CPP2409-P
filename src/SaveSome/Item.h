#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Item {
public:
    static Item createRandom();
    void applyEffect(Player& player);
    void render(sf::RenderWindow& window);
    bool isCollected(const sf::FloatRect& playerBounds) const;

private:
    sf::CircleShape shape;
};

#endif // ITEM_H
