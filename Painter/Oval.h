#pragma once
#include "Figure.h"

class Oval : public Figure {
public:
	Oval(int l, int t, int r, int b);
	void draw (HDC hdc) override;

	void pourBlack() override;
	void pourRed() override;
	void pourBlue() override;
};

