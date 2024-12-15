#include "Map.h"
#include <cstdlib>
#include <ctime>

Map::Map() {
    // 기본 생성자에서는 기본값을 설정하거나 빈 맵을 초기화할 수 있습니다.
    tileSize = { 40.f, 40.f };  // 기본 타일 크기 설정
    // tiles에 대해서도 초기화하거나 비워두는 등의 작업을 할 수 있습니다.
}
void Map::initialize(int width, int height) {


}
Map::Map(int width, int height) {
    tileSize = { 40, 40 };
    tiles.resize(height, std::vector<sf::RectangleShape>(width));

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            sf::RectangleShape tile(tileSize);
            tile.setPosition(x * tileSize.x, y * tileSize.y);

            int randColor = std::rand() % 10;
            if (randColor < 2) {
                tile.setFillColor(sf::Color::Red);
            }
            else if (randColor < 4) {
                tile.setFillColor(sf::Color::Green);
            }
            else if (randColor < 6) {
                tile.setFillColor(sf::Color::Blue);
            }
            else {
                tile.setFillColor(sf::Color::Magenta);
            }

            tiles[y][x] = tile;
        }
    }
}

void Map::render(sf::RenderWindow& window) {
    for (const auto& row : tiles) {
        for (const auto& tile : row) {
            window.draw(tile);
        }
    }
}

void Map::update(const sf::FloatRect& playerBounds) {
    for (auto& row : tiles) {
        for (auto& tile : row) {
            if (tile.getGlobalBounds().intersects(playerBounds)) {
                // 타일과 플레이어 간 충돌 처리
            }
        }
    }
}
sf::FloatRect Map::getBounds() const {
    return sf::FloatRect(0, 0, tileSize.x * tiles[0].size(), tileSize.y * tiles.size());
}