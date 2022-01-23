#include "../Header/Boss.hpp"
#include "../Header/GameMaster.hpp"
#include "../Header/Weapon.hpp"

Boss::Boss()
{

	_health = 150;
	_maxHealth = 150;
	_attackCD = 2500;

	speed = 70;
	_type = 2;
	//GameMaster::getInstance().addMoveableObject(this);


	_animTime.restart();
	_animWalking = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Undead_Boss_Walking);
	_animIdle = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Undead_Boss_Idle);

	_sprite.setTexture(_animIdle.getNextFrame());
	sf::FloatRect localBounds = _sprite.getGlobalBounds();
	_sprite.setOrigin(localBounds.width / 2, localBounds.height / 2);
	_sprite.setScale(sf::Vector2f(1, 1));
}
void Boss::updatePhysics(sf::RenderWindow& window, const sf::Event& event)
{

	Map laMap = GameMaster::getInstance().getMap();

	sf::Vector2f plyPos = GameMaster::getInstance().getPlayerPos();
	sf::Vector2f selfPos = _sprite.getPosition() + _sprite.getOrigin();

	int32_t roomIdPly = laMap.getRoomByPos(plyPos);
	int32_t roomIdSelf = laMap.getRoomByPos(selfPos);

	int32_t connectionIdPly = laMap.getConnectionByPos(plyPos);
	int32_t connectionIdSelf = laMap.getConnectionByPos(selfPos);

	sf::Vector2f toGoPos = plyPos - selfPos;

	if (roomIdPly == roomIdSelf) {
		_isSpotted = true;
	}
	//cout << abs(toGoPos.x) << "  y:" << abs(toGoPos.y) << endl;
	if (_isSpotted) {
		//cout << "ATTACK DIST: " << euclideDist(plyPos, selfPos) << endl;
		if (euclideDist(plyPos, selfPos) < 2000) {
			if (_timeSinceLastAttack.getElapsedTime().asMilliseconds() > _attackCD) {
				_timeSinceLastAttack.restart();
				cout << "ATTACK Beee!!! " << endl;
				GameMaster::getInstance().addDamageToPlayer(1);
			}
		}
		if (abs(toGoPos.x) < 10 && abs(toGoPos.y) < 6) {
			nextDirection = sf::Vector2f(0, 0);
		}
		else {
			if ((roomIdSelf != roomIdPly || roomIdPly == -1) && (connectionIdPly != connectionIdSelf || connectionIdSelf == -1)) {
				toGoPos = laMap.getNextNodePos(selfPos, plyPos) - selfPos;
				//cout << toGoPos.x << "  " << toGoPos.y << "  SORTIE" << endl;
			}
			nextDirection = toGoPos;

			if (toGoPos.x > 0) {
				_sprite.setScale(1.f, 1.f);
			}
			else {
				_sprite.setScale(-1.f, 1.f);
			}

			// Normalisation...
			float temp = sqrt((nextDirection.x * nextDirection.x + nextDirection.y * nextDirection.y));
			if (temp != 0) {
				nextDirection = nextDirection / temp;
			}
		}
	}

	//lancement de l'attaque uniquement si le cooldown d'attaque est à 0
	/*if (_timeSinceLastAttack.getElapsedTime().asSeconds() >= getEquippedWeapon1()->getAttackCd() * (_attackSpeedModifier / 100)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			const sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			getEquippedWeapon1()->attack(this, mousePosition);

			//reset du temps depuis la derniere attaque
			_timeSinceLastAttack.restart();
		}
	}*/
	if (getHealth() <= 0) {
		GameMaster::getInstance().destroyMoveableObject(this->getId());
	}
}

void Boss::update() {
	//TODO

	moveObject(nextDirection * speed * GameMaster::getInstance().getTimeSinceLastUpdate().asSeconds());
	if (nextDirection.x != 0 || nextDirection.y != 0) {
		if (_animTime.getElapsedTime().asMilliseconds() >= 70) {
			_sprite.setTexture(_animWalking.getNextFrame());
			_animTime.restart();
		}
	}
	else {

		if (_animTime.getElapsedTime().asMilliseconds() >= 70) {
			_sprite.setTexture(_animIdle.getNextFrame());
			_animTime.restart();
		}
	}
	nextDirection = sf::Vector2f(0, 0);
}