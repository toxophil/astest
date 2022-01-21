
/* Generated from GenMyModel */

#ifndef DEF_HITTABLECHARACTER
#define DEF_HITTABLECHARACTER

#include "MoveableObject.hpp"
#include "Weapon.hpp"

class HittableCharacter : public MoveableObject
{
private :
	double _health;
	Weapon* _equippedWeapon1;
	Weapon* _equippedWeapon2;

public:
	HittableCharacter();

	//setter
	void setEquippedWeapon1(Weapon* newWeapon);
	void setEquippedWeapon2(Weapon* newWeapon);
	void setHealth(double health);
	double getHealth();
	void HittableCharacter::changeHealth(double modificateur);
	//mise a jour des proprietes de l'objet apres collisions
	bool updateOnTouche(DrawableObject* obj);

	//getter
	Weapon* getEquippedWeapon1();
	Weapon* getEquippedWeapon2();
};


#endif
