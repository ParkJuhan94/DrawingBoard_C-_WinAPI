#include "Group.h"
#include "PainterFrame.h"

Group::Group() {
	//
}

void Group::setBoundary() {
	left_ = top_ = INT_MAX;
	right_ = bottom_ = INT_MIN;

	for (auto f : figList) {
		if (f->left_ < this->left_)
			this->left_ = f->left_;
		if (f->top_ < this->top_)
			this->top_ = f->top_;
		if (f->right_ > this->right_)
			this->right_ = f->right_;
		if (f->bottom_ > this->bottom_)
			this->bottom_ = f->bottom_;
	}
}

void Group::draw(HDC hdc) {
	if (colorType_ == BLACK_TYPE) {
		HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

		Rectangle(hdc, left_, top_, right_, bottom_);
		for (Figure* f : figList) {
			f->draw(hdc);
		}

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);
	}
	else if (colorType_ == RED_TYPE) {
		HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

		Rectangle(hdc, left_, top_, right_, bottom_);
		for (Figure* f : figList) {
			f->draw(hdc);
		}

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
		for (Figure* f : figList) {
			f->draw(hdc);
		}
	}

	
//	for (Figure* f : figList) {
//		f->draw(hdc);
//	}
}

void Group::add(Figure* f) {
	figList.push_back(f);
}

bool Group::isEmpty() {
	return figList.empty();		
}

void Group::move(int dx, int dy) {
	Figure::move(dx, dy);
	for (Figure* f : figList) {
		f->move(dx, dy);
	}
}

void Group::pourBlack() {
	colorType_ = BLACK_TYPE;
	parent_->removeFigure(this);
	parent_->reAddFigure(this);
}

void Group::pourRed() {
	colorType_ = RED_TYPE;
	parent_->removeFigure(this);
	parent_->reAddFigure(this);
}

void Group::pourBlue() {
	colorType_ = BLUE_TYPE;
	parent_->removeFigure(this);
	parent_->reAddFigure(this);
}
