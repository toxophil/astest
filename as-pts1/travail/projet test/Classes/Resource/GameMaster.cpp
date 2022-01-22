
/* Generated from GenMyModel */

#include "../Header/GameMaster.hpp"
#include <type_traits>
#include "../Header/Generator.hpp"
#include "../Header/Menu.hpp"
#include "../Header/Hud.hpp"

#include "../Header/Bow.hpp"
#include "../Header/Sword.hpp"

#include "../Header/MagicienUndead.hpp"
#include "../Header/MagicienDemon.hpp"
#include "../Header/MagicienOrc.hpp"
#include "../Header/MediumUndead.hpp"
#include "../Header/MediumDemon.hpp"
#include "../Header/MediumOrc.hpp"
#include "../Header/LittleUndead.hpp"
#include "../Header/LittleDemon.hpp"
#include "../Header/LittleOrc.hpp"
#include "../Header/BossUndead.hpp"
#include "../Header/BossDemon.hpp"
#include "../Header/BossOrc.hpp"
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
const sf::Vector2f GameMaster::getPlayerPos() const
{
	return _leJoueur->getSprite().getPosition() + _leJoueur->getSprite().getOrigin();
}
void GameMaster::setPlayerPos(int x, int y)
{
	_leJoueur->setPos(x, y);
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

const uint64_t GameMaster::getScreenW() const {
	return _screenW;
}

const uint64_t GameMaster::getScreenH() const {
	return _screenH;
}

MusicManager& GameMaster::getMusicManager() {
	return _leMusicManager;
}
SoundLoader& GameMaster::getSoundLoader() {
	return _leSoundLoader;
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

	sf::VideoMode leModeVideo = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(leModeVideo, "Super Dédale Bros ULtimate 2 feat. Dante from Devil May Cry EXTENDED Edition ver 1.246859553", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);


	_screenW = leModeVideo.width;
	_screenH = leModeVideo.height;

	// Créer la camera 
	Camera laCam;

	// Créer la Classe
	Bow arcCool(_textureLoader.getTexture(TextureLoader::TextureNames::Anime_Sword));

	// Weapon defWeapon, Animation idleAnim, Animation walkAnim, uint8_t defLife, uint16_t defSpeed
	//create a player

	//Classe classeDragonF(&thiefBow,_textureLoader.getAnimation(TextureLoader::AnimationNames::Lizard_F_Idle), _textureLoader.getAnimation(TextureLoader::AnimationNames::Lizard_F_Walking),5,200);
	Classe classeDragonF(&arcCool, _textureLoader.getAnimation(TextureLoader::AnimationNames::Knight_Idle), _textureLoader.getAnimation(TextureLoader::AnimationNames::Knight_Walking), 5, 130);

	Ennemy en();
	Animation a = _textureLoader.getAnimation(TextureLoader::AnimationNames::Lizard_F_Idle);

	Player player(classeDragonF);
	Sword sword(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Anime_Sword));
	player.setEquippedWeapon2(&sword);
	addMoveableObject(player);

	//create a skeleton
	BossDemon ennemy;

	//equip his bow
	//player.setEquippedWeapon1(&arcCool);		//L'arc est déja équippé, et ça fait buguer des bails
	//ennemy.setEquippedWeapon1(&arcCool);
	//clock pour connaitre les delta entre chaque frame
	Clock clk;
	bool openMainMenu = false;
	Menu leMenuP;

	_leMusicManager.playMusic(_leMusicManager.getMusic(MusicManager::MusicNames::Main), false);
	//boucle principale
	sf::Clock _musicCd;
	_musicCd.restart();

	Hud leHud(5);
	leHud.updateMoney(1500);
	bool done = false;

	// SET LE PLAYER, IMPORTANT POUR LE GET POUR LE PATHFINDING!!!!!!!!!!!!!!!!!!
	_leJoueur = &player;
	while (window.isOpen())
	{
		/*if (!window.hasFocus()) {
			continue;
		}*/
		/*if (_musicCd.getElapsedTime().asSeconds() > 5 && !done) {
			_leMusicManager.playMusic(_leMusicManager.getMusic(MusicManager::MusicNames::Main), true);
		}*/
		//mise a jour du delta
		_deltaTime = clk.restart();

		//gestionnaire d'�v�nements
		sf::Event event;
		if (openMainMenu) {
			while (window.pollEvent(event))
			{

				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear(); // Clear avant
				leMenuP.logicMenu(window, event); // Affichage Menu
			window.display();

		}
		else {
			
			//ev�nement 
			while (window.pollEvent(event))
			{

				if (event.type == sf::Event::Closed)
					window.close();
			}

			//boucle de physique
			for (auto& object : _moveableObjectList) {
				object->updatePhysics(window, event);

			}

			if (event.type == sf::Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
				{
					if (event.mouseWheelScroll.delta == 1)
					{
						player.setEquippedWeapon1(&arcCool);
					}
					else
					{
						player.setEquippedWeapon1(&arcCool);
					}
				}
			}


			//destruction des objets non n�cessaires
			destroy();

			//logique du jeu
			for (auto& object : _moveableObjectList) {
				object->update();
			}

			// Après avoir bougé, update la Caméra
			laCam.updateCameraOnPlayer(window, player.getSprite().getPosition(), player.getSprite().getGlobalBounds());

			//destruction des objets non n�cessaires
			destroy();

			//Affichage de la frame
			window.clear();

			
			laCam.drawMap(window, laMap, player.getSprite().getPosition());
			for (auto& object : _moveableObjectList) {
				window.draw(object->getSprite());
			}
			player.getEquippedWeapon1()->drawEquiped(window, player.getSprite().getPosition(), player.getSprite().getGlobalBounds()); 

			leHud.draw(window,3);
			laCam.focus(window);


		//	cout << "Room Index: " << laMap.getRoomByPos(player.getSprite().getPosition()) << endl;
		//	cout << "Connection Index: " << laMap.getConnectionByPos(player.getSprite().getPosition()) << endl;
		//	cout << "===" << endl;
			window.display();
		}

		_leMusicManager.logicMenu();
	}
}
