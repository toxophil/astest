
/* Generated from GenMyModel */

#include "..\Header\MoveableObject.hpp"

void MoveableObject::update(){}

void MoveableObject::updatePhysics(const sf::Event& event){}

bool MoveableObject::moveObject(const sf::Vector2f& direction)
{
	//TODO à peaufiner et ajouter les collisions

	_sprite.move(direction);

	return false;
}

