
/* Generated from GenMyModel */

#include "..\Header\Camera.hpp"
#include "..\Header\MoveableObject.hpp"
#include "..\Header\Map.hpp"
#include <SFML/Graphics.hpp>


Camera::Camera() {

}



void Camera::drawMap(const Map m, sf::RenderWindow& window)const{

}

void Camera::drawAll(const vector<DrawableObject>& objectList, sf::RenderWindow& window, const Map m)const{
    while (window.isOpen()) {
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        drawMap(m, window);
        for (uint32_t i = 0; i < objectList.size(); i++) {
            drawObject(objectList.at(i), window);
        }
        window.display();
    }
}

void Camera::drawObject(const DrawableObject& object, sf::RenderWindow& window)const {
    
}