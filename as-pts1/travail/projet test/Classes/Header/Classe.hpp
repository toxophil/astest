#pragma once


#include "Animation.hpp"
#include "Weapon.hpp"

class Classe
{
private:

	Animation _idleAnim;
	Animation _walkAnim;
	Weapon* _defWeapon;
	uint8_t _defLife;
	uint16_t _defSpeed;

public:
	Classe();
	Classe(Weapon*,Animation, Animation, uint8_t, uint16_t);

	Animation& getIdleAnim();
	Animation& getWalkAnim();
	Weapon* getDefaultWeapon() const;
	uint8_t getDefaultLife() const;
	uint16_t getDefaultSpeed() const;

};

