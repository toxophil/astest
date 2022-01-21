#include "../Header/ZoneRoom.hpp"
#include <cmath>
ZoneRoom::ZoneRoom(Room& uneSalle, MapTheme& leTheme) {
    _w = uneSalle.getW();
    _h = uneSalle.getH();

    _rooms.push_back(uneSalle);
    _leTheme = leTheme;
}

vector<Room> ZoneRoom::getRooms() const {
    return _rooms;
}
uint32_t ZoneRoom::getH() const {
    return _h;
}
uint32_t ZoneRoom::getW() const {
    return _w;
}

void ZoneRoom::addRoom(Room& uneRoom) {
    vector<uint32_t> lesRoomsAttachable;
    //cout << "============================================================== " << uneRoom.getID() << endl;
    uint32_t wA, hA, wB, hB, rdmPosA, rdmPosB, distanceMax, rdmSide, roomIDSelected;
    int64_t xA, yA, xB, yB;
    Room aConnecter;
    do {
        rdmSide = rand() % (4 - 1 + 1) + 1;
        //rdmSide = 1;
        ////cout << rdmSide << endl;
        switch (rdmSide) {
        case 1: // Haut
            lesRoomsAttachable = getTopFree();
            break;
        case 2: // Droite
            lesRoomsAttachable = getRightFree();
            break;
        case 3: // Gauche
            lesRoomsAttachable = getLeftFree();
            break;
        case 4: // Bas
            lesRoomsAttachable = getBotFree();
            break;
        }
        roomIDSelected = lesRoomsAttachable[rand() % lesRoomsAttachable.size()];
        aConnecter = _rooms[roomIDSelected];

        //cout << "POUR " << uneRoom.getID() << " ";
        //cout << "Selected: " << aConnecter.getID();
        rdmPosA;
        rdmPosB;

        wA = uneRoom.getW();
        hA = uneRoom.getH();
        wB = aConnecter.getW();
        hB = aConnecter.getH();

        switch (rdmSide) {
        case 1: // haut
            rdmPosA = rand() % (wA - 3) + 1;
            rdmPosB = rand() % (wB - 3) + 1;
            break;
        case 2: // droit
            rdmPosA = rand() % (hA - 3) + 1;
            rdmPosB = rand() % (hB - 3) + 1;
            break;
        case 3: // Gauche
            rdmPosA = rand() % (hA - 3) + 1;
            rdmPosB = rand() % (hB - 3) + 1;
            break;
        case 4: // Bas
            rdmPosA = rand() % (wA - 3) + 1;
            rdmPosB = rand() % (wB - 3) + 1;
            break;
        }

        distanceMax = rand() % 6 + 3;

        xA = aConnecter.getX();
        yA = aConnecter.getY();

        xB = aConnecter.getX();
        yB = aConnecter.getY();



        //cout << "Dist max: " << distanceMax << endl;
        switch (rdmSide) {
        case 1: // haut
            yA = yA - distanceMax - hA;
            xA = xA + rdmPosB - rdmPosA;
            break;
        case 2: // droit
            xA = xA + distanceMax + wB;
            yA = yA + rdmPosB - rdmPosA;
            break;
        case 3: // Gauche
            xA = xA - distanceMax - wA;
            yA = yA + rdmPosB - rdmPosA;
            break;
        case 4: // Bas
            yA = yA + distanceMax + hB;
            xA = xA + rdmPosB - rdmPosA;
            break;
        }

    } while (!isFree(xA, yA, wA, hA));
    uneRoom.setX(xA);
    uneRoom.setY(yA);
    //cout << "===== A" << endl;
    //cout << "X:" << xA << " Y:" << yA << endl;
    //cout << "W:" << wA << " H:" << hA << endl;
    //cout << "===== B" << endl;
    //cout << "X:" << xB << " Y:" << yB << endl;
    //cout << "W:" << wB << " H:" << hB << endl;
    // Créer les entrés dans les salles
    switch (rdmSide) {
    case 1: // haut
        uneRoom.modifyMatrice(hA - 1, rdmPosA, 0);
        _rooms[roomIDSelected].modifyMatrice(0, rdmPosB, 0);
        break;
    case 2: // droit
        uneRoom.modifyMatrice(rdmPosA, 0, 0);
        _rooms[roomIDSelected].modifyMatrice(rdmPosB, wB - 1, 0);
        break;
    case 3: // Gauche
        uneRoom.modifyMatrice(rdmPosA, wA - 1, 0);
        _rooms[roomIDSelected].modifyMatrice(rdmPosB, 0, 0);
        break;
    case 4: // Bas
        uneRoom.modifyMatrice(0, rdmPosA, 0);
        _rooms[roomIDSelected].modifyMatrice(hB - 1, rdmPosB, 0);

        break;
    }
    _rooms.push_back(uneRoom);

    bool estVertical = (rdmSide == 1 || rdmSide == 4);
    int64_t xC;
    int64_t yC;

    uint32_t wC;
    uint32_t hC;

    vector<vector<uint32_t>> matriceConnection;
    switch (rdmSide) {
    case 1: // haut
        yC = yA + hA;
        xC = xA + rdmPosA - 1;
        wC = 3;
        hC = abs(yC - yB);
        break;
    case 2: // droit
        yC = yA + rdmPosA - 1;
        xC = xB + wB;
        wC = xA - xB - wB;
        hC = 3;
        break;
    case 3: // Gauche
        yC = yA + rdmPosA - 1;
        xC = xA + wA;
        wC = xB - xA - wA;//xC - xB;
        hC = 3;
        break;
    case 4: // Bas
        yC = yB + hB;
        xC = xA + rdmPosA - 1;
        wC = 3;
        hC = abs(yA - yB - hB);
        break;
    }
    //cout << "Gonna ste " << rdmSide << ": " << hC << "   et " << wC << endl;
    if (estVertical) {
        for (uint32_t i = 0; i < hC; i++) {
            matriceConnection.push_back(vector<uint32_t>());
            for (uint32_t r = 0; r < wC; r++) {
                if (r == 1) {
                    matriceConnection[i].push_back(0);
                }
                else {
                    matriceConnection[i].push_back(1);
                }
            }
        }
    }
    else {
        for (uint32_t i = 0; i < hC; i++) {
            matriceConnection.push_back(vector<uint32_t>());
            for (uint32_t r = 0; r < wC; r++) {
                if (i == 1) {
                    matriceConnection[i].push_back(0);
                }
                else {
                    matriceConnection[i].push_back(1);
                }
            }
        }
    }
    //cout << "OWO Connections:   w=" << wC << " h=" << hC << " x=" << xC << " y=" << yC << endl;

    Connection laConnection = Connection(xC, yC, &uneRoom, &aConnecter, estVertical, matriceConnection);

    //cout << "VERIF x= " << laConnection.getX() << "  Y=" << laConnection.getY() << endl;
    // Ajoute les index de room annexe à la connection
    _lesConnections.push_back(laConnection);

    _rooms[_rooms.size()-1].addConnection(_lesConnections.size()-1); // La nouvelle room ajouté
    _rooms[roomIDSelected].addConnection(_lesConnections.size() - 1); // La room selectionné pour y être connecté

    _lesConnections[_lesConnections.size()-1].addRoom(_rooms.size() - 1);
    _lesConnections[_lesConnections.size() - 1].addRoom(roomIDSelected);

}
void ZoneRoom::setW(uint32_t w) {
    _w = w;
}
void ZoneRoom::setH(uint32_t h) {
    _h = h;
}


vector<uint32_t> ZoneRoom::getBotFree() const {
    vector<uint32_t> lesRooms;

    uint32_t w, h, w2, h2;
    int64_t x, y, x2, y2;
    int64_t jusquaX, jusquaY, jusquaX2, jusquaY2;

    bool doAdd;
    for (uint32_t i = 0; i < _rooms.size(); i++) {
        doAdd = true;
        x = _rooms[i].getX();
        y = _rooms[i].getY();
        w = _rooms[i].getW();
        h = _rooms[i].getH();

        jusquaX = x + w;
        jusquaY = y + h;
        for (uint32_t l = 0; l < _rooms.size(); l++) {
            if (i != l) {
                x2 = _rooms[l].getX();
                y2 = _rooms[l].getY();
                w2 = _rooms[l].getW();
                h2 = _rooms[l].getH();

                jusquaX2 = x2 + w2;
                jusquaY2 = y2 + h2;

                if (y < y2) {
                    if ((x < x2 && jusquaX >= x2) || (x >= x2 && x <= jusquaX2)) {
                        doAdd = false;
                        break;
                    }
                }
            }
        }
        if (doAdd) {
            lesRooms.push_back(i);
        }
    }
    return lesRooms;
}
vector<uint32_t> ZoneRoom::getRightFree() const {
    vector<uint32_t> lesRooms;

    uint32_t w, h, w2, h2;
    int64_t x, y, x2, y2;
    int64_t jusquaX, jusquaY, jusquaX2, jusquaY2;

    bool doAdd;
    for (uint32_t i = 0; i < _rooms.size(); i++) {
        doAdd = true;
        x = _rooms[i].getX();
        y = _rooms[i].getY();
        w = _rooms[i].getW();
        h = _rooms[i].getH();

        jusquaX = x + w;
        jusquaY = y + h;
        for (uint32_t l = 0; l < _rooms.size(); l++) {
            if (i != l) {
                x2 = _rooms[l].getX();
                y2 = _rooms[l].getY();
                w2 = _rooms[l].getW();
                h2 = _rooms[l].getH();

                jusquaX2 = x2 + w2;
                jusquaY2 = y2 + h2;
                //    //cout << "Verif... " << _rooms[i].getID() << " POUR " << _rooms[l].getID() << "   ";
                  //  //cout << (x<x2) << " et: " << (y<y2 && jusquaY >= y2) << (y>=y2 && y <= jusquaY2) << endl;
                if (x < x2) {
                    if ((y < y2 && jusquaY >= y2) || (y >= y2 && y <= jusquaY2)) {
                        doAdd = false;
                        ////cout << "Nopn!!!" << endl;
                        break;
                    }
                }

            }
        }
        if (doAdd) {
            lesRooms.push_back(i);
        }
    }
    return lesRooms;
}
vector<uint32_t> ZoneRoom::getTopFree() const {
    vector<uint32_t> lesRooms;

    uint32_t w, h, w2, h2;
    int64_t x, y, x2, y2;
    int64_t jusquaX, jusquaY, jusquaX2, jusquaY2;

    bool doAdd;
    for (uint32_t i = 0; i < _rooms.size(); i++) {
        doAdd = true;
        x = _rooms[i].getX();
        y = _rooms[i].getY();
        w = _rooms[i].getW();
        h = _rooms[i].getH();

        jusquaX = x + w;
        jusquaY = y + h;
        for (uint32_t l = 0; l < _rooms.size(); l++) {
            if (i != l) {
                x2 = _rooms[l].getX();
                y2 = _rooms[l].getY();
                w2 = _rooms[l].getW();
                h2 = _rooms[l].getH();

                jusquaX2 = x2 + w2;
                jusquaY2 = y2 + h2;

                if (y > y2) {
                    if ((x < x2 && jusquaX >= x2) || (x >= x2 && x <= jusquaX2)) {
                        doAdd = false;
                        break;
                    }
                }
            }
        }
        if (doAdd) {
            lesRooms.push_back(i);
        }
    }
    return lesRooms;
}
vector<uint32_t> ZoneRoom::getLeftFree() const {
    vector<uint32_t> lesRooms;

    uint32_t w, h, w2, h2;
    int64_t x, y, x2, y2;
    int64_t jusquaY, jusquaY2;

    bool doAdd;
    for (uint32_t i = 0; i < _rooms.size(); i++) {
        doAdd = true;
        x = _rooms[i].getX();
        y = _rooms[i].getY();
        w = _rooms[i].getW();
        h = _rooms[i].getH();

        jusquaY = y + h;
        for (uint32_t l = 0; l < _rooms.size(); l++) {
            if (i != l) {
                x2 = _rooms[l].getX();
                y2 = _rooms[l].getY();
                w2 = _rooms[l].getW();
                h2 = _rooms[l].getH();

                jusquaY2 = y2 + h2;

                if (x > x2) {
                    if ((y < y2 && jusquaY >= y2) || (y >= y2 && y <= jusquaY2)) {
                        doAdd = false;
                        break;
                    }
                }
            }
        }
        if (doAdd) {
            lesRooms.push_back(i);
        }
    }
    return lesRooms;
}



int64_t ZoneRoom::getMaxX() const {
    int64_t maxX = 0;
    int64_t checkX;
    for (uint32_t i = 0; i < _rooms.size(); i++) {
        checkX = _rooms[i].getX();
        if (checkX > maxX) {
            maxX = checkX;
        }
    }
    return maxX;
}
int64_t ZoneRoom::getMaxY() const {
    int64_t maxY = 0;
    int64_t checkY;
    for (uint32_t i = 0; i < _rooms.size(); i++) {
        checkY = _rooms[i].getY();
        if (checkY > maxY) {
            maxY = checkY;
        }
    }
    return maxY;
}
int64_t ZoneRoom::getMinX() const {
    int64_t minX = 0;
    int64_t checkX;
    for (uint32_t i = 0; i < _rooms.size(); i++) {
        checkX = _rooms[i].getX();
        if (checkX < minX) {
            minX = checkX;
        }
    }
    return minX;
}
int64_t ZoneRoom::getMinY() const {
    int64_t minY = 0;
    int64_t checkY;
    for (uint32_t i = 0; i < _rooms.size(); i++) {
        checkY = _rooms[i].getY();
        if (checkY < minY) {
            minY = checkY;
        }
    }
    return minY;
}

bool ZoneRoom::isFree(int64_t x, int64_t y, uint32_t w, uint32_t h) const {
    uint32_t w2, h2;
    int64_t x2, y2;
    int64_t jusquaX2, jusquaY2;

    int64_t jusquaX = x + w;
    int64_t jusquaY = y + h;
    ////cout << x << " Y:" << y << endl;
    for (uint32_t k = 0; k < _rooms.size(); k++) {
        Room uneRoom = _rooms[k];

        x2 = uneRoom.getX();
        y2 = uneRoom.getY();

        w2 = uneRoom.getW();
        h2 = uneRoom.getH();

        jusquaX2 = x2 + w2;
        jusquaY2 = y2 + h2;

        if ((y < y2 && jusquaY >= y2) || (y >= y2 && y <= jusquaY2)) {
            if ((x < x2 && jusquaX >= x2) || (x >= x2 && x <= jusquaX2)) {
                return false;
            }
        }
    }
    for (uint32_t k = 0; k < _lesConnections.size(); k++) {
        Connection uneConnection = _lesConnections[k];
        x2 = uneConnection.getX();
        y2 = uneConnection.getY();

        w2 = uneConnection.getW();
        h2 = uneConnection.getH();

        jusquaX2 = x2 + w2;
        jusquaY2 = y2 + h2;

        if ((y < y2 && jusquaY >= y2) || (y >= y2 && y <= jusquaY2)) {
            if ((x < x2 && jusquaX >= x2) || (x >= x2 && x <= jusquaX2)) {
                return false;
            }
        }
    }

    return true;
}

void ZoneRoom::addConnection(Connection& uneConnection) {
    _lesConnections.push_back(uneConnection);
}

vector<Connection> ZoneRoom::getConnections() const {
    return _lesConnections;
}

void ZoneRoom::makeIntersection() {

    uint32_t w, h, w2, h2;
    int64_t x, y, x2, y2;
    int64_t jusquaX, jusquaY, jusquaX2, jusquaY2;
    bool estVertical;

    for (uint32_t i = 0; i < _lesConnections.size(); i++) {
        //cout << "====== " << i << endl;
        Connection& uneConnection = _lesConnections[i];

        x = uneConnection.getX();
        y = uneConnection.getY();

        w = uneConnection.getW();
        h = uneConnection.getH();

        jusquaX = x + w;
        jusquaY = y + h;

        estVertical = uneConnection.estVertical();

        for (uint32_t k = 0; k < _lesConnections.size(); k++) {
            if (k != i) {
                ////cout << k << ":" << i << endl;
                x2 = _lesConnections[k].getX();
                y2 = _lesConnections[k].getY();

                w2 = _lesConnections[k].getW();
                h2 = _lesConnections[k].getH();

                jusquaX2 = x2 + w2;
                jusquaY2 = y2 + h2;


                if ((y < y2 && jusquaY >= y2) || (y >= y2 && y <= jusquaY2)) {
                    if ((x < x2 && jusquaX >= x2) || (x >= x2 && x <= jusquaX2)) {
                        //cout << "Oui Pour " << k << endl;
                        if (estVertical) {
                            //cout << "EST VERTICAL !  Ligne: " << (abs(y - y2) + 3) << endl;
                            uneConnection.modifyMatrice((abs(y - y2) + 1), 0, 0);
                            uneConnection.modifyMatrice((abs(y - y2) + 1), 2, 0);
                        }
                        else {
                            //cout << "EST Horizontal !  Ligne: " << abs(x2) - abs(x) << " " << endl;
                            uint64_t val = abs(abs(x2) - abs(x));
                            uneConnection.modifyMatrice(0, val + 1, 0);
                            uneConnection.modifyMatrice(2, val + 1, 0);
                        }

                    }
                }
            }
        }
    }
}

void ZoneRoom::makeNodes() {
    for (uint32_t i = 0; i < _lesConnections.size(); i++) {
        vector<uint32_t> lesRooms = _lesConnections[i].getRooms();


        if (_lesConnections[i].estVertical()) {

            Node a(i, true,_lesConnections[i].getX() * 32 + 32 + 16, _lesConnections[i].getY()*32 - 10); // Haut
            Node b(i, true, _lesConnections[i].getX() * 32 + 32 + 16, _lesConnections[i].getY() * 32 + _lesConnections[i].getH()*32 + 30);
            
            a.addConnection(b);
            b.addConnection(a);

            // ajoute Node dans les rooms
            // ajout Node dans les rooms
            int64_t yA = _rooms[lesRooms[0]].getY();
            int64_t yB = _rooms[lesRooms[1]].getY();
           // uint32_t hA = _rooms[lesRooms[0]].getH();
            //Node a;
            //Node b;
            Node c;
            Node d;
            if (yA < yB) {
                c = Node(lesRooms[0], false, _lesConnections[i].getX() * 32 + 32 + 16, _lesConnections[i].getY() * 32 - 64); // haut
                d = Node(lesRooms[1], false, _lesConnections[i].getX() * 32 + 32 + 16, _lesConnections[i].getY() * 32 + _lesConnections[i].getH() * 32 + 64);
            }
            else {
                c = Node(lesRooms[1], false, _lesConnections[i].getX() * 32 + 32 + 16, _lesConnections[i].getY() * 32 - 64); // haut
                d = Node(lesRooms[0], false, _lesConnections[i].getX() * 32 + 32 + 16, _lesConnections[i].getY() * 32 + _lesConnections[i].getH() * 32 + 64);
            }

            a.addConnection(c);
            c.addConnection(a);

            b.addConnection(d);
            d.addConnection(b);

            a.setLabel(" Haut ");
            b.setLabel(" Bas ");
            c.setLabel( " R Haut ");
            d.setLabel( " R Bas ");
            _lesNodes.push_back(a);
            _lesNodes.push_back(b);
            _lesNodes.push_back(c);
            _lesNodes.push_back(d);
        }
        else {

            Node a(i, true, _lesConnections[i].getX() * 32 + 32, _lesConnections[i].getY() * 32 + 32 + 16); // Gauche
            Node b(i, true, _lesConnections[i].getX() * 32 + _lesConnections[i].getW() * 32 - 32, _lesConnections[i].getY() * 32 +32 + 16 ); // Droite

            a.addConnection(b);
            b.addConnection(a);

            // ajoute Node dans les rooms
            // ajout Node dans les rooms
            int64_t xA = _rooms[lesRooms[0]].getX();
            int64_t xB = _rooms[lesRooms[1]].getX();
            //uint32_t wA = _rooms[lesRooms[0]].getW();

            Node c;
            Node d;
            if (xA < xB) {
                c = Node(lesRooms[0], false, _lesConnections[i].getX() * 32 - 32, _lesConnections[i].getY() * 32 + 32 + 16); // Gauche ?
                d = Node(lesRooms[1], false, _lesConnections[i].getX() * 32 + _lesConnections[i].getW() * 32 + 32, _lesConnections[i].getY() * 32 + 32 + 16);
            }
            else {
                c = Node(lesRooms[1], false, _lesConnections[i].getX() * 32 - 32, _lesConnections[i].getY() * 32 + 32 + 16); // Gauche ?
                d = Node(lesRooms[0], false, _lesConnections[i].getX() * 32 + _lesConnections[i].getW() * 32 + 32, _lesConnections[i].getY() * 32 + 32 + 16);
            }

            a.addConnection(c);
            c.addConnection(a);

            b.addConnection(d);
            d.addConnection(b);

            a.setLabel(" Haut ");
            b.setLabel(" Bas ");
            c.setLabel(" R Haut ");
            d.setLabel(" R Bas ");

            _lesNodes.push_back(a);
            _lesNodes.push_back(b);
            _lesNodes.push_back(c);
            _lesNodes.push_back(d);
        }
    }
    // Ajoute les connections entre les nodes des salles
    for (uint32_t i = 0; i < _lesNodes.size(); i++) {
        if (_lesNodes[i].estConnection()) {
            continue;
        }
        for (uint32_t j = 0; j < _lesNodes.size(); j++) {
            if (i != j && !_lesNodes[j].estConnection()) {
                if (_lesNodes[i].getIdSalle() == _lesNodes[j].getIdSalle()) {
                    _lesNodes[i].addConnection(_lesNodes[j]);
                }
            }
        }
    }
}
void ZoneRoom::makeTiles() {
    for (uint32_t i = 0; i <_lesConnections.size(); i++) {
        _lesConnections[i].applyTiles(_leTheme);
    }
    for (uint32_t i = 0; i < _rooms.size(); i++) {
        _rooms[i].applyTiles(_leTheme);
    }
}

void ZoneRoom::makeWalls() {
//    _walls = vector<Wall>();
    for (uint32_t i = 0; i < _lesConnections.size(); i++) {
        _lesConnections[i].applyWalls();
    }
    for (uint32_t i = 0; i < _rooms.size(); i++) {
       _rooms[i].applyWalls();
   }
 
   for (uint32_t i = 0; i < _lesConnections.size(); i++) {
        vector<Wall> lesW = _lesConnections[i].getWalls();
        for (uint32_t k = 0; k < lesW.size(); k++) {
            _walls.push_back(lesW[k]);
        }
    }
    for (uint32_t i = 0; i < _rooms.size(); i++) {
        vector<Wall> lesW = _rooms[i].getWalls();
        for (uint32_t k = 0; k < lesW.size(); k++) {
            _walls.push_back(lesW[k]);
        }
    }
    ////cout << "NBTOT WALL = " << _walls.size() << " EREEEEEEEEEEEEEEEEEEE" << endl;
}

vector<Node> ZoneRoom::getNodes() {
    return _lesNodes;
}

vector<Wall> ZoneRoom::getWalls() {
    return _walls;
}