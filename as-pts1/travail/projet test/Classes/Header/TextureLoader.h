#pragma once

#include <unordered_map>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class TextureLoader
{
public:
	enum class TextureNames {
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

		Floor1,
		Floor2,
		Floor3,
		Floor4,
		Floor5,
		Floor6,
		Floor7
	};

	TextureLoader();

	const Texture& getTexture(TextureNames texture);

private:
	unordered_map<TextureNames, Texture> _textureMap;


};

