
#ifndef DEF_MAP
#define DEF_MAP

#include <iostream>
using namespace std;

#include <vector>
#include "Room.hpp"
#include "Wall.hpp"
#include "Connection.hpp"

class Map {
private:
    vector<Room> _roomList;
    vector<Connection> _lesConnections;
    vector<Wall> _wallList;
public:
    Map();
    Map(vector<Room>, vector<Connection>, vector<Wall>);
    Map(vector<Room>, vector<Connection>);

    vector<Room> getRoomList() const;
    vector<Connection> getConnections() const;
    vector<Wall> getWallList() const;
    void addRoom(const Room&);
};


#endif
