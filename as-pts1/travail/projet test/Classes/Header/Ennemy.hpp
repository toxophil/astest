
/* Generated from GenMyModel */

#ifndef DEF_ENNEMY
#define DEF_ENNEMY

#include "HittableCharacter.hpp"

class Ennemy : public HittableCharacter
{
private:
	uint32_t _spotRange;
	bool _doAttack;
	float _attackSpeedModifier;
	sf::Clock _timeSinceLastAttack;

public:
	Ennemy();

	virtual void updatePhysics(sf::RenderWindow&, const sf::Event& event) = 0;
	virtual void update() = 0;

	bool isPlayerSpotted();
	int onCollision();
	void draw(sf::RenderWindow&);

};


#endif
