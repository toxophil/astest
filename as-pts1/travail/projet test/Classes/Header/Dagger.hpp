
/* Generated from GenMyModel */

#ifndef DEF_DAGGER
#define DEF_DAGGER

#include "Weapon.hpp"
#include <SFML/Graphics.hpp>

class Dagger : public Weapon
{
public:
	virtual bool attack(HittableCharacter* lanceur, const sf::Vector2i& attackPoint) override;

};


#endif
