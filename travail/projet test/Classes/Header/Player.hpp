#pragma once

#include "FriendlyCharacter.hpp"
#include <algorithm>


class Player : public FriendlyCharacter
{
private:
	float _attackSpeed;
	sf::Clock _timeSinceLastAttack;

public:
	Player();

	void updatePhysics(const sf::Event& event);
	void update();

};

