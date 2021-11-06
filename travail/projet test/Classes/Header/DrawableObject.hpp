
/* Generated from GenMyModel */

#ifndef DEF_DRAWABLEOBJECT
#define DEF_DRAWABLEOBJECT

#include <SFML/Graphics.hpp>
#include "Angle.hpp"

class DrawableObject
{
	//utilisé pour savoir quel id donner au prochain objet
	static uint32_t _nextId;

	private :
		uint32_t _id;

protected:
	double _width;
	double _height;
	Angle _angle;
	sf::Sprite _sprite;

public:

	DrawableObject();

	DrawableObject(Angle& a, uint32_t h, uint32_t w);

	
	uint32_t getId() const;
	uint32_t getWidth() const;
	uint32_t getHeight() const;
	Angle& getAngle();
};


#endif
