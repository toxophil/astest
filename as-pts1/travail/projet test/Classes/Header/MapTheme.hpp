#pragma once

#ifndef DEF_MAPTHEME
#define DEF_MAPTHEME

#include "TextureLoader.h"
#include <SFML/Graphics.hpp>
#include "MusicManager.hpp"

#include <vector>

using namespace std;
using namespace sf;

class MapTheme {
private:
    TextureLoader::TextureNames _enumTexture;
    vector<TextureLoader::TextureNames> _lesWalls;
    vector<MusicManager::MusicNames>  _lesMusiques;

public:
    MapTheme();
    MapTheme(TextureLoader::TextureNames);
    MapTheme(const MapTheme& copyMapTheme); // Copy Constructor

    void addTexture(TextureLoader::TextureNames);
    void addMusic(MusicManager::MusicNames&);
    Texture& getRdmWall();
    MusicManager::MusicNames& getRdmMusic();
    Texture& getTile();
};


#endif
