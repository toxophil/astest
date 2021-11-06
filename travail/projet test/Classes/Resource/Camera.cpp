
/* Generated from GenMyModel */

#include "..\Header\Camera.hpp"
#include "..\Header\MoveableObject.hpp"
#include "..\Header\Map.hpp"
#include <SFML/Graphics.hpp>






void Camera::drawMap(Map m, sf::RenderWindow window)
{

}

void Camera::drawObject(vector<MoveableObject> objectList, sf::RenderWindow window) {
    while (window.isOpen()) {
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
}