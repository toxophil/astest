

#include "..\Header\Camera.hpp"
#include "..\Header\MoveableObject.hpp"
#include "..\Header\Map.hpp"
#include <SFML/Graphics.hpp>


Camera::Camera(){
    _x = 0;
    _y = 0;
    view.setSize(1920.f, 1080.f);
}

Camera::Camera(int x, int y) {
    _x = x;
    _y = y;
    view.setSize(1920.f, 1080.f);
}

sf::View Camera::getView() {
    return view;
}

void Camera::move(Player p) {
    //Bouge le centre de la caméra pour qu'il soit au centre du personnage.    + p.getSprite().getScale().x   + p.getSprite().getScale().y
    //Pour le calcul, on récupère la position du sprite du joueur, et on ajoute le décalage du au fait que la coordonnée du sprite est son point en haut à gauche
    view.setCenter(p.getSprite().getPosition().x + p.getSprite().getLocalBounds().width/2, p.getSprite().getPosition().y + p.getSprite().getLocalBounds().height / 2);
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