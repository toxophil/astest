
/* Generated from GenMyModel */

#include "../Header/Player.hpp"
#include "../Header/GameMaster.hpp"
#include "../Header/Weapon.hpp"

Player::Player()
{
	_estEnnemi = 0;
	_sprite.setPosition(100, 100);
	nextDirection = sf::Vector2f(0, 0);
	speed = 200;

	//modifier de l'attack speed en pourcentage
	_attackSpeedModifier = 100.0f;
	_timeSinceLastAttack.restart();
}

void Player::updatePhysics(sf::RenderWindow& window,const sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		//d�placement vers la gauche
		nextDirection += sf::Vector2f(-speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		//d�placement vers la droite
		nextDirection += sf::Vector2f(speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		//d�placement vers le haut
		nextDirection += sf::Vector2f(0, -speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		//d�placement vers le bas
		nextDirection += sf::Vector2f(0, speed);
	}


	//normalisation du vecteur de longeur speed
	nextDirection.x = std::min(nextDirection.x, speed);
	nextDirection.y = std::min(nextDirection.y, speed);

	//lancement de l'attaque uniquement si le cooldown d'attaque est � 0
	if (_timeSinceLastAttack.getElapsedTime().asSeconds() >= getEquippedWeapon()->getProjectileCooldown()  * (_attackSpeedModifier / 100)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

			const sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			getEquippedWeapon()->attack(this, mousePosition);

			//reset du temps depuis la derniere attaque
			_timeSinceLastAttack.restart();
		}
	}
}

void Player::update() {
	//TODO
	moveObject(nextDirection * GameMaster::getInstance().getTimeSinceLastUpdate().asSeconds());
	nextDirection = sf::Vector2f(0, 0);
}
