#pragma once
#include "Misc.h"
#include <string>
#include <list>

class ActionListener;
class Frame;
class Component
{
public:
	Component(std::string title);

	virtual void draw(HDC hdc);
	virtual void setBounds(int x, int y, int width, int height);
	virtual bool inside(MyPoint p);
	virtual bool inside(int x, int y);
	virtual const char* getTitle();
	virtual void setTitle(std::string title);

	virtual void onClick(MyEvent e);
	virtual void addActionListener(ActionListener* l);
	virtual void addCompo(Component* c);

	virtual void setFrameParent(Frame* f);
	virtual Frame* getFrameParent();
	virtual int getX();
	virtual int getY();

	virtual void setCompoParent(Component* c);
	virtual Component* getCompoParent();     

	virtual int getCntListener();
	
	int mode_ = 0;		//mode_°¡ È¦¼öÀÏ ¶§ mode ON
protected:
	int x_, y_, width_, height_;
	Frame* frameParent_ = nullptr;
	Component* compoParent_ = nullptr;
	std::string title_;	
	std::list<ActionListener* > llist;
};

