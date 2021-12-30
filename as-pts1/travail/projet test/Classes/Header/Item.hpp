
#ifndef DEF_ITEM
#define DEF_ITEM

#include "TextureLoader.h"
using namespace std;

class Item
{
protected:
	Sprite _leSprite;
public:
	Item(Texture&);
	Sprite& getSprite();
};


#endif