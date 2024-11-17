#include "GameManager.h"
using namespace sf;

int main() {

    GameManager& gameManager = GameManager::getInstance();
    gameManager.initialize();

    Clock clock; // 시간 측정을 위한 시계

    while (gameManager.getWindow().isOpen()) {
        float deltaTime = clock.restart().asSeconds(); // 프레임 간 시간 계산
        gameManager.processEvents();
        gameManager.update(deltaTime);
        gameManager.render();
    }

    return 0;
}
