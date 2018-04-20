#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(Vec2& center);
	void Draw(Graphics& gfx);

	void Update(RectF& other, float dt);
	bool IsWallColliding();
	void BounceX();
	void BounceY();
	bool IsColliding(RectF& otherRect,bool hasChangedVel);
private:
	RectF rect;
	Vec2 vel = { 50.0f, 50.0f };
	Vec2 center;
	static constexpr float r{ 7.0f };
	//Color c;
	void UpdateRect();
};
