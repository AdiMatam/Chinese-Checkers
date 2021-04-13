#include "pch.hpp"
#include "slot.hpp"

sf::Color* Slot::fill;
std::vector<sf::Color>* Slot::colors;


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


void Slot::setup() {
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(THICK);
	setRadius(RADIUS);
	setOrigin(getRadius(), getRadius());
	overlay.setRadius(RADIUS / 3);
	overlay.setOrigin(overlay.getRadius(), overlay.getRadius());
}

void Slot::determineColor(float x, float y, int row) {
	sf::Color color;
	if (row == 9 or row == 0)
		color = *fill;
	else if (row <= 4 and row >= 1) {
		if (y > HALF) color = colors->at(3);
		else          color = colors->at(0);
	}
	else {
		if (x > HALF) {
			if (y > HALF) color = colors->at(4);
			else          color = colors->at(1);
		}
		else {
			if (y > HALF) color = colors->at(5);
			else          color = colors->at(2);
		}
	}
	setFillColor(color);
	overlay.setFillColor(color);
}