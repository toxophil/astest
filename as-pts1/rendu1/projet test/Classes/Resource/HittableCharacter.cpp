
/* Generated from GenMyModel */

#include "..\Header\HittableCharacter.hpp"

HittableCharacter::HittableCharacter()
{
    _health = 10;
}

void HittableCharacter::setEquippedWeapon(Weapon* newWeapon)
{
    _equippedWeapon = newWeapon;
}


Weapon* HittableCharacter::getEquippedWeapon()
{
    return _equippedWeapon;
}

bool HittableCharacter::attack() const
{
    return false;
}