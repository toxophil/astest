
/* Generated from GenMyModel */

#ifndef DEF_ARROW
#define DEF_ARROW

#include "Projectile.hpp"

class Arrow : public Projectile
{

public:
	Arrow();

	Arrow(const sf::Vector2f& launchDirection, double damage, const sf::Vector2f& startPosition, float vitesse, float DureeVie);
};


#endif
