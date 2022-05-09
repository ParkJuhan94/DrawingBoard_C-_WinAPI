#pragma once
#include "Figure.h"
#include <list> 

class Group: 
	public Figure
{
public:
	Group();

	void draw(HDC hdc);
	void add(Figure* n);
	void setBoundary();
	bool isEmpty();
	void move(int dx, int dy) override;

	void pourBlack() override;
	void pourRed() override;
	void pourBlue() override;
protected:
	std::list<Figure*> figList;
};

