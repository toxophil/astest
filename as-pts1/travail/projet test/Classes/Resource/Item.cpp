#include "../Header/Item.hpp"


Item::Item(Texture& laTexture) {
	_leSprite.setTexture(laTexture);

	sf::Vector2u size = laTexture.getSize();
	_leSprite.setOrigin(size.x/2, size.y/2);
}

Sprite& Item::getSprite() {
	return _leSprite;
}