
/* Generated from GenMyModel */

#include "../Header/Ennemy.hpp"
#include "../Header/GameMaster.hpp"
#include "../Header/Weapon.hpp"

Ennemy::Ennemy()
{

	_type = 2;
	_doAttack = true;
	_type = 5;
	_estEnnemi=1;
	_sprite.setPosition(80, 80);
	nextDirection = sf::Vector2f(0, 0);
	speed = 90;
	_pvMonstre = 200;
	//modifier de l'attack speed en pourcentage
	_attackSpeedModifier = 100.0f;
	_timeSinceLastAttack.restart();
}

/*void Ennemy::updatePhysics(sf::RenderWindow& window, const sf::Event& event)
{

	// Normalisation...
	float temp = sqrt((nextDirection.x * nextDirection.x + nextDirection.y * nextDirection.y));
	if (temp != 0) {
		nextDirection = nextDirection / temp;
	}
	//lancement de l'attaque uniquement si le cooldown d'attaque est ? 0
	if (_timeSinceLastAttack.getElapsedTime().asSeconds() >= getEquippedWeapon1()->getAttackCd() * (_attackSpeedModifier / 100)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			const sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			getEquippedWeapon1()->attack(this, mousePosition);

			//reset du temps depuis la derniere attaque
			_timeSinceLastAttack.restart();
		}
	}
	if (getHealth() <= 0) {
		GameMaster::getInstance().destroyMoveableObject(this->getId());
	}
	moveObject(nextDirection * speed  * GameMaster::getInstance().getTimeSinceLastUpdate().asSeconds());
	//moveObject(nextDirection * GameMaster::getInstance().getTimeSinceLastUpdate().asSeconds());
	nextDirection = sf::Vector2f(0, 0);
}*/

/*void Ennemy::update() {
	//TODO


	Map laMap = GameMaster::getInstance().getMap();

	sf::Vector2f plyPos = GameMaster::getInstance().getPlayerPos();
	sf::Vector2f selfPos = _sprite.getPosition() + _sprite.getOrigin();
	
	int32_t roomIdPly = laMap.getRoomByPos(plyPos);
	int32_t roomIdSelf = laMap.getRoomByPos(selfPos);

	int32_t connectionIdPly = laMap.getConnectionByPos(plyPos);
	int32_t connectionIdSelf = laMap.getConnectionByPos(selfPos);

	sf::Vector2f toGoPos = plyPos- selfPos;

	if ( (roomIdSelf != roomIdPly || roomIdPly == -1) && (connectionIdPly != connectionIdSelf || connectionIdSelf == -1) ) {
		toGoPos = laMap.getNextNodePos(selfPos, plyPos) - selfPos;
		//cout << toGoPos.x << "  " << toGoPos.y << "  SORTIE" << endl;
	}

	nextDirection = toGoPos;
}*/

double Ennemy::euclideDist(sf::Vector2f vecA, sf::Vector2f vecB)
{
	return pow((vecA.x - vecA.y) - (vecB.x - vecB.y),2); // sqrt trop gourmand je crois
}

int Ennemy::onCollision()
{
	return -1;
}

bool Ennemy::isPlayerSpotted()
{

	return false;
}

void Ennemy::draw(sf::RenderWindow& laWindow) {
	laWindow.draw(_sprite);

	cout << "pos x:" << _sprite.getPosition().x <<  " y:" << _sprite.getPosition().y << endl;
	int wBar = _sprite.getGlobalBounds().width;
	float diffw = 0;
	if (_health != 0) {
		diffw = _health / _maxHealth * wBar;
	}
	sf::RectangleShape barRouge(sf::Vector2f(wBar, 2));
	barRouge.setPosition(_sprite.getPosition() + sf::Vector2f(0, _sprite.getGlobalBounds().height + 2) - _sprite.getOrigin());
	barRouge.setFillColor(sf::Color(230, 0, 0));

	sf::RectangleShape barVerte(sf::Vector2f(diffw, 2));
	barVerte.setPosition(_sprite.getPosition() + sf::Vector2f(0, _sprite.getGlobalBounds().height + 2) - _sprite.getOrigin());
	barVerte.setFillColor(sf::Color(51, 204, 51));

	laWindow.draw(barRouge);
	laWindow.draw(barVerte);
}