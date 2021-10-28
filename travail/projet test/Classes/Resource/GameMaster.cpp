
/* Generated from GenMyModel */

#include "..\Header\GameMaster.hpp"
#include <type_traits>

//retourne l'instance du GameMaster
GameMaster& GameMaster::getInstance()
{
	static GameMaster instance;

	return instance;
}

GameMaster::GameMaster()
{
	
}

//retourne la map actuelle
const Map& GameMaster::getMap() const
{
	return _map;
}

//retourne la liste des éléments déplaçables
const vector<MoveableObject>& GameMaster::getMoveableObjectList()
{
	return _moveableObjectList;
}

//ajoute un élément déplacable à la liste des éléments déplacables
bool GameMaster::addMoveableObject(MoveableObject& moveableObject)
{
	_moveableObjectList.push_back(moveableObject);
	return true;
}

//supprime la référence à l'élément d'identifier (id) dans la liste des éléments déplacables
bool GameMaster::destroyMoveableObject(uint32_t id)
{
	bool destroyed = false;

	auto i = 0;
	while(!destroyed && i < _moveableObjectList.size()){
		if (_moveableObjectList.at(i).getId() == id) {
			_moveableObjectList.erase(_moveableObjectList.begin() + i);
			destroyed = true;
		}
	}

	return destroyed;
}
