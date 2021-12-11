
/* Generated from GenMyModel */

#include "../Header/Skeleton.hpp"
#include "../Header/GameMaster.hpp"

Skeleton::Skeleton()
{
	_sprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Skeleton));
	sf::FloatRect localBounds = _sprite.getGlobalBounds();
	_sprite.setOrigin(localBounds.width / 2, localBounds.height / 2);
	_sprite.setScale(sf::Vector2f(1, 1));

}
