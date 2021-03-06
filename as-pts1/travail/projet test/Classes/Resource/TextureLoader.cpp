#include "../Header/TextureLoader.h"
#include <stdexcept>

TextureLoader::TextureLoader()
{	// METTRE _nos. pour ne pas activer le smooth des textures ! :)
	//chargement de toutes les textures d?finies
	Texture tempText;
	Animation tempAnim;
	// Les textures
	unordered_map<TextureNames, string> loadLocationTexture;

	//listes des textures ? charger et leurs locations
	loadLocationTexture[TextureNames::ErrorTexture] = "Ressources/img/defaultTexture.jpg";
	loadLocationTexture[TextureNames::defaultTexture] = "Ressources/defaultTexture.png";

	//les monstres
	loadLocationTexture[TextureNames::Skeleton] = "Ressources/img/ennemy/orc/goblin_idle_anim_f1.png";

	// Les projectiles
	loadLocationTexture[TextureNames::Arrow] = "Ressources/img/projectile/arrow_nos.png";

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

	// Les d?cors de la map
	loadLocationTexture[TextureNames::DecorDoor] = "Ressources/img/map/hd/mur7.png";
	loadLocationTexture[TextureNames::DecorDoorLeft] = "Ressources/img/map/hd/tile004.png";
	loadLocationTexture[TextureNames::DecorDoorRight] = "Ressources/img/map/hd/tile005.png";
	loadLocationTexture[TextureNames::DecorPillard] = "Ressources/img/map/hd/pillier.png";
	loadLocationTexture[TextureNames::DecorWallA] = "Ressources/img/map/hd/porte1.png";
	loadLocationTexture[TextureNames::DecorWallB] = "Ressources/img/map/hd/porte2.png";
	loadLocationTexture[TextureNames::DecorWallC] = "Ressources/img/map/hd/porte3.png";
	loadLocationTexture[TextureNames::DecorWallD] = "Ressources/img/map/hd/porte4.png";
	loadLocationTexture[TextureNames::DecorWallE] = "Ressources/img/map/hd/porte5.png";


	loadLocationTexture[TextureNames::Logo] = "Ressources/img/menu/logo.png";

	loadLocationTexture[TextureNames::HeartFull] = "Ressources/img/hud/heart/ui_heart_full.png";
	loadLocationTexture[TextureNames::HeartDemi] = "Ressources/img/hud/heart/ui_heart_half.png";
	loadLocationTexture[TextureNames::HeartEmpty] = "Ressources/img/hud/heart/ui_heart_empty.png";

	loadLocationTexture[TextureNames::Bow] = "Ressources/img/weapon/weapon_bow.png";
	loadLocationTexture[TextureNames::Anime_Sword] = "Ressources/img/weapon/weapon_anime_sword.png";
	 
	// Les animations
	unordered_map<AnimationNames, vector<String>> loadLocationAnimation;
	// Animation L?zard
	loadLocationAnimation[AnimationNames::Lizard_M_Walking] = {
		"Ressources/img/player/lizard_m/walking/lizard_m_run_anim_f0.png",
		"Ressources/img/player/lizard_m/walking/lizard_m_run_anim_f1.png",
		"Ressources/img/player/lizard_m/walking/lizard_m_run_anim_f2.png",
		"Ressources/img/player/lizard_m/walking/lizard_m_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Lizard_M_Idle] = {
		"Ressources/img/player/lizard_m/idle/lizard_m_idle_anim_f0.png",
		"Ressources/img/player/lizard_m/idle/lizard_m_idle_anim_f1.png",
		"Ressources/img/player/lizard_m/idle/lizard_m_idle_anim_f2.png",
		"Ressources/img/player/lizard_m/idle/lizard_m_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Lizard_F_Walking] = {
		"Ressources/img/player/lizard_f/walking/lizard_f_run_anim_f0.png",
		"Ressources/img/player/lizard_f/walking/lizard_f_run_anim_f1.png",
		"Ressources/img/player/lizard_f/walking/lizard_f_run_anim_f2.png",
		"Ressources/img/player/lizard_f/walking/lizard_f_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Lizard_F_Idle] = {
		"Ressources/img/player/lizard_f/idle/lizard_f_idle_anim_f0.png",
		"Ressources/img/player/lizard_f/idle/lizard_f_idle_anim_f1.png",
		"Ressources/img/player/lizard_f/idle/lizard_f_idle_anim_f2.png",
		"Ressources/img/player/lizard_f/idle/lizard_f_idle_anim_f3.png" 
	};
	// Animation Magicien
	loadLocationAnimation[AnimationNames::Wizzard_M_Walking] = {
		"Ressources/img/player/wizzard_m/walking/wizzard_m_run_anim_f0.png",
		"Ressources/img/player/wizzard_m/walking/wizzard_m_run_anim_f1.png",
		"Ressources/img/player/wizzard_m/walking/wizzard_m_run_anim_f2.png",
		"Ressources/img/player/wizzard_m/walking/wizzard_m_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Wizzard_M_Idle] = {
		"Ressources/img/player/wizzard_m/idle/wizzard_m_idle_anim_f0.png",
		"Ressources/img/player/wizzard_m/idle/wizzard_m_idle_anim_f1.png",
		"Ressources/img/player/wizzard_m/idle/wizzard_m_idle_anim_f2.png",
		"Ressources/img/player/wizzard_m/idle/wizzard_m_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Wizzard_F_Walking] = {
		"Ressources/img/player/wizzard_f/walking/wizzard_f_run_anim_f0.png",
		"Ressources/img/player/wizzard_f/walking/wizzard_f_run_anim_f1.png",
		"Ressources/img/player/wizzard_f/walking/wizzard_f_run_anim_f2.png",
		"Ressources/img/player/wizzard_f/walking/wizzard_f_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Wizzard_F_Idle] = {
		"Ressources/img/player/wizzard_f/idle/wizzard_f_idle_anim_f0.png",
		"Ressources/img/player/wizzard_f/idle/wizzard_f_idle_anim_f1.png",
		"Ressources/img/player/wizzard_f/idle/wizzard_f_idle_anim_f2.png",
		"Ressources/img/player/wizzard_f/idle/wizzard_f_idle_anim_f3.png"
	};
	// Animation Elf
	loadLocationAnimation[AnimationNames::Elf_M_Walking] = {
		"Ressources/img/player/elf_m/walking/elf_m_run_anim_f0.png",
		"Ressources/img/player/elf_m/walking/elf_m_run_anim_f1.png",
		"Ressources/img/player/elf_m/walking/elf_m_run_anim_f2.png",
		"Ressources/img/player/elf_m/walking/elf_m_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Elf_M_Idle] = {
		"Ressources/img/player/elf_m/idle/elf_m_idle_anim_f0.png",
		"Ressources/img/player/elf_m/idle/elf_m_idle_anim_f1.png",
		"Ressources/img/player/elf_m/idle/elf_m_idle_anim_f2.png",
		"Ressources/img/player/elf_m/idle/elf_m_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Elf_F_Walking] = {
		"Ressources/img/player/elf_f/walking/elf_f_run_anim_f0.png",
		"Ressources/img/player/elf_f/walking/elf_f_run_anim_f1.png",
		"Ressources/img/player/elf_f/walking/elf_f_run_anim_f2.png",
		"Ressources/img/player/elf_f/walking/elf_f_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Elf_F_Idle] = {
		"Ressources/img/player/elf_f/idle/elf_f_idle_anim_f0.png",
		"Ressources/img/player/elf_f/idle/elf_f_idle_anim_f1.png",
		"Ressources/img/player/elf_f/idle/elf_f_idle_anim_f2.png",
		"Ressources/img/player/elf_f/idle/elf_f_idle_anim_f3.png"
	};
	// Animation Knight
	loadLocationAnimation[AnimationNames::Knight_Walking] = {
		"Ressources/img/player/knight/walking/knight_run_anim_f0.png",
		"Ressources/img/player/knight/walking/knight_run_anim_f1.png",
		"Ressources/img/player/knight/walking/knight_run_anim_f2.png",
		"Ressources/img/player/knight/walking/knight_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Knight_Idle] = {
		"Ressources/img/player/knight/idle/knight_idle_anim_f0.png",
		"Ressources/img/player/knight/idle/knight_idle_anim_f1.png",
		"Ressources/img/player/knight/idle/knight_idle_anim_f2.png",
		"Ressources/img/player/knight/idle/knight_idle_anim_f3.png"
	};

	loadLocationAnimation[AnimationNames::Demon_Mage_Walking] = {
		"Ressources/img/ennemy/demon/necromancer_run_anim_f0.png",
		"Ressources/img/ennemy/demon/necromancer_run_anim_f1.png",
		"Ressources/img/ennemy/demon/necromancer_run_anim_f2.png",
		"Ressources/img/ennemy/demon/necromancer_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Demon_Mage_Idle] = {
		"Ressources/img/ennemy/demon/necromancer_idle_anim_f0.png",
		"Ressources/img/ennemy/demon/necromancer_idle_anim_f1.png",
		"Ressources/img/ennemy/demon/necromancer_idle_anim_f2.png",
		"Ressources/img/ennemy/demon/necromancer_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Demon_Little_Walking] = {
		"Ressources/img/ennemy/demon/imp_run_anim_f0.png",
		"Ressources/img/ennemy/demon/imp_run_anim_f1.png",
		"Ressources/img/ennemy/demon/imp_run_anim_f2.png",
		"Ressources/img/ennemy/demon/imp_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Demon_Little_Idle] = {
		"Ressources/img/ennemy/demon/imp_idle_anim_f0.png",
		"Ressources/img/ennemy/demon/imp_idle_anim_f1.png",
		"Ressources/img/ennemy/demon/imp_idle_anim_f2.png",
		"Ressources/img/ennemy/demon/imp_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Demon_Medium_Walking] = {
		"Ressources/img/ennemy/demon/chort_run_anim_f0.png",
		"Ressources/img/ennemy/demon/chort_run_anim_f1.png",
		"Ressources/img/ennemy/demon/chort_run_anim_f2.png",
		"Ressources/img/ennemy/demon/chort_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Demon_Medium_Idle] = {
		"Ressources/img/ennemy/demon/chort_idle_anim_f0.png",
		"Ressources/img/ennemy/demon/chort_idle_anim_f1.png",
		"Ressources/img/ennemy/demon/chort_idle_anim_f2.png",
		"Ressources/img/ennemy/demon/chort_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Demon_Boss_Walking] = {
		"Ressources/img/ennemy/demon/big_demon_run_anim_f0.png",
		"Ressources/img/ennemy/demon/big_demon_run_anim_f1.png",
		"Ressources/img/ennemy/demon/big_demon_run_anim_f2.png",
		"Ressources/img/ennemy/demon/big_demon_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Demon_Boss_Idle] = {
		"Ressources/img/ennemy/demon/big_demon_idle_anim_f0.png",
		"Ressources/img/ennemy/demon/big_demon_idle_anim_f1.png",
		"Ressources/img/ennemy/demon/big_demon_idle_anim_f2.png",
		"Ressources/img/ennemy/demon/big_demon_idle_anim_f3.png"
	};
	// ORC
	loadLocationAnimation[AnimationNames::Orc_Mage_Walking] = {
		"Ressources/img/ennemy/orc/orc_shaman_run_anim_f0.png",
		"Ressources/img/ennemy/orc/orc_shaman_run_anim_f1.png",
		"Ressources/img/ennemy/orc/orc_shaman_run_anim_f2.png",
		"Ressources/img/ennemy/orc/orc_shaman_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Orc_Mage_Idle] = {
		"Ressources/img/ennemy/orc/orc_shaman_idle_anim_f0.png",
		"Ressources/img/ennemy/orc/orc_shaman_idle_anim_f1.png",
		"Ressources/img/ennemy/orc/orc_shaman_idle_anim_f2.png",
		"Ressources/img/ennemy/orc/orc_shaman_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Orc_Little_Walking] = {
		"Ressources/img/ennemy/orc/goblin_run_anim_f0.png",
		"Ressources/img/ennemy/orc/goblin_run_anim_f1.png",
		"Ressources/img/ennemy/orc/goblin_run_anim_f2.png",
		"Ressources/img/ennemy/orc/goblin_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Orc_Little_Idle] = {
		"Ressources/img/ennemy/orc/goblin_idle_anim_f1.png",
		"Ressources/img/ennemy/orc/goblin_idle_anim_f2.png",
		"Ressources/img/ennemy/orc/goblin_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Orc_Medium_Walking] = {
		"Ressources/img/ennemy/orc/orc_warrior_run_anim_f0.png",
		"Ressources/img/ennemy/orc/orc_warrior_run_anim_f1.png",
		"Ressources/img/ennemy/orc/orc_warrior_run_anim_f2.png",
		"Ressources/img/ennemy/orc/orc_warrior_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Orc_Medium_Idle] = {
		"Ressources/img/ennemy/orc/orc_warrior_idle_anim_f0.png",
		"Ressources/img/ennemy/orc/orc_warrior_idle_anim_f1.png",
		"Ressources/img/ennemy/orc/orc_warrior_idle_anim_f2.png",
		"Ressources/img/ennemy/orc/orc_warrior_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Orc_Boss_Walking] = {
		"Ressources/img/ennemy/orc/ogre_run_anim_f0.png",
		"Ressources/img/ennemy/orc/ogre_run_anim_f1.png",
		"Ressources/img/ennemy/orc/ogre_run_anim_f2.png",
		"Ressources/img/ennemy/orc/ogre_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Orc_Boss_Idle] = {
		"Ressources/img/ennemy/orc/ogre_idle_anim_f0.png",
		"Ressources/img/ennemy/orc/ogre_idle_anim_f1.png",
		"Ressources/img/ennemy/orc/ogre_idle_anim_f2.png",
		"Ressources/img/ennemy/orc/ogre_idle_anim_f3.png"
	};

	// Undead
	loadLocationAnimation[AnimationNames::Undead_Mage_Walking] = {
		"Ressources/img/ennemy/undead/ice_zombie_run_anim_f0.png",
		"Ressources/img/ennemy/undead/ice_zombie_run_anim_f1.png",
		"Ressources/img/ennemy/undead/ice_zombie_run_anim_f2.png",
		"Ressources/img/ennemy/undead/ice_zombie_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Undead_Mage_Idle] = {
		"Ressources/img/ennemy/undead/ice_zombie_idle_anim_f0.png",
		"Ressources/img/ennemy/undead/ice_zombie_idle_anim_f1.png",
		"Ressources/img/ennemy/undead/ice_zombie_idle_anim_f2.png",
		"Ressources/img/ennemy/undead/ice_zombie_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Undead_Little_Walking] = {
		"Ressources/img/ennemy/undead/tiny_zombie_run_anim_f0.png",
		"Ressources/img/ennemy/undead/tiny_zombie_run_anim_f1.png",
		"Ressources/img/ennemy/undead/tiny_zombie_run_anim_f2.png",
		"Ressources/img/ennemy/undead/tiny_zombie_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Undead_Little_Idle] = {
		"Ressources/img/ennemy/undead/tiny_zombie_idle_anim_f1.png",
		"Ressources/img/ennemy/undead/tiny_zombie_idle_anim_f2.png",
		"Ressources/img/ennemy/undead/tiny_zombie_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Undead_Medium_Walking] = {
		"Ressources/img/ennemy/undead/skelet_run_anim_f0.png",
		"Ressources/img/ennemy/undead/skelet_run_anim_f1.png",
		"Ressources/img/ennemy/undead/skelet_run_anim_f2.png",
		"Ressources/img/ennemy/undead/skelet_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Undead_Medium_Idle] = {
		"Ressources/img/ennemy/undead/skelet_idle_anim_f0.png",
		"Ressources/img/ennemy/undead/skelet_idle_anim_f1.png",
		"Ressources/img/ennemy/undead/skelet_idle_anim_f2.png",
		"Ressources/img/ennemy/undead/skelet_idle_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Undead_Boss_Walking] = {
		"Ressources/img/ennemy/undead/big_zombie_run_anim_f0.png",
		"Ressources/img/ennemy/undead/big_zombie_run_anim_f1.png",
		"Ressources/img/ennemy/undead/big_zombie_run_anim_f2.png",
		"Ressources/img/ennemy/undead/big_zombie_run_anim_f3.png"
	};
	loadLocationAnimation[AnimationNames::Undead_Boss_Idle] = {
		"Ressources/img/ennemy/undead/big_zombie_idle_anim_f0.png",
		"Ressources/img/ennemy/undead/big_zombie_idle_anim_f1.png",
		"Ressources/img/ennemy/undead/big_zombie_idle_anim_f2.png",
		"Ressources/img/ennemy/undead/big_zombie_idle_anim_f3.png"
	};

	// Background Menu Wild
	loadLocationAnimation[AnimationNames::Background_Wild] = {
		"Ressources/img/menu/background/wild_1.jpg",
		"Ressources/img/menu/background/wild_2.jpg",
		"Ressources/img/menu/background/wild_3.jpg",
		"Ressources/img/menu/background/wild_4.jpg"
	};

	// Coin
	loadLocationAnimation[AnimationNames::Coin] = {
		"Ressources/img/hud/coin/coin_anim_f0.png",
		"Ressources/img/hud/coin/coin_anim_f1.png",
		"Ressources/img/hud/coin/coin_anim_f2.png",
		"Ressources/img/hud/coin/coin_anim_f3.png"
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
			tempText.setSmooth(false);
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

Texture& TextureLoader::getTexture(TextureNames texture)
{
	auto it = _textureMap.find(texture);
	if (it == _textureMap.end()) {
		//Texture non trouv?e, on retourne la texture par d?fault
		return _textureMap[TextureNames::defaultTexture];
	}

	//texture trouv?e on retourne la texture associ?e
	return it->second;
}

Animation& TextureLoader::getAnimation(AnimationNames animation)
{
	
	auto it = _animationMap.find(animation);
	if (it == _animationMap.end()) {
		//Texture non trouv?e, on retourne la texture par d?fault
		return _animationMap[AnimationNames::defaultAnimation];
	}

	//texture trouv?e on retourne la texture associ?e
	return it->second;
}

