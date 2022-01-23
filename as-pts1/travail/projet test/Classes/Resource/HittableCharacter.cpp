
/* Generated from GenMyModel */

#include "../Header/HittableCharacter.hpp"
#include "../Header/GameMaster.hpp"

HittableCharacter::HittableCharacter()
{
    _health = 10;
    _maxHealth = 10;
    _equippedWeapon1 = nullptr;
    _equippedWeapon2 = nullptr;
}

void HittableCharacter::setEquippedWeapon1(Weapon* newWeapon)
{
    _equippedWeapon1 = newWeapon;
}
void HittableCharacter::setEquippedWeapon2(Weapon* newWeapon)
{
    _equippedWeapon2 = newWeapon;
}

void HittableCharacter::setHealth(double health)
{
    _health = health;
}

double HittableCharacter::getHealth()
{
    return _health;
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

void HittableCharacter::addDamage(double dmg)
{
    if (dmg > _health) {
        _health = 0;
    }
    else {
        _health -= dmg;
    }
}
Weapon* HittableCharacter::getEquippedWeapon1()
{
    return HittableCharacter::_equippedWeapon1;
}
Weapon* HittableCharacter::getEquippedWeapon2()
{
    return HittableCharacter::_equippedWeapon2;
}


