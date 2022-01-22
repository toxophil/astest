
/* Generated from GenMyModel */

#include "../Header/LittleDemon.hpp"
#include "../Header/GameMaster.hpp"

LittleDemon::LittleDemon()
{
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Demon_Little_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Demon_Little_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
