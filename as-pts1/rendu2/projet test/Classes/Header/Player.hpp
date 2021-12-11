#pragma once

#include "FriendlyCharacter.hpp"
#include <algorithm>


class Player : public FriendlyCharacter
{
private:
	float _attackSpeedModifier;
	sf::Clock _timeSinceLastAttack;

public:
	Player();

	void updatePhysics(sf::RenderWindow& ,const sf::Event& event);
	void update();

};

