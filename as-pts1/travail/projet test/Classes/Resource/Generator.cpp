#include "../Header/Generator.hpp"
#include "../Header/Connection.hpp"
#include "../Header/ZoneRoom.hpp"
#include "../Header/GameMaster.hpp"

#include <iostream>
#include <fstream>
#include <sys/types.h>

#include <cstdlib> // Librairie RANDOM
#include <ctime>

#include <math.h>

Generator::Generator() {
    MapTheme themeA(TextureLoader::TextureNames::Floor1);
    MapTheme themeB(TextureLoader::TextureNames::Floor2);
    MapTheme themeC(TextureLoader::TextureNames::Floor3);
    MapTheme themeD(TextureLoader::TextureNames::Floor4);
    MapTheme themeE(TextureLoader::TextureNames::Floor5);
    MapTheme themeF(TextureLoader::TextureNames::Floor6);
    MapTheme themeG(TextureLoader::TextureNames::Floor7);

    themeA.addTexture(TextureLoader::TextureNames::DecorPillard);
    themeB.addTexture(TextureLoader::TextureNames::DecorPillard);
    themeC.addTexture(TextureLoader::TextureNames::DecorPillard);
    themeD.addTexture(TextureLoader::TextureNames::DecorPillard);
    themeE.addTexture(TextureLoader::TextureNames::DecorPillard);
    themeF.addTexture(TextureLoader::TextureNames::DecorPillard);
    themeG.addTexture(TextureLoader::TextureNames::DecorPillard);

    themeA.addTexture(TextureLoader::TextureNames::DecorWallA);
    themeB.addTexture(TextureLoader::TextureNames::DecorWallA);
    themeC.addTexture(TextureLoader::TextureNames::DecorWallB);
    themeD.addTexture(TextureLoader::TextureNames::DecorWallC);
    themeE.addTexture(TextureLoader::TextureNames::DecorWallC);
    themeF.addTexture(TextureLoader::TextureNames::DecorWallD);
    themeG.addTexture(TextureLoader::TextureNames::DecorWallE);

    _lesThemes.push_back(themeA);
    _lesThemes.push_back(themeB);
    _lesThemes.push_back(themeC);
    _lesThemes.push_back(themeD);
    _lesThemes.push_back(themeE);
    _lesThemes.push_back(themeF);
    _lesThemes.push_back(themeG);
}

MapTheme& Generator::getRdmTheme() {
    int rdm = rand() % _lesThemes.size();
    return _lesThemes[rdm];
}

Map Generator::makeMap(uint32_t difficulter) {
    uint32_t nbSalle = 10;//difficulter*3;
    vector<Room> lesSalles;

    // Crèer les ZoneRoom !
    bool doBig = true;
    int32_t ha = 3;
    int32_t wa = 3;
    for (uint32_t i = 0; i < nbSalle + 1; i++) {
        ha = rand() % 10 + 5;
        wa = rand() % 10 + 5; // 12 et 5

        vector<vector<uint32_t>> matriceRoom;
        for (uint32_t r = 0; r < ha + 1; r++) {
            matriceRoom.push_back(vector<uint32_t>());
            for (uint32_t g = 0; g < wa + 1; g++) {
                if (r == 0 || r == ha || g == 0 || g == wa) {
                    matriceRoom[r].push_back(1);
                }
                else {
                    matriceRoom[r].push_back(0);
                }
            }
        }
        ////cout << ha << " : " << wa << endl;
        lesSalles.push_back(Room(i, matriceRoom));
    }
    ZoneRoom laZoneRoom = ZoneRoom(lesSalles[0], getRdmTheme());

    for (uint32_t i = 1; i < nbSalle + 1; i++) {
        laZoneRoom.addRoom(lesSalles[i]);
    }

    laZoneRoom.makeIntersection();
    laZoneRoom.makeNodes();
    laZoneRoom.makeTiles();
    laZoneRoom.makeWalls();
    //cout << "CHECK NB WALL " << laZoneRoom.getWalls().size() << endl;
    for (uint32_t i = 0; i < laZoneRoom.getNodes().size(); i++) {
        cout << laZoneRoom.getNodes()[i].getConnections().size() << endl;
        cout << "MH " << endl;
    }
    Map generatedMap = Map(laZoneRoom.getRooms(), laZoneRoom.getConnections(), laZoneRoom.getWalls(), laZoneRoom.getNodes());
    return generatedMap;
}

