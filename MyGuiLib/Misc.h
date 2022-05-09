#pragma once
#include "Windows.h"

class MyPoint {
public:
	int x_, y_;
	MyPoint(int x, int y);
	MyPoint();
};

class Component;
class MyEvent {
private:
	UINT msg_;
	WPARAM wParam_;
	LPARAM lParam_;
	Component* source_;
public:
	MyEvent(UINT msg, WPARAM wParam, LPARAM lParam);
	bool isLButtonDown();
	bool isLButtonUp();
	bool isRButtonDown();
	bool isRButtonUp();
	bool isCtrlKeyDown();
	bool isShiftKeyDown();
	int getX();
	int getY();
	MyPoint getPos();
	MyEvent addSource(Component* c);
	Component* getSource();
};
