
/* Generated from GenMyModel */

#include "../Header/Projectile.hpp"
#include "../Header/GameMaster.hpp"

Projectile::Projectile()
{
	sf::Vector2f directionF(200, 0);

	nextDirection = directionF;
	_damage = 1;
	speed = 200;
	maxLifetime = 5;
	lifetime.restart();
	_estEnnemi	; // 0 joueur 1 ennemie 
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

	//destruction de l'objet si sa vie arrive à sa fin
	if (lifetime.getElapsedTime().asSeconds() >= maxLifetime) {
		GameMaster::getInstance().destroyMoveableObject(getId());
		delete this;
	}
}

void Projectile::updatePhysics(sf::RenderWindow& window,const sf::Event& event)
{
	//check de collision avec un autre hittable character ou un mur
}
int Projectile::onCollision() {
		GameMaster::getInstance().destroyMoveableObject(getId());
		return 1;
	//delete this;
}