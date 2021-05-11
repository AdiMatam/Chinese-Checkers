#include "pch.hpp"
#include "checkers.hpp"

ChineseCheckers::ChineseCheckers(sf::RenderWindow* window, int playerCount) 
	: m_Window(window), m_PlayerCount(playerCount), m_CurrentPlayer(0)
{
	initiate();
}

ChineseCheckers::~ChineseCheckers() {
	std::cout << "Ending game" << std::endl;
}

void ChineseCheckers::nextTurn() {
	if (++m_CurrentPlayer >= m_PlayerCount)
		m_CurrentPlayer = 0;
}

void ChineseCheckers::initiate() {
	return;
}
