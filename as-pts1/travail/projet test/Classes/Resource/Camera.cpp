

#include "..\Header\Camera.hpp"
#include "..\Header\MoveableObject.hpp"
#include "..\Header\Map.hpp"
#include <SFML/Graphics.hpp>


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
    //dessin des murs :
    for (int i = 0; i < m.getWallList().size(); i++) {
        sf::Vertex line[] = {
            //créé un rectangle avec les coordonnées stockées dans WallList
            sf::Vertex(sf::Vector2f(m.getWallList().at(i).getHG().x, m.getWallList().at(i).getHG().y)),
            sf::Vertex(sf::Vector2f(m.getWallList().at(i).getHD().x, m.getWallList().at(i).getHD().y)),
            sf::Vertex(sf::Vector2f(m.getWallList().at(i).getBD().x, m.getWallList().at(i).getBD().y)),
            sf::Vertex(sf::Vector2f(m.getWallList().at(i).getBG().x, m.getWallList().at(i).getBG().y))
        };
        _window.draw(line, 2, sf::Lines);
    }
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