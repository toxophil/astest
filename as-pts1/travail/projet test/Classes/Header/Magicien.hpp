#pragma once

#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN

#include "Ennemy.hpp"
class Magicien : public Ennemy
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
	Magicien();

	void updatePhysics(sf::RenderWindow&, const sf::Event& event);
	void update();
	//int onCollision();


};

#endif
