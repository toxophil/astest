
#ifndef DEF_SWORD
#define DEF_SWORD

#include "Weapon.hpp"

class Sword : public Weapon
{
protected:
	float _attackCd;
	float _attackVitesse;

public:

	Sword(Texture& laTexture);
	//fonction qui utilise l'arme pour attaquer (retourne vrai si l'attaque est réussie)
	//virtual attack(HittableCharacter* lanceur, const sf::Vector2f& attackPoint);
	bool attackSword(HittableCharacter* lanceur, const sf::Vector2f& attackPoint);
};


#endif