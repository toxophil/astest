#ifndef DEF_WEAPON
#define DEF_WEAPON

#include "Item.hpp"
#include <SFML/Graphics.hpp>

class HittableCharacter;

class Weapon : public Item
{
protected:
	float _attackCd;
	float _attackVitesse;
	float _attackSpeed;
	float _attackDuration;
	float _projectileCooldown;
	int estEnnemie;
public:
	Weapon();
	Weapon(Texture& laTexture);

	float getAttackCd() const;
	float getAttackVitesse() const;
	float getAttackSpeed() const;
	float getAttackDuration() const;
	float getProjectileCooldown() const;
	
	//fonction qui utilise l'arme pour attaquer (retourne vrai si l'attaque est réussie)
	//virtual bool attack(HittableCharacter* lanceur, const sf::Vector2f& attackPoint);
	virtual bool attack(HittableCharacter* lanceur, const sf::Vector2f& attackPoint);
	void drawEquiped(sf::RenderWindow& window, sf::Vector2f laPosition, sf::FloatRect localBounds);
};


#endif