#include "pch.hpp"
#include "slot.hpp"

Theme* Slot::theme;

Slot::Slot(float x, float y, int row) {
	setup();
	setPosition(sf::Vector2f(x, y));
    overlay.setPosition(sf::Vector2f(x, y));
    determineColor(x, y, row);
}

bool Slot::clicked(float mouseX, float mouseY) const {
    sf::Vector2f pos = getPosition();
    bool x = (pos.x - RADIUS <= mouseX) && (mouseX <= pos.x + RADIUS);
    return x && (pos.y - RADIUS <= mouseY) && (mouseY <= pos.y + RADIUS);
}

void Slot::pick() {
    overlay.setFillColor(sf::Color::Black);
}
void Slot::resetFill() {
    overlay.setFillColor(getFillColor());
}

int Slot::getIdentity() {
	sf::Color fill = getFillColor();
	if (fill == theme->getColor(Theme::BACKGROUND)) return -1;
	// TOP -> RET 0
	// BOT -> RET 1
	return (fill == theme->getColor(Theme::BOTTOM) || 
		    fill == theme->getColor(Theme::BOTTOM_LEFT) || 
		    fill == theme->getColor(Theme::BOTTOM_RIGHT));
}

void Slot::setup() {
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(THICK);
	setRadius(RADIUS);
	setOrigin(getRadius(), getRadius());
	overlay.setRadius(RADIUS / 3);
	overlay.setOrigin(overlay.getRadius(), overlay.getRadius());
}

void Slot::determineColor(float x, float y, int row) {
	sf::Color* color;
	if (row == 9 or row == 0)
		color = &theme->getColor(Theme::BACKGROUND);
	else if (row <= 4 and row >= 1) {
		if (y > HALF) color = &theme->getColor(Theme::BOTTOM);
		else          color = &theme->getColor(Theme::TOP);
	}
	else {
		if (x > HALF) {
			if (y > HALF) color = &theme->getColor(Theme::BOTTOM_RIGHT);
			else          color = &theme->getColor(Theme::TOP_RIGHT);
		}
		else {
			if (y > HALF) color = &theme->getColor(Theme::BOTTOM_LEFT);
			else          color = &theme->getColor(Theme::TOP_LEFT);
		}
	}
	setFillColor(*color);
	overlay.setFillColor(*color);
}