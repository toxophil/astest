#pragma once

#include "FriendlyCharacter.hpp"
#include <algorithm>
#include "Classe.hpp"

class Skill : public HittableCharacter{
	private :
		std::string _name;
		float _cooldown;
		float _power;
		string _desc;
		bool _isOur;

	public :
		Skill(std::string nom, float cd, float pwr, std::string d);
		std::string getName();
		float getPower();
		float getCooldown();
		bool usable();
		void setIsOurTrue();
};

