#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"
// #include <TGUI/TGUI.hpp>

int main() {
    log("Starting up...");
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    auto LOCKSIZE = sf::Style::Titlebar | sf::Style::Close;
    
    sf::RenderWindow window(sf::VideoMode(HEIGHT, HEIGHT), "Chinese Checkers", LOCKSIZE, settings);
    // tgui::Gui gui(window);
    sf::Color bg = {222, 237, 255};
    Checkers game(window, bg);

    // tgui::Button::Ptr button = tgui::Button::create();
    // button->setPosition(tgui::Layout2d(HEIGHT / 2, HEIGHT / 2));
    // button->setText("Loafer");
    // button->setTextSize(24);
    // gui.add(button);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();
            else if (keyPressed(event, sf::Keyboard::Enter))
                game.switchTurn();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left)
                    logf("[%d, %d]", event.mouseButton.x, event.mouseButton.y);
            }
            // gui.handleEvent(event);
        }   
        window.clear(bg);
        game.draw();
        // gui.draw();
        window.display();
    }
    // gui.removeAllWidgets();
}