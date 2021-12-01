
/* Generated from GenMyModel */

#include "..\Header\Bow.hpp"
#include "..\Header\Arrow.hpp"
#include "..\Header\GameMaster.hpp"

bool Bow::attack(HittableCharacter* lanceur, const sf::Vector2i& attackPoint)
{
    //création du projectile et ajout de ce projectile dans la liste des objets du GameMaster
    sf::Vector2i lanceurPos = sf::Vector2i(lanceur->getSprite().getPosition());

    sf::Vector2i launchDirection = attackPoint - lanceurPos;

    auto myProjectile = new Arrow(launchDirection, 1, lanceur->getSprite().getPosition(), _attackSpeed, _attackDuration);

    GameMaster::getInstance().addMoveableObject(myProjectile);

    return true;
}
