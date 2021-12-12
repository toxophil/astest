
/* Generated from GenMyModel */

#include "../Header/GameMaster.hpp"
#include <type_traits>
#include "../Header/Skorpion.hpp"
#include "../Header/DaggerOfSpeed.hpp"
#include "../Header/Generator.hpp"
#include "../Header/Skeleton.hpp"

//retourne l'instance du GameMaster
GameMaster& GameMaster::getInstance()
{
	static GameMaster instance;

	return instance;
}

void GameMaster::destroy()
{
	//destruction des objets non n�cessaires
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

//retourne la liste des �l�ments d�pla�ables
const std::list<MoveableObject*>& GameMaster::getMoveableObjectList()
{
	return _moveableObjectList;
}

TextureLoader& GameMaster::getTextureLoader()
{
	return _textureLoader;
}

const Time& GameMaster::getTimeSinceLastUpdate() const
{
	return _deltaTime;
}

//ajoute un �l�ment d�placable � la liste des �l�ments d�placables
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

//supprime la r�f�rence � l'�l�ment d'identifier (id) dans la liste des �l�ments d�placables
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
	// Le générateur
	Generator leGen = Generator();
	Map laMap = leGen.makeMap(5);
	_map = laMap;

	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Super Dédale Bros ULtimate 2 feat. Dante from Devil May Cry EXTENDED Edition ver 1.246859553", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	// Créer la camera 
	Camera laCam;

	// Créer la Classe
	Skorpion thiefBow;
	DaggerOfSpeed thiefDagger;

	// Weapon defWeapon, Animation idleAnim, Animation walkAnim, uint8_t defLife, uint16_t defSpeed
	//create a player

	Classe classeDragonF(&thiefBow,_textureLoader.getAnimation(TextureLoader::AnimationNames::Lizard_F_Idle), _textureLoader.getAnimation(TextureLoader::AnimationNames::Lizard_F_Walking),5,200);
	Animation a = _textureLoader.getAnimation(TextureLoader::AnimationNames::Lizard_F_Idle);

	Player player(classeDragonF);
	addMoveableObject(player);

	//create a skeleton
	Skeleton ennemy;
	addMoveableObject(ennemy);


	
	//equip his bow
	player.setEquippedWeapon(&thiefBow);
	ennemy.setEquippedWeapon(&thiefBow);
	//clock pour connaitre les delta entre chaque frame
	Clock clk;



	//boucle principale
	while (window.isOpen())
	{
		//mise a jour du delta
		_deltaTime = clk.restart();

		//gestionnaire d'�v�nements
		sf::Event event;

		//ev�nement 
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		//boucle de physique
		for (auto& object : _moveableObjectList) {
			object->updatePhysics(window,event);
			
		}

		if (event.type == sf::Event::MouseWheelScrolled)
		{
			if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
			{
				if (event.mouseWheelScroll.delta == 1)
				{
					player.setEquippedWeapon(&thiefBow);
				}
				else
				{
				player.setEquippedWeapon(&thiefDagger);
				}
			}
		}


		//destruction des objets non n�cessaires
		destroy();

		//logique du jeu
		for (auto &object : _moveableObjectList) {
			object->update();
		}

		// Après avoir bougé, update la Caméra
		laCam.updateCameraOnPlayer(window, player.getSprite().getPosition(), player.getSprite().getGlobalBounds());

		//destruction des objets non n�cessaires
		destroy();

		//Affichage de la frame
		window.clear();
		

		laCam.drawMap(window, laMap);
		for (auto& object : _moveableObjectList) {
			window.draw(object->getSprite());
		}
		window.display();
	}
}
