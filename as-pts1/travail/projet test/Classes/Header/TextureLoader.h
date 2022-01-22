#pragma once

#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Animation.hpp"

using namespace std;
using namespace sf;

class TextureLoader
{
public:
	enum class TextureNames {
		ErrorTexture,
		Orc,
		Skeleton,
		Arrow,
		defaultTexture,
		/* mur*/

		WallRL,
		RightTop,
		LeftTop,
		WallLeft,
		WallRight,

		PillarLeft,
		PillarRight,

		Floor1,
		Floor2,
		Floor3,
		Floor4,
		Floor5,
		Floor6,
		Floor7,

		DecorDoor,
		DecorDoorLeft,
		DecorDoorRight,
		DecorPillard,
		DecorWallA,
		DecorWallB,
		DecorWallC,
		DecorWallD,
		DecorWallE,

		Logo,

		HeartFull,
		HeartDemi,
		HeartEmpty,

		Bow,
		Anime_Sword
	};

	enum class AnimationNames {
		defaultAnimation,

		Lizard_M_Walking,
		Lizard_M_Idle,
		Lizard_F_Walking,
		Lizard_F_Idle,

		Wizzard_M_Walking,
		Wizzard_M_Idle,
		Wizzard_F_Walking,
		Wizzard_F_Idle,

		Elf_M_Walking,
		Elf_M_Idle,
		Elf_F_Walking,
		Elf_F_Idle,

		Knight_Walking,
		Knight_Idle,

		Demon_Mage_Walking,
		Demon_Mage_Idle,
		Demon_Little_Walking,
		Demon_Little_Idle,
		Demon_Medium_Walking,
		Demon_Medium_Idle,
		Demon_Boss_Walking,
		Demon_Boss_Idle,

		Orc_Mage_Walking,
		Orc_Mage_Idle,
		Orc_Little_Walking,
		Orc_Little_Idle,
		Orc_Medium_Walking,
		Orc_Medium_Idle,
		Orc_Boss_Walking,
		Orc_Boss_Idle,

		Undead_Mage_Walking,
		Undead_Mage_Idle,
		Undead_Little_Walking,
		Undead_Little_Idle,
		Undead_Medium_Walking,
		Undead_Medium_Idle,
		Undead_Boss_Walking,
		Undead_Boss_Idle,

		Background_Wild,
		Coin

	};

	TextureLoader();

	Texture& getTexture(TextureNames texture);
	Animation& getAnimation(AnimationNames animation);

private:
	unordered_map<TextureNames, Texture> _textureMap;
	unordered_map<AnimationNames, Animation> _animationMap;

};

