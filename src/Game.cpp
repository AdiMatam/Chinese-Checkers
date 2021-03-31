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



/*

    sf::Clock clock;
    int elapsed;
    bool shouldRotate = false;

void handleRotation(Checkers* game, sf::Clock* clock, bool* shouldRotate) {
    if (clock->getElapsedTime().asMilliseconds() >= 3 && *shouldRotate) {
        clock->restart();
        game->rotateBoard();
    } 
    if (game->getRotation() == 180) *shouldRotate = false;
}

void clickTest(Checkers* game, sf::Event::MouseButtonEvent* mouse) {
    logf("%d, %d", mouse->x, mouse->y);
    for (Slot& s : game->getSlots()) {
        if (s.clicked(mouse->x, mouse->y)) {
            s.setFillColor(sf::Color::Magenta);
        }
    }
}


else if (keyPressed(event, sf::Keyboard::Enter)) {
                game.switchTurn();
                shouldRotate = true;
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    clickTest(&game, &event.mouseButton);                    
                }
            }
*/