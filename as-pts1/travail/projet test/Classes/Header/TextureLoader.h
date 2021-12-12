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

		Logo
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

		Background_Wild

	};

	TextureLoader();

	const Texture& getTexture(TextureNames texture);
	Animation& getAnimation(AnimationNames animation);

private:
	unordered_map<TextureNames, Texture> _textureMap;
	unordered_map<AnimationNames, Animation> _animationMap;

};

