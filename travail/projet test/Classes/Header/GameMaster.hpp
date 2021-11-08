
/* Generated from GenMyModel */

#ifndef DEF_GAMEMASTER
#define DEF_GAMEMASTER

#include "Map.hpp"
#include "MoveableObject.hpp"
#include "Camera.hpp"
#include "Ennemy.hpp"
#include "TextureLoader.h"
#include <vector>
#include "Thief.hpp"

class Player;

using namespace std;

class GameMaster
{
private :
	Map _map;
	std::list<MoveableObject*> _moveableObjectList;
	std::list<std::list<MoveableObject*>::iterator> _toDestroy;
	TextureLoader _textures;
	Camera _camera;
	Time _deltaTime;

	//fonction de destruction des objets de moveable object list a partir de la liste to destroy
	void destroy();

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

	const std::list<MoveableObject*>& getMoveableObjectList();

	TextureLoader& getTextureLoader();

	const Time& getTimeSinceLastUpdate() const;
	//---------------------------------

	//fonction principale du jeu
	void runGame();

	//ajoute un élément déplacable à la liste des éléments déplacables
	bool addMoveableObject(MoveableObject& moveableObject);

	bool addMoveableObject(MoveableObject* moveableObject);

	//supprime la référence à l'élément d'identifier (id) dans la liste des éléments déplacables
	bool destroyMoveableObject(uint32_t id);

};


#endif
