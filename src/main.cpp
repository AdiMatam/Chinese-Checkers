#include <string>
#include <iostream>
#include <TGUI/TGUI.hpp>

#include "header/helpers.hpp"
#include "header/color_manip.hpp"

using CONSTANT = const unsigned int;
CONSTANT WIDTH = 256;
CONSTANT HEIGHT = WIDTH;

void updateGradient(sf::VertexArray& gradient, HSV& color) {
    for (int x = 0; x < 256; x++) {
        color.s = x / 255.f;
        for (int y = 0; y < 256; y++) {
            color.v = y / 255.f;
            gradient[x * 256 + y].color = toRGB(color);
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML-Window");

    log("Starting up...");

    sf::Clock clock;
    
    HSV current = { 0, 0, 0 };
    sf::VertexArray gradient(sf::Points, 256 * 256);
    sf::Vector2f* pos;

    for (int x = 0; x < 256; x++) {
        for (int y = 0; y < 256; y++) {
            pos = &(gradient[x * 256 + y].position);
            pos->x = x; pos->y = 255 - y;
        }
    }

    float elapsed;
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();
        }
        window.clear();
        elapsed = clock.getElapsedTime().asMilliseconds();
        if (static_cast<int>(elapsed) >= 100) {
            current.h++;
            if (current.h == 360.f) current.h = 0.f;   
            clock.restart();
        }
        updateGradient(gradient, current);
        window.draw(gradient);
        window.display();
    }
}