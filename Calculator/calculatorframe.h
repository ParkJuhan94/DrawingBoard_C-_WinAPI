#pragma once
#include "frame.h"
#include "label.h"

class CalculatorFrame :
    public Frame
{
public:
	CalculatorFrame();
	CalculatorFrame(std::wstring, int width, int height);

	Component* eventHandler(MyEvent e) override;		
	void initialize() override;	
	void changeLabel(Component* btn);
protected:
	std::string labelText_ = "EditText";		//label의 기본 텍스트를 EditText로 지정
	Component* btnApple = nullptr;
	Component* btnBanana = nullptr;
	Component* label = nullptr;
};

