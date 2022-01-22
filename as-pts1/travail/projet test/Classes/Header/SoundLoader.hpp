#pragma once

#include <unordered_map>
#include <vector>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class SoundLoader
{
public:
	enum class MusicNames {
		ArrowShoot
	};

	SoundLoader();
	void playSound(MusicNames);
private:

	vector<sf::Sound> _lesSounds;
	unordered_map<MusicNames, sf::SoundBuffer> _soundMap;
};
