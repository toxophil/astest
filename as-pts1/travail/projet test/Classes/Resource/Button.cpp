#include "../Header/Button.hpp"

bool Button::isHovered(sf::RenderWindow& laWindow) {
	const sf::Vector2f mousePosition = laWindow.mapPixelToCoords(sf::Mouse::getPosition(laWindow));
	if (mousePosition.x >= _x && mousePosition.x <= _x + _w && mousePosition.y >= _y && mousePosition.y <= _y + _h) {
		return true;
	}
	return false;
}

Button::Button(string text, int64_t x, int64_t y, uint64_t w, uint64_t h, sf::Font& laFont ) {

	_text.setFont(laFont);
	_text.setString(text);
	_text.setCharacterSize(38);

	sf::FloatRect globalBounds = _text.getGlobalBounds();
	_text.setPosition(x+w/2 - globalBounds.width/2, y + (int64_t)h/2 - 19 - 4);
	_text.setFillColor(sf::Color::Black);

	_x = x;
	_y = y;
	_w = w;
	_h = h;

	_rectangle = sf::RectangleShape();
	_rectangle.setPosition(x, y);
	_rectangle.setSize(sf::Vector2f(w, h));
	_rectangle.setFillColor(sf::Color::White);
}
void Button::draw(sf::RenderWindow& laWindow) {
	if (isHovered(laWindow)) {
		_text.setFillColor(sf::Color::White);
		_rectangle.setFillColor(sf::Color::Black);
	}
	else {
		_text.setFillColor(sf::Color::Black);
		_rectangle.setFillColor(sf::Color::White);
	}

	laWindow.draw(_rectangle);
	laWindow.draw(_text);
}