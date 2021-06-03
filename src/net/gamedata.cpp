#include "pch.hpp"
#include "gamedata.hpp"

GameData::GameData(int count, int gameId)
    : ready(false), playerCount(count), gameId(gameId) {}

void GameData::addPlayer(SocketPtr conn) {
    players.push_back(conn);
    if (players.size() == playerCount)
        ready = true;
}

sf::Packet& operator <<(sf::Packet& packet, const GameData& character) {
    return packet;
}

sf::Packet& operator >>(sf::Packet& packet, GameData& character) {
    return packet;
}