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
#include "SoundLoader.hpp"

class Player;

using namespace std;

class GameMaster
{
private:
	MusicManager _leMusicManager;
	SoundLoader _leSoundLoader;

	Map _map;
	Player* _leJoueur;

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

	bool _openMainMenu = true;
public:
	//-------Singleton
	static GameMaster& getInstance();
	GameMaster(GameMaster const&) = delete;
	void operator=(GameMaster const&) = delete;
	//-------

	//--------------GETTERS------------
	const Map& getMap() const;
	const sf::Vector2f getPlayerPos() const;
	void setPlayerPos(int, int);
	void addDamageToPlayer(double);

	const std::list<MoveableObject*>& getMoveableObjectList();

	TextureLoader& getTextureLoader();

	const Time& getTimeSinceLastUpdate() const;

	const uint64_t getScreenW() const;
	const uint64_t getScreenH() const;
	
	MusicManager& getMusicManager();
	SoundLoader& getSoundLoader();

	//sf::RenderWindow& getWindow() const;
	//---------------------------------

	//fonction principale du jeu
	void startGame(uint8_t);
	void nextGame();
	void endGame();

	void runGame();
	
	//ajoute un �l�ment d�placable � la liste des �l�ments d�placables
	bool addMoveableObject(MoveableObject& moveableObject);

	bool addMoveableObject(MoveableObject* moveableObject);

	//supprime la r�f�rence � l'�l�ment d'identifier (id) dans la liste des �l�ments d�placables
	bool destroyMoveableObject(uint32_t id);
};

#endif