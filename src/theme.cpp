#include "pch.hpp"
#include "theme.hpp"

Theme::Theme() {
	setColor(Index::TOP,          sf::Color::White);
	setColor(Index::TOP_LEFT,     sf::Color::Red);
	setColor(Index::TOP_RIGHT,    sf::Color::Blue);
	setColor(Index::BOTTOM_LEFT,  sf::Color::Green);
	setColor(Index::BOTTOM_RIGHT, sf::Color::Yellow);
	setColor(Index::BOTTOM,       sf::Color(90, 90, 90));

	setColor(Index::BACKGROUND,   sf::Color(255, 239, 201));
}

void Theme::setColor(Index which, const sf::Color& color) {
	mColors[int(which)] = color;
}

sf::Color& Theme::getColor(Index which) {
	return mColors[int(which)];
}

//void Theme::finalize() {
//	auto searchPoint = mColors.rend();
//	int otherIndex;
//	for (int i = 0; i < mColors.size(); i++) {
//		otherIndex = std::distance(std::find(mColors.rbegin(), searchPoint--, mColors[i]), mColors.rend() - 1);
//		if (otherIndex != -1) {
//			if (i != otherIndex or mColors[i] == mBackground) {
//				//mColors[i]
//			}
//		}
//	}
//}
