#include "pch.hpp"
#include "helpers.hpp"

class Slot : public sf::CircleShape {
private:
	sf::Color m_GoalColor;
	sf::CircleShape m_Overlay;
public:
	Slot(float x, float y, int row);
	bool clicked(float x, float y) const;
	void draw(sf::RenderWindow* win, sf::Transform* t) const;
	sf::Color& getGoalColor();
private:
	void config();
	void determineColor(int x, int y, int row);
};