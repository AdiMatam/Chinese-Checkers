#pragma once

#include "pch.hpp"

class Theme {
private:
	sf::Color mBackground;
	std::array<sf::Color, 6> mColors;

public:
	enum Index {
		TOP, TOP_RIGHT, TOP_LEFT, BOTTOM, BOTTOM_RIGHT, BOTTOM_LEFT
	};
	
	Theme();
	void setBackground(const sf::Color& background);
	void setColor(Index which, const sf::Color& color);
	sf::Color& getBackground();
	sf::Color& getColor(Index which);
	//void finalize();

};

