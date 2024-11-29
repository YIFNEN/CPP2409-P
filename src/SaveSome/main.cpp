#include "GameManager.h"
using namespace sf;

int main() {
    GameManager& gameManager = GameManager::getInstance();
    gameManager.initialize();

    Clock clock;
    while (gameManager.getWindow().isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        gameManager.processEvents();
        gameManager.update(deltaTime);
        gameManager.render();
    }

    return 0;
}
