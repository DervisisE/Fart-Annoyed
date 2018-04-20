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
		float percentageX = 1.0f;
		float percentageY = 1.0f;
		/*if (abs(c2c.x)>(otherRect.right - otherRect.left) / 2.0f)
		{
			percentageX = abs(c2c.x) - ((otherRect.right - otherRect.left) / 2.0f);
			//percentageX = c2c.x - ((otherRect. - otherRect.) / 2.0f);
		}
		if (abs(c2c.y)>(otherRect.bottom - otherRect.top) / 2.0f)
		{
			percentageY = abs(c2c.y)  - ((otherRect.bottom - otherRect.top) / 2.0f);
			//percentageY = c2c.y - ((otherRect.bottom - otherRect.top) / 2.0f);
		}*/

		//c2c.x -= percentageX;
		//c2c.y -= percentageY;
		if (((abs(c2c.x) - (otherRect.right - otherRect.left) / 2.0f) + (abs(c2c.y) - (otherRect.bottom - otherRect.top) / 2.0f))>r)
		{
			return false;
		}
		c2c.x /= ((otherRect.right - otherRect.left) / 2.0f);
		c2c.y /= ((otherRect.bottom - otherRect.top) / 2.0f);
		c2c.Normalize();
		if (abs(c2c.x)>0.70710678f && !hasChangedVel)
		{
			BounceX();
		}
		else if (abs(c2c.y)>0.70710678f && !hasChangedVel)
		{
			BounceY();
		}
		else if (!hasChangedVel)
		{
			BounceX(); BounceY();
		}
		
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
