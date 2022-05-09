#pragma once
#include "Button.h"

class CalculatorButton :
    public Button
{
public:
    CalculatorButton(std::string title);

    void onClick(MyEvent e) override;
    void setParent(Frame*) override;
};

