
/* Generated from GenMyModel */

#include "../Header/MagicienOrc.hpp"
#include "../Header/GameMaster.hpp"

MagicienOrc::MagicienOrc()
{
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Orc_Mage_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Orc_Mage_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
