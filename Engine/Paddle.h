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


private:
	static constexpr Color c = Colors::White;
	RectF rect;
	static constexpr float width{ 80.0f };
	static constexpr float height{ 30.0f };
	Vec2 center;
	float vel =500.0f;
};