#ifndef CONNECTION_H_INCLUDED
#define CONNECTION_H_INCLUDED

#include <iostream>
using namespace std;

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

class Room;
class Connection {
private:
    Room* _roomA;
    Room* _roomB;

    int64_t _x;
    int64_t _y;
    vector<vector<uint32_t>> _matrice;
    vector<sf::Sprite> _tiles;

    bool _estVertical;
public:
    Connection(int64_t, int64_t, Room*, Room*, bool, vector<vector<uint32_t>>);

    int64_t getX() const;
    int64_t getY() const;
    uint32_t getW() const;
    uint32_t getH() const;
    bool estVertical() const;

    vector<vector<uint32_t>> getMatrice() const;
    void modifyMatrice(int32_t, int32_t, uint32_t);

    void applyTiles();
    vector<sf::Sprite> getTiles() const;
};

#endif // CONNECTION_H_INCLUDED