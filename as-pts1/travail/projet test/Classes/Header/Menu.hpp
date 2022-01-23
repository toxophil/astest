
#ifndef DEF_MENU
#define DEF_MENU

#include "Animation.hpp"
#include "Button.hpp"

class Menu
{
private:
	sf::Font fontMenu;
	vector<Button> _lesBoutons;
	vector<Button> _lesBoutonsClasse;

	Animation _backgroundAnim;
	sf::Clock _animTime;

	sf::Texture _imgCommentJouer;
	sf::Texture _imgHistoire;

	sf::Sprite _backgroundSprite;
	sf::Sprite _logoSprite;

	sf::View _laVue;

	sf::Sprite _commentJouer;
	sf::Sprite _histoire;

	sf::Text _selecPerso;
	uint8_t menuState = 0;
public:
	Menu();
	void logicMenu(sf::RenderWindow&, const sf::Event& event);
};


#endif
