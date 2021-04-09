#include "pch.hpp"

#include "helpers.hpp"

float RADIUS         = 20;
float THICK          = RADIUS / 5;
float GAP            = RADIUS / 2;
float YSTEP          = RADIUS * 2 + GAP;
float XSTEP          = YSTEP * 1.15f;
float BOARD_DIAMETER = RADIUS * 2 * 17 + GAP * 19;
float HEIGHT         = BOARD_DIAMETER + 2 * GAP;

void logColor(const sf::Color& color) {
    printf("[%d, %d, %d]\n", int(color.r), int(color.g), int(color.b));
}

bool keyPressed(const sf::Event& e, const sf::Keyboard::Key& code) {
    return e.type == sf::Event::KeyPressed && e.key.code == code;
}

bool mousePressed(const sf::Event& e, const sf::Mouse::Button& code) {
    return (
        e.type == sf::Event::MouseButtonPressed &&
        e.mouseButton.button == code);
}
