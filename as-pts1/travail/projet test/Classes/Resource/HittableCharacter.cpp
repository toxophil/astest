
/* Generated from GenMyModel */

#include "../Header/HittableCharacter.hpp"
#include "Weapon.cpp"


HittableCharacter::HittableCharacter()
{
    _health = 10;
    _equippedWeapon = nullptr;
}

void HittableCharacter::setEquippedWeapon(Weapon* newWeapon)
{
    _equippedWeapon = newWeapon;
}

void HittableCharacter::setHealth(double health)
{
    _health = health;
}

void HittableCharacter::changeHealth(double modificateur)
{
    if (modificateur >= 0)
    {
        _health += modificateur;
    }
    else
    {
        _health -= modificateur;
    }
}

Weapon* HittableCharacter::getEquippedWeapon()
{
    return _equippedWeapon;
}

