#include "pch.hpp"
#include "server.hpp"

Server::Server(int PORT, const sf::IpAddress& IP)
    : m_Port(PORT), m_IP(IP) {
    m_Listener.listen(PORT, IP);
    //m_Selector.add(m_Listener);
}

//PRIVATE
void Server::acceptConnection() {
    printf("New connection\n");
    SocketPtr connection = std::make_shared<sf::TcpSocket>();
    m_Listener.accept(*connection);
    //m_Selector.add(*connection);
    m_Connections.push_back(connection);

    sf::Packet data;
    int totalPlayers, gameId;
    if (connection->receive(data) == sf::Socket::Done) {
        data >> totalPlayers;
        data.clear();
        gameId = generateGameId(totalPlayers);
        if (gameId == -1) {
            // create new game
            gameId = m_GameMap.size();
            m_GameMap[gameId] = std::move(GameSelectorPackage(totalPlayers, gameId));
        }
        GameSelectorPackage* current = &m_GameMap[gameId];
        current->addPlayer();

        data << *current << (current->playerCount - 1);
        connection->send(data);
        data.clear();
    }
}

int Server::generateGameId(int playerCount) {
    // if game unready AND game count == count, return key of that game
    // else, return max_key++;
    for (auto& pair : m_GameMap) {
        if (pair.second.totalPlayers == playerCount and !pair.second.ready)
            return pair.first;
    }
    return -1;
}

//void Server::handleClients() {
//    for (SocketPtr conn : m_Connections) {
//        if (m_Selector.isReady(*conn)) {
//            // ASSUMING THAT DATA IS VALIDATED (ON CLIENT SIDE)
//            sf::Packet packet;
//            if (conn->receive(packet) == sf::Socket::Done) {
//                GameData data;
//                packet >> data;
//                GameData& current = m_GameMap[data.gameId];
//
//                if (data.msg == "get")
//                    send(conn, &packet, &current);
//                else if (data.msg == "update")
//                    current = std::move(data);
//            }
//        }
//    }
//}

void Server::send(SocketPtr who, sf::Packet* packet, GameData* data) {
    packet->clear();
        *packet << *data;
        who->send(*packet);
    packet->clear();
}

void Server::run() {
    //bool ho = false;
    //printf("Waiting for connections\n");
    //while (true) {
    //    if (ho and m_Connections.size() == 0)
    //        break;
    //    if (m_Selector.wait()) {
    //        if (m_Selector.isReady(m_Listener)) {
    //            ho = true;
    //            acceptConnection();
    //        }
    //        else
    //            handleClients();
    //    }
    //}
    printf("Server loop broken\n");
}

/*
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
