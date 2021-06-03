#pragma once

#include "pch.hpp"
#include "helpers.hpp"

class ChineseCheckers : public sf::TcpSocket {
public:
	ChineseCheckers(sf::RenderWindow*, int count, const sf::IpAddress& addr=sf::IpAddress::getLocalAddress());

private:
	sf::RenderWindow* m_Window;
	int m_PlayerCount;
	sf::Packet m_Data;

	void initConnection();
};

