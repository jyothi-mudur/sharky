/*
 * sharkPuzzle.h
 *
 *  Created on: Feb 16, 2018
 *      Author: jyothi
 */

#ifndef SHARKPUZZLE_H_
#define SHARKPUZZLE_H_

#include "defines.h"
#include "card.h"
#include "neighbors.h"
#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>

class sharkPuzzle {
public:
	sharkPuzzle();
	~sharkPuzzle();
	void init();
	void vRunLoop();
private:
	std::map<int,card> sharkCards;
	std::list<int> ltAvailableCards;
	bool bIsCardRotated;
	int tPositions[9];
	int tPosition;
	int tRotations;
	std::vector<int> GetAvailableChoices(int CardNo, int pos);
	void initGrid();
	void initCards();
	bool placeCard(int CardNo, int pos);
	void removeCard(int pos);
    void printPuzzle();
    bool bCheckMatchingOfCards(int CardNo, int pos);
    bool bCheckMatchingOnLeft(int,int);
    bool bCheckMatchingOnRight(int,int);
    bool bCheckMatchingOnBottom(int,int);
    bool bCheckMatchingOnTop(int,int);
    bool eRotateCard
	   (eSharkPart eSelCardSharkPart,
	    int tNeighborPos,
		eDirection eDir);
    bool bSolvePuzzle(int tCardSelected, int defRotations=0);
    bool bCompareSharkParts(eSharkPart eSharkPart1, eSharkPart eSharkPart2);
    eSharkPart eGetMatchingSharkPart(eSharkPart);
};

#endif /* SHARKPUZZLE_H_ */
