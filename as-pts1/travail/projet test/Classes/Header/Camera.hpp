/* Generated from GenMyModel */

#ifndef DEF_CAMERA
#define DEF_CAMERA

#include "Map.hpp"
#include "MoveableObject.hpp"
#include <vector>
#include <type_traits>
#include <list>

using namespace std;

class Camera {
private:
	int _x, _y;
	sf::RenderWindow _window;

public:
	Camera();
	Camera(int x, int y);
	void drawMap(sf::RenderWindow&, const Map m);
	void drawAll(sf::RenderWindow&, const std::list<MoveableObject*> objectList, const Map m);
	void drawObject(sf::RenderWindow&, const MoveableObject* object) const;
};


#endif
