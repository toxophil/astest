
/* Generated from GenMyModel */

#include "../Header/Projectile.hpp"
#include "../Header/GameMaster.hpp"

Projectile::Projectile()
{
	sf::Vector2f directionF(200, 0);

	nextDirection = directionF;
	speed = 200;
	maxLifetime = 5;
	lifetime.restart();
	_estEnnemi	; // 0 joueur 1 ennemie 
	_type = 3;
}

Projectile::Projectile(const sf::Vector2i& launchDirection, double damage,int estEnnemi) {
	_estEnnemi = estEnnemi;
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
	std::list<MoveableObject*> moveable = GameMaster::getInstance().getMoveableObjectList();
	for (auto& object : moveable) {
		float ox = object->getSprite().getPosition().x;
		float oy = object->getSprite().getPosition().y;
		float lx = this->getSprite().getPosition().x;
		float ly = this->getSprite().getPosition().y;    //Rend le if qui suis *bien* plus lisible
		if (object->getType() == 2 && ox < lx + 10 && ox > lx - 10 && oy < ly + 10 && oy > ly - 10) {
			HittableCharacter* p = dynamic_cast<HittableCharacter*>(object);
			p->setHealth(p->getHealth() - _damage);
			GameMaster::getInstance().destroyMoveableObject(this->getId());
		}
	}
}
int Projectile::onCollision() {
		GameMaster::getInstance().destroyMoveableObject(getId());
		return false;
	//delete this;
}
/*bool Projectile::updateOnTouche()
{
	
}*/