
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

	//fonction de mise � jour de la physique de l'objet (d�placerment, tir, etc...)
	virtual void updatePhysics(const sf::Event &event);

	//fonction de d�placement de l'objet (retourne si le d�placement a �t� possible) - 
	bool moveObject(const sf::Vector2f& direction);
};


#endif
