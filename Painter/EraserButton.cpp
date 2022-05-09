#include "EraserButton.h"
#include "PainterFrame.h"
#include "plusactionlistener.h"

EraserButton::EraserButton(std::string title)
	:Button(title)
{
	//
}

void EraserButton::onClick(MyEvent e) {	
	for (auto i : pllist) {
		i->getContainer()->setPourColor(this);
	}
}

void EraserButton::addPlusActionListener(PlusActionListener* l) {
	pllist.push_back(l);
	OutputDebugString(L"리스너 생성\n");
}