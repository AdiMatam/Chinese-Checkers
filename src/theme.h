#pragma once

#include "pch.hpp"

class Theme {
private:
	sf::Color mBackground;
	std::vector<sf::Color> mColors;

public:
	enum class Index {
		TOP, TOP_RIGHT, TOP_LEFT, BOTTOM, BOTTOM_RIGHT, BOTTOM_LEFT
	};
	
	Theme();
	void setBackground(const sf::Color& background);
	void setColor(Index which, const sf::Color& color);

};

