
#ifndef DEF_WEAPON
#define DEF_WEAPON

#include "Item.hpp"
#include <SFML/Graphics.hpp>

class HittableCharacter;

class Weapon : public Item
{
protected:
	float _damage;
	float _attackCd;
	float _attackVitesse;

public:
	Weapon(Texture& laTexture);
	virtual ~Weapon();
	float getDamage() const;
	float getAttackCd() const;
	float getAttackVitesse() const;
	
	//fonction qui utilise l'arme pour attaquer (retourne vrai si l'attaque est réussie)
	//virtual attack(HittableCharacter* lanceur, const sf::Vector2f& attackPoint);
	bool attack(HittableCharacter* lanceur, const sf::Vector2f& attackPoint);
	void drawEquiped(sf::RenderWindow& window, sf::Vector2f laPosition, sf::FloatRect localBounds);
};


#endif