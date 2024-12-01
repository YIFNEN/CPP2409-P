#include "Map.h"
#include <cstdlib>
using namespace sf;

void Map::initialize(int width, int height) {

    mapData = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
    tileShape.setSize(Vector2f(tileSize, tileSize));
    tileShape.setOutlineColor(Color::Black);
    tileShape.setOutlineThickness(1);

    loadMap(); // 맵 데이터 생성
}

void Map::loadMap() {
    int width = mapData[0].size();
    int height = mapData.size();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // 벽으로 맵 테두리 생성
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                mapData[y][x] = 1; // 1은 충돌 가능 블록
            } else if (rand() % 10 == 0) {
                mapData[y][x] = 2; // 2는 색상 타일 (랜덤)
            }
        }
    }
}

void Map::update(const FloatRect& playerBounds) {
    int width = mapData[0].size();
    int height = mapData.size();

    // 충돌 처리 (예시)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (mapData[y][x] == 1) {
                FloatRect tileBounds(x * tileSize, y * tileSize, tileSize, tileSize);
                if (playerBounds.intersects(tileBounds)) {
                    // 충돌 발생 시 플레이어 위치를 보정
                }
            }
        }
    }
}

void Map::render(RenderWindow& window) {
    int width = mapData[0].size();
    int height = mapData.size();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (mapData[y][x] > 0) {
                tileShape.setPosition(x * tileSize, y * tileSize);

                if (mapData[y][x] == 1)
                    tileShape.setFillColor(Color::Magenta); // 벽
                else if (mapData[y][x] == 2)
                    tileShape.setFillColor(Color::Green); // 특수 타일

                window.draw(tileShape);
            }
        }
    }
}

bool Map::isCollidable(int x, int y) const {
    if (x >= 0 && y >= 0 && y < mapData.size() && x < mapData[0].size())
        return mapData[y][x] == 1;
    return false;
}
