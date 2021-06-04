#include "pch.hpp"
#include "checkers.hpp"

void ChineseCheckers::onConnect(int playerCount) {
	m_Packet << playerCount;
	this->send(m_Packet);
	m_Packet.clear();
	if (this->receive(m_Packet) == sf::Socket::Done)
		m_Packet >> m_GameData >> m_PlayerId;
	m_Packet.clear();
}

