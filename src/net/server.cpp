#include "pch.hpp"
#include "server.hpp"

Server::Server(int PORT, const sf::IpAddress& IP)
    : m_Port(PORT), m_IP(IP) {
    m_Listener.listen(PORT, IP);
    m_Selector.add(m_Listener);
}

//PRIVATE
void Server::acceptConnection() {
    printf("New connection\n");
    SocketPtr connection = std::make_shared<sf::TcpSocket>();
    m_Listener.accept(*connection);
    m_Selector.add(*connection);
    m_Connections.push_back(connection);

    sf::Packet data;
    int playerCount, gameId;
    if (connection->receive(data) == sf::Socket::Done) {
        data >> playerCount;
        data.clear();
        gameId = generateGameId(playerCount);
        if (gameId == -1) {
            gameId = m_GameMap.size();
            m_GameMap[gameId] = std::move(GameData(playerCount, gameId));
        }
        GameData* current = &m_GameMap[gameId];
        current->addPlayer(connection);
        data << *current << (current->players.size() - 1);
        data.clear();
    }
}

int Server::generateGameId(int playerCount) {
    // if game unready AND game count == count, return key of that game
    // else, return max_key++;
    for (auto& pair : m_GameMap) {
        if (pair.second.playerCount == playerCount and !pair.second.ready)
            return pair.first;
    }
    return -1;
}

//int Server::gameAmountByPlayerCount(int playerCount) {
//    int count = 0;
//    for (auto& pair : m_GameMap) {
//        if (pair.second.playerCount == playerCount)
//            count++;
//    }
//    return count;
//}

void Server::broadcast() {
    /*
    for (SocketPtr recvr : m_Clients) {
        if (m_Selector.isReady(*recvr)) {
            sf::Packet data;
            if (std::find(m_Dead.begin(), m_Dead.end(), recvr) != m_Dead.end())
                continue;
            if (recvr->receive(data) == sf::Socket::Done) {

                //SampleObject obj;
                //data >> obj;
                //printf("%s\n", obj.str().c_str());

                //for (SocketPtr sender : m_Clients) {
                //    if (sender == recvr) continue;
                //    sender->send(data);
                //}
                data.clear();
            }
            else if (recvr->receive(data) == sf::Socket::Disconnected) {
                std::cout << recvr << "\n";
                recvr->disconnect();
                m_Dead.push_back(recvr);
            }
        }
    }
    */
}

void Server::run() {
    bool go = true;
    printf("Waiting for connections\n");
    while (go) {
        if (m_Selector.wait()) {
            if (m_Selector.isReady(m_Listener))
                acceptConnection();
            else
                broadcast();
        }
    }
    printf("Server loop broken\n");
}

