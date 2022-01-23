#pragma once

#ifndef DEF_MEDIUM
#define DEF_MEDIUM

#include "Ennemy.hpp"
class Medium : public Ennemy
{
private:
	bool _doAttack;
	float _attackSpeedModifier;
	sf::Clock _timeSinceLastAttack;
	int _attackCD = 200;


protected:
	sf::Clock _animTime;
	Animation _animIdle;
	Animation _animWalking;

public:
	Medium();

	void updatePhysics(sf::RenderWindow&, const sf::Event& event);
	void update();
	//int onCollision();


};

#endif
