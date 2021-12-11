
/* Generated from GenMyModel */

#include "../Header/Bow.hpp"
#include "../Header/Arrow.hpp"
#include "../Header/GameMaster.hpp"

bool Bow::attack(HittableCharacter* lanceur, const sf::Vector2f& attackPoint)
{
    //cr�ation du projectile et ajout de ce projectile dans la liste des objets du GameMaster
    sf::Vector2f lanceurPos = sf::Vector2f(lanceur->getSprite().getPosition());

    sf::Vector2f launchDirection = attackPoint - lanceurPos;

    auto myProjectile = new Arrow(launchDirection, 1, lanceur->getSprite().getPosition(), _attackSpeed, _attackDuration);

    GameMaster::getInstance().addMoveableObject(myProjectile);

    return true;
}