#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"
// #include "color_manip.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Big");
    Checkers game = Checkers(&window);

    log("Starting up...");

    const sf::Color bg = {222, 237, 255};

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();
        }   
        window.clear(bg);
        game.draw();        
        window.display();
    }
}