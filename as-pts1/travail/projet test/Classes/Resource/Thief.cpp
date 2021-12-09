
/* Generated from GenMyModel */

#include "..\Header\Thief.hpp"
#include "..\Header\GameMaster.hpp"

Thief::Thief()
{
	_sprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::PlayerThief));
	_sprite.setScale(sf::Vector2f(1,1));
	sf::FloatRect localBounds = _sprite.getGlobalBounds();
	_sprite.setOrigin(localBounds.width / 2, localBounds.height / 2);
}
