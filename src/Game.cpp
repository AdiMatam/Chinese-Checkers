#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"

int main() {
	const std::string TITLE = "Chinese Checkers";
	sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), TITLE);
	sf::Event ev;
	
	ChineseCheckers game(&window);
	
	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed)
				window.close();
		}
		game.draw();
	}
}