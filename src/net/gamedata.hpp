#pragma once

#include "pch.hpp"
#include "helpers.hpp"

struct GameData {
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

struct GameSelectorPackage : public GameData {
    sf::SocketSelector clients;
    GameSelectorPackage() = default;
    GameSelectorPackage(int count, int gameId);
};
