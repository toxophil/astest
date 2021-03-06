
/* Generated from GenMyModel */

#include "..\Header\Arrow.hpp"
#include "..\Header\GameMaster.hpp"

Arrow::Arrow()
{
	sf::Vector2i direction(200, 0);
	sf::Vector2f directionF(direction);

	nextDirection = directionF;
	_damage = 1;
	_sprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Arrow));

}

Arrow::Arrow(const sf::Vector2i& launchDirection, double damage, const sf::Vector2f& startPosition) {
	_damage = damage;
	speed = 200;
	nextDirection = sf::Vector2f(launchDirection);
	_sprite.setPosition(startPosition);

	//calcul de la longeur du vecteur
	float vectorLength = std::sqrtf(std::powf((nextDirection.x), 2) + std::powf((nextDirection.y), 2));
	//normalisation du vecteur puis set ? la vitesse de la fl?che
	nextDirection.x = (nextDirection.x / vectorLength) * speed;
	nextDirection.y = (nextDirection.y / vectorLength) * speed;

	//set de la texture de la fleche
	_sprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Arrow));
}