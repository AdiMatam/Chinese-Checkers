#include "helpers.hpp"

float RADIUS         = 20;
float THICK          = RADIUS / 5;
float GAP            = RADIUS / 2;
float STEP           = RADIUS * 2 + GAP;
float BOARD_DIAMETER = RADIUS * 2 * 17 + GAP * 19;
float HEIGHT         = BOARD_DIAMETER + 2 * GAP;

void logColor(const sf::Color& color) {
    printf("[%d, %d, %d]\n", static_cast<int>(color.r), static_cast<int>(color.g), static_cast<int>(color.b));
}

bool keyPressed(const sf::Event& e, const sf::Keyboard::Key& code) {
    return e.type == sf::Event::KeyPressed && e.key.code == code;
}

bool mousePressed(const sf::Event& e, const sf::Mouse::Button& code) {
    return (
        e.type == sf::Event::MouseButtonPressed &&
        e.mouseButton.button == code);
}
