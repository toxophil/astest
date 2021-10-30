
/* Generated from GenMyModel */

#include "..\Header\DrawableObject.hpp"
#include "..\Header\Angle.hpp"

//initialisation de l'incr�menteur
uint32_t DrawableObject::_nextId = 0;

DrawableObject::DrawableObject()
{
	//g�n�re un id diff�rent par objet
	_id = DrawableObject::_nextId++;

	//initialisation avec des valeurs piff�s
	_angle = Angle();
	_height = 1;
	_width = 1;

}

uint32_t DrawableObject::getId() const
{
	return _id;
}
