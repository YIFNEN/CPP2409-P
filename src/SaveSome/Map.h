#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>

class Map {
private:
    std::vector<std::vector<sf::RectangleShape>> tiles;
    sf::Vector2f tileSize;

public:
    Map();
    void initialize(int width, int height);
    Map(int width, int height);
    void render(sf::RenderWindow& window);
    void update(const sf::FloatRect& playerBounds); // 메서드 선언
    sf::FloatRect getBounds() const;
};


#endif