#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "header/helpers.hpp"


#define WIDTH 500
#define HEIGHT 300

int main() {
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML-Window");    
    log("Starting up...");

    sf::Texture knight;
    loadImage(&knight, "img/wrook.png");
    sf::Sprite sprite;
    sprite.setTexture(knight);
    // logColor(sprite.getColor());
    sprite.setColor(sf::Color(255, 0, 255));
    sprite.setOrigin(32.f, 32.f);
    sprite.setPosition(sf::Vector2f(250.f, 32.f));

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
        window.draw(sprite);
        window.display();
    }
}

