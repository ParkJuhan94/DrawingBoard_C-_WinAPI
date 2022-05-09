#include "Rect.h"
#include "PainterFrame.h"

Rect::Rect(int l, int t, int r, int b)
	:Figure(l, t, r, b)
{
	//
}

void Rect::draw(HDC hdc) {
	if (colorType_ == BLACK_TYPE) {
		HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

		Rectangle(hdc, left_, top_, right_, bottom_);

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);
	}
	else if (colorType_ == RED_TYPE) {
		HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

		Rectangle(hdc, left_, top_, right_, bottom_);

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);
	}
	else if (colorType_ == BLUE_TYPE) {
		HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

		Rectangle(hdc, left_, top_, right_, bottom_);

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);
	}
	else {		//색 안채움. default
		Rectangle(hdc, left_, top_, right_, bottom_);
	}	
}

void Rect::pourBlack() {
	colorType_ = BLACK_TYPE;
	parent_->removeFigure(this);
	parent_->reAddFigure(this);
}

void Rect::pourRed() {
	colorType_ = RED_TYPE;
	parent_->removeFigure(this);
	parent_->reAddFigure(this);
}

void Rect::pourBlue() {
	colorType_ = BLUE_TYPE;
	parent_->removeFigure(this);
	parent_->reAddFigure(this);
}

