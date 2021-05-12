#include "pch.hpp"
#include "helpers.hpp"

float RADIUS = 18.f;
float THICK  = 3.f;
float GAP    = RADIUS;
float XSTEP  = RADIUS * 2 + GAP;
float YSTEP  = sqrtf(powf(XSTEP, 2.f) - powf(GAP / 2.f + RADIUS, 2.f));
float SIZE   = (YSTEP * 17) + (GAP * 2);
float HALF   = SIZE / 2;


sf::Color OUTLINE    = { 199, 144, 97 };
sf::Color BACKGROUND = { 105, 48, 0 };
sf::Color COLORS[6]  = {
	sf::Color::White,
	sf::Color::Red,
	sf::Color::Blue,
	sf::Color::Green,
	sf::Color::Yellow,
	sf::Color(90, 90, 90),
};

void logColor(const sf::Color& color) {
	printf("%d, %d, %d\n", int(color.r), int(color.g), int(color.b));
}
