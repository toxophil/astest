
/* Generated from GenMyModel */

#include "../Header/Ennemy.hpp"
#include "../Header/GameMaster.hpp"
#include "../Header/Weapon.hpp"

Ennemy::Ennemy()
{
	_type = 2;
	_estEnnemi=1;
	_sprite.setPosition(80, 80);
	nextDirection = sf::Vector2f(0, 0);
	speed = 200;
	_pvMonstre = 200;
	//modifier de l'attack speed en pourcentage
	_attackSpeedModifier = 100.0f;
	_timeSinceLastAttack.restart();
}

void Ennemy::updatePhysics(sf::RenderWindow& window, const sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		//d�placement vers la gauche
		nextDirection += sf::Vector2f(-speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		//d�placement vers la droite
		nextDirection += sf::Vector2f(speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		//d�placement vers le haut
		nextDirection += sf::Vector2f(0, -speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		//d�placement vers le bas
		nextDirection += sf::Vector2f(0, speed);
	}


	//normalisation du vecteur de longeur speed
	nextDirection.x = std::min(nextDirection.x, speed);
	nextDirection.y = std::min(nextDirection.y, speed);

	//lancement de l'attaque uniquement si le cooldown d'attaque est � 0
	if (_timeSinceLastAttack.getElapsedTime().asSeconds() >= getEquippedWeapon1()->getAttackCd() * (_attackSpeedModifier / 100)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			const sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			getEquippedWeapon1()->attack(this, mousePosition);

			//reset du temps depuis la derniere attaque
			_timeSinceLastAttack.restart();
		}
	}
	if (getHealth() <= 0) {
		GameMaster::getInstance().destroyMoveableObject(this->getId());
	}
}

void Ennemy::update() {
	//TODO
	moveObject(nextDirection * GameMaster::getInstance().getTimeSinceLastUpdate().asSeconds());
	nextDirection = sf::Vector2f(0, 0);
}

int Ennemy::onCollision()
{
	return 2;
}
