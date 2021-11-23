
/* Generated from GenMyModel */

#ifndef DEF_WALL
#define DEF_WALL

#include "SolidObject.hpp"

class Wall : public SolidObject
{
private :
	sf::Vector2f point1;
	sf::Vector2f point2;

public :
	Wall();
	Wall(sf::Vector2f p1, sf::Vector2f p2);
	sf::Vector2f getPoint1();
	sf::Vector2f getPoint2();
};


#endif
