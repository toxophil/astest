#include "..\Header\Room.hpp"
#include "..\Header\Connection.hpp"
#include "..\Header\GameMaster.hpp"

Room::Room() {
    _matrice = vector<vector<uint32_t>>();
    _id = -1;
    _x = 0;
    _y = 0;
}
Room::Room(uint32_t id, vector<vector<uint32_t>> matrice) {
    _matrice = matrice;
    _id = id;
    _x = 0;
    _y = 0;
}

vector<vector<uint32_t>> Room::getMatrice() const {
    return _matrice;
}

int64_t Room::getX() const {
    return _x;
}
int64_t Room::getY() const {
    return _y;
}
uint32_t Room::getW() const {
    return _matrice[0].size();
}
uint32_t Room::getH() const {
    return _matrice.size();
}

uint32_t Room::getID() const {
    return _id;
}

vector<RoomObject> Room::getContained() const {
    return _contained;
}
void Room::addContained(RoomObject& objet) {
    _contained.push_back(objet);
}

void Room::setX(int64_t x) {
    _x = x;
}
void Room::setY(int64_t y) {
    _y = y;
}

uint32_t Room::getNbConnection() const {
    return _lesConnections.size();
}
void Room::addConnection(Connection& uneConnection) {
    _lesConnections.push_back(&uneConnection);
}


void Room::modifyMatrice(int32_t l, int32_t c, uint32_t val) {
    _matrice[l][c] = val;
}

void Connection::applyTiles() {
    sf::Sprite sprite;

    _tiles = vector<sf::Sprite>();

    for (uint32_t i = 0; i < getH(); i++) {
        for (uint32_t r = 0; r < getW(); r++) {
            uint32_t indice = _tiles.size();
            _tiles.push_back(sprite);

            if (_matrice[i][r] == 0) {
                _tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Floor1));
                _tiles[indice].setPosition(_x * 32 + (int64_t)r * 32, _y * 32 + (int64_t)i * 32);
                _tiles.push_back(sprite);
                indice++;

            }
            else {
                if (i == 0 || i == getH() - 1) { // HAUT / BAS
                    _tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::WallRL));
                    _tiles[indice].setPosition(_x * 32 + (int64_t)r * 32, _y * 32 + (int64_t)i * 32);
                    _tiles.push_back(sprite);
                    indice++;

                    if (i == 0) { // En Haut

                        if (r == 0) { // à gauche
                            _tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::LeftTop));
                            _tiles[indice].setPosition(_x * 32, _y * 32);
                            _tiles.push_back(sprite);
                            indice++;
                        }
                        else if (r == getW() - 1) {
                            _tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::RightTop));
                            _tiles[indice].setPosition(_x * 32 + (int64_t)r * (int64_t)32, _y * 32);
                            _tiles.push_back(sprite);
                            indice++;
                        }
                    }
                    else { // En Bas
                        if (r < getW() - 1) {
                            if (_matrice[i][r + 1] == 0) {
                                //textureWallTopLeft
                                //textureWallTopRight
                                _tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::RightTop));
                                _tiles[indice].setPosition(_x * 32 + (int64_t)r * 32, _y * 32 + (int64_t)i * 32);
                                _tiles.push_back(sprite);
                                indice++;
                            }
                        }
                        if (r > 0) {
                            if (_matrice[i][r - 1] == 0) {
                                //textureWallTopLeft
                                //textureWallTopRight
                                _tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::LeftTop));
                                _tiles[indice].setPosition(_x * 32 + (int64_t)r * 32, _y * 32 + (int64_t)i * 32);
                                _tiles.push_back(sprite);
                                indice++;
                            }
                        }
                    }
                }
                else if (_matrice[i][r] != 0) { // Millieu

                    _tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Floor1));
                    _tiles[indice].setPosition(_x * 32 + (int64_t)r * 32, _y * 32 + (int64_t)i * 32);
                    _tiles.push_back(sprite);
                    indice++;

                    if (r == 0) { // Gauche
                        _tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::WallLeft));
                        _tiles[indice].setPosition(_x * 32, _y * 32 + (int64_t)i * 32);
                        _tiles.push_back(sprite);
                        indice++;

                    }
                    else if (r == getW() - 1) {
                        _tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::WallRight));
                        _tiles[indice].setPosition(_x * 32 + (int64_t)r * 32, _y * 32 + (int64_t)i * 32);
                        _tiles.push_back(sprite);
                    }
                }
            }
        }
    }
}

vector<sf::Sprite> Connection::getTiles() const {
    return _tiles;
}