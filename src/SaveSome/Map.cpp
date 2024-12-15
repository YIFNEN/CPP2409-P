#include "Map.h"
#include <cstdlib>
#include <ctime>

Map::Map() {
    // �⺻ �����ڿ����� �⺻���� �����ϰų� �� ���� �ʱ�ȭ�� �� �ֽ��ϴ�.
    tileSize = { 40.f, 40.f };  // �⺻ Ÿ�� ũ�� ����
    // tiles�� ���ؼ��� �ʱ�ȭ�ϰų� ����δ� ���� �۾��� �� �� �ֽ��ϴ�.
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
                // Ÿ�ϰ� �÷��̾� �� �浹 ó��
            }
        }
    }
}
sf::FloatRect Map::getBounds() const {
    return sf::FloatRect(0, 0, tileSize.x * tiles[0].size(), tileSize.y * tiles.size());
}