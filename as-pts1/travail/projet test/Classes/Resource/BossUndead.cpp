
/* Generated from GenMyModel */

#include "../Header/BossUndead.hpp"
#include "../Header/GameMaster.hpp"

BossUndead::BossUndead()
{
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Undead_Boss_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Undead_Boss_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
