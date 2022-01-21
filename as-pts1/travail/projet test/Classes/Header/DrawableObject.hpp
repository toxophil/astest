
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
		

protected:
	uint32_t _id;
	double _width;
	double _height;
	Angle _angle;
	sf::Sprite _sprite;
	int _estEnnemi;
	int _type; //1 player 2 ennemie 3 projectile 0 default

	float _nbVie; //10 = max nb vie player
	float _pvMonstre; //pv pour les monstres
	uint32_t _nbPiece;
	float _degat;
	float _pvLargeur ; //largeur en pixel
	float _pvHauteur ; //hauteur en pixel
	sf::RectangleShape _restant;
	sf::RectangleShape _max;


	sf::Text _pvText;
	sf::Font _fontText;

public:
	DrawableObject();
	DrawableObject(Angle& a, uint32_t h, uint32_t w);
	
	int getNbVie() const;
	int getNbPiece() const;
	uint32_t getDegat() const;
	uint32_t getId() const;
	uint32_t getWidth() const;
	uint32_t getHeight() const;
	Angle& getAngle();
	int getType();
	const sf::Sprite& getSprite();
	float getPvMonstre();
	void setPvMonstre(float hp);
};


#endif
