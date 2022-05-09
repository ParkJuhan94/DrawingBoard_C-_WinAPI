#include "calculatorframe.h"
#include <iostream>
#include <exception>
Frame* mainWindow = nullptr;
int main() {
	try {
		mainWindow = new CalculatorFrame(L"��ü������Ʈ", 1000,800);
		mainWindow->run();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}	
}
