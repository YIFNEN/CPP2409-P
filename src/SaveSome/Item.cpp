#include "Item.h"
#include <cstdlib> // for rand()

using namespace sf;

// 정적 메서드: 랜덤 아이템 생성
Item Item::createRandom(float windowWidth, float windowHeight) {
    Item item;
    item.initializeShape(10.f, Color::Yellow); // 초기화 공통 처리
    item.shape.setPosition(rand() % static_cast<int>(windowWidth),
        rand() % static_cast<int>(windowHeight));
    return item;
}

// 아이템 초기화 (반복 코드 최소화)
void Item::initializeShape(float radius, Color color) {
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius); // 중심 기준 정렬
}

// 플레이어 효과 적용
void Item::applyEffect(Player& player) {
    // 예: 색상 변경
    player.changeColor(Color::Green);

    // 추가 효과 (예: 속도 증가)
    player.increaseSpeed(1.5f); // 플레이어 속도를 1.5배 가속
}

// 아이템 렌더링
void Item::render(RenderWindow& window) {
    window.draw(shape);
}

// 아이템이 수집되었는지 확인
bool Item::isCollected(const FloatRect& playerBounds) const {
    return shape.getGlobalBounds().intersects(playerBounds);
}