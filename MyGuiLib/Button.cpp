#include "Button.h"
#include "frame.h"

Button::Button(std::string title)
	: Component(title)
{
	width_ = 70; height_ = 25;
}

void Button::onClick(MyEvent e) {}