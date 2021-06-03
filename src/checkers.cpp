#include "pch.hpp"
#include "checkers.hpp"

ChineseCheckers::ChineseCheckers(sf::RenderWindow* window, int playerCount, const sf::IpAddress& addr)
	: m_Window(window), m_PlayerCount(playerCount) 
{
	this->connect(addr, 3000);
}
