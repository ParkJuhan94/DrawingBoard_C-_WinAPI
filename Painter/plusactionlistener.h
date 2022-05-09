#pragma once
#include "listener.h"
#include "FigTypeButton.h"
#include "PainterFrame.h"

class PlusActionListener 
    : public ActionListener
{
public:
    PlusActionListener(PainterFrame* container);
    void actionPerformed() override;
    PainterFrame* getContainer();
protected:
    PainterFrame* container_ = nullptr;
};

