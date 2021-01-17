#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>


#define WIDTH 500
#define HEIGHT 300

int main() {
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML-Window");
    
    std::cout << "Starting up..." << std::endl;
    
    auto screen = sf::VideoMode::getDesktopMode();
    std::string msg = "Display Size: " + std::to_string(screen.width) + "x" + std::to_string(screen.height);
    
    sf::Font font;
    if (!font.loadFromFile("fonts/comic.ttf")) {
        throw std::exception();
    }
    sf::Text text(msg, font, 20);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(100, 120));
    
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear(sf::Color::Blue);
        window.draw(text);
        window.display();
    }
}