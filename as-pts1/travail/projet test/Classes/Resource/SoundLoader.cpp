#include "../Header/SoundLoader.hpp"


// Les textures
#include <iostream>
SoundLoader::SoundLoader()
{

	unordered_map<MusicNames, string> loadLocationMusic;
	loadLocationMusic[MusicNames::ArrowShoot] = "Ressources/sound/weapon/arrow.ogg";

	for (auto& it : loadLocationMusic) {
		sf::SoundBuffer sndBuffer;
		if (!sndBuffer.loadFromFile(it.second)) {
			throw std::invalid_argument("Impossible de trouver le son: "+ it.second);
		}

		_soundMap[it.first] = sndBuffer;
	}
}

void SoundLoader::playSound(MusicNames musicSrc) {

	_lesSounds.push_back(sf::Sound ());
	_lesSounds.back().setBuffer(_soundMap[musicSrc]);
	_lesSounds.back().play();
	cout << "Play ?" << endl;
}