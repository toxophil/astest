
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
	bool _side;
public:
	Weapon();

	float getAttackSpeed() const;
	float getAttackDuration() const;
	float getProjectileCooldown() const;
	void setSide(bool side);
	//fonction qui utilise l'arme pour attaquer (retourne vrai si l'attaque est réussie)
	virtual bool attack(HittableCharacter* lanceur, const sf::Vector2f& attackPoint);
};


#endif
