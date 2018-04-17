#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(Vec2& center);
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool IsWallColliding();
	void BounceX();
	void BounceY();
private:
	RectF rect;
	Vec2 vel = { 300.0f, 300.0f };
	Vec2 center;
	static constexpr float r{ 7.0f };
	//Color c;
	void UpdateRect();
};
