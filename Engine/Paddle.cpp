#include "Paddle.h"

Paddle::Paddle(Vec2 & center)
{
	this->center = center;
	UpdateRect();
}

void Paddle::Draw(Graphics & gfx)
{
	gfx.DrawRect(rect, c);
}

void Paddle::Update(Keyboard & kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		center.x -= (vel * dt);
		UpdateRect();
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		center.x += (vel * dt);
		UpdateRect();
	}
	IsWallColliding();

}

void Paddle::UpdateRect()
{
	rect = { center.x - (width / 2.0f),center.x + (width / 2.0f),center.y - (height / 2.0f),center.y + (height / 2.0f) };
}

bool Paddle::IsWallColliding()
{
	if (rect.IsOverlappingWith(RectF({ -40.0f,-40.0f }, 40.0f, 680.0f))) 
	{
		center.x = width / 2.0f;
		UpdateRect();
		return true;
	}
	else if (rect.IsOverlappingWith(RectF({ 800.0f,-40.0f }, 40.0f, 680.0f)))
	{
		center.x = 800.0f - (width / 2.0f);
		UpdateRect();
		return true;
	}
	return false;
}
