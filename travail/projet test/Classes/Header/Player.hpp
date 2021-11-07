
/* Generated from GenMyModel */

#ifndef DEF_PLAYER
#define DEF_PLAYER

#include "FriendlyCharacter.hpp"
#include <algorithm>
#include "GameMaster.hpp"

class GameMaster;

class Player : public FriendlyCharacter
{

public:
	Player();

	void updatePhysics(const sf::Event& event);
	void update();

};


#endif
