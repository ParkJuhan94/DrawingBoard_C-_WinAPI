#pragma once
#include "Button.h"

class PlusActionListener;
class PourColorButton :
    public Button
{
public:
    PourColorButton(std::string title);
    void addPlusActionListener(PlusActionListener* l);

    void onClick(MyEvent e) override;
protected:
    std::list<PlusActionListener* > pllist;
};

