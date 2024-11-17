#include "Map.h"
#include <vector>

std::vector<std::vector<int>> createMap(int width, int height) {
    std::vector<std::vector<int>> map(height, std::vector<int>(width, 0));

    // 벽을 가장자리로 둘러싸는 간단한 맵 생성
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                map[y][x] = 1; // 벽
            }
        }
    }

    return map;
}
