
/* Generated from GenMyModel */

#include "../Header/BossOrc.hpp"
#include "../Header/GameMaster.hpp"

BossOrc::BossOrc()
{
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Orc_Boss_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Orc_Boss_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
