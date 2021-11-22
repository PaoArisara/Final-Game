#include "Item.h"

Item::Item(float pos_x, float pos_y, Texture* texture, int type)
{
	this->type = type;
	this->ItemSprite.setPosition(pos_x, pos_y);
	this->ItemSprite.setTexture(*texture);
	this->ItemSprite.setScale(0.03f, 0.03f);

	if (type == ITEM_BULLET)
	{
		this->ItemSprite.setScale(0.03, 0.03f);
	}

}

void Item::update()
{
	this->ItemSprite.move(0.f, 0.4f);
}

void Item::render(RenderTarget* target)
{
	target->draw(this->ItemSprite);
}
