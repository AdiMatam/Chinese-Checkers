#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"
// #include "color_manip.hpp"

int main() {
    log("Starting up...");
      
    sf::RenderWindow window(sf::VideoMode(500, 500), "Big");
    sf::Color bg = {222, 237, 255};
    Checkers game(window, bg);

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