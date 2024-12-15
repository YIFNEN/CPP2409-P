#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Item {
public:
    static Item createRandom(float windowWidth, float windowHeight); // 윈도우 크기 사용
    void applyEffect(Player& player); // 플레이어 효과 적용
    void render(sf::RenderWindow& window);
    bool isCollected(const sf::FloatRect& playerBounds) const;

private:
    sf::CircleShape shape;

    void initializeShape(float radius, sf::Color color); // 공통 초기화 로직
};

#endif // ITEM_H
