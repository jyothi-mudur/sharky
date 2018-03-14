/*
 * main.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: jyothi
 */
#include <iostream>
#include "sharkPuzzle.h"
int main() {
	sharkPuzzle* mySharkPuzzle = new sharkPuzzle();;
	mySharkPuzzle->vRunLoop();
	delete mySharkPuzzle;
	return 0;
}



