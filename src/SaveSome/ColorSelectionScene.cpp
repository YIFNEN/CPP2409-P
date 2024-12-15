#include "ColorSelectionScene.h"

ColorSelectionScene::ColorSelectionScene()
    : colorSelected(false), selectedColor(sf::Color::White) {
    redArea.setSize({ 800 / 3.f, 600 });
    redArea.setPosition(0, 0);
    redArea.setFillColor(sf::Color::Red);

    greenArea.setSize({ 800 / 3.f, 600 });
    greenArea.setPosition(800 / 3.f, 0);
    greenArea.setFillColor(sf::Color::Green);

    blueArea.setSize({ 800 / 3.f, 600 });
    blueArea.setPosition(2 * 800 / 3.f, 0);
    blueArea.setFillColor(sf::Color::Blue);
}

void ColorSelectionScene::handleInput(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (redArea.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            selectedColor = sf::Color::Red;
            colorSelected = true;
        }
        else if (greenArea.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            selectedColor = sf::Color::Green;
            colorSelected = true;
        }
        else if (blueArea.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            selectedColor = sf::Color::Blue;
            colorSelected = true;
        }
    }
}

void ColorSelectionScene::render(sf::RenderWindow& window) {
    window.draw(redArea);
    window.draw(greenArea);
    window.draw(blueArea);
}

bool ColorSelectionScene::isColorSelected() const {
    return colorSelected;
}

sf::Color ColorSelectionScene::getSelectedColor() const {
    return selectedColor;
}
