
/* Generated from GenMyModel */

#ifndef DEF_BOW
#define DEF_BOW

#include "Weapon.hpp"
#include <SFML/Graphics.hpp>

class HittableCharacter;

class Bow : public Weapon
{
public:
	Bow(Texture& laTexture);
	bool attack(HittableCharacter* lanceur, const sf::Vector2f& attackPoint);
};


#endif
