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
	// Window ���α׷����� ���� �⺻ �������̴�. �ǵ帮�� �ʴ´�.
	HINSTANCE hInst_;
	HWND hWnd_;
	HDC hDC_;    // �� ������ �־�� �׸��� �׸� �� �ִ�.

	// ������ ���� �ʿ��� ����
	MyPoint start_;
	MyPoint end_;

	//�ϳ��� ���� ��ü�� �����ϱ� ���� ����
	//Figure* tempFigure = nullptr;
		
	std::list<Component*> componentList;		//���̺귯��  -->Frame
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
