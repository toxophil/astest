
/* Generated from GenMyModel */

#ifndef DEF_MOVEABLEOBJECT
#define DEF_MOVEABLEOBJECT

#include "DrawableObject.hpp"

class MoveableObject : public DrawableObject
{
private:

public:
	//fonction de misa a jour de la logique de l'objet
	virtual void update();

	//fonction de mise à jour de la physique de l'objet (déplacerment, tir, etc...)
	virtual void updatePhysics(const sf::Event &event);

	//fonction de déplacement de l'objet (retourne si le déplacement a été possible) - 
	bool moveObject(const sf::Vector2f& direction);
};


#endif
