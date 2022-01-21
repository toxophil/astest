
#include "../Header/Map.hpp"
#include "../Header/GameMaster.hpp"
#include <vector>

Map::Map() {}
Map::Map(vector<Room> roomList, vector<Connection> lesConnections, vector<Wall> wallList, vector<Node> nodeList) {
    _roomList = roomList;
    _lesConnections = lesConnections;
    _wallList = wallList;
    _nodeList = nodeList;

    for (uint32_t i = 0; i < _nodeList.size(); i++) {
        cout << "Check node " << i << " nb Connection:" << _nodeList[i].getConnections().size() << " ID Salle:" << _nodeList[i].getIdSalle() << " EstConnection:" << _nodeList[i].estConnection() << endl;
        cout << " :::: Connections:" << endl;
            for (uint32_t j = 0; j < _nodeList[i].getConnections().size(); j++) {
                cout << "        Connected to: " << " ID Salle:" << _nodeList[i].getConnections()[j].getIdSalle() << " EstConnection:" << _nodeList[i].getConnections()[j].estConnection() << endl;
            }
    }
    
    ee.restart();
}
Map::Map(vector<Room> roomList, vector<Connection> lesConnections) {
    _roomList = roomList;
    _lesConnections = lesConnections;
}
vector<Room> Map::getRoomList() const {
    return _roomList;
}
vector<Connection> Map::getConnections() const {
    return _lesConnections;
}
vector<Wall> Map::getWallList() const {
    return _wallList;
}

void Map::addRoom(const Room& room) {
    _roomList.push_back(room);
}

int32_t Map::getRoomByPos(sf::Vector2f pos) const {
    for (uint32_t i = 0; i < _roomList.size(); i++) {
        if (pos.x >= _roomList[i].getX()*32 && pos.x <= _roomList[i].getX()*32 + _roomList[i].getW()*32 && pos.y >= _roomList[i].getY()*32 + 32 && pos.y <= _roomList[i].getY()*32 + _roomList[i].getH()*32 - 20) {
            return i;
        }
    }
    return -1;
}
int32_t Map::getConnectionByPos(sf::Vector2f pos) const {
    for (uint32_t i = 0; i < _lesConnections.size(); i++) {
        if (pos.x >= _lesConnections[i].getX() * 32 && pos.x <= _lesConnections[i].getX() * 32 + _lesConnections[i].getW() * 32 && pos.y >= _lesConnections[i].getY() * 32 - 20 && pos.y <= _lesConnections[i].getY() * 32 + _lesConnections[i].getH() * 32 + 32) {
            return i;
        }
    }
    return -1;
}

double Map::getDistance(sf::Vector2f posA, sf::Vector2f posB) const  {
    return sqrt(pow((posB.x - posA.x),2) + pow((posB.y - posA.y), 2));
}

uint32_t Map::getNearestNode(sf::Vector2f pos) const {
    int32_t salleId;
    Node bestNode;
    uint32_t nodeId = 0;

    //cout << "Nodelist nearest: " << _nodeList.size() << endl;
    double dist = 10000000000;
    if (getConnectionByPos(pos) != -1) {
        salleId = getConnectionByPos(pos);
        for (uint32_t i = 0; i < _nodeList.size(); i++) {
            if (_nodeList[i].getIdSalle() == salleId && _nodeList[i].estConnection()) {
                double newDist = getDistance(sf::Vector2f(_nodeList[i].getX(), _nodeList[i].getY()), pos);
                if (newDist < dist) {
                    dist = newDist;
                    bestNode = _nodeList[i];
                    nodeId = i;
                    // cout << "Best node trouver " << i << endl;
                }
            }
        }
    }
    else if (getRoomByPos(pos) != -1) {
        salleId = getRoomByPos(pos);
        for (uint32_t i = 0; i < _nodeList.size(); i++) {
            if (_nodeList[i].getIdSalle() == salleId && !_nodeList[i].estConnection()) {
                double newDist = getDistance(sf::Vector2f(_nodeList[i].getX(), _nodeList[i].getY()), pos);
                if (newDist < dist) {
                    dist = newDist;
                    bestNode = _nodeList[i];
                    nodeId = i;
                    //cout << "Best node trouver " << i << endl;
                }
            }
        }
    }
    return nodeId;
}

uint32_t Map::getRealNode(Node copyNode) {
    for (uint32_t i = 0; i < _nodeList.size(); i++) {
        if (copyNode == _nodeList[i]) {
            return i;
        }
    }
    return 0;
}
vector<Node> Map::getNodePathTo(vector<Node> nodePathList,Node toGo, vector<Node> alreadyCheckedNode = vector<Node>() ) {
    Node lastNode = _nodeList[getRealNode(nodePathList[nodePathList.size() - 1])];
    vector<Node> nodeConnections = lastNode.getConnections();
    //cout << "==================" << endl;
    alreadyCheckedNode.push_back(lastNode);
    // cout << "Last = " << lastNode.getX() << lastNode.getY() << endl;
    //cout << "PAth=" << nodePathList.size() << endl;
    //cout << "NB COnnections " << _nodeList[getRealNode(lastNode)].getConnections().size() <<  " Check nb:" << nodePathList[nodePathList.size()-1].getConnections().size() << endl;
     //cout << " LAST NODE =  " << lastNode.getIdSalle() << " " << lastNode.estConnection()  <<  "label: " + lastNode.getLabel().toAnsiString() << endl;
     //cout << "FUll Path = " << endl;
     /*for (uint32_t i = 0; i < nodePathList.size(); i++) {
         cout << nodePathList[i].getIdSalle() << " " << nodePathList[i].estConnection() << endl;
     }*/

    bool skip = false;
    for (int i = 0; i < nodeConnections.size(); i++) {
        // cout << " Check " << nodeConnections[i].getIdSalle() << " " << nodeConnections[i].estConnection() << endl;
        skip = false;
        for (int j = 0; j < alreadyCheckedNode.size(); j++) {
            if (nodeConnections[i] == alreadyCheckedNode[j]) {
                
                skip = true;
                break;
            }
        }
        if (skip) {
            //    cout << "Yup skip" << endl;
            continue;
        }
        
        //cout << " Check " << nodeConnections[i].getIdSalle() << " " << nodeConnections[i].estConnection() << endl;
       //  cout << "Check " << nodeConnections[i].getX() << "  " << nodeConnections[i].getY() << " WITH" << toGo.getX() << "  " << toGo.getY() << endl;
        if (nodeConnections[i] == toGo) { // Trouvé ! c'est le bon chemin, on retourne le chemin
            nodePathList.push_back(nodeConnections[i]);
           // cout << "TROUVER§§§§§!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!§!  PATH LIST:" << endl;
          /*  for (uint32_t k = 0; k < nodePathList.size(); k++) {
                cout << "k: " << k << " " << nodePathList[k].getIdSalle() << endl;
            }*/
            return nodePathList;
        }
        else if (nodePathList.size() < 3){ // limit de node, sinon ça lag trop
            vector<Node> newNodePathList = nodePathList;
            newNodePathList.push_back(nodeConnections[i]);
            //  cout << "Check next ..." << endl;
            return getNodePathTo(newNodePathList, toGo, alreadyCheckedNode);
        }
    }
    if (nodePathList.size() <= 1) {
         //cout << "Nop..." << endl;
        return nodePathList;
    }
    nodePathList.pop_back(); // revient en arrière
    return getNodePathTo(nodePathList, toGo, alreadyCheckedNode);
}

sf::Vector2f Map::getNextNodePos(sf::Vector2f actualPos, sf::Vector2f toGoPos) {
    vector<Node> openNode;
    vector<Node> previousNode;
    vector<int64_t> distanceFromActual;
    vector<int64_t> distanceFromToGo;

    Node actualNode = _nodeList[getNearestNode(actualPos)];
    Node toGoNode = _nodeList[getNearestNode(toGoPos)];
    /*
    cout << "========================================" << endl;
    cout << "ROOM POS:" << getRoomByPos(toGoPos) << " CONNECTIONPOS: " << getConnectionByPos(toGoPos) << endl;
     

    //cout << "AHHH actualNode Size: " << toGoNode.getConnections().size() << endl;
    //cout << "'===" << endl;
    cout << "actualNode Check " << toGoNode.getIdSalle() << " " << toGoNode.estConnection() << endl;
    cout << "IANode Check " << actualNode.getIdSalle() << " " << actualNode.estConnection() << endl;
    cout << "VERIF ? " << endl;
    for (uint32_t i = 0; i < _nodeList.size(); i++) {
        cout << _nodeList[i].getIdSalle() << " " << _nodeList[i].estConnection()  << " NBCO?: " << _nodeList[i].getConnections().size() << endl;
    }
    cout << "FIN VERIF" << endl;

    cout << ee.getElapsedTime().asMilliseconds() << endl;*/
    vector<Node> nodeBeginPath;
    nodeBeginPath.push_back(actualNode);

    vector<Node> nodePathToGo = getNodePathTo(nodeBeginPath,toGoNode);
    if (nodePathToGo.size() > 1) {
        return sf::Vector2f(nodePathToGo[1].getX(), nodePathToGo[1].getY()); // Retourne la pos de la  prochaine node à franchir
    }
    else {
        return sf::Vector2f(actualNode.getX(), actualNode.getY());
    }
}