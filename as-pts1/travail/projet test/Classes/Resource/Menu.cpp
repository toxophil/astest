
#include "../Header/Menu.hpp"
#include "../Header/TextureLoader.h"
#include "../Header/GameMaster.hpp"

vector<String> _lesBoutons;
Animation _backgroundAnim;


sf::Sprite _backgroundSprite;
sf::Sprite _logoSprite;

Menu::Menu() {
	// Créer la view
	sf::VideoMode leScreen = sf::VideoMode::getDesktopMode();
	_laVue = sf::View(sf::Vector2f(0, 0), sf::Vector2f(leScreen.width, leScreen.height));

	uint64_t buttonW = leScreen.width/3;
	uint64_t buttonH = leScreen.height/5;

	int64_t offsetY = buttonH +5;

	int64_t x = leScreen.width / 2 - buttonW / 2;
	int64_t y = offsetY;

	
	_lesBoutons.push_back(Button("Explorer",x,y,buttonW,buttonH));
	y += offsetY;
	_lesBoutons.push_back(Button("Comment jouer ?", x, y, buttonW, buttonH));
	y += offsetY;
	_lesBoutons.push_back(Button("L'histoire", x, y, buttonW, buttonH));
	y += offsetY;
	_lesBoutons.push_back(Button("Quitter", x, y, buttonW, buttonH));


	_backgroundAnim = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Background_Wild);
	_backgroundAnim.setSpeed(100);

	// ReSize
	Vector2u backGSize = _backgroundAnim.getNextFrame().getSize();
	_backgroundSprite.setScale(backGSize.x/GameMaster::getInstance().getScreenW() , backGSize.y / GameMaster::getInstance().getScreenH());

	sf::FloatRect scaledSize = _backgroundSprite.getGlobalBounds();
	_backgroundSprite.setOrigin(scaledSize.width / 2, scaledSize.height / 2);
	_backgroundSprite.setPosition(_laVue.getCenter());

	cout << GameMaster::getInstance().getScreenW() << endl;
	Texture logoTexture = GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Logo);
	Vector2u sizeLogo = logoTexture.getSize();

	_logoSprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Logo));
	_logoSprite.setScale(0.5, 0.5);
	_logoSprite.setOrigin(sizeLogo.x/2, sizeLogo.y/2);

	Vector2f centerPos = _laVue.getCenter();
	_logoSprite.setPosition(centerPos.x, centerPos.y + GameMaster::getInstance().getScreenH()/1.6 - sizeLogo.x);


	_animTime.restart();
}
void Menu::logicMenu(sf::RenderWindow& window, const sf::Event& event) {
	window.setView(_laVue);

	if (_animTime.getElapsedTime().asMilliseconds() >= _backgroundAnim.getSpeed()) {
		_backgroundSprite.setTexture(_backgroundAnim.getNextFrame());

		sf::FloatRect scaledSize = _backgroundSprite.getGlobalBounds();
		_backgroundSprite.setOrigin(scaledSize.width / 2, scaledSize.height / 2);
		_backgroundSprite.setPosition(_laVue.getCenter());

		_animTime.restart();
	}
	
	window.draw(_backgroundSprite);
	window.draw(_logoSprite);
}