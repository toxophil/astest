
#ifndef DEF_MAP
#define DEF_MAP

#include <iostream>
using namespace std;

#include <vector>
#include "Room.hpp"
#include "Wall.hpp"
#include "Connection.hpp"
#include "Node.hpp"

class Map {
private:
    vector<Room> _roomList;
    vector<Connection> _lesConnections;
    vector<Wall> _wallList;
    vector<Node> _nodeList;
    sf::Clock ee;

public:
    Map();
    Map(vector<Room>, vector<Connection>, vector<Wall>, vector<Node>);
    Map(vector<Room>, vector<Connection>);

    vector<Room> getRoomList() const;
    vector<Connection> getConnections() const;
    vector<Wall> getWallList() const;
    void addRoom(const Room&);

    int32_t getRoomByPos(sf::Vector2f) const;
    int32_t getConnectionByPos(sf::Vector2f) const;

    double Map::getDistance(sf::Vector2f posA, sf::Vector2f posB) const;
    uint32_t getNearestNode(sf::Vector2f pos) const;
      
    uint32_t Map::getRealNode(Node copyNode);
    vector<Node> getNodePathTo(vector<Node> nodePathList, Node toGo, vector<Node> alreadyCheckedNode);
    sf::Vector2f getNextNodePos(sf::Vector2f, sf::Vector2f);
};


#endif
