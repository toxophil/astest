
/* Generated from GenMyModel */

#ifndef DEF_ENNEMY
#define DEF_ENNEMY

#include "HittableCharacter.hpp"

class Ennemy : public HittableCharacter
{
private:
	bool _doAttack;
	float _attackSpeedModifier;
	sf::Clock _timeSinceLastAttack;
protected:
	int _attackCD = 2000;
	bool _isSpotted = false;
	double euclideDist(sf::Vector2f, sf::Vector2f);
public:
	Ennemy();

	virtual void updatePhysics(sf::RenderWindow&, const sf::Event& event) = 0;
	virtual void update() = 0;

	bool isPlayerSpotted();
	int onCollision();
	void draw(sf::RenderWindow&);

};


#endif
