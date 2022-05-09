#pragma once
#include "component.h"

class ActionListener;
class Frame;
class SpinButton :
    public Component
{
public:
	SpinButton(std::string title);

	virtual void onClick(MyEvent e);
};

