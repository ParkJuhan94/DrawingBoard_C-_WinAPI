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

//Ŭ���Ҷ� ���� ITEM ���� draw �ǵ���. �� frame���� add() �ǵ���
//ó�� Ŭ���� �� status�� ¦��
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