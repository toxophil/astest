#pragma once

#include "FriendlyCharacter.hpp"
#include <algorithm>
#include "Inventory.hpp"
#include "Skill.hpp"
#include "Classe.hpp"

class Player : public FriendlyCharacter
{
private:
	float _attackSpeedModifier;
	sf::Clock _timeSinceLastAttack;
	sf::Clock _animTime;

	sf::Clock _skill0;
	sf::Clock _skill1;
	sf::Clock _skill2;

	Inventory* _inventory;
	Classe _laClasse;
	Animation anim;
	sf::Sprite _holdingWeapon;

	//tableau des compétences affiliées
	vector<Skill> playerSkills;

	void obtainSkill();
	void useFirstSkill();
	void useSecondSkill();
	void useThirdSkill();
	void useSkill();
	void showSkills();

public:
	Player();
	Player(Classe laClasse);

	void updatePhysics(sf::RenderWindow& ,const sf::Event& event);
	void update();
	Inventory* getInventory();
	sf::Vector2f getPos() const;

	void setPos(int, int);
};