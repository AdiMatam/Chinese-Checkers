#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"

int main() {
    log("Starting up...");
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(HEIGHT, HEIGHT), "Window", sf::Style::Default, settings);
    sf::Color bg = {222, 237, 255};
    Checkers game(window, bg);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();
            // if (mousePRessed)
        }   
        window.clear(bg);
        game.draw();        
        window.display();
    }
}