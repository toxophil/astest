
/* Generated from GenMyModel */

#ifndef DEF_HITTABLECHARACTER
#define DEF_HITTABLECHARACTER

#include "MoveableObject.hpp"
#include "Weapon.hpp"

class HittableCharacter : public MoveableObject
{
private :
	double _health;
	Weapon* _equippedWeapon;
		
public:
	HittableCharacter();

	//setter
	void setEquippedWeapon(Weapon* newWeapon);

	//getter
	Weapon* getEquippedWeapon();
	
	//fonction qui attaque en utilisant l'arme �quip�e (retourne vrai si l'attaque est r�ussie)
	bool attack() const;
};


#endif
