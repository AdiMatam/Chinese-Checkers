#include "pch.hpp"
#include "checkers.hpp"

CC::ChineseCheckers(sf::RenderWindow* window, int playerCount, const sf::IpAddress& addr)
	: m_Window(window)
{
	this->connect(addr, 3000);
	onConnect(playerCount);
}

//void CC::sendAndRecv(const std::string& msg) {
//	m_GameData.msg = msg;
//	m_Packet << m_GameData;
//	this->send(m_Packet);
//	m_Packet.clear();
//
//	if (this->receive(m_Packet) == sf::Socket::Done)
//		m_Packet >> m_GameData;
//	m_Packet.clear();
//}
