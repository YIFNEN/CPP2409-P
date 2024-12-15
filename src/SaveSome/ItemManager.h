#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>

class ItemManager {
private:
    std::vector<sf::CircleShape> items;

public:
    void spawnItems(sf::FloatRect mapBounds);
    void update(Player& player);
    void render(sf::RenderWindow& window);
};

#endif
