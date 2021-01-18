#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "header/helpers.hpp"

using CONSTANT = const unsigned int;
CONSTANT WIDTH = 500;
CONSTANT HEIGHT = WIDTH;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML-Window");    
    log("Starting up...");

    sf::Texture textures[12];
    loadAllTextures(textures);

    const sf::Color bg(210, 180, 140);
    
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear(bg);
        // window.draw(sprite);
        window.display();
    }
}

