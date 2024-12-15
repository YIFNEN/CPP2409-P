#include "Item.h"
#include <cstdlib> // for rand()

using namespace sf;

// ���� �޼���: ���� ������ ����
Item Item::createRandom(float windowWidth, float windowHeight) {
    Item item;
    item.initializeShape(10.f, Color::Yellow); // �ʱ�ȭ ���� ó��
    item.shape.setPosition(rand() % static_cast<int>(windowWidth),
        rand() % static_cast<int>(windowHeight));
    return item;
}

// ������ �ʱ�ȭ (�ݺ� �ڵ� �ּ�ȭ)
void Item::initializeShape(float radius, Color color) {
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius); // �߽� ���� ����
}

// �÷��̾� ȿ�� ����
void Item::applyEffect(Player& player) {
    // ��: ���� ����
    player.changeColor(Color::Green);

    // �߰� ȿ�� (��: �ӵ� ����)
    player.increaseSpeed(1.5f); // �÷��̾� �ӵ��� 1.5�� ����
}

// ������ ������
void Item::render(RenderWindow& window) {
    window.draw(shape);
}

// �������� �����Ǿ����� Ȯ��
bool Item::isCollected(const FloatRect& playerBounds) const {
    return shape.getGlobalBounds().intersects(playerBounds);
}