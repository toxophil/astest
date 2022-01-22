
/* Generated from GenMyModel */

#include "../Header/LittleUndead.hpp"
#include "../Header/GameMaster.hpp"

LittleUndead::LittleUndead()
{
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Undead_Little_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Undead_Little_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
