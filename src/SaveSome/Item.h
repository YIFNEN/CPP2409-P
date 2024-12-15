#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Item {
public:
    static Item createRandom(float windowWidth, float windowHeight); // ������ ũ�� ���
    void applyEffect(Player& player); // �÷��̾� ȿ�� ����
    void render(sf::RenderWindow& window);
    bool isCollected(const sf::FloatRect& playerBounds) const;

private:
    sf::CircleShape shape;

    void initializeShape(float radius, sf::Color color); // ���� �ʱ�ȭ ����
};

#endif // ITEM_H
