
/* Generated from GenMyModel */

#include "../Header/Arrow.hpp"
#include "../Header/GameMaster.hpp"

Arrow::Arrow()
{
	sf::Vector2f directionF(200, 0);

	nextDirection = directionF;
	_damage = 1;
	_sprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Arrow));

}

Arrow::Arrow(const sf::Vector2f& launchPos, double damage, const sf::Vector2f& startPosition,float vitesse,float dureeVie,bool side) {
	//set de la texture de la fleche
	_sprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Arrow));
	_damage = damage;
	speed = vitesse/2;
	nextDirection = sf::Vector2f(launchPos);
	_estEnnemi = side;
	sf::FloatRect localBounds = _sprite.getGlobalBounds();

	// Set la pos
	_sprite.setOrigin(localBounds.width/2, localBounds.height/2);
	_sprite.setPosition(startPosition);
	const float PI = 3.14159265359f;
	sf::Vector2f dirVec = launchPos;

	_sprite.setRotation(90);

	//calcul de la longeur du vecteur
	float vectorLength = std::sqrtf(std::powf((nextDirection.x), 2) + std::powf((nextDirection.y), 2));
	//normalisation du vecteur puis set à la vitesse de la flèche
	nextDirection.x = (nextDirection.x / vectorLength) * speed;
	nextDirection.y = (nextDirection.y / vectorLength) * speed;

}