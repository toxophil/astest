#include "..\Header\Connection.hpp"
#include "..\Header\Room.hpp"
//#include "..\Header\GameMaster.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

Connection::Connection(int64_t x, int64_t y, Room* roomA, Room* roomB, bool estVertical, vector<vector<uint32_t>> matrice) {
    _x = x;
    _y = y;
    _roomA = roomA;
    _roomB = roomB;
    _estVertical = estVertical;
    _matrice = matrice;
}
int64_t Connection::getX() const {
    return _x;
}
int64_t Connection::getY() const {
    return _y;
}
uint32_t Connection::getW() const {
    return _matrice[0].size();
}
uint32_t Connection::getH() const {
    return _matrice.size();
}
bool Connection::estVertical() const {
    return _estVertical;
}

vector<vector<uint32_t>> Connection::getMatrice() const {
    return _matrice;
}

void Connection::modifyMatrice(int32_t l, int32_t c, uint32_t val) {
    _matrice[l][c] = val;
}

void Connection::applyTiles() {
    Sprite sprite;

    uint32_t h = _matrice.size();
    uint32_t w = _matrice[0].size();

    _tiles = vector<Sprite>();
    for (uint32_t i = 0; i < h; i++) {
        for (uint32_t r = 0; r < w; r++) {
            uint32_t indice = _tiles.size();
            _tiles.push_back(sprite);

            if (_matrice[i][r] == 0) {
                //_tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Floor1));
                _tiles[indice].setPosition(_x * 32 + r * 32, _y * 32 + i * 32);
                _tiles.push_back(sprite);
                indice++;
            }
            else {
                if (!estVertical) {

                    //_tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::WallRL));
                    _tiles[indice].setPosition(_x * 32 + r * 32, _y * 32 + i * 32);
                    _tiles.push_back(sprite);
                    indice++;
                }
                else if (r == 0) {
                    //_tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::WallRight));
                    _tiles[indice].setPosition(_x * 32 + r * 32, _y * 32 + i * 32);
                    _tiles.push_back(sprite);
                    indice++;
                }
                else if (r == 2) {
                    //_tiles[indice].setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::WallLeft));
                    _tiles[indice].setPosition(_x * 32 + r * 32, _y * 32 + i * 32);
                    _tiles.push_back(sprite);
                    indice++;
                }
            }
        }
    }
}

vector<Sprite> Connection::getTiles() const {
    return _tiles;
}