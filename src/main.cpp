#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"

void printMatrix(const float* arr);

int main() {
	const std::string TITLE = "Chinese Checkers";
	sf::ContextSettings set;
	set.antialiasingLevel = 8;

	sf::RenderWindow window(
		sf::VideoMode(SIZE, SIZE), TITLE, sf::Style::Default, set
	);
	sf::Event ev;
	ChineseCheckers game(&window, 2);
	
	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed)
				window.close();

			else if (!game.isOver()) {
				if (mousePressed(ev, sf::Mouse::Left))
					game.processClick(ev.mouseButton.x, ev.mouseButton.y);
				if (keyPressed(ev, sf::Keyboard::Enter) and game.movedAtAll())
					game.nextTurn();
				if (keyPressed(ev, sf::Keyboard::Right) or keyPressed(ev, sf::Keyboard::Left))
					game.spin(ev.key.code);
			}
		}
		game.draw();
	}
}

void printMatrix(const float* arr) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			std::cout << arr[i * 4 + j] << " ";
		std::cout << "\n";
	}
}