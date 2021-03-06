
/* Generated from GenMyModel */

#include "../Header/Player.hpp"
#include "../Header/GameMaster.hpp"
#include "../Header/Weapon.hpp"
#include "../Header/Sword.hpp"
#include "../Header/Bow.hpp"

Player::Player() {
	_type = 1;
	_estEnnemi = 0;
	_sprite.setPosition(120, 120);
	nextDirection = sf::Vector2f(0, 0);
	speed = 50;
	_degat = 0.01;
	_timeSinceLastAttack.restart();
	_inventory = &Inventory();

	_animTime.restart();
	setHealth(1);
	anim = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Lizard_F_Idle);
}
Player::Player(Classe laClasse)
{
	_type = 1;
	_estEnnemi = 0;
	_sprite.setPosition(120, 120);
	nextDirection = sf::Vector2f(0, 0);
	speed = laClasse.getDefaultSpeed();
	_degat = 0.01;
	_timeSinceLastAttack.restart();
	_inventory = &Inventory();

	_animTime.restart();
	_laClasse = laClasse;
	setHealth(laClasse.getDefaultLife());
	setEquippedWeapon1(laClasse.getDefaultWeapon());
	anim = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Lizard_F_Idle);
}

void Player::updatePhysics(sf::RenderWindow& window,const sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		//déplacement vers la gauche
		nextDirection += sf::Vector2f(-speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		//déplacement vers la droite
		nextDirection += sf::Vector2f(speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		//déplacement vers le haut
		nextDirection += sf::Vector2f(0, -speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		//déplacement vers le bas
		nextDirection += sf::Vector2f(0, speed);
	}

	const sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (mousePosition.x > _sprite.getPosition().x  ) {
		_sprite.setScale(1.f, 1.f);
	}
	else {
		_sprite.setScale(-1.f, 1.f);
	}
	// Reset origine
	sf::FloatRect globalBounds = _sprite.getGlobalBounds();
	_sprite.setOrigin(globalBounds.width/2, globalBounds.height/2);

	//normalisation du vecteur de longeur speed
	nextDirection.x = std::min(nextDirection.x, speed);
	nextDirection.y = std::min(nextDirection.y, speed);

	//lancement de l'attaque uniquement si le cooldown d'attaque est ŕ 0
	if (_timeSinceLastAttack.getElapsedTime().asSeconds() >= getEquippedWeapon1()->getAttackCd() * 1) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

			const sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			Bow* bow = dynamic_cast<Bow*>(getEquippedWeapon1());
			bow->attack(this, mousePosition);

			//reset du temps depuis la derniere attaque
			_timeSinceLastAttack.restart();
		}
	}
	if (_timeSinceLastAttack.getElapsedTime().asSeconds() >= getEquippedWeapon2()->getAttackCd() * 1) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {

			const sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			Sword* sword = dynamic_cast<Sword*>(getEquippedWeapon2());
			sword->attackSword(this,mousePosition);

			//reset du temps depuis la derniere attaque
			_timeSinceLastAttack.restart();
		}
	}
}

void Player::update() {
	//TODO
	moveObject(nextDirection * GameMaster::getInstance().getTimeSinceLastUpdate().asSeconds());
	if (nextDirection.x != 0 || nextDirection.y != 0) {	
		if (_animTime.getElapsedTime().asMilliseconds() >= _laClasse.getWalkAnim().getSpeed()) {_animTime.restart();
			////cout << "nextttt : " << endl;
			_sprite.setTexture(_laClasse.getWalkAnim().getNextFrame());
			_animTime.restart();
		}
	}
	else {
		
		if (_animTime.getElapsedTime().asMilliseconds() >= _laClasse.getIdleAnim().getSpeed()) {
			_sprite.setTexture(_laClasse.getIdleAnim().getNextFrame());
			//_sprite.setTexture(anim.getNextFrame());
			_animTime.restart();
		}
	}
	nextDirection = sf::Vector2f(0, 0);
}


Inventory* Player::getInventory() {
	return _inventory;
}

sf::Vector2f Player::getPos() const {
	return _sprite.getPosition() + _sprite.getOrigin();
}
void Player::setClasse(Classe laClasse) {
	speed = laClasse.getDefaultSpeed();
	_timeSinceLastAttack.restart();
	_inventory = &Inventory();

	_animTime.restart();
	_laClasse = laClasse;
	setHealth(laClasse.getDefaultLife());
	setEquippedWeapon1(laClasse.getDefaultWeapon());
	anim = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Lizard_F_Idle);
}
Classe& Player::getClasse() {
	return _laClasse;
}
/*bool Player::updateOnTouche() {
	_nbVie = _nbVie - _degat; //on enleve des pvs si collisions avec ennemies
	_nbPiece++; //on ajoute des pieces si collisions
	_pvMonstre=_pvMonstre-0.1;

}*/

/*bool Player::onTouche(MoveableObject * obj)
{
	if(obj->getType()==3)
	{
		_pvMonstre = _pvMonstre - obj->getDegat();
		GameMaster::getInstance().destroyMoveableObject(obj->getId());
		cout << "la fleche doit etre detruite" << endl;
	}
	return true;
}*/

void Player::addDamage(double dmg)
{
	if (dmg > _health) {
		_health = 0;
		GameMaster::getInstance().endGame(); // Perdus !
	}
	else {
		_health -= dmg;
	}
}
void Player::setPos(int x, int y) {
	_sprite.setPosition(x, y);
}