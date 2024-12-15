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
    static GameManager& getInstance();  // 싱글턴 접근 함수
    void initialize(); // 게임 초기화
    void processEvents(); // 이벤트 처리
    void update(float deltaTime); // 상태 업데이트
    void render(); // 렌더링

    sf::RenderWindow& getWindow() { return window; } // 창 접근자
    Player& getPlayer() { return player; }           // 플레이어 접근자
    void spawnItem(); // 아이템 생성
    void spawnObstacle(); // 장애물 생성

private:
    GameManager() {} //  기본 생성자 (private으로 유지)
    ~GameManager() = default; // 소멸자 기본 설정

    GameManager(const GameManager&) = delete; // 복사 생성자 삭제
    GameManager& operator=(const GameManager&) = delete; // 복사 대입 연산자 삭제

    sf::RenderWindow window;
    Player player;
    Map map;
    std::vector<Item> items;
    std::vector<Obstacle> obstacles;
};

#endif 
