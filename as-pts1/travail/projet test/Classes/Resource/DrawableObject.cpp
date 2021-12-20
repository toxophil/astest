
/* Generated from GenMyModel */

#include "../Header/DrawableObject.hpp"
#include "../Header/Angle.hpp"
using namespace std;

//initialisation de l'incrémenteur
uint32_t DrawableObject::_nextId = 0;

DrawableObject::DrawableObject(){
	//génère un id différent par objet
	_id = DrawableObject::_nextId++;

	//initialisation avec des valeurs piffés
	_angle = Angle();
	_height = 1;
	_width = 1;
	_nbVie = 9; //10 = max nb vie player 
	_nbPiece = 1500;
	_degat = 0.1;
	_estEnnemi = 0;
	_fontText = sf::Font();
	_fontText.loadFromFile("Ressources/fonts/BitPotionExt.ttf");
	_pvText.setFont(_fontText);
	_pvText.setString("0");
	_pvText.setCharacterSize(10);
	_pvText.setOrigin(20, 20);
	_pvText.setColor(sf::Color(255, 255, 255));
	//_pvText.setPosition((-((int)leScreen.width) / 2) + 3 + (int)spriteSize.x * 8, leScreen.height / 2 - spriteSize.y * 7 - 20 + 10.5);
	_pvMonstre = 100;
	_pvHauteur = 4;
	_pvLargeur = _pvMonstre;
	_type = 0;
	sf::RectangleShape _restant(sf::Vector2f(_pvMonstre, _pvHauteur));
	sf::RectangleShape _max(sf::Vector2f(_pvLargeur, _pvHauteur));
	/*float _nbVie = 10; //10 = max nb vie player
	uint32_t _pvMonstre = 50; //pv pour les monstres
	uint32_t _nbPiece;
	float _degat = 0.1;
	*/
}
DrawableObject::DrawableObject(Angle& a, uint32_t h, uint32_t w) {
	//génère un id différent par objet
	_id = DrawableObject::_nextId++;
	_fontText = sf::Font();
	_fontText.loadFromFile("Ressources/fonts/BitPotionExt.ttf");
	_angle = a;
	_height = h;
	_width = w;
	_nbVie = 9; //10 = max nb vie player 
	_nbPiece = 1500;
	_degat = 0.1;
	_pvMonstre = 100;
	_estEnnemi = 0;
	_pvText.setFont(_fontText);
	_pvText.setString("salut");
	_pvText.setCharacterSize(10);
	_pvText.setOrigin(20, 20);
	_pvText.setColor(sf::Color(255, 255, 255));
	_pvLargeur= _pvMonstre;
	_pvHauteur= 10; 
	sf::RectangleShape _restant(sf::Vector2f(_pvMonstre , _pvHauteur));
	sf::RectangleShape _max(sf::Vector2f(_pvLargeur, _pvHauteur));
}

int DrawableObject::getNbVie() const
{
	return _nbVie;
}
int DrawableObject::getNbPiece() const
{
	return _nbPiece;
}
uint32_t DrawableObject::getDegat() const
{
	return _nbPiece;
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

int DrawableObject::getType()
{
	return _type;
}

