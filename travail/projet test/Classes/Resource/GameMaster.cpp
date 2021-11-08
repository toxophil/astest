
/* Generated from GenMyModel */

#include "..\Header\GameMaster.hpp"
#include <type_traits>
#include "..\Header\Skorpion.hpp"

//retourne l'instance du GameMaster
GameMaster& GameMaster::getInstance()
{
	static GameMaster instance;

	return instance;
}

void GameMaster::destroy()
{
	//destruction des objets non nécessaires
	std::list<std::list<MoveableObject*>::iterator>::iterator i = _toDestroy.begin();
	while (i != _toDestroy.end())
	{
		_moveableObjectList.erase((*i));
		_toDestroy.erase(i++);

	}
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
const std::list<MoveableObject*>& GameMaster::getMoveableObjectList()
{
	return _moveableObjectList;
}

TextureLoader& GameMaster::getTextureLoader()
{
	return _textures;
}

const Time& GameMaster::getTimeSinceLastUpdate() const
{
	return _deltaTime;
}


//ajoute un élément déplacable à la liste des éléments déplacables
bool GameMaster::addMoveableObject(MoveableObject& moveableObject)
{
	_moveableObjectList.push_back(&moveableObject);
	return true;
}

bool GameMaster::addMoveableObject(MoveableObject* moveableObject)
{
	_moveableObjectList.push_back(moveableObject);
	return true;
}

//supprime la référence à l'élément d'identifier (id) dans la liste des éléments déplacables
bool GameMaster::destroyMoveableObject(uint32_t id)
{

	bool destroyed = false;

	std::list<MoveableObject*>::iterator i = _moveableObjectList.begin();
	while (i != _moveableObjectList.end() && !destroyed)
	{
		if ((*i)->getId() == id)
		{
			_toDestroy.push_back(i);
			destroyed = true;
		}
		++i;
	}
	return destroyed;
}


void GameMaster::runGame()
{
	//caméra
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

	//create a player
	Thief player;
	addMoveableObject(player);

	//create his bow
	Skorpion thiefBow;
	
	//equip his bow
	player.setEquippedWeapon(&thiefBow);

	//start of game
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	//clock pour connaitre les delta entre chaque frame
	Clock clk;

	//boucle principale
	while (window.isOpen())
	{
		//mise a jour du delta
		_deltaTime = clk.restart();

		//gestionnaire d'évènements
		sf::Event event;

		//evènement 
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		//boucle de physique
		for (auto& object : _moveableObjectList) {
			object->updatePhysics(event);
		}

		//destruction des objets non nécessaires
		destroy();

		//logique du jeu
		for (auto &object : _moveableObjectList) {
			object->update();
		}

		//destruction des objets non nécessaires
		destroy();

		//Affichage de la frame
		window.clear();
	
		//Camera.drawAll();
		for (auto& object : _moveableObjectList) {
			window.draw(object->getSprite());
		}

		window.display();
	}
}