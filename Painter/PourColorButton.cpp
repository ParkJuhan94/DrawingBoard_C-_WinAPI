#include "PourColorButton.h"
#include "PainterFrame.h"
#include "plusactionlistener.h"

PourColorButton::PourColorButton(std::string title)
	:Button(title)
{
	//
}

void PourColorButton::onClick(MyEvent e) {	
	for (auto i : pllist) {
		i->getContainer()->setPourColor(this);
	}	
}

void PourColorButton::addPlusActionListener(PlusActionListener* l) {
	pllist.push_back(l);
	OutputDebugString(L"리스너 생성\n");
}