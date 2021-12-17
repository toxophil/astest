
#ifndef DEF_HUD
#define DEF_HUD


#include <SFML/Graphics.hpp>
#include "Animation.hpp"
using namespace std;

class Hud {
private:
	sf::Font _fontText;
	sf::Text _monneyText;

	vector<sf::Sprite> _lesCoeurs;

	sf::Texture _heartFull;
	sf::Texture _heartDemi;
	sf::Texture _heartEmpty;

	sf::Sprite _coinSprite;
	Animation _coinAnim;
	sf::Clock _animTime;

	sf::View _laVue;
public:
	Hud(std::uint16_t);
	void addHeart();
	void updateMoney(uint32_t);
	void draw(sf::RenderWindow&, float);
};


#endif
