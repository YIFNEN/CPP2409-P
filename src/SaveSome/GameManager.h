#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class GameManager {
public:
    static GameManager& getInstance() {
        static GameManager instance;
        return instance;
    }

    void initialize(); // �ʱ�ȭ �Լ�
    void processEvents(); // �̺�Ʈ ó�� �Լ�
    void update(float deltaTime); // ���� ���� ������Ʈ
    void render(); // ������ �Լ�

    sf::RenderWindow& getWindow() { return window; } // â ������

private:
    GameManager() = default; // �����ڸ� private���� �����Ͽ� �̱��� ����
    sf::RenderWindow window;
    Player player;
};

#endif // GAMEMANAGER_H
