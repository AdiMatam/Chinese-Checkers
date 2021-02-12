#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"
// #include <TGUI/TGUI.hpp>

void handleRotation(Checkers* game, sf::Clock* clock, bool* shouldRotate) {
    if (clock->getElapsedTime().asMilliseconds() >= 5 && *shouldRotate) {
        clock->restart();
        game->rotateBoard();
    } 
    if (game->getRotation() == 180) *shouldRotate = false;
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
                if (event.mouseButton.button == sf::Mouse::Left)
                    logf("[%d, %d]", event.mouseButton.x, event.mouseButton.y);
            }
        }
        handleRotation(&game, &clock, &shouldRotate);
        
        window.clear(bg);
        game.draw();
        window.display();
    }
}