#pragma once

#include "pch.hpp"
#include "helpers.hpp"

using SocketPtr = std::shared_ptr<sf::TcpSocket>;

struct GameData {
    std::vector<SocketPtr> players;
    bool ready;
    int playerCount;
    int gameId;

    GameData(int count, int gameId);
    void addPlayer(SocketPtr conn);
};

sf::Packet& operator <<(sf::Packet& packet, const GameData& character); {
    return packet;
}

sf::Packet& operator >>(sf::Packet& packet, GameData& character); {
    return packet;
}