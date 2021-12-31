
/* Generated from GenMyModel */

#ifndef DEF_SWORD
#define DEF_SWORD

#include "Weapon.hpp"

class Sword : public Weapon
{
public:
	Sword(Texture& laTexture);
	bool attack(HittableCharacter* lanceur, const sf::Vector2f& attackPoint) override;

};


#endif
