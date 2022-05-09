#include "Figure.h"
#include "PainterFrame.h"

Figure::Figure() {
	//
}

Figure::Figure(int l, int t, int r, int b)
	:left_(l), top_(t), right_(r), bottom_(b)
{
	//
}

void Figure::normalize() {
	if (left_ > right_) {
		int temp = left_;
		left_ = right_;
		right_ = temp;
	}
	if (top_ > bottom_) {
		int temp = top_;
		top_ = bottom_;
		bottom_ = temp;
	}
}

bool Figure::inside(MyPoint p) {
	return left_ < p.x_&& p.x_ < right_
		&& top_ < p.y_&& p.y_ < bottom_;
}

void Figure::move(int dx, int dy) {
	left_ += dx;
	right_ += dx;
	top_ += dy;
	bottom_ += dy;
}

void Figure::setParent(PainterFrame* parent) {
	parent_ = parent;
}

void Figure::erase() {
	parent_->removeFigure(this);
	//OutputDebugString(L"erase() ¼º°ø\n");
}