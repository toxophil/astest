
/* Generated from GenMyModel */

#include "../Header/MoveableObject.hpp"
#include "../Header/GameMaster.hpp"
#include <iostream>

using namespace std;


void MoveableObject::updateAffichagePv()
{

    _pvText.setPosition(_sprite.getPosition().x, _sprite.getPosition().y);
    _pvText.setString(to_string((int)_pvMonstre));

    // on met a jour la taille
    _restant.setSize(sf::Vector2f(_pvMonstre/10, _pvHauteur));
    _max.setSize(sf::Vector2f(_pvLargeur/10, _pvHauteur));
    //la couleur - pourra etre mis en initialisation
    _restant.setFillColor(sf::Color::Green);
    _max.setFillColor(sf::Color::Red);
    //on met la position
    _restant.setPosition(_sprite.getPosition().x + 10, _sprite.getPosition().y - 4);
    _max.setPosition(_sprite.getPosition().x + 10, _sprite.getPosition().y - 4);
}


sf::Text MoveableObject::getPvText()
{
    return _pvText;
}

sf::RectangleShape MoveableObject::getRestant()
{
    return _restant;
}

sf::RectangleShape MoveableObject::getMax()
{
    return _max;
}

int MoveableObject::onCollision() {
    return 0;
}

bool MoveableObject::updateOnTouche(MoveableObject *obj) {
    /*bullshit*/
    _nbVie = _nbVie - _degat; 
    _nbPiece++; 
    /**/
    //fleche - fleche   fleche sera abimé 
    //fleche - move     fleche detruit move abimé
    //move - fleche     move abimé fleche detruit
    // attention ce dernier cas se presente comme un doublon
    // en effet chaque move sera checké 1 fois si l'on modifie le obj à cette endroit on risque de 
    // modifier 2 fois chaque move en collision
    // pour éviter ce problème on ne modifie pas les obj directement
    //move - move       move abimé - move abimé corp à corp passif
    if (_type == 3 && obj->_type == 3)
    {
        _pvMonstre -= obj->_degat;
        obj->_pvMonstre -= _pvMonstre;
        if (_pvMonstre <= 0)
        {
            GameMaster::getInstance().destroyMoveableObject(getId());
            return false;
        }
        if (obj->_pvMonstre <= 0)
        {
            GameMaster::getInstance().destroyMoveableObject(obj->getId());
        }
    }

    if (_type == 3 && (obj->_type == 1 || obj->_type == 2))
    {
        obj->_pvMonstre -= _degat;
        if (obj->_pvMonstre <= 0)
        {
            GameMaster::getInstance().destroyMoveableObject(obj->getId());
        }
        GameMaster::getInstance().destroyMoveableObject(getId());
        return false;
    }

    if ( (_type == 1 || _type == 2 )&& obj->_type == 3)
    {
        _pvMonstre -= obj->_degat;
        if (_pvMonstre <= 0)
        {
            GameMaster::getInstance().destroyMoveableObject(getId());
            return false;
        }
        GameMaster::getInstance().destroyMoveableObject(obj->getId());
    }

    if (_type == 1 || _type == 2 && _type == 1 || _type == 2)
    {

    }
    //_nbVie = _nbVie - _degat;
    //_nbPiece++;
    return true;
}


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
                     if(object->_estEnnemi != _estEnnemi ) {
                        //update stats 1
                        //update stats 2
                        //check 1 alive 
                        //check 2 alive
                        //si check 1 dead 
                         if (object->_type == 1)
                         {   
                             //player
                             //1 update things
                             //2 check if it should be dead
                             if (!updateOnTouche(object))
                             {
                                 return false;
                             }
                         }
                        if (object->_type == 2)
                        {
                            if (!updateOnTouche(object))
                            {
                                return false;
                            }
                        }
                        if (object->_type == 3)
                        {
                            if (!updateOnTouche(object))
                            {
                                return false;
                            }
                            cout << "type 3 :";
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

        if ((y < y2 && jusquaY >= y2) || (y >= y2 && y <= jusquaY2)) {
            if ((x < x2 && jusquaX >= x2) || (x >= x2 && x <= jusquaX2)) {
                //detruit si est projectile
                if(_type == 3) //si collision retourne 1 c'est que c'est un projectile
                {
                    GameMaster::getInstance().destroyMoveableObject(getId());
                } 
                return false;   
            }
        }
     }//update coord
_sprite.move(direction);
//update barre pv
updateAffichagePv();
return true;
    
}



