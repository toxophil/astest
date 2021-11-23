#include "..\Header\TextureLoader.h"
#include <stdexcept>

TextureLoader::TextureLoader()
{
	//chargement de toutes les textures d�finies
	Texture tempText;

	unordered_map<TextureNames, string> loadLocation;

	//listes des textures � charger et leurs locations
	loadLocation[TextureNames::defaultTexture] = "Ressources/defaultTexture.png";
	loadLocation[TextureNames::PlayerThief] = "Ressources/playerTempo.png";



	for(auto& it: loadLocation){
		if (!tempText.loadFromFile(it.second)) {
			//error dans le chargment...
			throw invalid_argument("Erreur dans le chargement de la texture" + it.second);
		}

		//on ajoute la texture dans la map des textures
		_textureMap[it.first] = tempText;
	}




}

const Texture& TextureLoader::getTexture(TextureNames texture)
{
	auto it = _textureMap.find(texture);
	if (it == _textureMap.end()) {
		//Texture non trouv�e, on retourne la texture par d�fault
		return _textureMap[TextureNames::defaultTexture];
	}

	//texture trouv�e on retourne la texture associ�e
	return it->second;
}
