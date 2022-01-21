
/* Generated from GenMyModel */

#include "../Header/Bow.hpp"
#include "../Header/Arrow.hpp"
#include "../Header/GameMaster.hpp"

Bow::Bow(Texture& laTexture) : Weapon(laTexture) {
    _attackCd = 1.0f;
    _attackVitesse = 600.0f;
}

bool Bow::attack(HittableCharacter* lanceur, const sf::Vector2f& attackPoint)
{
    cout << "ATTACK BOW" << endl;
    //création du projectile et ajout de ce projectile dans la liste des objets du GameMaster
    sf::Vector2f lanceurPos = sf::Vector2f(lanceur->getSprite().getPosition());
    sf::Vector2f launchDirection = attackPoint - lanceurPos;
    auto myProjectile = new Arrow(launchDirection, _leSprite.getPosition(), 10, _attackVitesse);
    GameMaster::getInstance().addMoveableObject(myProjectile);
    return true;
}
