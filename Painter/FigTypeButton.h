#pragma once
#include "Button.h"

class PlusActionListener;
class FigTypeButton : 
    public Button
{
public:     
    FigTypeButton(std::string title);
    void addPlusActionListener(PlusActionListener* l);

    void onClick(MyEvent e) override;
protected:
    std::list<PlusActionListener*> pllist;
};