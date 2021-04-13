#include "pch.hpp"

#include "helpers.hpp"

float RADIUS = 18.f;
float THICK  = 3.f;
float GAP    = RADIUS;
float XSTEP  = RADIUS * 2 + GAP;
float YSTEP  = sqrtf(powf(XSTEP, 2.f) - powf(GAP / 2.f + RADIUS, 2.f));
float SIZE   = (YSTEP * 17) + (GAP * 2);
float HALF   = SIZE / 2;

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
