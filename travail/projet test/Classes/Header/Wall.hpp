#ifndef CORRIDOR_H_INCLUDED
#define CORRIDOR_H_INCLUDED


#include <iostream>
#include <SFML/System/Vector2.hpp>
using namespace std;

class Wall {
private:
    int64_t _x;
    int64_t _y;
    int64_t _w;
    int64_t _h;
public:
    Wall(int64_t, int64_t, int64_t, int64_t);

    int64_t getY() const;
    int64_t getX() const;
    int64_t getW() const;
    int64_t getH() const;
    //retourne l'angle haut gauche (HG), bas droit (BD) ... d'un mur
    sf::Vector2i getHG() const;
    sf::Vector2i getHD() const;
    sf::Vector2i getBG() const;
    sf::Vector2i getBD() const;
};


#endif // CORRIDOR_H_INCLUDED
