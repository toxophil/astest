#include "../Header/Wall.hpp"


Wall::Wall(int64_t x, int64_t y, uint32_t w, uint32_t h) {
    _x = x;
    _y = y;
    _w = w;
    _h = h;
}

int64_t Wall::getY() const {
    return _y;
}
int64_t Wall::getX() const {
    return _x;
}

uint32_t Wall::getW() const {
    return _w;
}
uint32_t Wall::getH() const {
    return _h;
}
sf::Vector2i Wall::getHG() const {
    sf::Vector2i pt;
    pt.x = _x + _h / 2;
    pt.y = _y - _w / 2;
    return pt;
}
sf::Vector2i Wall::getHD() const {
    sf::Vector2i pt;
    pt.x = _x + _h / 2;
    pt.y = _y + _w / 2;
    return pt;
}
sf::Vector2i Wall::getBG() const {
    sf::Vector2i pt;
    pt.x = _x - _h / 2;
    pt.y = _y - _w / 2;
    return pt;
}
sf::Vector2i Wall::getBD() const {
    sf::Vector2i pt;
    pt.x = _x - _h / 2;
    pt.y = _y + _w / 2;
    return pt;
}

