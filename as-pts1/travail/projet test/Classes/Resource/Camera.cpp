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

void Camera::drawMap(sf::RenderWindow& window, Map m, sf::Vector2f playerPos) {
    vector<Connection>& lesConnections = m.getConnections();
    vector<Room>& lesRooms = m.getRoomList();

    bool trouver = false;
    for (uint32_t i = 0; i < lesRooms.size(); i++) {
        Room& uneRoom = lesRooms[i];
        if (uneRoom.getX() * 32 < playerPos.x && uneRoom.getX() * 32 + (int)uneRoom.getW() * 32 > playerPos.x) {
            if (uneRoom.getY() * 32 < playerPos.y && uneRoom.getY() * 32 + (int)uneRoom.getH() * 32 > playerPos.y) {
                trouver = true;
                vector<sf::Sprite> lesTiles = uneRoom.getTiles();
                for (uint32_t r = 0; r < lesTiles.size(); r++) {
                    window.draw(lesTiles[r]);
                }
                //vector<Connection>& lesConnectionsRoom = lesConnections[uneRoom.getConnections()];
               
                vector<uint32_t>& lesIndexConnections = uneRoom.getConnections();
                //cout << "NB CONNECTIONS: " << lesIndexConnections.size() << endl;
                for (uint32_t i = 0; i < lesIndexConnections.size(); i++) {
                    vector<sf::Sprite> lesTiles = lesConnections[lesIndexConnections[i]].getTiles();
                    for (uint32_t r = 0; r < lesTiles.size(); r++) {
                        window.draw(lesTiles[r]);
                    }
                }

                break;
                //uneRoom.get
            }
        }
    }
    if (!trouver) {
        for (uint32_t i = 0; i < lesRooms.size(); i++) {
            Connection& uneConnection = lesConnections[i];
            if (uneConnection.getX() * 32 < playerPos.x && uneConnection.getX() * 32 + (int)uneConnection.getW() * 32 > playerPos.x) {
                if (uneConnection.getY() * 32 < playerPos.y && uneConnection.getY() * 32 + (int)uneConnection.getH() * 32 > playerPos.y) {

                    vector<sf::Sprite> lesTiles = uneConnection.getTiles();
                    for (uint32_t r = 0; r < lesTiles.size(); r++) {
                        window.draw(lesTiles[r]);
                    }
                    //vector<Connection>& lesConnectionsRoom = lesConnections[uneRoom.getConnections()];
                   
                    vector<uint32_t>& lesIndexRooms = uneConnection.getRooms();
                  //  cout << "NB CONNECTIONS: " << lesIndexRooms.size() << endl;
                    for (uint32_t i = 0; i < lesIndexRooms.size(); i++) {
                        vector<sf::Sprite> lesTiles = lesRooms[lesIndexRooms[i]].getTiles();
                        for (uint32_t r = 0; r < lesTiles.size(); r++) {
                            window.draw(lesTiles[r]);
                        }
                    }

                    break;
                }
            }
        }
    }
   /*for (uint32_t i = 0; i < lesConnections.size(); i++) {
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
    */
}

void Camera::drawAll(sf::RenderWindow& window, const std::list<MoveableObject*> objectList, const Map m) {
    ////cout << "/))) " << endl;
    //drawMap(window,m);
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
    
    ////cout << laPosition.x << " - "<< ((float)mousePosition.x - (float)windowSize.x / 2) << " ET " <<  " y:" << mousePosition.y << endl;
    _laVue.setCenter(laPosition);
    window.setView(_laVue);
}

void Camera::focus(sf::RenderWindow& laWindow) {
    laWindow.setView(_laVue);
}