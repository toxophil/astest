#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED


#include <iostream>
#include <SFML/System/Vector2.hpp>
using namespace std;

class Wall {
private:
    int64_t _x;
    int64_t _y;
    uint32_t _w;
    uint32_t _h;
public:
    Wall(int64_t, int64_t, uint32_t, uint32_t);

    int64_t getY() const;
    int64_t getX() const;
    uint32_t getW() const;
    uint32_t getH() const;
    //retourne l'angle haut gauche (HG), bas droit (BD) ... d'un mur
    sf::Vector2i getHG() const;
    sf::Vector2i getHD() const;
    sf::Vector2i getBG() const;
    sf::Vector2i getBD() const;
};


#endif // WALL_H_INCLUDED
