
#ifndef DEF_MENU
#define DEF_MENU

#include "Animation.hpp"

class Menu
{
private:
	vector<String> _lesBoutons;
	Animation _backgroundAnim;
	sf::Clock _animTime;

	sf::Sprite _backgroundSprite;
	sf::Sprite _logoSprite;

	sf::View _laVue;
public:
	Menu();
	void logicMenu(sf::RenderWindow&, const sf::Event& event);
};


#endif
