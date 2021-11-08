
/* Generated from GenMyModel */

#include "..\Header\Player.hpp"
#include "..\Header\GameMaster.hpp"

Player::Player()
{
	_sprite.setPosition(100, 100);
	nextDirection = sf::Vector2f(0, 0);
	speed = 100;

	//attack speed en secondes
	_attackSpeed = 1.5f;
	_timeSinceLastAttack.restart();
}

void Player::updatePhysics(const sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		//déplacement vers la gauche
		nextDirection += sf::Vector2f(-speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		//déplacement vers la droite
		nextDirection += sf::Vector2f(speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		//déplacement vers le haut
		nextDirection += sf::Vector2f(0, -speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		//déplacement vers le bas
		nextDirection += sf::Vector2f(0, speed);
	}

	//normalisation du vecteur de longeur speed
	nextDirection.x = std::min(nextDirection.x, speed);
	nextDirection.y = std::min(nextDirection.y, speed);

	//lancement de l'attaque uniquement si le cooldown d'attaque est à 0
	if (_timeSinceLastAttack.getElapsedTime().asSeconds() >= _attackSpeed) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			//attack
			getEquippedWeapon()->attack(this, sf::Mouse::getPosition());

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
