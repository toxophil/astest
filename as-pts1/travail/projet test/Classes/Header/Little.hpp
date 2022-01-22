#pragma once

#ifndef DEF_LITTLE
#define DEF_LITTLE

#include "Ennemy.hpp"
class Little : public Ennemy
{
private:
	bool _doAttack;
	float _attackSpeedModifier;
	sf::Clock _timeSinceLastAttack;



protected:
	sf::Clock _animTime;
	Animation _animIdle;
	Animation _animWalking;

public:
	Little();

	void updatePhysics(sf::RenderWindow&, const sf::Event& event);
	void update();
	//int onCollision();


};

#endif
