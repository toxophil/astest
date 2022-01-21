
/* Generated from GenMyModel */

#include "../Header/Weapon.hpp"
#include <iostream>
#include "../Header/Ennemy.hpp"
#include "../Header/GameMaster.hpp"

Weapon::Weapon(Texture& laTexture) : Item(laTexture)
{
    _damage = 100.0f;
    _attackCd = 1.0f;
    _attackVitesse = 1.0f;
}

Weapon::~Weapon(){}


float Weapon::getAttackVitesse() const
{
    return _attackVitesse;
}

float Weapon::getAttackCd() const
{
    return _attackCd;
}

float Weapon::getDamage() const
{
    return _damage;
}


const float PI = 3.14159265359f;
bool Weapon::attack(HittableCharacter* lanceur, const sf::Vector2f& attackPoint)
{
    return false;
}
void Weapon::drawEquiped(sf::RenderWindow& window, sf::Vector2f laPosition, sf::FloatRect localBounds)
{
    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::Vector2u windowSize = window.getSize();

    laPosition.y = laPosition.y +localBounds.height / 4;
    laPosition.x = laPosition.x;//+ localBounds.width / 2;
    
    float xOffset = mousePosition.x - laPosition.x;
    float yOffset = mousePosition.y - laPosition.y;
    //cout << yOffset << endl;
    if (mousePosition.x > laPosition.x) {
        _leSprite.setScale(1.f, 1.f);
        xOffset = min(xOffset, 90.0f);
        xOffset = max(xOffset, 65.0f);
    }
    else {
        _leSprite.setScale(-1.f, 1.f);
        xOffset = max(xOffset, -90.0f);
        xOffset = min(xOffset, -65.0f);
    }

    if (mousePosition.y > laPosition.y) {
        yOffset = min(yOffset, 55.0f);
    }
    else {
        yOffset = max(yOffset, -55.0f);
    }

    xOffset = xOffset / 5;
    yOffset = yOffset / 10;

    //cout << ":::::::" << endl;
    laPosition.x += xOffset;
    laPosition.y += yOffset - 8;

    sf::FloatRect textureSize = _leSprite.getGlobalBounds();
    _leSprite.setOrigin(textureSize.width / 2, textureSize.height / 2);

    _leSprite.setPosition(laPosition);

    window.draw(_leSprite);
}