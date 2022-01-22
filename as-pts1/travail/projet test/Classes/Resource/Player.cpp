
/* Generated from GenMyModel */

#include "../Header/Player.hpp"
#include "../Header/GameMaster.hpp"
#include "../Header/Weapon.hpp"
#include "../Header/Sword.hpp"
#include "../Header/Bow.hpp"

Player::Player() {
	_type = 1;
	_estEnnemi = 0;
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

	//lancement de l'attaque uniquement si le cooldown d'attaque est à 0
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

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//														partie skills
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	// utilisation des skills : 

	// /!\ keyPressed fait une erreur donc change pour isKeyPressed

	//initialisation premiere des timers.
	//IMPOSSIBLE NE PAS FAIRE ICI

	//lancement des skills uniquement si le cooldown d'attaque est à 0
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) useFirstSkill();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) useSecondSkill();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) useThirdSkill();
	
	//a mettre dans gamemaster TRES COMPLIQUE A IMPLEMENTER
	//affiche le tableau des compétences possédées pour les affilier
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) showSkills();
	
}

//touches pour utiliser les compétences
void Player::useFirstSkill() {
	if (playerSkills[0].getCooldown().getElapsedTime().asSeconds() >= _skill0.getElapsedTime().asSeconds()) {
		useSkill(0);
		_skill0.restart();
		_skill0.getElapsedTime();
	}
}
void Player::useSecondSkill() {
	if (playerSkills[1].getCooldown().getElapsedTime().asSeconds() >= _skill1.getElapsedTime().asSeconds()) {
		useSkill(1);
		_skill1.restart();
		_skill1.getElapsedTime();
	}
}
void Player::useThirdSkill() {
	if (playerSkills[2].getCooldown().getElapsedTime().asSeconds() >= _skill2.getElapsedTime().asSeconds()) {
		useSkill(2);
		_skill2.restart();
		_skill2.getElapsedTime();
	}
}


//utilisation d'une compétence
void Skill::useSkill(int a) {}


//affiche le tableau des compétences possédées pour les affilier
void Player::showSkills() {

	if (allSkills.size() >= 0) {
		for (int i = 0; i > allSkills.size(); i++) {
			if (allSkills[i].usable()) {
				std::cout << i << " " << playerSkills[i].getName() << " " << playerSkills[i].getPower() << " " << playerSkills[i].getCooldown() << " " << endl;
			}
		}
		//affiliation des competences
		std::cout << "You can link up to 3 skills" << endl;
		//choix skill 1
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
			int j;
			std::cout << "Which skill do you want first ?" << endl;
			std::cout << "(enter its number)" << endl;
			std::cin >> j;
			if (allSkills[j].usable()) {
				playerSkills[1] = allSkills[j];
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
			int j;
			std::cout << "Which skill do you want second ?" << endl;
			std::cout << "(enter its number)" << endl;
			std::cin >> j;
			if (allSkills[j].usable()) {
				playerSkills[2] = allSkills[j];
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
			int j;
			std::cout << "Which skill do you want third ?" << endl;
			std::cout << "(enter its number)" << endl;
			std::cin >> j;
			if (allSkills[j].usable()) {
				playerSkills[3] = allSkills[j];
			}
		}
	}
	//check skills level abilty
	else {
		std::cout << "You don't have skills" << endl;
	}
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//														fin partie skills
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//deplacement
void Player::update() {
	//TODO
	moveObject(nextDirection * GameMaster::getInstance().getTimeSinceLastUpdate().asSeconds());
	if (nextDirection.x != 0 || nextDirection.y != 0) {	
		if (_animTime.getElapsedTime().asMilliseconds() >= _laClasse.getWalkAnim().getSpeed()) {_animTime.restart();
			_sprite.setTexture(_laClasse.getWalkAnim().getNextFrame());
			_animTime.restart();
		}
	}
	else {
		
		if (_animTime.getElapsedTime().asMilliseconds() >= _laClasse.getIdleAnim().getSpeed()) {
			_sprite.setTexture(_laClasse.getIdleAnim().getNextFrame());
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
void Player::setPos(int x, int y) {
	_sprite.setPosition(x, y);
}