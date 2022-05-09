#pragma once
#include "component.h"

class ActionListener;
class Frame;
class Button
	: public Component
{
public:	
	Button(std::string title);
		
	virtual void onClick(MyEvent e);
};

