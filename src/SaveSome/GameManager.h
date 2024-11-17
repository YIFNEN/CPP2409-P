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

    void initialize(); // 초기화 함수
    void processEvents(); // 이벤트 처리 함수
    void update(float deltaTime); // 게임 상태 업데이트
    void render(); // 렌더링 함수

    sf::RenderWindow& getWindow() { return window; } // 창 접근자

private:
    GameManager() = default; // 생성자를 private으로 설정하여 싱글톤 보장
    sf::RenderWindow window;
    Player player;
};

#endif // GAMEMANAGER_H
