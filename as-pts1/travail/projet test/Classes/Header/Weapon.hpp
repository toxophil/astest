
/* Generated from GenMyModel */

#ifndef DEF_WEAPON
#define DEF_WEAPON

#include "Item.hpp"
#include <SFML/Graphics.hpp>

class HittableCharacter;

class Weapon : public Item
{
protected:
	float _attackSpeed;
	float _attackDuration;
	float _projectileCooldown;

public:
	Weapon();

	float getAttackSpeed() const;
	float getAttackDuration() const;
	float getProjectileCooldown() const;
	
	//fonction qui utilise l'arme pour attaquer (retourne vrai si l'attaque est réussie)
	virtual bool attack(HittableCharacter* lanceur, const sf::Vector2i& attackPoint);
};


#endif
