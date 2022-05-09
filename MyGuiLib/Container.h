#pragma once
#include "component.h"

class Container : 
	public Component
{
public:
	Container(std::string title);

	virtual void onClick(MyEvent e);
	virtual void addCompo(Component* c);
	
protected:
	std::list<Component*> compoList_;
	int status_ = 0;	//status_가 홀수일 때 this를 제거
};

