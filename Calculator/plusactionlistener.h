#pragma once
#include "listener.h"
#include "calculatorbutton.h"

class PlusActionListener 
    : public ActionListener
{
public:
    PlusActionListener(Frame* container);
    void actionPerformed() override;
    Frame* getContainer() override;
protected:
    Frame* container_ = nullptr;
};

