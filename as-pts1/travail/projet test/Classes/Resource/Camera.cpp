

#include "..\Header\Camera.hpp"
#include "..\Header\MoveableObject.hpp"
#include "..\Header\Map.hpp"
#include <SFML/Graphics.hpp>

#include "..\Header\Room.hpp"
#include "..\Header\Connection.hpp"
#include <vector>

Camera::Camera(){
    _x = 0;
    _y = 0;
    sf::RenderWindow _window(sf::VideoMode(1920, 1080), "Super Dédale Bros ULtimate 2 feat. Dante from Devil May Cry EXTENDED Edition ver 1.246859553");
    _window.setFramerateLimit(60);
}

Camera::Camera(int x, int y) {
    _x = x;
    _y = y;
    sf::RenderWindow _window(sf::VideoMode(1920, 1080), "Super Dédale Bros ULtimate 2 feat. Dante from Devil May Cry EXTENDED Edition ver 1.246859553");
    _window.setFramerateLimit(60);
}

sf::RenderWindow& Camera::getWindow() {
    return _window;
}


void Camera::drawMap(Map m) {
    vector<Connection> lesConnections = m.getConnections();
    vector<Room> lesRooms = m.getRoomList();

   /* for (uint32_t i = 0; i < lesConnections.size(); i++) {
        vector<sf::Sprite> lesTiles = lesConnections[i].getTiles();
        for (uint32_t r = 0; r < lesTiles.size(); r++) {
            _window.draw(lesTiles[r]);
        }
    }
    for (uint32_t i = 0; i < lesRooms.size(); i++) {
        vector<sf::Sprite> lesTiles = lesRooms[i].getTiles();
        for (uint32_t r = 0; r < lesTiles.size(); r++) {
            _window.draw(lesTiles[r]);
        }
    }*/
}

void Camera::drawAll(const std::list<MoveableObject*> objectList, const Map m) {
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        drawMap(m);
        for (MoveableObject* object : objectList) {
            drawObject(object);
        }
        _window.display();
    }
}

void Camera::drawObject(const MoveableObject* object)const {

}