#include "..\Header\Generator.hpp"
#include "..\Header\Connection.hpp"
#include "..\Header\ZoneRoom.hpp"

#include <iostream>
#include <fstream>
#include <sys/types.h>

#include <cstdlib> // Librairie RANDOM
#include <ctime>

#include <math.h>

Generator::Generator() {}


Map Generator::makeMap(uint32_t difficulter) const {
    uint32_t nbSalle = 200;//difficulter*3;
    vector<Room> lesSalles;

    // Crèer les ZoneRoom !
    bool doBig = true;
    int32_t ha = 3;
    int32_t wa = 3;
    for (uint32_t i = 0; i < nbSalle + 1; i++) {
        ha = rand() % 20 + 5;
        wa = rand() % 20 + 5; // 12 et 5

        vector<vector<uint32_t>> matriceRoom;
        for (uint32_t r = 0; r < ha + 1; r++) {
            matriceRoom.push_back(vector<uint32_t>());
            for (uint32_t g = 0; g < wa + 1; g++) {
                if (r == 0 || r == ha || g == 0 || g == wa) {
                    matriceRoom[r].push_back(1);
                    // cout << "Oui" << endl;
                }
                else {
                    matriceRoom[r].push_back(0);
                }
            }
        }
        //cout << ha << " : " << wa << endl;
        lesSalles.push_back(Room(i, matriceRoom));
    }
    ZoneRoom laZoneRoom = ZoneRoom(lesSalles[0]);

    for (uint32_t i = 1; i < nbSalle + 1; i++) {
        laZoneRoom.addRoom(lesSalles[i]);
    }

    laZoneRoom.makeIntersection();
    Map generatedMap = Map(laZoneRoom.getRooms(), laZoneRoom.getConnections());
    return generatedMap;
}

