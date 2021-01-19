#include <string>
#include <iostream>
#include <TGUI/TGUI.hpp>

#include "header/helpers.hpp"

using CONSTANT = const unsigned int;
CONSTANT WIDTH = 500;
CONSTANT HEIGHT = WIDTH;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML-Window");
    tgui::Gui gui(window);

    log("Starting up...");

    sf::Texture textures[12];
    loadAllTextures(textures);
    auto& temp = textures[0];
    sf::Image img = temp.copyToImage();
    
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            const sf::Color& c = img.getPixel(i, j);
            if (c.r != 0 || c.g != 0 || c.b != 0) {
                printf("%d, %d -> ", i, j);
                logColor(c);
            }
        }
    }

    sf::Color bg(210, 180, 140);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            gui.handleEvent(event);
        }
        window.clear(bg);
        // window.draw(img);
        gui.draw();
        window.display();
    }
}
