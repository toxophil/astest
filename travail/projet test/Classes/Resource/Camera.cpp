

#include "..\Header\Camera.hpp"
#include "..\Header\MoveableObject.hpp"
#include "..\Header\Map.hpp"
#include <SFML/Graphics.hpp>


Camera::Camera() {
    _x = 0;
    _y = 0;
    _window.setSize(sf::Vector2u(1920, 1080));
    _window.setTitle("Super Dédale Bros ULtimate 2 feat. Dante from Devil May Cry EXTENDED Edition ver 1.246859553");
    _window.setFramerateLimit(60);
}

Camera::Camera(int x, int y) {
    _x = x;
    _y = y;
    _window.setSize(sf::Vector2u(1920, 1080));
    _window.setTitle("Super Dédale Bros ULtimate 2 feat. Dante from Devil May Cry EXTENDED Edition ver 1.246859553");
    _window.setFramerateLimit(60);
}

sf::RenderWindow& Camera::getWindow() {
    return _window;
}


void Camera::drawMap(Map m) {
    //dessin des murs :
    for (int i = 0; i < m.getWallList().size(); i++) {
        sf::Vertex line[] = {
            //créer uun vecteur avec les 2 coordonnées stockées dans WallList
            sf::Vertex(sf::Vector2f(m.getWallList().at(i).getPoint1().x, m.getWallList().at(i).getPoint1().y)),
            sf::Vertex(sf::Vector2f(m.getWallList().at(i).getPoint2().x, m.getWallList().at(i).getPoint2().y))
        };
        _window.draw(line, 2, sf::Lines);
    }
}

void Camera::drawAll(const list<MoveableObject*> objectList, const Map m) {
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