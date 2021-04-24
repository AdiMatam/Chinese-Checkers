#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"


int main() {
    auto STYLE = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "Chinese Checkers", STYLE);
    sf::Event event;

    Theme theme;
    Checkers game(&window, &theme);
    
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();

            else if (mousePressed(event, sf::Mouse::Left))
                game.processClick(event.mouseButton.x, event.mouseButton.y, false);

            else if (keyPressed(event, sf::Keyboard::Enter) && game.movedAtAll())
                game.switchTurn();
        }
        game.draw();
        window.display();
    }
}

