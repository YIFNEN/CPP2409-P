#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Map.h"
#include "Item.h"
#include "Obstacle.h"

class GameManager {
public:
    static GameManager& getInstance();
    void initialize(); // ���� �ʱ�ȭ
    void processEvents(); // �̺�Ʈ ó��
    void update(float deltaTime); // ���� ������Ʈ
    void render(); // ������

    sf::RenderWindow& getWindow() { return window; } // â ������
    Player& getPlayer() { return player; }           // �÷��̾� ������
    void spawnItem(); // ������ ����
    void spawnObstacle(); // ��ֹ� ����

private:
    GameManager() = default;
    sf::RenderWindow window;
    Player player;
    Map map;
    std::vector<Item> items;
    std::vector<Obstacle> obstacles;
};

#endif // GAMEMANAGER_H
