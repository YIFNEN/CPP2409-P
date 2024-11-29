#include "Item.h"
using namespace sf;

Item Item::createRandom() {
    Item item;
    item.shape.setRadius(10.f);
    item.shape.setFillColor(Color::Yellow);
    item.shape.setPosition(rand() % 800, rand() % 600);
    return item;
}

void Item::applyEffect(Player& player) {
    player.changeColor(Color::Green); // 예: 플레이어의 속도 증가

}

void Item::render(RenderWindow& window) {
    window.draw(shape);
}

bool Item::isCollected(const FloatRect& playerBounds) const {
    return shape.getGlobalBounds().intersects(playerBounds);
}
