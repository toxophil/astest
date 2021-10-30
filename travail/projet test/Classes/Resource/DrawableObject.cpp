
/* Generated from GenMyModel */

#include "..\Header\DrawableObject.hpp"
#include "..\Header\Angle.hpp"

//initialisation de l'incrémenteur
uint32_t DrawableObject::_nextId = 0;

DrawableObject::DrawableObject()
{
	//génère un id différent par objet
	_id = DrawableObject::_nextId++;

	//initialisation avec des valeurs piffés
	_angle = Angle();
	_height = 1;
	_width = 1;

}

uint32_t DrawableObject::getId() const
{
	return _id;
}
