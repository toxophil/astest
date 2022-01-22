
/* Generated from GenMyModel */

#include "../Header/MediumUndead.hpp"
#include "../Header/GameMaster.hpp"

MediumUndead::MediumUndead()
{
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Undead_Medium_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Undead_Medium_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
