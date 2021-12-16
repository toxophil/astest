
/* Generated from GenMyModel */

#include "../Header/MoveableObject.hpp"
#include "../Header/GameMaster.hpp"
#include <iostream>

using namespace std;

//check des collisions
bool MoveableObject::moveObject(const sf::Vector2f& direction)
{
    //map de gamemaster puis walls de la map de gamemaster  
	Map laMap = GameMaster::getInstance().getMap();
	vector<Wall> lesWalls = laMap.getWallList();

    // les bounds de la sprite de drawable object
    sf::FloatRect gBounds = _sprite.getGlobalBounds();    
    
    //positions du sprite de drawable object
    sf::Vector2f pos = _sprite.getPosition();

    //coordonnée des 4 points update + direction
	float x = pos.x + direction.x;
	float y = pos.y + direction.y;
    float jusquaX = x + gBounds.width;
    float jusquaY = y + gBounds.height;
    ////cout << "LesWall nb : " << lesWalls.size() << endl;
    
     //liste MoveableObject de gamemaster
 std::list<MoveableObject*> moveable = GameMaster::getInstance().getMoveableObjectList();
    //ces acteurs ne sont pas des static objets comme les murs
    //on recup les projectiles & les players et les ennemies

 float a1, b1, a2, b2;
 sf::FloatRect temp;

     for (auto& object : moveable) 
     {
         if(object->_id == _id )
         { }
         else
         {
             temp = object->_sprite.getGlobalBounds();
             float a1 = pos.x;
             float b1 = pos.y;
             float a2 = a1 + temp.width;
             float b2 = b1 + temp.height;

             if ((y < b1 && jusquaY >= b1) || (y >= b1 && y <= b2)) {
                 if ((x < a1 && jusquaX >= a1) || (x >= a1 && x <= a2)) {
                     //onTouche(); 
                    // cout << "touche "<< _id <<" is "<< object->_id << endl;
                 }
             }
         }
     }
    for (uint32_t l = 0; l < lesWalls.size(); l++) {
        //calculs des coordonnées des 4 coins tout les murs
        float x2 = lesWalls[l].getX();
        float y2 = lesWalls[l].getY();
        uint32_t w2 = lesWalls[l].getW();
        uint32_t h2 = lesWalls[l].getH();
        float jusquaX2 = x2 + w2;
        float jusquaY2 = y2 + h2;
        //test pour moveable object type projectile appel oncollision de joueur & projectile 
        //-> pour detruire projectile & enlever les pvs

        if ((y < y2 && jusquaY >= y2) || (y >= y2 && y <= jusquaY2)) {
            if ((x < x2 && jusquaX >= x2) || (x >= x2 && x <= jusquaX2)) {
                
                //cout << "NOP " << lesWalls[l].getX() << endl;
                //_sprite.move(sf::Vector2f(x2, y2));//direction);
                
                //lancement evenement collision
                onCollision();
                //ne peut pas bouger
                return false;
            }
        }
    }
	_sprite.move(direction);
	return true;
}

void MoveableObject::onCollision() {}