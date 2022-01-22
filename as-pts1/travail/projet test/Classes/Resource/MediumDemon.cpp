
/* Generated from GenMyModel */

#include "../Header/MediumDemon.hpp"
#include "../Header/GameMaster.hpp"

MediumDemon::MediumDemon()
{
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Demon_Medium_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Demon_Medium_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
