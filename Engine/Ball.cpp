#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2 & center)
{
	this->center = center;
	rect = { center.x - r,center.x + r,center.y - r,center.y + r };
}

void Ball::Draw(Graphics & gfx)
{
	SpriteCodex::DrawBall(center, gfx);
}

void Ball::Update(float dt)
{
	
	Vec2 old_center = center;//
	center+= (vel * dt);
	if (IsWallColliding())
	{
		old_center += vel * dt;
		center = old_center;
		UpdateRect();
	}
	UpdateRect();
	

}

bool Ball::IsWallColliding( )
{
	UpdateRect();
	if (rect.IsOverlappingWith(RectF({ -20.0f,-20.0f }, 20.0f, 640.0f))) //mporei k na fygei na paei volta
	{
		BounceX();
		return true;
	}
	else if(rect.IsOverlappingWith(RectF({ 800.0f,00.0f }, 20, 600.0f)))
	{
		BounceX();
		return true;
	}
	if (rect.IsOverlappingWith(RectF({ -20.0f,-20.0f }, 840.0f, 20.0f ))) //mporei k na fygei na paei volta
	{
		BounceY();
		return true;
	}
	else if (rect.IsOverlappingWith(RectF({ 00.0f,600.0f }, 800.0f,20 )))
	{
		BounceY();
		return true;
	}
	return false;

}

void Ball::BounceX()
{
	vel.x *= -1.0f;
}

void Ball::BounceY()
{
	vel.y *= -1.0f;
}

void Ball::UpdateRect()
{
	rect = { center.x - r,center.x + r,center.y - r,center.y + r };
}
