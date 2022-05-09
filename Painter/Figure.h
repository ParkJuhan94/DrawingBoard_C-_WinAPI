#pragma once
#include "Windows.h"
#include "Misc.h"

class PainterFrame;
class Figure
{
public:
	Figure();
	Figure(int l, int t, int r, int b);
	virtual void draw(HDC hdc) = 0;
	virtual void pourBlack() = 0;
	virtual void pourRed() = 0;
	virtual void pourBlue() = 0;
	void erase();
	virtual void setParent(PainterFrame* parent);

	void normalize();	//사각형그릴 때 left가 right보다 왼쪽에 있어야한다. top bottom도 마찬가지. 정규화.
	virtual void move(int dx, int dy);	
	bool inside(MyPoint);

	int left_, top_;		//시작점 x y
	int right_, bottom_;	//끝점   x y		

	static const int BLACK_TYPE = 1;
	static const int RED_TYPE = 2;
	static const int BLUE_TYPE = 3;
	int moveMode_ = 0;

protected:
	PainterFrame* parent_ = nullptr;
	int colorType_ = 0;
};

