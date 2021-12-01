
/* Generated from GenMyModel */

#include "..\Header\Weapon.hpp"

Weapon::Weapon()
{
    _attackSpeed = 1.0f;
    _attackDuration = 1.0f;
    _projectileVelocity = 1.0f;
}

float Weapon::getAttackSpeed() const
{
    return _attackSpeed;
}

bool Weapon::attack(HittableCharacter* lanceur, const sf::Vector2i& attackPoint)
{
    return false;
}
