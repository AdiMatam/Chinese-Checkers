#include "pch.hpp"
#include "helpers.hpp"

class Slot : public sf::CircleShape {
private:
	sf::Color m_GoalColor;
	sf::CircleShape m_Overlay;
public:
	Slot(float x, float y, int row);
	bool clicked(float x, float y) const;
private:
	void config();
};