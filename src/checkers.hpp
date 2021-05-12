#include "pch.hpp"
#include "helpers.hpp"
#include "slot.hpp"

class ChineseCheckers {
private:
	sf::RenderWindow* m_Window;
	sf::CircleShape m_Outline;
	
	int m_PlayerCount;
	int m_CurrentPlayer;
	Slot* m_Selected;

	std::vector<Slot> m_Slots;

public:
	ChineseCheckers(sf::RenderWindow* window, int playerCount=2);
	~ChineseCheckers();
	void nextTurn();
	void draw();
	void createBoard();
	Slot* find(float x, float y);

private:
	void initiate();
};