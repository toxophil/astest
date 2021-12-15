#include "../Header/Hud.hpp"
#include "../Header/TextureLoader.h"
#include "../Header/GameMaster.hpp"

Hud::Hud(std::uint16_t nbCoeurs) {


	sf::VideoMode leScreen = sf::VideoMode::getDesktopMode();
	_laVue = sf::View(sf::Vector2f(0, 0), sf::Vector2f(leScreen.width, leScreen.height));

	_heartEmpty = GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::HeartEmpty);
	_heartDemi = GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::HeartDemi);
	_heartFull = GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::HeartFull);

	Vector2u spriteSize = _heartFull.getSize();

	_coinAnim = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Coin);
	_coinAnim.setSpeed(110);
	_animTime.restart();

	_coinSprite.setTexture(_coinAnim.getNextFrame());
	_coinSprite.setScale(4, 4);
	_coinSprite.setPosition((-((int)leScreen.width) / 2) + 3 + (int)spriteSize.x*4, leScreen.height / 2 - spriteSize.y * 7 - 20);

	_fontText = sf::Font();
	_fontText.loadFromFile("Ressources/fonts/BitPotionExt.ttf");
	
	_monneyText.setFont(_fontText);
	_monneyText.setString("0");
	_monneyText.setCharacterSize(40);
	_monneyText.setOrigin(20, 20);
	_monneyText.setColor(sf::Color(255,255,255));
	_monneyText.setPosition((-((int)leScreen.width) / 2) + 3 + (int)spriteSize.x * 8, leScreen.height / 2 - spriteSize.y * 7 - 20 + 10.5);

	for (uint16_t i = 0; i < nbCoeurs; i++) {
		sf::Sprite spriteCoeur;
		spriteCoeur.setTexture(_heartFull);
		spriteCoeur.setScale(4,4);
		spriteCoeur.setPosition((- ((int)leScreen.width)/2) + (int)spriteSize.x * 4 * i + 3 + 20, leScreen.height/2 - spriteSize.y*4 - 20);
		_lesCoeurs.push_back(spriteCoeur);
		
	}

}
void Hud::addHeart() {
	sf::Sprite spriteCoeur;
	spriteCoeur.setTexture(_heartFull);
	_lesCoeurs.push_back(spriteCoeur);
}

void Hud::updateMoney(uint32_t moneyNb) {
	_monneyText.setString(to_string(moneyNb));
}

void Hud::draw(sf::RenderWindow& laWindow, std::uint16_t nbVie) {
	laWindow.setView(_laVue);
	for (uint16_t i = 0; i < _lesCoeurs.size(); i++) {
		if (nbVie >= 2) {
			nbVie -= 2;
			_lesCoeurs[i].setTexture(_heartFull);
		}else if(nbVie > 0) {
			nbVie = 0;
			_lesCoeurs[i].setTexture(_heartDemi);
		}
		else {
			_lesCoeurs[i].setTexture(_heartEmpty);
		}
		laWindow.draw(_lesCoeurs[i]);
	}
	if (_animTime.getElapsedTime().asMilliseconds() >= _coinAnim.getSpeed()) {
		_coinSprite.setTexture(_coinAnim.getNextFrame());
		//sf::FloatRect scaledSize = _coinSprite.getGlobalBounds();
		_animTime.restart();
	}
	laWindow.draw(_coinSprite);
	laWindow.draw(_monneyText);
}