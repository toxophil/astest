
/* Generated from GenMyModel */

#include "../Header/Weapon.hpp"
#include <iostream>
#include "../Header/Ennemy.hpp"
#include "../Header/GameMaster.hpp"
#include "..\Header\Sword.hpp"

Sword::Sword(Texture& laTexture) : Weapon(laTexture)
{
    _attackCd = 1.0f;
    _attackVitesse = 1.0f;
}

bool Sword::attackSword(HittableCharacter* lanceur, const sf::Vector2f& attackPoint){
    vector<Ennemy> res;
    std::list<MoveableObject*> moveable = GameMaster::getInstance().getMoveableObjectList();
    for (auto& object : moveable) {
        float ox = object->getSprite().getPosition().x;
        float oy = object->getSprite().getPosition().y;
        float lx = lanceur->getSprite().getPosition().x;
        float ly = lanceur->getSprite().getPosition().y;    //Rend le if qui suis *bien* plus lisible
        if (object->getType() == 2 && ox < lx + 20000 && ox > lx - 20000 && oy < ly + 20000 && oy > ly - 20000) {
            HittableCharacter* p = dynamic_cast<HittableCharacter*>(object);
            cout << p->getHealth() << endl;
            p->setHealth(p->getHealth() - _damage);
            cout << p->getHealth() << endl;
        }
    }
    return false;
}