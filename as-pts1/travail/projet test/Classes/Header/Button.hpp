
#ifndef DEF_BUTTON
#define DEF_BUTTON


#include <SFML/Graphics.hpp>
using namespace std;

class Button {
private:
	sf::Text _text;
	int64_t _x;
	int64_t _y;
	uint64_t _w;
	uint64_t _h;
	sf::RectangleShape _rectangle;

	bool isHovered(sf::RenderWindow&);
public:
	Button(string, int64_t, int64_t, uint64_t, uint64_t, sf::Font&);
	void draw(sf::RenderWindow&);
};


#endif
