#include "pch.hpp"
#include "helpers.hpp"

// CONSTANTS -> VARIOUS ELEMENTS OF THE BOARD
float RADIUS = 18.f;
float THICK  = 1.f;
float GAP    = RADIUS;
float XSTEP  = RADIUS * 2 + GAP;
// DISTANCE FORMULA TO DETERMINE Y-SPACING BETWEEN CIRCLES ON BOARD
float YSTEP  = sqrtf(powf(XSTEP, 2.f) - powf(GAP / 2.f + RADIUS, 2.f));
float SIZE   = (YSTEP * 17) + (GAP * 2);
float HALF   = SIZE / 2;

// COLOR DEFINITIONS
sf::Color OUTLINE    = { 50, 50, 50 };
sf::Color BACKGROUND = { 255, 255, 255 };

// SLOT COLORS
sf::Color COLORS[6]  = {
	sf::Color(255, 255, 255),
	sf::Color(0, 0, 255),
	sf::Color(255, 0, 0),
	sf::Color(230, 245, 66),
	sf::Color(0, 255, 0),
	sf::Color(50, 50, 50),
};

// "COLORS" IS AN ARRAY
// METHOD "FILLS" ARRAY WITH THE COLORS THAT "BELONG" TO THE CURRENT PLAYER.
void getMyColors(int currPlayer, int totalPlayers, sf::Color* colors, int len) {
	int index = currPlayer * len; // 0 | 3
	// 2 players - 0,1,2 | 3,4,5
	for (int i = index; i < index + len; i++)
		colors[i - index] = COLORS[i];
}

// DETERMINES IF "SEARCH" IN ARRAY
bool arrContains(const sf::Color& search, sf::Color* array, int len) {
	auto end = array + len;
	return std::find(
		array, end, search)
		!= end;
}

// SFML EVENT HANDLING - "SHORTCUTS"
bool keyPressed(sf::Event& ev, sf::Keyboard::Key code) {
	return (
		ev.type == sf::Event::KeyPressed and
		ev.key.code == code
	);
}

bool mousePressed(sf::Event& ev, sf::Mouse::Button code) {
	return (
		ev.type == sf::Event::MouseButtonPressed and
		ev.mouseButton.button == code
	);
}
