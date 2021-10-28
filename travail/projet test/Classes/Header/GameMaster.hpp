
/* Generated from GenMyModel */

#ifndef DEF_GAMEMASTER
#define DEF_GAMEMASTER

#include "Map.hpp"
#include "MoveableObject.hpp"
#include "Camera.hpp"
#include "Player.hpp"
#include "Ennemy.hpp"
#include <vector>

using namespace std;

class GameMaster
{
private :
	Map _map;
	vector<MoveableObject> _moveableObjectList;
	Camera _camera;

	//private pour design pattern singleton
	GameMaster();
		
public:
	//-------Singleton
	static GameMaster& getInstance();
	GameMaster(GameMaster const&) = delete;
	void operator=(GameMaster const&) = delete;
	//-------

	//--------------GETTERS------------
	const Map& getMap() const;

	const vector<MoveableObject>& getMoveableObjectList();

	const vector<Player>& getPlayerList() const;

	const vector<Ennemy>& getEnnemyList() const;
	//---------------------------------


	bool addMoveableObject(MoveableObject& moveableObject);

	bool destroyMoveableObject(uint32_t id);

};


#endif
