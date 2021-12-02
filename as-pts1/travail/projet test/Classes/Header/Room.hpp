
/* Generated from GenMyModel */

#ifndef DEF_ROOM
#define DEF_ROOM

#include <iostream>
using namespace std;

#include <vector>
#include "RoomObject.hpp"

class Connection;

class Room {
private:
    vector<vector<uint32_t>> _matrice;
    vector<sf::Sprite> _tiles;

    int64_t _x;
    int64_t _y;
    uint32_t _id;

    vector<RoomObject> _contained;
    vector<Connection*> _lesConnections;
public:
    Room();
    Room(uint32_t, vector<vector<uint32_t>>);
    vector<RoomObject> getContained() const;
    vector<vector<uint32_t>> getMatrice() const;

    int64_t getX() const;
    int64_t getY() const;
    uint32_t getW() const;
    uint32_t getH() const;

    uint32_t getID() const;

    void addContained(RoomObject&);
    void setX(int64_t);
    void setY(int64_t);

    uint32_t getNbConnection() const;
    void addConnection(Connection&);

    void modifyMatrice(int32_t, int32_t, uint32_t);
    void applyTiles();
    vector<sf::Sprite> getTiles() const;

};

#endif
