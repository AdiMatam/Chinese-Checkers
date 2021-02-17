#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"

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

int main() {
    log("Starting up...");
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    auto LOCKSIZE = sf::Style::Titlebar | sf::Style::Close;
    
    sf::RenderWindow window(sf::VideoMode(HEIGHT, HEIGHT), "Chinese Checkers", LOCKSIZE, settings);
    sf::Color bg = {222, 237, 255};
    Checkers game(window, bg);

    sf::Event event;
    sf::Clock clock;
    int elapsed;
    bool shouldRotate = false;
    
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();
            else if (keyPressed(event, sf::Keyboard::Enter)) {
                game.switchTurn();
                shouldRotate = true;
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    clickTest(&game, &event.mouseButton);                    
                }
            }
        }
        handleRotation(&game, &clock, &shouldRotate);
        
        window.clear(bg);
        game.draw();
        window.display();
    }
}