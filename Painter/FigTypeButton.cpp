#include "FigTypeButton.h"
#include "PainterFrame.h"
#include "plusactionlistener.h"

FigTypeButton::FigTypeButton(std::string title)
	:Button(title)
{
	//
}

void FigTypeButton::onClick(MyEvent e) {	
	for (auto i : pllist) {
		//i->actionPerformed();
		i->getContainer()->setFigType(this);
	}
	//parent_->setFigType(this);	->listener ���� �� ����
}

void FigTypeButton::addPlusActionListener(PlusActionListener* l) {
	pllist.push_back(l);
	OutputDebugString(L"������ ����\n");
}