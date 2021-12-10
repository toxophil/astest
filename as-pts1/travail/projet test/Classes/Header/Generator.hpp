#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED

#include "../Header/Map.hpp"
#include "../Header/Room.hpp"

class Generator {
public:
    Generator();
    Map makeMap(uint32_t) const;
};

#endif // GENERATOR_H_INCLUDED
