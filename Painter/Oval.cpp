#include "Oval.h"
#include "PainterFrame.h"

Oval::Oval(int l, int t, int r, int b)
	:Figure(l, t, r, b)
{
	//
}

void Oval::draw(HDC hdc) {
	if (colorType_ == BLACK_TYPE) {
		HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

		Ellipse(hdc, left_, top_, right_, bottom_);

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);
	}
	else if (colorType_ == RED_TYPE) {
		HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

		Ellipse(hdc, left_, top_, right_, bottom_);

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);
	}
	else if (colorType_ == BLUE_TYPE) {
		HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

		Ellipse(hdc, left_, top_, right_, bottom_);

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);
	}
	else {		//색 안채움. default
		Ellipse(hdc, left_, top_, right_, bottom_);
	}
}

void Oval::pourBlack() {
	colorType_ = BLACK_TYPE;
	parent_->removeFigure(this);
	parent_->reAddFigure(this);
}

void Oval::pourRed() {
	colorType_ = RED_TYPE;
	parent_->removeFigure(this);
	parent_->reAddFigure(this);
}

void Oval::pourBlue() {
	colorType_ = BLUE_TYPE;
	parent_->removeFigure(this);
	parent_->reAddFigure(this);
}
