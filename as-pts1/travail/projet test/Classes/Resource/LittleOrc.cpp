
/* Generated from GenMyModel */

#include "../Header/LittleOrc.hpp"
#include "../Header/GameMaster.hpp"

LittleOrc::LittleOrc()
{
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Orc_Little_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Orc_Little_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
