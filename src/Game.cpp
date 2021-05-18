#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"

int main() {
	const std::string TITLE = "Chinese Checkers";
	sf::ContextSettings set;
	set.antialiasingLevel = 16;
	sf::RenderWindow window(
		sf::VideoMode(SIZE, SIZE), TITLE, sf::Style::Default, set
	);
	sf::Event ev;
	
	ChineseCheckers game(&window, 2);

	sf::Texture tex;
	tex.loadFromFile("res/img/background.jpg");
	tex.setSmooth(true);
	sf::Sprite sp;
	sp.setTexture(tex);
	sp.setColor(sf::Color(255, 255, 255, 128));
	
	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed)
				window.close();
			if (ev.type == sf::Event::Resized)
				window.setSize(
					sf::Vector2u(ev.size.width, ev.size.width)
				);
			if (keyPressed(ev, sf::Keyboard::Enter))
				game.rotateBoard();
		}
		window.clear(BACKGROUND);
		window.draw(sp);
		game.draw();
		window.display();
	}
}