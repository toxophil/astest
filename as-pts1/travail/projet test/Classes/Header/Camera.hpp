/* Generated from GenMyModel */

#ifndef DEF_CAMERA
#define DEF_CAMERA

#include "Map.hpp"
#include "MoveableObject.hpp"
#include "Player.hpp"
#include <vector>
#include <type_traits>
#include <list>

using namespace std;

class Camera {
private:

	int _x, _y;
	sf::View _laVue;

public:
	Camera();
	Camera(int x, int y);
	void drawMap(sf::RenderWindow&, const Map m, sf::Vector2f);
	void drawAll(sf::RenderWindow&, const std::list<MoveableObject*> objectList, const Map m);
	void drawObject(sf::RenderWindow&, const MoveableObject* object) const;
	void updateCameraOnPlayer(sf::RenderWindow&, sf::Vector2f, sf::FloatRect);
	void focus(sf::RenderWindow&);
};


#endif
