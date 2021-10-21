
/* Generated from GenMyModel */

#ifndef DEF_GAMEMASTER
#define DEF_GAMEMASTER

#include "Map.hpp"
#include "MoveableObject.hpp"
#include "Camera.hpp"
#include <vector>

class GameMaster
{
	private :
		Map Map;
		std::vector<MoveableObject> MoveableObjectList;
		Camera Camera;
		static GameMaster Instance;
		
public:
	
};


#endif
