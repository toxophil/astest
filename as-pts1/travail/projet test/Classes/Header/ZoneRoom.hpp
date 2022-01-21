#ifndef ZONEROOM_H_INCLUDED
#define ZONEROOM_H_INCLUDED

#include <iostream>
using namespace std;

#include <vector>
#include "Room.hpp"
#include "Connection.hpp"
#include "MapTheme.hpp"
#include "Node.hpp"

class ZoneRoom {
private:
    MapTheme _leTheme;
    int64_t _w;
    int64_t _h;
    vector<Room> _rooms;
    vector<Connection> _lesConnections;
    vector<Node> _lesNodes;
    vector<Wall> _walls;
public:
    ZoneRoom(Room&, MapTheme&);
    vector<Room> getRooms() const;


    uint32_t getW() const;
    uint32_t getH() const;

    void addRoom(Room&);
    void setW(uint32_t);
    void setH(uint32_t);

    vector<uint32_t> getTopFree() const;
    vector<uint32_t> getRightFree() const;
    vector<uint32_t> getBotFree() const;
    vector<uint32_t> getLeftFree() const;

    int64_t getMaxX() const;
    int64_t getMaxY() const;
    int64_t getMinX() const;
    int64_t getMinY() const;

    bool isFree(int64_t, int64_t, uint32_t, uint32_t) const;

    void addConnection(Connection&);
    vector<Connection> getConnections() const;

    void makeIntersection();
    void makeNodes();
    void makeTiles();
    void makeWalls();

    vector<Node> getNodes();
    vector<Wall> getWalls();
};

#endif // ZONEROOM_H_INCLUDED
