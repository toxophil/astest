
/* Generated from GenMyModel */

#ifndef DEF_PROJECTILE
#define DEF_PROJECTILE

#include "MoveableObject.hpp"
#include <SFML/Graphics.hpp>

class Projectile : public MoveableObject
{
protected:
	double _damage;
	sf::Clock lifetime;
	float maxLifetime;

public:
	Projectile();

	Projectile(const sf::Vector2i& launchDirection, double damage);

	//fonction de misa a jour de la logique de l'objet
	virtual void update();

	//fonction de mise à jour de la physique de l'objet (déplacerment, tir, etc...)
	virtual void updatePhysics(const sf::Event& event);

};


#endif
