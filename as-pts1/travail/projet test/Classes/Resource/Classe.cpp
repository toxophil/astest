#include "../Header/Classe.hpp"
#include "../Header/GameMaster.hpp"

Classe::Classe() {
	_defLife = 2;
	_defSpeed = 100;
}
Classe::Classe(Weapon* defWeapon, Animation idleAnim, Animation walkAnim, uint8_t defLife, uint16_t defSpeed) {
	_idleAnim = idleAnim;
	_walkAnim = walkAnim;
	_defWeapon = defWeapon;
	_defLife = defLife;
	_defSpeed = defSpeed;
}

Animation& Classe::getIdleAnim() {
	return _idleAnim;
}
Animation& Classe::getWalkAnim() {
	return _walkAnim;
}
Weapon* Classe::getDefaultWeapon() const {
	return _defWeapon;
}

uint8_t Classe::getDefaultLife() const {
	return _defLife;
}

uint16_t Classe::getDefaultSpeed() const {
	return _defSpeed;
}