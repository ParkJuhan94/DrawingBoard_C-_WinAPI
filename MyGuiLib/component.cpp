#include "component.h"
#include "frame.h"

Component::Component(std::string title)
	: title_(title), x_(0), y_(0), width_(0), height_(0) {}

void Component::draw(HDC hdc) {
	HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 65, 85));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);	

	SetTextColor(hdc, RGB(255, 255, 255));
	SetBkColor(hdc, RGB(0, 65, 85));

	Rectangle(hdc, x_, y_, x_ + width_, y_ + height_);
	TextOutA(hdc, x_ + 5, y_ + 4, title_.c_str(), title_.length());	

	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);
}

void Component::setBounds(int x, int y, int width, int height) {
	x_ = x; y_ = y; width_ = width; height_ = height;
}

bool Component::inside(MyPoint p) {
	return inside(p.x_, p.y_); 
}

bool Component::inside(int x, int y) {
	return (x_ < x) && (x < (x_ + width_)) && (y_ < y) && (y < (y_ + height_));
}

void Component::addActionListener(ActionListener* l) {
	llist.push_back(l);
}

void Component::addCompo(Component* c) {}

int Component::getX() {return this->x_;}

int Component::getY() {return this->y_;}

const char* Component::getTitle() {return title_.c_str();}

void Component::setTitle(std::string title) {title_ = title;}

void Component::setFrameParent(Frame* f) {frameParent_ = f;}

Frame* Component::getFrameParent() {return frameParent_;}

void Component::setCompoParent(Component* c) {compoParent_ = c;}

Component* Component::getCompoParent() {return compoParent_;}

int Component::getCntListener() {return llist.size();}

void Component::onClick(MyEvent e) {}