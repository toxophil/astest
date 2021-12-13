#include "../Header/MapTheme.hpp"
#include "../Header/GameMaster.hpp"

MapTheme::MapTheme(){}
MapTheme::MapTheme(TextureLoader::TextureNames enumTexture) {
	_enumTexture = enumTexture;
}
MapTheme::MapTheme(const MapTheme& copyMapTheme) {
	_enumTexture = copyMapTheme._enumTexture;
	_lesWalls = copyMapTheme._lesWalls;
	_lesMusiques = copyMapTheme._lesMusiques;
}
void MapTheme::addTexture(Texture& uneTexture) {
	_lesWalls.push_back(uneTexture);
}
void MapTheme::addMusic(MusicManager::MusicNames& enumMusic) {
	_lesMusiques.push_back(enumMusic);
}

Texture& MapTheme::getRdmWall() {
	int rdm = rand() % _lesWalls.size();
	return _lesWalls[rdm];
}
MusicManager::MusicNames& MapTheme::getRdmMusic() {
	int rdm = rand() % _lesMusiques.size();
	return _lesMusiques[rdm];
}
Texture& MapTheme::getTile() {
	return GameMaster::getInstance().getTextureLoader().getTexture(_enumTexture);
}