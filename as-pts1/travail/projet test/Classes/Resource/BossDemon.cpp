
/* Generated from GenMyModel */

#include "../Header/BossDemon.hpp"
#include "../Header/GameMaster.hpp"

BossDemon::BossDemon()
{
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Demon_Boss_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Demon_Boss_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
