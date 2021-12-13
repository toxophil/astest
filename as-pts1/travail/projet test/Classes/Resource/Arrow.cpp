
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


const float PI = 3.14159265359f;
Arrow::Arrow(const sf::Vector2f& launchPos, double damage, const sf::Vector2f& startPosition,float vitesse,float dureeVie) {
	//set de la texture de la fleche
	_sprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Arrow));
	_sprite.setScale(0.8,0.8);

	_damage = damage;
	speed = vitesse/2;
	nextDirection = sf::Vector2f(launchPos);
	sf::FloatRect localBounds = _sprite.getGlobalBounds();

	// Set la pos
	_sprite.setOrigin(localBounds.width/2, localBounds.height/2);
	_sprite.setPosition(startPosition);


	//_sprite.setRotation(arrowAngle);
	
	//calcul de la longeur du vecteur
	float vectorLength = std::sqrtf(std::powf((nextDirection.x), 2) + std::powf((nextDirection.y), 2));
	//normalisation du vecteur puis set � la vitesse de la fl�che
	nextDirection.x = (nextDirection.x / vectorLength) * speed;
	nextDirection.y = (nextDirection.y / vectorLength) * speed;

	float angle = atan2(nextDirection.y, nextDirection.x);
	_sprite.setRotation((angle * 180 / PI) + 90.f);
	cout << angle << endl;

}