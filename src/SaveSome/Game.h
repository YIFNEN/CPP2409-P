#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"
#include "ObstacleManager.h"
#include "ItemManager.h"
#include <SFML/Graphics.hpp>
#include "ColorSelectionScene.h"

enum class GameState {
    ColorSelection,
    MainGame
};

class Game {
private:
    sf::RenderWindow window;
    GameState currentState;
    ColorSelectionScene colorSelectionScene; // 선언 추가
    Player player;
    Map map;
    ObstacleManager obstacleManager;
    ItemManager itemManager;
    bool isGameOver;

    void handleEvents();
    void update(float deltaTime);
    void render();
    void checkGameOver();

public:
    Game();
    void run();
};
#endif
