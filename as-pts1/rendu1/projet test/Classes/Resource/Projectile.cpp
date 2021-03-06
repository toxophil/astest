
/* Generated from GenMyModel */

#include "..\Header\Projectile.hpp"
#include "..\Header\GameMaster.hpp"

Projectile::Projectile()
{
	sf::Vector2i direction(200, 0);
	sf::Vector2f directionF(direction);

	nextDirection = directionF;
	_damage = 1;
	speed = 200;
	maxLifetime = 5;
	lifetime.restart();
}

Projectile::Projectile(const sf::Vector2i& launchDirection, double damage) {
	_damage = damage;
	speed = 200;
	maxLifetime = 5;
	nextDirection = sf::Vector2f(launchDirection);
	float vectorLength = std::sqrtf(std::powf((nextDirection.x), 2) + std::powf((nextDirection.y),2));
	nextDirection.x = (nextDirection.x / vectorLength) * speed;
	nextDirection.y = (nextDirection.y / vectorLength) * speed;
}

void Projectile::update()
{
	moveObject(nextDirection * GameMaster::getInstance().getTimeSinceLastUpdate().asSeconds());

	//destruction de l'objet si sa vie arrive ? sa fin
	if (lifetime.getElapsedTime().asSeconds() >= maxLifetime) {
		GameMaster::getInstance().destroyMoveableObject(getId());
		delete this;
	}
}

void Projectile::updatePhysics(const sf::Event& event)
{
	//check de collision avec un autre hittable character
}


