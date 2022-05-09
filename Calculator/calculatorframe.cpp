#include "calculatorframe.h"
#include "calculatorbutton.h"
#include "plusactionlistener.h"

CalculatorFrame::CalculatorFrame() :Frame(L"", 800, 600) {
	//
}

CalculatorFrame::CalculatorFrame(std::wstring title, int width, int height)
	: Frame(title, width, height)
{
	//
}

Component* CalculatorFrame::eventHandler(MyEvent e)
{
	Frame::eventHandler(e);
	
	invalidate();
	return nullptr;
}

void CalculatorFrame::initialize()
{
	btnApple = new CalculatorButton("Apple");
	btnBanana = new CalculatorButton("Banana");
	label = new Label(labelText_);

	add(btnApple);
	add(btnBanana);
	add(label);

	btnApple->setBounds(10, 10, 70, 25);
	btnBanana->setBounds(100, 10, 70, 25);
	label->setBounds(55, 70, 70, 25);

	btnApple->addActionListener(new PlusActionListener(this));
	btnBanana->addActionListener(new PlusActionListener(this));
	//OutputDebugString(L"초기화 실행\n");
}

void CalculatorFrame::changeLabel(Component* btn)
{
	if (btn == btnApple) {	
		for( auto i : componentList) {
			if (i->getCntListener() == 0) {

				labelText_ = "Apple";
				i->setTitle(labelText_);

				break;
			}
		}		
	}
	else if (btn == btnBanana) {
		for (auto i : componentList) {
			if (i->getCntListener() == 0) {

				labelText_ = "Banana";
				i->setTitle(labelText_);

				break;
			}
		}
	}
}