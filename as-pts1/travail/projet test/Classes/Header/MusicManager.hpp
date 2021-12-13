#pragma once

#include <unordered_map>
#include <vector>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

const float cdFade = 0.5;
class MusicManager
{
public:
	enum class MusicNames {
		Fight2,
		GothicDark,
		Havoc,

		Main
	};

	MusicManager();
	void playMusic(string,bool);
	void logicMenu();
	String getMusic(MusicNames);
private:
	Music _musicPlaying;
	string _musicPlayingSrc;
	string _musicNext;
	sf::Clock _musicCd;

	unordered_map<MusicNames, String> _musicMap;
};
