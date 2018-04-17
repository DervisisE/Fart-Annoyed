#include "Brick.h"

Brick::Brick(Vec2 & topLeft,  Color c)
{
	this->c = c;
	rect = { topLeft.x,topLeft.x + width,topLeft.y,topLeft.y + height };

}

void Brick::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect, c);
}
