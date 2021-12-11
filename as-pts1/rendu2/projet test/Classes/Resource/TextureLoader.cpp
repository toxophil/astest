#include "../Header/TextureLoader.h"
#include <stdexcept>

TextureLoader::TextureLoader()
{	// METTRE _nos. pour ne pas activer le smooth des textures ! :)
	//chargement de toutes les textures définies
	Texture tempText;

	unordered_map<TextureNames, string> loadLocation;

	//listes des textures à charger et leurs locations
	loadLocation[TextureNames::defaultTexture] = "Ressources/defaultTexture.png";

	//les monstres
	loadLocation[TextureNames::Skeleton] = "Ressources/img/ennemy/orc/goblin_idle_anim_f0_nos.png";
	// Les persos
	loadLocation[TextureNames::PlayerKnight] = "Ressources/img/player/knight/knight_f_idle_anim_f1_nos.png";
	loadLocation[TextureNames::PlayerThief] = "Ressources/img/player/lizard_b/lizard_m_idle_anim_f1_nos.png";

	// Les projectiles
	loadLocation[TextureNames::Arrow] = "Ressources/img/projectile/arrow.png";

	// Textures de la map
	loadLocation[TextureNames::WallRL] = "Ressources/img/map/hd/mur3.png";
	loadLocation[TextureNames::RightTop] = "Ressources/img/map/hd/mur8.png";
	loadLocation[TextureNames::LeftTop] = "Ressources/img/map/hd/mur9.png";
	loadLocation[TextureNames::WallLeft] = "Ressources/img/map/hd/mur5.png";
	loadLocation[TextureNames::WallRight] = "Ressources/img/map/hd/mur4.png";

	loadLocation[TextureNames::PillarLeft] = "Ressources/img/map/hd/tile038.png";
	loadLocation[TextureNames::PillarRight] = "Ressources/img/map/hd/tile036.png";

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
		size_t found = it.second.find("_nos.");
		if (found != string::npos){
			tempText.setSmooth(false);
		}
		else {
			tempText.setSmooth(true);
		}
		_textureMap[it.first] = tempText;
	}




}

const Texture& TextureLoader::getTexture(TextureNames texture)
{
	auto it = _textureMap.find(texture);
	if (it == _textureMap.end()) {
		//Texture non trouvée, on retourne la texture par défault
		return _textureMap[TextureNames::defaultTexture];
	}

	//texture trouvée on retourne la texture associée
	return it->second;
}
