#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"



class Paddle
{
public:
	Paddle(Vec2& center);
	void Draw(Graphics& gfx);
	void Update(Keyboard& kbd, float dt);
	void UpdateRect();
	bool IsWallColliding();
    RectF rect;

private:
	static constexpr Color c = Colors::White;
	static constexpr float width{ 200.0f };
	static constexpr float height{ 30.0f };
	Vec2 center;
	float vel =500.0f;
};