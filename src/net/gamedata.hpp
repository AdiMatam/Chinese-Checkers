#pragma once

#include "pch.hpp"
#include "helpers.hpp"

using SocketPtr = std::shared_ptr<sf::TcpSocket>;

struct GameData {
    //std::vector<SocketPtr> players;
    int playerCount;
    bool ready;
    int totalPlayers;
    int gameId;
    std::string msg;

    GameData();
    GameData(int count, int gameId);
    void addPlayer();
};

sf::Packet& operator <<(sf::Packet& packet, const GameData& character);

sf::Packet& operator >>(sf::Packet& packet, GameData& character);
