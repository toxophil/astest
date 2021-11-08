
/* Generated from GenMyModel */

#include "..\Header\Thief.hpp"
#include "..\Header\GameMaster.hpp"

Thief::Thief()
{
	_sprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::PlayerThief));
}
