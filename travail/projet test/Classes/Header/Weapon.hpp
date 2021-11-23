
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
public:
	Weapon();

	float getAttackSpeed() const;

	//fonction qui utilise l'arme pour attaquer (retourne vrai si l'attaque est réussie)
	virtual bool attack(HittableCharacter* lanceur, const sf::Vector2i& attackPoint);
};


#endif
