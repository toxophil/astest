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
		PlayerKnight,
		PlayerThief,
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
		Floor7
	};

	enum class AnimationNames {
		defaultAnimation,

		Lizard_F_Walking,
		Lizard_F_Idle
	};

	TextureLoader();

	const Texture& getTexture(TextureNames texture);
	Animation& getAnimation(AnimationNames animation);

private:
	unordered_map<TextureNames, Texture> _textureMap;
	unordered_map<AnimationNames, Animation> _animationMap;

};

