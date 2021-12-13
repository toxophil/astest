#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class MusicManager
{
private:
	vector<Texture> _lesTextures;
	uint8_t _textureCpt = 0;
	uint32_t _speed = 100;
public:
	enum class MusicNames {
		defaultAnimation,

		Lizard_M_Walking,
		Lizard_M_Idle,
		Lizard_F_Walking,
		Lizard_F_Idle,

		Wizzard_M_Walking,
		Wizzard_M_Idle,
		Wizzard_F_Walking,
		Wizzard_F_Idle,

		Elf_M_Walking,
		Elf_M_Idle,
		Elf_F_Walking,
		Elf_F_Idle,

		Knight_Walking,
		Knight_Idle,

		Background_Wild

	};
	MusicManager();
};


Music music;
if (!music.openFromFile("Ressources/music/menu/background/epic.ogg"))
return -1; // error

music.setPitch(1);           // increase the pitch
music.setVolume(140);
music.setLoop(true);         // make it loop
music.play();
