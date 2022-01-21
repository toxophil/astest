#pragma once

#include "FriendlyCharacter.hpp"
#include <algorithm>
#include "Inventory.hpp"
#include "Classe.hpp"

class Player : public FriendlyCharacter
{
private:
	float _attackSpeedModifier;
	sf::Clock _timeSinceLastAttack;
	sf::Clock _animTime;
	Inventory* _inventory;
	Classe _laClasse;
	Animation anim;

	sf::Sprite _holdingWeapon;

public:
	Player();
	Player(Classe laClasse);

	void updatePhysics(sf::RenderWindow& ,const sf::Event& event);
	void update();
	Inventory* getInventory();
	sf::Vector2f getPos() const;

	void setPos(int, int);
};