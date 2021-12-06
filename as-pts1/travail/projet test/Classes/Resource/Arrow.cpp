
/* Generated from GenMyModel */

#include "..\Header\Arrow.hpp"
#include "..\Header\GameMaster.hpp"

Arrow::Arrow()
{
	sf::Vector2f directionF(200, 0);

	nextDirection = directionF;
	_damage = 1;
	_sprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Arrow));

}

Arrow::Arrow(const sf::Vector2f& launchDirection, double damage, const sf::Vector2f& startPosition,float vitesse,float dureeVie) {
	_damage = damage;
	speed = vitesse;
	nextDirection = sf::Vector2f(launchDirection);
	_sprite.setPosition(startPosition);

	//calcul de la longeur du vecteur
	float vectorLength = std::sqrtf(std::powf((nextDirection.x), 2) + std::powf((nextDirection.y), 2));
	//normalisation du vecteur puis set à la vitesse de la flèche
	nextDirection.x = (nextDirection.x / vectorLength) * speed;
	nextDirection.y = (nextDirection.y / vectorLength) * speed;

	//set de la texture de la fleche
	_sprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Arrow));
}