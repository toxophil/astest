
/* Generated from GenMyModel */

#ifndef DEF_MOVEABLEOBJECT
#define DEF_MOVEABLEOBJECT

#include "DrawableObject.hpp"

class MoveableObject : public DrawableObject
{
private:

protected:
	sf::Vector2f nextDirection;
	//vitesse de l'objet
	float speed;
	bool _estEnnemi;

public:
	//fonction de misa a jour de la logique de l'objet
	virtual void update() = 0;

	//fonction de mise � jour de la physique de l'objet (d�placerment, tir, etc...)
	virtual void updatePhysics(sf::RenderWindow& ,const sf::Event &event) = 0;

	// Appell� � chaque collision
	virtual void onCollision();

	//fonction de d�placement de l'objet (retourne si le d�placement a �t� possible) - 
	bool moveObject(const sf::Vector2f& direction);
};


#endif
