
/* Generated from GenMyModel */

#ifndef DEF_WEAPON
#define DEF_WEAPON

#include "Item.hpp"
#include <SFML/Graphics.hpp>

class HittableCharacter;

class Weapon : public Item
{
	
public:
	//fonction qui utilise l'arme pour attaquer (retourne vrai si l'attaque est réussie)
	virtual bool attack(HittableCharacter* lanceur, const sf::Vector2i& attackPoint);
};


#endif
