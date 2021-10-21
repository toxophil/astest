/* Generated from GenMyModel */

#ifndef DEF_CAMERA
#define DEF_CAMERA

#include "Map.hpp"
#include "MoveableObject.hpp"
#include <vector>

using namespace std;

class Camera{

public:
	void drawMap(Map);
	void drawObject(vector<MoveableObject>);
};


#endif
