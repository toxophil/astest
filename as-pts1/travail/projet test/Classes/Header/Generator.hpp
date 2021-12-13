#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED

#include "Map.hpp"
#include "Room.hpp"
#include "MapTheme.hpp"
#include <vector>

class Generator {
private:
    vector<MapTheme> _lesThemes;
    MapTheme& getRdmTheme();
public:
    Generator();
    Map makeMap(uint32_t);
};

#endif