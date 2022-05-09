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
	//parent_->setFigType(this);	->listener 쓰기 전 상태
}

void FigTypeButton::addPlusActionListener(PlusActionListener* l) {
	pllist.push_back(l);
	OutputDebugString(L"리스너 생성\n");
}