#include "Map.h"
#include <vector>

std::vector<std::vector<int>> createMap(int width, int height) {
    std::vector<std::vector<int>> map(height, std::vector<int>(width, 0));

    // ���� �����ڸ��� �ѷ��δ� ������ �� ����
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                map[y][x] = 1; // ��
            }
        }
    }

    return map;
}
