#pragma once
#include "Button.h"

class PlusActionListener;
class EraserButton :
    public Button
{
public:
    EraserButton(std::string title);
    void addPlusActionListener(PlusActionListener* l);

    void onClick(MyEvent e) override;
protected:
    std::list<PlusActionListener* > pllist;
};

