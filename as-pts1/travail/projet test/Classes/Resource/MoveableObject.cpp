
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
  
    //positions du sprite de drawable object
    sf::Vector2f pos = _sprite.getPosition();
    // les bounds de la sprite de drawable object
    sf::FloatRect gBounds = _sprite.getGlobalBounds();

    //coordonnée des 4 points update + direction
	float x = pos.x + direction.x;
	float y = pos.y + direction.y;
    float jusquaX = x + gBounds.width;
    float jusquaY = y + gBounds.height;


    //liste des MoveableObject de gamemaster
     std::list<MoveableObject*> moveable = GameMaster::getInstance().getMoveableObjectList();

     float a1, b1, a2, b2;
     sf::FloatRect temp;
     bool detruit=true;
     uint32_t idtemp = _id;

     for (auto& object : moveable){
         temp = object->_sprite.getGlobalBounds(); //les bounds d'un de la liste des moveable
         if(object->_id == idtemp) {
            //si c'est le meme ojet on ne fait rien
         }   
         else{
            float a1 = temp.left;
            float b1 = temp.top;
            float a2 = a1 + temp.width;
            float b2 = b1 + temp.height;

             if ((y < b1 && jusquaY >= b1) || (y >= b1 && y <= b2)) {
                 if ((x < a1 && jusquaX >= a1) || (x >= a1 && x <= a2)){
                     if(object->_estEnnemi == _estEnnemi ) {
                         // check if allied ?
                     } 
                     else{
                        //update properties on hit
                        onTouche();            
                        //destruction du moveable si c'est une fleche
                        if (1 == onCollision())
                        {
                            //cout << "destruction" << endl;
                            //cout << "fleche touche " << idtemp << " is " << object->_id << endl;
                            return false();  
                            
                        }
                        
                     }
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
                //ne peut pas bouger
                //detruit si est projectile
                 
                if(onCollision() == 1)
                {
                    //cout << "detruit par mur" << endl;
                }
                else
                {
                   // cout << "ne peut pas bouger" << idtemp << " is " << endl;
                }
                
                
                return false;   
            }
        }
    }
//si on a pas encore quitté le pgm on peut bouger
_sprite.move(direction);
return true;
    
}

int MoveableObject::onCollision() {
    return 2;
}

void MoveableObject::onTouche()  {

}