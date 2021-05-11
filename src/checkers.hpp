#include "pch.hpp"
#include "helpers.hpp"

class ChineseCheckers {
private:
	sf::RenderWindow* m_Window;
	int m_PlayerCount;
	int m_CurrentPlayer;
public:
	ChineseCheckers(sf::RenderWindow* window, int playerCount=2);
	~ChineseCheckers();
	void nextTurn();
private:
	void initiate();
};