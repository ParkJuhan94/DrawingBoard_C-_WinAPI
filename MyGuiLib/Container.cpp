#include "Container.h"
#include "frame.h"

Container::Container(std::string title)
	: Component(title)
{
	width_ = 70; height_ = 25;
}

void Container::addCompo(Component* c) {
	compoList_.push_back(c);
	c->setCompoParent(this);
}

//클릭할때 하위 ITEM 들이 draw 되도록. 즉 frame에서 add() 되도록
//처음 클릭할 때 status는 짝수
void Container::onClick(MyEvent e) {
	
	if (status_ % 2) {
		for (auto i : compoList_) {
			i->getFrameParent()->remove(i);			
		}
	}
	else {
		for (auto i : compoList_) {
			i->getFrameParent()->add(i);
		}
	}
	
	status_++;
	mode_++;
}