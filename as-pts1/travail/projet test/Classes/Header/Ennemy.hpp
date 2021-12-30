
/* Generated from GenMyModel */

#ifndef DEF_ENNEMY
#define DEF_ENNEMY

#include "HittableCharacter.hpp"

class Ennemy : public HittableCharacter
{
private:
	float _attackSpeedModifier;
	sf::Clock _timeSinceLastAttack;

public:
	Ennemy();

	void updatePhysics(sf::RenderWindow&, const sf::Event& event);
	void update();
	int onCollision();


};


#endif
