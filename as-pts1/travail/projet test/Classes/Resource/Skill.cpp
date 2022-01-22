
/* Generated from GenMyModel */

#include "../Header/Skill.hpp"
#include "../Header/Player.hpp"
//#include "../Header/Ennemy.hpp"



//constructeur
Skill::Skill(std::string nom, float cd, float pwr,  std::string d) {
	_name = nom;
	_cooldown = cd;
	_power = pwr;
	_desc = d;
	_isOur = false;
}

std::string Skill::getName() {
	return _name;
}
float Skill::getCooldown() {
	return _cooldown;
}
float Skill::getPower() {
	return _power;
}
bool Skill::usable() {
	return _isOur;
}
void Skill::setIsOurTrue() {
	_isOur = true;
}

//obtention des compétences
/*void Skill::obtainSkill() {
	if (Ennemy.getHealth() == 0 && !allSkills[Ennemy.getSkillNumber()].usable()) {
		allSkills[Ennemy.getSkillNumber()].setIsOurTrue();
		if (playerSkills.size() <= 2) {
			int j = 0;
			playerSkills[j] = allSkills[Ennemy.getSkillNumber()];
			j++;
		}
	}
}*/

