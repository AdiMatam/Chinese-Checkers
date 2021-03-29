#include "Pch.hpp"
#include "Helpers.hpp"
#include "Checkers.hpp"

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    const auto LOCKSIZE = sf::Style::Titlebar | sf::Style::Close;
    
    sf::RenderWindow window(sf::VideoMode(HEIGHT, HEIGHT), "Chinese Checkers", LOCKSIZE, settings);
    sf::Color bg(222, 237, 255);
    Checkers game(window, bg);

    sf::Event event;
    Slot* selected = nullptr;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();
            else if (mousePressed(event, sf::Mouse::Left)) {
                Slot* current = game.find(event.mouseButton.x, event.mouseButton.y);
                if (current == nullptr) continue;
                if (game.getIdentity(current) == game.getTurn()) {
                    current->pick();
                    selected = current;
                }
                else if (game.getIdentity(current) == -1 && selected != nullptr) {
                    // slot color should be selected color
                    // selected color should be bg
                    current->setFillColor(selected->getFillColor());
                    current->resetFill();

                    selected->setFillColor(bg);
                    selected->resetFill();
                    selected = nullptr;
                    game.switchTurn();
                }
            }
        }
        window.clear(bg);
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