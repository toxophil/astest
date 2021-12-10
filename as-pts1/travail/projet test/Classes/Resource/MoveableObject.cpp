
/* Generated from GenMyModel */

#include "../Header/MoveableObject.hpp"
#include "../Header/GameMaster.hpp"
#include <iostream>
using namespace std;

bool MoveableObject::moveObject(const sf::Vector2f& direction)
{

	Map laMap = GameMaster::getInstance().getMap();

	vector<Wall> lesWalls = laMap.getWallList();
    sf::FloatRect gBounds = _sprite.getGlobalBounds();


    sf::Vector2f pos = _sprite.getPosition();
	float x = pos.x + direction.x;
	float y = pos.y + direction.y;
    float jusquaX = x + gBounds.width;
    float jusquaY = y + gBounds.height;
    //cout << "LesWall nb : " << lesWalls.size() << endl;
    for (uint32_t l = 0; l < lesWalls.size(); l++) {
        float x2 = lesWalls[l].getX();
        float y2 = lesWalls[l].getY();
        uint32_t w2 = lesWalls[l].getW();
        uint32_t h2 = lesWalls[l].getH();

        float jusquaX2 = x2 + w2;
        float jusquaY2 = y2 + h2;
        if ((y < y2 && jusquaY >= y2) || (y >= y2 && y <= jusquaY2)) {
            if ((x < x2 && jusquaX >= x2) || (x >= x2 && x <= jusquaX2)) {
                //cout << "NOP " << lesWalls[l].getX() << endl;
                //_sprite.move(sf::Vector2f(x2, y2));//direction);
                onCollision();
                return false;
            }
        }
    }
	_sprite.move(direction);
	return true;
}

void MoveableObject::onCollision() {}