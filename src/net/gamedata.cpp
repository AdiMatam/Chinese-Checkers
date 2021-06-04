#include "pch.hpp"
#include "gamedata.hpp"

GameData::GameData()
    : playerCount(0), ready(false), totalPlayers(0), gameId(0) {}

GameData::GameData(int count, int gameId)
    : playerCount(0), ready(false), totalPlayers(count), gameId(gameId) {}

void GameData::addPlayer() {
    playerCount++;
    if (playerCount == totalPlayers)
        ready = true;
}

sf::Packet& operator <<(sf::Packet& packet, const GameData& character) {
    return packet;
}

sf::Packet& operator >>(sf::Packet& packet, GameData& character) {
    return packet;
}

GameSelectorPackage::GameSelectorPackage(int count, int gameId)
    : GameData(count, gameId) {}
