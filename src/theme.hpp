#pragma once

#include "pch.hpp"

class Theme {
private:
	std::array<sf::Color, 7> mColors;

public:
	enum Index {
		TOP, TOP_RIGHT, TOP_LEFT, BOTTOM, BOTTOM_RIGHT, BOTTOM_LEFT, BACKGROUND
	};
	
	Theme();
	void setColor(Index which, const sf::Color& color);
	sf::Color& getColor(Index which);
	//void finalize();

};

