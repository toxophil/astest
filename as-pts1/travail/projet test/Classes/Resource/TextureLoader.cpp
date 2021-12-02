#include "..\Header\TextureLoader.h"
#include <stdexcept>

TextureLoader::TextureLoader()
{
	//chargement de toutes les textures d�finies
	Texture tempText;

	unordered_map<TextureNames, string> loadLocation;

	//listes des textures � charger et leurs locations
	loadLocation[TextureNames::defaultTexture] = "Ressources/defaultTexture.png";
	loadLocation[TextureNames::PlayerThief] = "Ressources/player.jpg";
	loadLocation[TextureNames::Arrow	] = "Ressources/Arrow.jpg";

	// Textures de la map
	loadLocation[TextureNames::WallRL] = "Ressources/img/map/hd/mur3.png";
	loadLocation[TextureNames::RightTop] = "Ressources/img/map/hd/mur8.png";
	loadLocation[TextureNames::LeftTop] = "Ressources/img/map/hd/mur9.png";
	loadLocation[TextureNames::WallLeft] = "Ressources/img/map/hd/mur5.png";
	loadLocation[TextureNames::WallRight] = "Ressources/img/map/hd/mur4.png";

	loadLocation[TextureNames::Floor1] = "Ressources/img/map/hd/floor1.png";
	loadLocation[TextureNames::Floor2] = "Ressources/img/map/hd/floor2.png";
	loadLocation[TextureNames::Floor3] = "Ressources/img/map/hd/floor3.png";
	loadLocation[TextureNames::Floor4] = "Ressources/img/map/hd/floor4.png";
	loadLocation[TextureNames::Floor5] = "Ressources/img/map/hd/floor5.png";
	loadLocation[TextureNames::Floor6] = "Ressources/img/map/hd/floor6.png";
	loadLocation[TextureNames::Floor7] = "Ressources/img/map/hd/floor7.png";




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
