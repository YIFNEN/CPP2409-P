#ifndef COLOR_SELECTION_SCENE_H
#define COLOR_SELECTION_SCENE_H

#include <SFML/Graphics.hpp>

class ColorSelectionScene {
private:
    sf::RectangleShape redArea;
    sf::RectangleShape greenArea;
    sf::RectangleShape blueArea;
    sf::Color selectedColor;
    bool colorSelected;

public:
    ColorSelectionScene();
    void handleInput(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    bool isColorSelected() const;
    sf::Color getSelectedColor() const;
};

#endif