
/* Generated from GenMyModel */

#include "..\Header\DrawableObject.hpp"

//initialisation de l'incr�menteur
uint32_t DrawableObject::_nextId = 0;

DrawableObject::DrawableObject()
{
	//g�n�re un id diff�rent par objet
	_id = DrawableObject::_nextId++;

}

uint32_t DrawableObject::getId() const
{
	return _id;
}
