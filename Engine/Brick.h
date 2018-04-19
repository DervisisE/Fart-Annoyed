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
	RectF rect;
	bool destroyed = false;
private:
	
	static constexpr float width{ 20.0f };
	static constexpr float height{ 48.0f };
	Color c;
	
};
