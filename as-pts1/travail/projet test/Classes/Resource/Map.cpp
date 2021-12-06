
#include "..\Header\Map.hpp"
#include "..\Header\GameMaster.hpp"
#include <vector>

Map::Map() {}
Map::Map(vector<Room> roomList, vector<Connection> lesConnections, vector<Wall> wallList) {
    _roomList = roomList;
    _lesConnections = lesConnections;
    _wallList = wallList;
}
Map::Map(vector<Room> roomList, vector<Connection> lesConnections) {
    _roomList = roomList;
    _lesConnections = lesConnections;
}
vector<Room> Map::getRoomList() const {
    return _roomList;
}
vector<Connection> Map::getConnections() const {
    return _lesConnections;
}
vector<Wall> Map::getWallList() const {
    return _wallList;
}

void Map::addRoom(const Room& room) {
    _roomList.push_back(room);
}
