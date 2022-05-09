#include "plusactionlistener.h"

PlusActionListener::PlusActionListener(Frame* container) 
	: container_(container)
{
	//
}

void PlusActionListener::actionPerformed() {
//	container_->setFigType();
}

Frame* PlusActionListener::getContainer() {
	return container_;
}
