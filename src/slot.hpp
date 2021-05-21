#include "pch.hpp"
#include "helpers.hpp"

class Slot : public sf::CircleShape {
private:
	sf::Color m_GoalColor;
	sf::CircleShape m_Overlay;
public:
	static sf::Color* s_PlayerColors;
	
	Slot(float x, float y, int row);
	bool clicked(float x, float y) const;
	void draw(sf::RenderWindow* win) const;
	sf::Color& getGoalColor();
	bool isMine(int currentPlayer, int totalPlayers);
	bool isEmpty();
	void pick();
	void unpick();
private:
	void config();
	void determineColor(int x, int y, int row);
};