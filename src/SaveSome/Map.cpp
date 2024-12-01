#include "Map.h"
#include <cstdlib>
using namespace sf;

void Map::initialize(int width, int height) {

    mapData = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
    tileShape.setSize(Vector2f(tileSize, tileSize));
    tileShape.setOutlineColor(Color::Black);
    tileShape.setOutlineThickness(1);

    loadMap(); // �� ������ ����
}

void Map::loadMap() {
    int width = mapData[0].size();
    int height = mapData.size();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // ������ �� �׵θ� ����
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                mapData[y][x] = 1; // 1�� �浹 ���� ���
            } else if (rand() % 10 == 0) {
                mapData[y][x] = 2; // 2�� ���� Ÿ�� (����)
            }
        }
    }
}

void Map::update(const FloatRect& playerBounds) {
    int width = mapData[0].size();
    int height = mapData.size();

    // �浹 ó�� (����)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (mapData[y][x] == 1) {
                FloatRect tileBounds(x * tileSize, y * tileSize, tileSize, tileSize);
                if (playerBounds.intersects(tileBounds)) {
                    // �浹 �߻� �� �÷��̾� ��ġ�� ����
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
                    tileShape.setFillColor(Color::Magenta); // ��
                else if (mapData[y][x] == 2)
                    tileShape.setFillColor(Color::Green); // Ư�� Ÿ��

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
