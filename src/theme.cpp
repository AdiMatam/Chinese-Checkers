#include "pch.hpp"
#include "theme.h"

Theme::Theme() {
	mBackground = sf::Color(255, 239, 201);
	setColor(Index::TOP,          sf::Color::White);
	setColor(Index::TOP_LEFT,     sf::Color::Red);
	setColor(Index::TOP_RIGHT,    sf::Color::Blue);
	setColor(Index::BOTTOM_LEFT,  sf::Color::Green);
	setColor(Index::BOTTOM_RIGHT, sf::Color::Yellow);
	setColor(Index::BOTTOM,       sf::Color(90, 90, 90));
}

void Theme::setBackground(const sf::Color& background) {
	mBackground = background;
}
void Theme::setColor(Index which, const sf::Color& color) {
	mColors[int(which)] = color;
}
