
/* Generated from GenMyModel */

#include "../Header/MediumOrc.hpp"
#include "../Header/GameMaster.hpp"

MediumOrc::MediumOrc()
{
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Orc_Medium_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Orc_Medium_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
