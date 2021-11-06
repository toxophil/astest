
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

//retourne la liste des �l�ments d�pla�ables
const vector<MoveableObject>& GameMaster::getMoveableObjectList()
{
	return _moveableObjectList;
}

TextureLoader& GameMaster::getTextureLoader()
{
	return _textures;
}


//ajoute un �l�ment d�placable � la liste des �l�ments d�placables
bool GameMaster::addMoveableObject(MoveableObject& moveableObject)
{
	_moveableObjectList.push_back(moveableObject);
	return true;
}

//supprime la r�f�rence � l'�l�ment d'identifier (id) dans la liste des �l�ments d�placables
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
	//cam�ra
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
		//gestionnaire d'�v�nements
		sf::Event event;

		//ev�nement 
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