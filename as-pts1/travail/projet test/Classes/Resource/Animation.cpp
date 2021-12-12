#include "../Header/Animation.hpp"
#include <iostream>
#include "../Header/GameMaster.hpp"
using namespace std;
Animation::Animation() {}
Animation::Animation(const Animation& copyAnim) {
	_lesTextures = copyAnim._lesTextures;// vector<Texture>();
}


Texture& Animation::getNextFrame() {
	_textureCpt = (_textureCpt+1)%_lesTextures.size();
	return _lesTextures[_textureCpt];
}
uint32_t Animation::getSpeed() const {
	return _speed;
}

void Animation::addFrame(Texture& laTexture) {
	if (_lesTextures.size() < 255) {
		_lesTextures.push_back(laTexture);
	}
}