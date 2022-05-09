#include "plusactionlistener.h"

PlusActionListener::PlusActionListener(PainterFrame* container)
	: container_(container)
{
	//
}

void PlusActionListener::actionPerformed() {
//	container_->setFigType();
}

PainterFrame* PlusActionListener::getContainer() {
	return container_;
}
