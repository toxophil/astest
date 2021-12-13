#include "../Header/Camera.hpp"
#include "../Header/MoveableObject.hpp"
#include "../Header/Map.hpp"
#include <SFML/Graphics.hpp>

#include "../Header/Room.hpp"
#include "../Header/Connection.hpp"
#include <vector>

Camera::Camera() {
    _x = 0;
    _y = 0;

    sf::VideoMode leScreen = sf::VideoMode::getDesktopMode();
    _laVue = sf::View(sf::Vector2f(0, 0), sf::Vector2f(leScreen.width, leScreen.height));
    _laVue.zoom(0.32);
}

Camera::Camera(int x, int y){
    _x = x;
    _y = y;

    sf::VideoMode leScreen = sf::VideoMode::getDesktopMode();
    _laVue = sf::View(sf::Vector2f(0, 0), sf::Vector2f(leScreen.width, leScreen.height));
    _laVue.zoom(0.32);
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
    //cout << "/))) " << endl;
    drawMap(window,m);
    for (MoveableObject* object : objectList) {
        drawObject(window, object);
    }
}

void Camera::drawObject(sf::RenderWindow& window, const MoveableObject* object)const {

}

void Camera::updateCameraOnPlayer(sf::RenderWindow& window, sf::Vector2f laPosition, sf::FloatRect localBounds) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2u windowSize = window.getSize();

    laPosition.y = laPosition.y + localBounds.height / 2;
    laPosition.x = laPosition.x + localBounds.width / 2;

    float xOffset = (float)mousePosition.x - (float)windowSize.x / 2;
    xOffset = min(xOffset,800.0f);
    xOffset = max(xOffset, -800.0f);

    float yOffset = ( (float)mousePosition.y - (float)windowSize.y / 2);
    yOffset = min(yOffset, 1000.0f);
    yOffset = max(yOffset, -1000.0f);
    
    yOffset = yOffset / 20;
    xOffset = xOffset / 20;
    laPosition.x += xOffset;
    laPosition.y += yOffset;
    
    //cout << laPosition.x << " - "<< ((float)mousePosition.x - (float)windowSize.x / 2) << " ET " <<  " y:" << mousePosition.y << endl;
    _laVue.setCenter(laPosition);
    window.setView(_laVue);
}