

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
}

Camera::Camera(int x, int y) {
    _x = x;
    _y = y;
}

void Camera::drawMap(sf::RenderWindow& window, Map m) {
    vector<Connection> lesConnections = m.getConnections();
    vector<Room> lesRooms = m.getRoomList();

   for (uint32_t i = 0; i < lesConnections.size(); i++) {
        vector<sf::Sprite> lesTiles = lesConnections[i].getTiles();
        for (uint32_t r = 0; r < lesTiles.size(); r++) {
            window.draw(lesTiles[r]);
        }
    }
    for (uint32_t i = 0; i < lesRooms.size(); i++) {
        vector<sf::Sprite> lesTiles = lesRooms[i].getTiles();
        for (uint32_t r = 0; r < lesTiles.size(); r++) {
            window.draw(lesTiles[r]);
        }
    }

}

void Camera::drawAll(sf::RenderWindow& window, const std::list<MoveableObject*> objectList, const Map m) {
    cout << "/))) " << endl;
    drawMap(window,m);
    for (MoveableObject* object : objectList) {
        drawObject(window, object);
    }
}

void Camera::drawObject(sf::RenderWindow& window, const MoveableObject* object)const {

}