#include "SpinButton.h"
#include "frame.h"

SpinButton::SpinButton(std::string title)
	: Component(title)
{
	width_ = 70; height_ = 25;
}

void SpinButton::onClick(MyEvent e) {
	mode_++;
}

