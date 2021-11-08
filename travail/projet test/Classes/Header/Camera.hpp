/* Generated from GenMyModel */

#ifndef DEF_CAMERA
#define DEF_CAMERA

#include "Map.hpp"
#include "MoveableObject.hpp"
#include <vector>

using namespace std;

class Camera {
private:
	int _x, _y;

public:
	Camera();
	Camera(int x, int y);
	void drawMap(const Map m, sf::RenderWindow& window) const;
	void drawAll(const vector<DrawableObject>& objectList, sf::RenderWindow& window, const Map m) const;
	void drawObject(const DrawableObject& object, sf::RenderWindow& window) const;
};


#endif
