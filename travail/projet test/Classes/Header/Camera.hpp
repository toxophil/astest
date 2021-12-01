/* Generated from GenMyModel */

#ifndef DEF_CAMERA
#define DEF_CAMERA

#include "Map.hpp"
#include "MoveableObject.hpp"
#include <vector>
#include <type_traits>
#include <list>
#include "Player.hpp"

using namespace std;

class Camera {
private:
	int _x, _y;
	sf::RenderWindow _window;
	sf::View view;

public:
	Camera();
	Camera(int x, int y);

	void drawMap(const Map m);
	void drawAll(const std::list<MoveableObject*> objectList, const Map m);
	void drawObject(const MoveableObject* object) const;
	sf::View getView();
	void move(Player p);
};


#endif
