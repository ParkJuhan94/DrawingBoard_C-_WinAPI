#pragma once
#include "frame.h"

class ActionListener {
public:
	virtual void actionPerformed() = 0;
	virtual Frame* getContainer() = 0;
};