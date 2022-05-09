#include "MenuBar.h"
#include "Menu.h"
#include "SpinButton.h"
#include "PainterFrame.h"
#include "FigTypeButton.h"
#include "PourColorButton.h"
#include "plusactionlistener.h"
#include "EraserButton.h"

#include "Rect.h"
#include "Oval.h"
#include "Group.h"

PainterFrame::PainterFrame() :Frame(L"", 800, 600) {
	//
}

PainterFrame::PainterFrame(std::wstring title, int width, int height)
	: Frame(title, width, height)
{
	//
}

void PainterFrame::initialize() {
	menuBarParent_ = new Component("Nothing");
	menuBar_ = new MenuBar("그리기 도구 모음");

	menuPickFigure_ = new Menu("도형");
	btnRect_ = new FigTypeButton("사각형");
	btnOval_ = new FigTypeButton("타원");

	menuPourColor_ = new Menu("채우기");
	btnBlack_ = new PourColorButton("Black");
	btnRed_ = new PourColorButton("Red");
	btnBlue_ = new PourColorButton("Blue");

	menuEraser_ = new Menu("지우개");
	btnEraser_ = new EraserButton("It's working.");

	spinBtnUp_ = new SpinButton("∧");
	spinBtnDown_ = new SpinButton("∨");
	
	menuBar_->setCompoParent(menuBarParent_);		//menubar의 초기 설정을 위한 셋팅

	//각 component들을 painterframe에 추가
	add(menuBar_);
	add(menuPickFigure_);
	add(menuPourColor_);
	add(menuEraser_);
	add(btnRect_);
	add(btnOval_);
	add(btnBlack_);
	add(btnRed_);
	add(btnBlue_);
	add(btnEraser_);
	add(spinBtnUp_);
	add(spinBtnDown_);

	//item 들을 상위 container 에 연결
	menuBar_->addCompo(menuPickFigure_);
	menuBar_->addCompo(menuPourColor_);
	menuBar_->addCompo(menuEraser_);
	menuBar_->addCompo(spinBtnUp_);
	menuBar_->addCompo(spinBtnDown_);	

	menuPickFigure_->addCompo(btnRect_);
	menuPickFigure_->addCompo(btnOval_);

	menuPourColor_->addCompo(btnBlack_);
	menuPourColor_->addCompo(btnRed_);
	menuPourColor_->addCompo(btnBlue_);

	menuEraser_->addCompo(btnEraser_);

	//위치, 길이 초기화
	menuBar_->setBounds(50, 10, 140, 25);

	menuPickFigure_->setBounds(10, 40, 70, 25);
	menuPourColor_->setBounds(85, 40, 70, 25);
	menuEraser_->setBounds(160,	40,	70,	25);

	btnRect_->setBounds(10, 70, 70, 25);
	btnOval_->setBounds(10, 95, 70, 25);

	btnBlack_->setBounds(85, 70, 70, 25);
	btnRed_->setBounds(85, 95, 70, 25);
	btnBlue_->setBounds(85, 120, 70, 25);

	btnEraser_->setBounds(160, 70, 90, 25);

	spinBtnUp_->setBounds(260, 40, 25, 25);
	spinBtnDown_->setBounds(260, 70, 25, 25);
	//리스너 추가
	menuBar_->addActionListener(new PlusActionListener(this));

	menuPickFigure_->addActionListener(new PlusActionListener(this));
	menuPourColor_->addActionListener(new PlusActionListener(this));
	menuEraser_->addActionListener(new PlusActionListener(this));

	btnRect_->addPlusActionListener(new PlusActionListener(this));
	btnOval_->addPlusActionListener(new PlusActionListener(this));

	btnBlack_->addPlusActionListener(new PlusActionListener(this));
	btnRed_->addPlusActionListener(new PlusActionListener(this));
	btnBlue_->addPlusActionListener(new PlusActionListener(this));

	btnEraser_->addPlusActionListener(new PlusActionListener(this));

	spinBtnUp_->addActionListener(new PlusActionListener(this));
	spinBtnDown_->addActionListener(new PlusActionListener(this));
}

Component* PainterFrame::eventHandler(MyEvent e) {

	if (Frame::eventHandler(e) != nullptr) {
		return nullptr;
	}
	else {
		if (e.isLButtonUp()) {
			OutputDebugString(L"[leftClick]\n");
			end_ = e.getPos();
			Figure* f = find(start_);
			Component* c = findComponent(start_);

			if (e.isShiftKeyDown())			//shift 그룹화
			{			
				createGroup();
			}
			else if (e.isCtrlKeyDown())		//ctrl 이동
			{		
				if (f) f->move(end_.x_ - start_.x_, end_.y_ - start_.y_);
			}
			else {
				//도형 버튼 이벤트
				if (menuPickFigure_->mode_ % 2 == 1) {
					if (figType_ == RECT_TYPE) {
						myFigureList.push_back(tempFigure = new Rect(start_.x_, start_.y_, end_.x_, end_.y_));
						tempFigure->setParent(this);
					}
					else if (figType_ == OVAL_TYPE) {
						myFigureList.push_back(tempFigure = new Oval(start_.x_, start_.y_, end_.x_, end_.y_));
						tempFigure->setParent(this);
					}
				}				
				
				if (f){
					//색상 채우기 버튼 이벤트						
					if (menuPourColor_->mode_ % 2 == 1) {
						if (colorType_ == BLACK_TYPE) {							
							f->pourBlack();
						}
						else if (colorType_ == RED_TYPE) {
							f->pourRed();
						}
						else if (colorType_ == BLUE_TYPE) {
							f->pourBlue();
						}
					}
										
					//지우개의 ON OFF
					if (menuEraser_->mode_ % 2 == 1) {
						f->erase();						
					}					
				}	

				if (c) {
					//spinButton의 move					
					if (c->getX() == 260 && c->getY() == 40) {						
						for (auto i : myFigureList) {
							if (i->moveMode_ % 2 == 1) {
								OutputDebugString(L"북서로 move\n");
								i->move(-4, -4);
							}
						}
					}
					if (c->getX() == 260 && c->getY() == 70) {
						for (auto i : myFigureList) {
							if (i->moveMode_ % 2 == 1) {
								OutputDebugString(L"남동으로 move\n");
								i->move(4, 4);
							}
						}
					}					
				}
			}
			invalidate();
		}
		else if (e.isRButtonUp()) {
			OutputDebugString(L"[rightClick]\n");
			end_ = e.getPos();
			Figure* f = find(start_);

			if (f) {
				f->moveMode_++;
			}

			invalidate();
		}
	}
	return nullptr;
}

void PainterFrame::removeFigure(Figure* f) {
	myFigureList.remove(f);
}

void PainterFrame::reAddFigure(Figure* f) {
	myFigureList.push_back(f);
}

Figure* PainterFrame::find(MyPoint p) {
	for (auto f = myFigureList.rbegin(); f != myFigureList.rend(); f++) {
		if ((*f)->inside(p)) {
			return *f;
		}
	}
	return nullptr;
}

bool PainterFrame::containedIn(Figure* f, MyPoint start, MyPoint end) {
	return start.x_ < f->left_&& f->right_ < end.x_
		&& start.y_ < f->top_&& f->bottom_ < end.y_;
}

void PainterFrame::repaint() {
	Frame::repaint();
	for (auto i = myFigureList.begin(); i != myFigureList.end(); i++) {
		(*i)->draw(hDC_);
	}
}

void PainterFrame::createGroup() {		//중요. iterator로 탐색 도중에 삭제를 해버리면 안된다. 그래서 탐색하여 temp에 담아두고 탐색이 끝나면 temp와 같은 것을 삭제해준다.
	std::list<Figure*> temp;

	for (auto f : this->myFigureList) {
		if (containedIn(f, start_, end_)) {
			temp.push_back(f);
		}
	}

	if (!temp.empty()) {	//포함되는 figure이 하나라도 있으면
		Group* g = new Group();
		g->setParent(this);

		for (auto f : temp) {
			g->add(f);
			myFigureList.remove(f);
		}
		g->setBoundary();
		myFigureList.push_back(g);
	}
}

void PainterFrame::setFigType(Component* c) {
	//c에 따라서 사각형, 타원 선택
	if (c == btnRect_) {
		figType_ = RECT_TYPE;
	}
	else if (c == btnOval_) {
		figType_ = OVAL_TYPE;
	}
}

void PainterFrame::setPourColor(Component* c) {	
	//c에 따라서 black, red, blue 선택
	if (c == btnBlack_) {
		colorType_ = BLACK_TYPE;
	}
	else if (c == btnRed_) {
		colorType_ = RED_TYPE;
	}
	else if (c == btnBlue_) {
		colorType_ = BLUE_TYPE;
	}
}