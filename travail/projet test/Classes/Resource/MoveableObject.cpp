
/* Generated from GenMyModel */

#include "..\Header\MoveableObject.hpp"


bool MoveableObject::moveObject(const sf::Vector2f& direction)
{
	//TODO � peaufiner et ajouter les collisions

	_sprite.move(direction);

	return false;
}

