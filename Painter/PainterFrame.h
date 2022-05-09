#pragma once
#include "frame.h"

class EraserButton;
class FigTypeButton;
class PourColorButton;
class Figure;
class PainterFrame :
    public Frame
{
public:    
	PainterFrame();
	PainterFrame(std::wstring, int width, int height);

	Component* eventHandler(MyEvent e) override;
	void repaint() override;
	void initialize() override;

	Figure* find(MyPoint);
	bool containedIn(Figure*, MyPoint, MyPoint);
	void createGroup();
	void setFigType(Component* c);
	void setPourColor(Component* c);
	void removeFigure(Figure* f);
	void reAddFigure(Figure* f);

	//그림판을 위한 상수를 정의
	static const int RECT_TYPE = 1;
	static const int OVAL_TYPE = 2;
	static const int BLACK_TYPE = 1;
	static const int RED_TYPE = 2;
	static const int BLUE_TYPE = 3;

protected:
	Component* menuBarParent_;
	Component* menuBar_;

	Component* menuPickFigure_;
	FigTypeButton* btnRect_;
	FigTypeButton* btnOval_;

	Component* menuPourColor_;
	PourColorButton* btnBlack_;
	PourColorButton* btnRed_;
	PourColorButton* btnBlue_;

	Component* menuEraser_;
	EraserButton* btnEraser_;

	Component* spinBtnUp_;
	Component* spinBtnDown_;

	//이 상수들은 숨겨놔야함.
	int figType_ = 0;
	int colorType_ = 0;

	Figure* tempFigure;
	std::list<Figure*> myFigureList;
};
