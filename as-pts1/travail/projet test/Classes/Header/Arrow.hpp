
/* Generated from GenMyModel */

#ifndef DEF_ARROW
#define DEF_ARROW

#include "Projectile.hpp"

class Arrow : public Projectile
{

public:
	Arrow();
	Arrow(const sf::Vector2f& aimPos, const sf::Vector2f& initPos, double damage, float vitesse, int camp, float dureeVie);
	//Arrow(const sf::Vector2f& launchDirection, const sf::Vector2f& , double damage, float vitesse);
};


#endif
