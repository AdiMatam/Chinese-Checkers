#include "Pch.hpp"
#include "Helpers.hpp"
#include "Checkers.hpp"

namespace Pref {
    int         STYLE = sf::Style::Titlebar | sf::Style::Close;
    std::string TITLE = "Chinese Checkers";
    sf::Color   BG    = sf::Color(222, 237, 255);
};

int main() {
    sf::RenderWindow window(sf::VideoMode(HEIGHT, HEIGHT), Pref::TITLE, Pref::STYLE);
    Checkers game(window, Pref::BG);
    sf::Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();
            else if (mousePressed(event, sf::Mouse::Left))
                game.processClick(event.mouseButton.x, event.mouseButton.y);
        }
        window.clear(Pref::BG);
        game.draw();
        window.display();
    }
}
