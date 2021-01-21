#include <string>
#include <iostream>
#include <TGUI/TGUI.hpp>

#include "header/helpers.hpp"
#include "header/color_manip.hpp"

using CONSTANT = const unsigned int;
CONSTANT WIDTH = 256;
CONSTANT HEIGHT = WIDTH;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML-Window");
    // tgui::Gui gui(window);

    log("Starting up...");

    HSV hsv = toHSV(125, 200, 50);
    sf::Color rgb = toRGB(hsv);

    logColor(rgb);
    
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();
            // gui.handleEvent(event);
        }
        window.clear(sf::Color::White);
        // gui.draw();
        window.display();
    }
}