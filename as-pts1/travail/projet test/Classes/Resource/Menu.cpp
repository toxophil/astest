
#include "../Header/Menu.hpp"
#include "../Header/TextureLoader.h"
#include "../Header/GameMaster.hpp"

vector<String> _lesBoutons;
Animation _backgroundAnim;


sf::Sprite _backgroundSprite;
sf::Sprite _logoSprite;

Menu::Menu() {
	// Créer la view

	if (!fontMenu.loadFromFile("Ressources/fonts/BebasNeue-Light.ttf")) {
		throw invalid_argument("Font inexistante");
	}

	sf::VideoMode leScreen = sf::VideoMode::getDesktopMode();
	_laVue = sf::View(sf::Vector2f(0, 0), sf::Vector2f(leScreen.width, leScreen.height));
	Vector2f centerPos = _laVue.getCenter();

	uint64_t buttonW = leScreen.width/6;
	uint64_t buttonH = leScreen.height/11;

	int64_t offsetY = buttonH +5;

	int64_t x = - (int64_t)buttonW / 2;
	int64_t y = -(int64_t) buttonH/2;

	//cout << "X: " << x << endl;
	_lesBoutons.push_back(Button("Explorer",x,y,buttonW,buttonH, fontMenu));
	y += offsetY;
	_lesBoutons.push_back(Button("Comment jouer ?", x, y, buttonW, buttonH, fontMenu));
	y += offsetY;
	_lesBoutons.push_back(Button("L'histoire", x, y, buttonW, buttonH, fontMenu));
	y += offsetY;
	_lesBoutons.push_back(Button("Quitter", x, y, buttonW, buttonH, fontMenu));
	

	y = -(int64_t)buttonH / 2;
	uint64_t buttonH2 = leScreen.height / 15;
	offsetY = buttonH2 + 5;
	//cout << "X: " << x << endl;
	_lesBoutonsClasse.push_back(Button("Elf Femme", x, y, buttonW, buttonH2, fontMenu));
	y += offsetY;
	_lesBoutonsClasse.push_back(Button("Elf Homme", x, y, buttonW, buttonH2, fontMenu));
	y += offsetY;
	_lesBoutonsClasse.push_back(Button("Chevalier", x, y, buttonW, buttonH2, fontMenu));
	y += offsetY;
	_lesBoutonsClasse.push_back(Button("Lezard Femme", x, y, buttonW, buttonH2, fontMenu));
	y += offsetY;
	_lesBoutonsClasse.push_back(Button("Lezard Homme", x, y, buttonW, buttonH2, fontMenu));
	y += offsetY;
	_lesBoutonsClasse.push_back(Button("Magicien Femme", x, y, buttonW, buttonH2, fontMenu));
	y += offsetY;
	_lesBoutonsClasse.push_back(Button("Magicien Homme", x, y, buttonW, buttonH2, fontMenu));

	_backgroundAnim = GameMaster::getInstance().getTextureLoader().getAnimation(TextureLoader::AnimationNames::Background_Wild);
	_backgroundAnim.setSpeed(120);

	// ReSize
	Vector2u backGSize = _backgroundAnim.getNextFrame().getSize();
	_backgroundSprite.setScale(backGSize.x/GameMaster::getInstance().getScreenW() , backGSize.y / GameMaster::getInstance().getScreenH());

	sf::FloatRect scaledSize = _backgroundSprite.getGlobalBounds();
	_backgroundSprite.setOrigin(scaledSize.width / 2, scaledSize.height / 2);
	_backgroundSprite.setPosition(_laVue.getCenter());

	////cout << GameMaster::getInstance().getScreenW() << endl;
	Texture logoTexture = GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Logo);
	Vector2u sizeLogo = logoTexture.getSize();

	_logoSprite.setTexture(GameMaster::getInstance().getTextureLoader().getTexture(TextureLoader::TextureNames::Logo));
	_logoSprite.setScale(0.5, 0.5);
	_logoSprite.setOrigin(sizeLogo.x/2, sizeLogo.y/2);

	_logoSprite.setPosition(centerPos.x, centerPos.y + GameMaster::getInstance().getScreenH()/1.6 - sizeLogo.y);



	// LES Sprites DU MENU
	_imgCommentJouer.loadFromFile("Ressources/img/menu/commentjouer.jpg");
	_imgHistoire.loadFromFile("Ressources/img/menu/histoire.jpg");


	_commentJouer.setTexture(_imgCommentJouer);
	_histoire.setTexture(_imgHistoire);
	cout << "Size Screen: " << leScreen.width << " sizeX:" << _imgCommentJouer.getSize().x << endl;
	_commentJouer.setPosition(centerPos.x - _imgCommentJouer.getSize().x / 2, centerPos.y - (int)_imgCommentJouer.getSize().y/2);
	_histoire.setPosition(centerPos.x - _imgHistoire.getSize().x / 2, centerPos.y - (int)_imgHistoire.getSize().y/2);

	_selecPerso.setString("Veuillez choisir un personnage");
	_selecPerso.setFont(fontMenu);
	_selecPerso.setCharacterSize(45);
	_selecPerso.setFillColor(sf::Color::Black);
	_selecPerso.setPosition(x, buttonH / 2 - 10);



	_animTime.restart();
}



void Menu::logicMenu(sf::RenderWindow& window, sf::Event& event) {
	window.setView(_laVue);
	cout << _lastClick.getElapsedTime().asMilliseconds() << endl;
	bool mouseLeftClicked = false;
	bool escapePressed = false;
	if (_lastClick.getElapsedTime().asMilliseconds() > 100) {
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
		{
			if (_lastKeyPressed != 1) {
				cout << "Yup" << endl;
				_lastKeyPressed = 1;
				mouseLeftClicked = true;
				_lastClick.restart();
			}
		}
		else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
			if (_lastKeyPressed != 2) {
				_lastKeyPressed = 2;
				escapePressed = true;
				_lastClick.restart();
			}
		}
		else {
			_lastKeyPressed = 0;
		}
	}

	if (_animTime.getElapsedTime().asMilliseconds() >= _backgroundAnim.getSpeed()) {
		_backgroundSprite.setTexture(_backgroundAnim.getNextFrame());

		sf::FloatRect scaledSize = _backgroundSprite.getGlobalBounds();
		_backgroundSprite.setOrigin(scaledSize.width / 2, scaledSize.height / 2);
		_backgroundSprite.setPosition(_laVue.getCenter());

		_animTime.restart();
	}

	window.draw(_backgroundSprite);
	window.draw(_logoSprite);

	if (escapePressed) { // Retourne au menu principale
		menuState = 0;
		_lastClick.restart();
	}

	switch (menuState) {
	case 0: // Menu Principale
		for (uint8_t i = 0; i < 4; i++) {
			_lesBoutons[i].draw(window);
			if (mouseLeftClicked && _lesBoutons[i].isHovered(window)) {
				menuState = i + 1;
				_lastClick.restart();
			}
		}
		break;
	case 1: // Jouer
		for (uint8_t i = 0; i < _lesBoutonsClasse.size(); i++) {
			_lesBoutonsClasse[i].draw(window);
			if (mouseLeftClicked && _lesBoutonsClasse[i].isHovered(window)) {
				menuState = 0; // Reset le state du menu, comme ça il reviendra sur le menu principale une fois mort !
				GameMaster::getInstance().startGame(i + 1);
			}
		}
		break;
	case 2: // Comment jouer
		window.draw(_commentJouer);	 
		break;
	case 3: // L'histoire
		window.draw(_histoire);
		break;
	case 4: // Quitter 
		window.close();
		break;
	case 5: // Selec perso
		window.draw(_selecPerso);
		break;
	}
}