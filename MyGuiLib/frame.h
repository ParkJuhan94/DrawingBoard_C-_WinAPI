#pragma once
#include "Windows.h"
#include <WinUser.h>
#include <string>
#include <list>
#include "Misc.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Component;
class Frame {
protected:
	// Window 프로그래밍을 위한 기본 변수들이다. 건드리지 않는다.
	HINSTANCE hInst_;
	HWND hWnd_;
	HDC hDC_;    // 이 변수가 있어야 그림을 그릴 수 있다.

	// 응용을 위해 필요한 변수
	MyPoint start_;
	MyPoint end_;

	//하나의 도형 객체를 저장하기 위한 변수
	//Figure* tempFigure = nullptr;
		
	std::list<Component*> componentList;		//라이브러리  -->Frame
public:
	Frame();
	Frame(std::wstring, int width, int height);

	void run();
	void invalidate();
	void add(Component* c);
	void remove(Component* c);
	Component* findComponent(MyPoint p);

	virtual Component* eventHandler(MyEvent e);
	virtual void changeLabel(Component* c);
	virtual void repaint();

	virtual void initialize() = 0;
	
};
