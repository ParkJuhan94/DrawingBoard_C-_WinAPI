#include "label.h"
#include "frame.h"

Label::Label(std::string title)
	: Component(title)
{
	width_ = 400; height_ = 25;
}
