
/* Generated from GenMyModel */

#include "../Header/MagicienUndead.hpp"
#include "../Header/GameMaster.hpp"

MagicienUndead::MagicienUndead()
{
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Undead_Mage_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Undead_Mage_Idle);
	GameMaster::getInstance().addMoveableObject(this);
}
