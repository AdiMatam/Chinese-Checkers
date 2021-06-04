#pragma once

#include "pch.hpp"
#include "helpers.hpp"
#include "net/gamedata.hpp"

class ChineseCheckers : public sf::TcpSocket {
public:
	ChineseCheckers(sf::RenderWindow*, int playerCount, const sf::IpAddress& addr=sf::IpAddress::getLocalAddress());
	//void sendAndRecv(const std::string& msg);
private:
	sf::RenderWindow* m_Window;
	sf::Packet m_Packet;
	GameData m_GameData;
	int m_PlayerId;

	void onConnect(int);
};

using CC = ChineseCheckers;