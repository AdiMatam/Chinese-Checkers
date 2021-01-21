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

    sf::Texture texture;
    loadTexture(&texture, "img/bbishop.png");
    sf::Image img = texture.copyToImage();
    sf::Sprite sp;
    sp.setTexture(texture);
    logColor(sp.getColor());
    
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            const sf::Color& c = img.getPixel(i, j);
            // if (c.r != 0 || c.g != 0 || c.b != 0) {
                // if (c.r < 200) {
                    printf("%d, %d -> ", i, j);
                    logColor(c);
                    img.setPixel(i, j, sf::Color::Blue);
                // }
            // }
        }
    }

    texture.loadFromImage(img);
    sf::Sprite piece(texture);

    sf::Color bg(210, 180, 140);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear(bg);
        window.draw(piece);
        window.display();
    }
}