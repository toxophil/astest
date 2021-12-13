#include "../Header/MusicManager.hpp"


// Les textures
#include <iostream>
MusicManager::MusicManager()
{
	Music tempMusic;
	unordered_map<MusicNames, string> loadLocationMusic;
	loadLocationMusic[MusicNames::Fight2] = "Ressources/music/gameplay/normal/Fight2.ogg";
	loadLocationMusic[MusicNames::GothicDark] = "Ressources/music/gameplay/normal/Gothic_Dark.ogg";
	loadLocationMusic[MusicNames::Havoc] = "Ressources/music/gameplay/normal/Havoc.ogg";

	loadLocationMusic[MusicNames::Main] = "Ressources/music/menu/background/epic.ogg";

	for (auto& it : loadLocationMusic) {
		_musicMap[it.first] = it.second;
	}
}

void MusicManager::playMusic(string musicSrc,bool doTransition) {
	if (_musicPlayingSrc != musicSrc) {
		if (doTransition) {
			_musicNext = musicSrc;			
		}
		else {
			cout << "Joue Music " << musicSrc << endl;
			_musicPlaying.stop();
			_musicPlaying.openFromFile(musicSrc);
			
			_musicPlaying.setVolume(140);
			_musicPlaying.setPitch(1);
			_musicPlaying.setLoop(true);
			_musicPlaying.play();

			_musicPlayingSrc = musicSrc;
			_musicNext = "";
		}
	}
}
void MusicManager::logicMenu() {
	if (_musicNext != "") {
		if (_musicCd.getElapsedTime().asMilliseconds() >= cdFade) {
			if (_musicPlayingSrc != "") {
				_musicPlaying.setVolume(max(_musicPlaying.getVolume() - 5,1.0f));
				_musicCd.restart();
				if (_musicPlaying.getVolume() <= 1) {
					playMusic(_musicNext, false);
				}
			}
			else {
				playMusic(_musicNext, false);
			}
		}
	}
}
String MusicManager::getMusic(MusicNames musicEnum) {
	return _musicMap[musicEnum];
}