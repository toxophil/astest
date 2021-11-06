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
		defaultTexture
	};

	TextureLoader();

	const Texture& getTexture(TextureNames texture);

private:
	unordered_map<TextureNames, Texture> _textureMap;


};

