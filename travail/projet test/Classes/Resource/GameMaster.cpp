
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

TextureLoader& GameMaster::getTextureLoader()
{
	return _textures;
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


void GameMaster::runGame()
{
	//caméra
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	//create a player
	Thief player;
	addMoveableObject(player);

	//start of game
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	//boucle principale
	while (window.isOpen())
	{
		//gestionnaire d'évènements
		sf::Event event;

		//evènement 
		while (window.pollEvent(event))
		{
			//boucle de physique
			for (auto& object : _moveableObjectList) {
				object.updatePhysics(event);
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		//logique du jeu
		for (auto &object : _moveableObjectList) {
			object.update();
		}

		//Affichage de la frame
		window.clear();
	
		for (auto &object : _moveableObjectList) {
			window.draw(object.getSprite());
		}

		window.display();
	}
}