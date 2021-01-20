#include <string>
#include <iostream>
#include <TGUI/TGUI.hpp>

#include "header/helpers.hpp"

using CONSTANT = const unsigned int;
CONSTANT WIDTH = 500;
CONSTANT HEIGHT = WIDTH;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML-Window");
    // tgui::Gui gui(window);

    log("Starting up...");

    sf::Texture bpawn;
    loadTexture(&bpawn, "img/bbishop.png");
    sf::Texture wpawn;
    loadTexture(&wpawn, "img/wbishop.png");

    sf::Sprite sprites[4];
    sprites[0].setTexture(bpawn);
    sprites[0].setPosition(100, 100);

    sprites[1].setTexture(bpawn);
    sprites[1].setPosition(300, 100);
    sprites[1].setColor(sf::Color::Blue);

    sprites[2].setTexture(wpawn);
    sprites[2].setPosition(100, 300);
    sprites[2].setColor(sf::Color::Black);

    sprites[3].setTexture(wpawn);
    sprites[3].setPosition(300, 300);
    sprites[3].setColor(sf::Color::Blue);
    
    const sf::Color bg(210, 180, 140);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            // gui.handleEvent(event);
        }
        window.clear(bg);
        drawSpriteArray<4>(&window, sprites);
        // window.draw(img);
        // gui.draw();
        window.display();
    }
}