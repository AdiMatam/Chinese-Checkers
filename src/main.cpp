#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"

/* EXPERIMENTATION
void config(tgui::Button::Ptr button) {
	button->setSize(tgui::Layout2d(30, 30));
	button->setOrigin(sf::Vector2f(0.f, 0.f));
	button->setPosition(tgui::Layout2d("parent.w/2 - w - 5", "parent.h - h - 5"));
}

 	tgui::Gui gui(window);
	tgui::Button::Ptr right = tgui::Button::create();
	config(right);
	gui.add(right);
*/

int main() {
	// SFML GRAPHICS CONFIGURATION
	const std::string TITLE = "Chinese Checkers";
	sf::ContextSettings set;
	set.antialiasingLevel = 8;

	sf::RenderWindow window(
		sf::VideoMode(SIZE, SIZE), TITLE, sf::Style::Default, set
	);
	sf::Event ev;
	ChineseCheckers game(&window, 2);
	
	// MAIN GAME LOOP
	// SCREEN CONTINOUSLY CLEARED AND GEOMETRY REDRAWN
	// "DATA" OF GEOMETRY ALTERED BY "EVENTS" -> KEYPRESS, MOUSEPRESS, ETC
	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed or keyPressed(ev, sf::Keyboard::Escape))
				window.close();

			else if (!game.isOver()) {
				if (mousePressed(ev, sf::Mouse::Left))
					game.processClick(ev.mouseButton.x, ev.mouseButton.y);
				
				else if (keyPressed(ev, sf::Keyboard::Enter) and game.movedAtAll())
					game.nextTurn();
				
				else if (keyPressed(ev, sf::Keyboard::Left) or keyPressed(ev, sf::Keyboard::Right))
					game.spin(ev.key.code);

				//else if (ev.key.control and keyPressed(ev, sf::Keyboard::S))
				//	game.save("test.chk");
			}
		}
		game.draw();
	}
	return 0;
}
