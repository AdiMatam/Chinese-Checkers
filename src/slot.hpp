#include "pch.hpp"
#include "helpers.hpp"

class Slot : public sf::CircleShape {
private:
	sf::Color m_GoalColor;
	int m_Owner;
public:
	Slot(float x, float y, int owner);
	bool clicked(float x, float y) const;
private:
	void config();
};