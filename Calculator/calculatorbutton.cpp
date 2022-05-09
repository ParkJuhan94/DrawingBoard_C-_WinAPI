#include "calculatorbutton.h"
#include "listener.h"
#include "calculatorframe.h"

CalculatorButton::CalculatorButton(std::string title)
	:Button(title)
{
	//
}

void CalculatorButton::onClick(MyEvent e) {
	OutputDebugString(L"clicked\n");
	for (auto i : llist) {
		//i->actionPerformed();
		i->getContainer()->changeLabel(this);
	}	
}

void CalculatorButton::setParent(Frame* f) {
	parent_ = f;
}