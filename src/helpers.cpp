#include "pch.hpp"
#include "helpers.hpp"

float RADIUS = 18.f;
float THICK  = 1.f;
float GAP    = RADIUS;
float XSTEP  = RADIUS * 2 + GAP;
float YSTEP  = sqrtf(powf(XSTEP, 2.f) - powf(GAP / 2.f + RADIUS, 2.f));
float SIZE   = (YSTEP * 17) + (GAP * 2);
float HALF   = SIZE / 2;


//sf::Color OUTLINE    = { 199, 144, 97 };
sf::Color OUTLINE    = { 50, 50, 50 };
sf::Color BACKGROUND = { 255, 255, 255 };
sf::Color COLORS[6]  = {
	sf::Color(255, 255, 255),
	sf::Color(0, 0, 255),
	sf::Color(255, 0, 0),
	sf::Color(230, 245, 66),
	sf::Color(0, 255, 0),
	sf::Color(50, 50, 50),
};

void logColor(const sf::Color& color) {
	printf("%d, %d, %d\n", int(color.r), int(color.g), int(color.b));
}

bool keyPressed(sf::Event& ev, sf::Keyboard::Key code) {
	return (
		ev.type == sf::Event::KeyPressed and
		ev.key.code == code
	);
}
