#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"
#include "net/server.hpp"

int main() {
	char who;
	std::cin >> who;
	if (who == 's') {
		Server s(3000, sf::IpAddress::getLocalAddress());
		s.run();
		return 0;
	}
	const std::string TITLE = "Chinese Checkers";
	sf::ContextSettings set;
	set.antialiasingLevel = 8;

	sf::RenderWindow window(
		sf::VideoMode(SIZE, SIZE), TITLE, sf::Style::Default, set
	);
	sf::Event ev;
	ChineseCheckers game(&window, 2);
	
	while (window.isOpen()) {
		//game.sendAndRecv("get");
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed or keyPressed(ev, sf::Keyboard::Escape))
				window.close();
		}
	}
	return 0;
}


/* EXPERIMENTATION - IGNORE FOR PRES.
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
