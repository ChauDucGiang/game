#pragma once
// Hình chữ nhật bao quanh object
struct Rect
{
	float x, y;					// Toạ độ
	float width, height;		// Kích thước

	Rect() {}
	Rect(float x, float y, float width, float height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
	
	// Kiểm tra this chứa r
	bool IsContain(Rect r)
	{
		return !((x + width < r.x) || (x > r.x + r.width) || (y < r.y - r.height) || (y - height > r.y));
	}
};