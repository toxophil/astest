
/* Generated from GenMyModel */

#include "../Header/DrawableObject.hpp"
#include "../Header/Angle.hpp"

//initialisation de l'incrémenteur
uint32_t DrawableObject::_nextId = 0;

DrawableObject::DrawableObject(){
	//génère un id différent par objet
	_id = DrawableObject::_nextId++;

	//initialisation avec des valeurs piffés
	_angle = Angle();
	_height = 1;
	_width = 1;

}
DrawableObject::DrawableObject(Angle& a, uint32_t h, uint32_t w) {
	//génère un id différent par objet
	_id = DrawableObject::_nextId++;

	_angle = a;
	_height = h;
	_width = w;
}


uint32_t DrawableObject::getId() const {
	return _id;
}
uint32_t DrawableObject::getWidth() const {
	return _width;
}
uint32_t DrawableObject::getHeight() const {
	return _height;
}
Angle& DrawableObject::getAngle() {
	return _angle;
}

const sf::Sprite& DrawableObject::getSprite() {
	return _sprite;
}
