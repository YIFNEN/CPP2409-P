#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>

class Map {
public:
    void initialize(int width, int height);
    void update(const sf::FloatRect& playerBounds);
    void render(sf::RenderWindow& window);
    bool isColliding(const sf::FloatRect& playerBounds) const;
    bool isCollidable(int x, int y) const;

private:
    std::vector<std::vector<int>> mapData;
    sf::RectangleShape tileShape;
    int tileSize = 40;

    void loadMap(); // 간단한 맵 생성
};

#endif // MAP_H
