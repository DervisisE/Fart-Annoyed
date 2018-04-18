#include "Ball.h"
#include "SpriteCodex.h"
#include <math.h>

Ball::Ball(Vec2 & center)
{
	this->center = center;
	UpdateRect();
}

void Ball::Draw(Graphics & gfx)
{
	SpriteCodex::DrawBall(center, gfx);
}

void Ball::Update(RectF& other,float dt)
{
	
	Vec2 old_center = center;
	center+= (vel * dt);
	if (IsWallColliding())
	{
		old_center += vel * dt;
		center = old_center;
	}
	UpdateRect();

	
	
	 
	if (IsColliding(other, false))
	{
		old_center += vel * dt;
		center = old_center;
	}
	UpdateRect();
	

}

bool Ball::IsWallColliding( )
{
	UpdateRect();
	bool isColliding = false;
	if (rect.IsOverlappingWith(RectF({ -40.0f,-40.0f }, 40.0f, 680.0f))) //mporei k na fygei na paei volta
	{
		BounceX();
		isColliding=true;
	}
	else if(rect.IsOverlappingWith(RectF({ 800.0f,-40.0f }, 40.0f, 680.0f)))
	{
		BounceX();
		isColliding = true;
	}
	if (rect.IsOverlappingWith(RectF({ -40.0f,-40.0f }, 880.0f, 40.0f ))) //mporei k na fygei na paei volta
	{
		BounceY();
		isColliding = true;
	}
	else if (rect.IsOverlappingWith(RectF({ -40.0f,600.0f }, 880.0f,40.0f )))
	{
		BounceY();
		isColliding = true;
	}
	return isColliding;

}

void Ball::BounceX()
{
	vel.x *= -1.0f;
}

void Ball::BounceY()
{
	vel.y *= -1.0f;
}

bool Ball::IsColliding(RectF & otherRect,bool hasChangedVel)
{
	UpdateRect();
	if (rect.IsOverlappingWith(otherRect))
	{
		Vec2 otherCenter = { (otherRect.left + otherRect.right) / 2.0f,(otherRect.top + otherRect.bottom) / 2.0f };
		Vec2 c2c = otherCenter - center;
		c2c.Normalize();
		if (abs(c2c.x)>0.707168 && !hasChangedVel)
		{
			BounceX();
		}
		else if (abs(c2c.y)>0.707168 && !hasChangedVel)
		{
			BounceY();
		}//GWNIESS
		return true;
	}
	else
	{
		return false;
	}
}

void Ball::UpdateRect()
{
	rect = { center.x - r,center.x + r,center.y - r,center.y + r };
}
