#pragma once

#include "pch.hpp"
#include "helpers.hpp"
#include "gamedata.hpp"

using SocketPtr = std::shared_ptr<sf::TcpSocket>;

class Server {
private:
    int m_Port;
    sf::IpAddress m_IP;

    sf::TcpListener m_Listener;
    sf::SocketSelector m_Selector;
    std::vector<SocketPtr> m_Connections;
    std::unordered_map<int, GameData> m_GameMap; //id -> game

    void acceptConnection();
    void communicate();
    int generateGameId(int count);
    void send(SocketPtr conn, sf::Packet* packet, GameData* data);

public:
    Server(int PORT, const sf::IpAddress& IP);
    void run();
};
