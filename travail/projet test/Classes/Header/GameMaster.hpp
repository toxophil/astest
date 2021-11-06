
/* Generated from GenMyModel */

#ifndef DEF_GAMEMASTER
#define DEF_GAMEMASTER

#include "Map.hpp"
#include "MoveableObject.hpp"
#include "Camera.hpp"
#include "Player.hpp"
#include "Ennemy.hpp"
#include "TextureLoader.h"
#include "Thief.hpp"
#include <vector>

using namespace std;

class GameMaster
{
private :
	Map _map;
	vector<MoveableObject> _moveableObjectList;
	TextureLoader _textures;
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

	TextureLoader& getTextureLoader();
	//---------------------------------

	//fonction principale du jeu
	void runGame();

	//ajoute un �l�ment d�placable � la liste des �l�ments d�placables
	bool addMoveableObject(MoveableObject& moveableObject);

	//supprime la r�f�rence � l'�l�ment d'identifier (id) dans la liste des �l�ments d�placables
	bool destroyMoveableObject(uint32_t id);

};


#endif
