#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
class Brick
{
public:
	Brick() = default;
	Brick(Vec2& topLeft,Color c);
	void Draw(Graphics& gfx) const;

private:
	RectF rect;
	static constexpr float width{ 40.0f };
	static constexpr float height{ 24.0f };
	Color c;
	bool destroyed = false;
};
