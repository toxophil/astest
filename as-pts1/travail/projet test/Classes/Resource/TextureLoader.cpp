#include "../Header/TextureLoader.h"
#include <stdexcept>

TextureLoader::TextureLoader()
{	// METTRE _nos. pour ne pas activer le smooth des textures ! :)
	//chargement de toutes les textures définies
	Texture tempText;
	Animation tempAnim;
	// Les textures
	unordered_map<TextureNames, string> loadLocationTexture;

	//listes des textures à charger et leurs locations
	loadLocationTexture[TextureNames::defaultTexture] = "Ressources/defaultTexture.png";

	//les monstres
	loadLocationTexture[TextureNames::Skeleton] = "Ressources/img/ennemy/orc/goblin_idle_anim_f0_nos.png";
	// Les persos
	loadLocationTexture[TextureNames::PlayerKnight] = "Ressources/img/player/knight/knight_f_idle_anim_f1_nos.png";
	loadLocationTexture[TextureNames::PlayerThief] = "Ressources/img/player/lizard_b/lizard_m_idle_anim_f1_nos.png";

	// Les projectiles
	loadLocationTexture[TextureNames::Arrow] = "Ressources/img/projectile/arrow.png";

	// Textures de la map
	loadLocationTexture[TextureNames::WallRL] = "Ressources/img/map/hd/mur3.png";
	loadLocationTexture[TextureNames::RightTop] = "Ressources/img/map/hd/mur8.png";
	loadLocationTexture[TextureNames::LeftTop] = "Ressources/img/map/hd/mur9.png";
	loadLocationTexture[TextureNames::WallLeft] = "Ressources/img/map/hd/mur5.png";
	loadLocationTexture[TextureNames::WallRight] = "Ressources/img/map/hd/mur4.png";

	loadLocationTexture[TextureNames::PillarLeft] = "Ressources/img/map/hd/tile038.png";
	loadLocationTexture[TextureNames::PillarRight] = "Ressources/img/map/hd/tile036.png";

	loadLocationTexture[TextureNames::Floor1] = "Ressources/img/map/hd/floor1.png";
	loadLocationTexture[TextureNames::Floor2] = "Ressources/img/map/hd/floor2.png";
	loadLocationTexture[TextureNames::Floor3] = "Ressources/img/map/hd/floor3.png";
	loadLocationTexture[TextureNames::Floor4] = "Ressources/img/map/hd/floor4.png";
	loadLocationTexture[TextureNames::Floor5] = "Ressources/img/map/hd/floor5.png";
	loadLocationTexture[TextureNames::Floor6] = "Ressources/img/map/hd/floor6.png";
	loadLocationTexture[TextureNames::Floor7] = "Ressources/img/map/hd/floor7.png";

	// Les animations
	unordered_map<AnimationNames, vector<String>> loadLocationAnimation;

	loadLocationAnimation[AnimationNames::Lizard_F_Idle] = {
		"Ressources/img/player/lizard_f/idle/lizard_f_idle_anim_f0.png",
		"Ressources/img/player/lizard_f/idle/lizard_f_idle_anim_f1.png",
		"Ressources/img/player/lizard_f/idle/lizard_f_idle_anim_f2.png",
		"Ressources/img/player/lizard_f/idle/lizard_f_idle_anim_f3.png" 
	};
	loadLocationAnimation[AnimationNames::Lizard_F_Walking] = {
		"Ressources/img/player/lizard_f/walking/lizard_f_run_anim_f0.png",
		"Ressources/img/player/lizard_f/walking/lizard_f_run_anim_f1.png",
		"Ressources/img/player/lizard_f/walking/lizard_f_run_anim_f2.png",
		"Ressources/img/player/lizard_f/walking/lizard_f_run_anim_f3.png"
	};

	for(auto& it: loadLocationTexture){
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

	// Ajout Animation
	for (auto& it : loadLocationAnimation) {
		tempAnim = Animation();

		for (uint32_t i = 0; i < it.second.size(); i++) {
			if (!tempText.loadFromFile(it.second[i])) {
				//error dans le chargment...
				throw invalid_argument("Erreur dans le chargement de l'Animation Texture: "+ it.second[i]);
			}
			tempText.setSmooth(false);
			tempAnim.addFrame(tempText);
		}
		_animationMap[it.first] = tempAnim;
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

Animation& TextureLoader::getAnimation(AnimationNames animation)
{
	
	auto it = _animationMap.find(animation);
	if (it == _animationMap.end()) {
		//Texture non trouvée, on retourne la texture par défault
		return _animationMap[AnimationNames::defaultAnimation];
	}

	//texture trouvée on retourne la texture associée
	return it->second;
}

