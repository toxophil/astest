#pragma once

#ifndef DEF_BOSS
#define DEF_BOSS

#include "Ennemy.hpp"
class Boss : public Ennemy
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
	Boss();

	void updatePhysics(sf::RenderWindow&, const sf::Event& event);
	void update();
	//int onCollision();


};

#endif
