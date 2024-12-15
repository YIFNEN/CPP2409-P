#include "ItemManager.h"
#include <cstdlib>
#include <ctime>

void ItemManager::spawnItems(sf::FloatRect mapBounds) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < 5; ++i) {
        sf::CircleShape item(10);
        item.setPosition(
            std::rand() % static_cast<int>(mapBounds.width - 20),
            std::rand() % static_cast<int>(mapBounds.height - 20));

        if (i % 2 == 0) {
            item.setFillColor(sf::Color::Cyan); // �ӵ� ����
        }
        else {
            item.setFillColor(sf::Color::Yellow); // ���� ����
        }

        items.push_back(item);
    }
}

void ItemManager::update(Player& player) {
    for (auto it = items.begin(); it != items.end();) {
        if (player.getBounds().intersects(it->getGlobalBounds())) {
            if (it->getFillColor() == sf::Color::Cyan) {
                // �ӵ� ���� ����
            }
            else if (it->getFillColor() == sf::Color::Yellow) {
                // ���� ���� ����
            }

            it = items.erase(it);
        }
        else {
            ++it;
        }
    }
}

void ItemManager::render(sf::RenderWindow& window) {
    for (const auto& item : items) {
        window.draw(item);
    }
}
