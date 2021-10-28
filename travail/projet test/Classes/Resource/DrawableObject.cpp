
/* Generated from GenMyModel */

#include "..\Header\DrawableObject.hpp"

//initialisation de l'incrémenteur
uint32_t DrawableObject::_nextId = 0;

DrawableObject::DrawableObject()
{
	//génère un id différent par objet
	_id = DrawableObject::_nextId++;

}

uint32_t DrawableObject::getId() const
{
	return _id;
}
