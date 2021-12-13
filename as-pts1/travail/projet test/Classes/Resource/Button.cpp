#include "../Header/Button.hpp"

bool Button::isHovered(sf::RenderWindow& laWindow) {
	const sf::Vector2f mousePosition = laWindow.mapPixelToCoords(sf::Mouse::getPosition(laWindow));
	if (mousePosition.x >= _x && mousePosition.x <= _x + _w && mousePosition.y <= _y && mousePosition.y >= _y + _h) {
		return true;
	}
	return false;
}

Button::Button(string text, int64_t x, int64_t y, uint64_t w, uint64_t h) {
	_text.setString(text);
	_text.setFillColor(sf::Color::Black);
	_text.setPosition(x, y - h/2);

	_x = x;
	_y = y;
	_w = w;
	_h = h;

	_rectangle = sf::RectangleShape(sf::Vector2f(x, y));
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