
/* Generated from GenMyModel */

#include "../Header/MagicienDemon.hpp"
#include "../Header/GameMaster.hpp"

MagicienDemon::MagicienDemon()
{
	_sprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Skeleton));
	sf::FloatRect localBounds = _sprite.getGlobalBounds();
	_sprite.setOrigin(localBounds.width / 2, localBounds.height / 2);
	_sprite.setScale(sf::Vector2f(1, 1));
	_pvMonstre = 1;
	_type = 2;

	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Demon_Mage_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Demon_Mage_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
