/* Generated from GenMyModel */

#ifndef DEF_GAMEMASTER
#define DEF_GAMEMASTER

#include "Map.hpp"
#include "MoveableObject.hpp"
#include "Camera.hpp"
#include "Ennemy.hpp"
#include "TextureLoader.h"
#include <vector>
#include "Skeleton.hpp"
#include "MusicManager.hpp"

class Player;

using namespace std;

class GameMaster
{
private:
	MusicManager _leMusicManager;
	Map _map;
	std::list<MoveableObject*> _moveableObjectList;
	std::list<std::list<MoveableObject*>::iterator> _toDestroy;
	TextureLoader _textureLoader;
	Camera _camera;
	Time _deltaTime;

	// Set une nouvelle _camera
	
	//fonction de destruction des objets de moveable object list a partir de la liste to destroy
	void destroy();

	//private pour design pattern singleton
	GameMaster();

	uint64_t _screenW;
	uint64_t _screenH;
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

	const uint64_t getScreenW() const;
	const uint64_t getScreenH() const;
	MusicManager& getMusicManager();

	//sf::RenderWindow& getWindow() const;
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