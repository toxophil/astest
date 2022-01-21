#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Animation
{
private:
	vector<Texture> _lesTextures;
	uint8_t _textureCpt = 0;
	uint32_t _speed = 100;
public:
	Animation();
	Animation(const Animation& copyAnim); // Copy Constructor
	Texture& getNextFrame();
	uint32_t getSpeed() const;
	void setSpeed(uint32_t speed);
	void addFrame(Texture&);
};