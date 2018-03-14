/*
 * sharkPuzzle.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: jyothi
 */

#include "sharkPuzzle.h"

sharkPuzzle::sharkPuzzle() {
	initGrid();
	initCards();
	tPosition = 0;
	tRotations = 0;
	bIsCardRotated = false;
}

sharkPuzzle::~sharkPuzzle() {
	initGrid();
	ltAvailableCards.clear();
	bIsCardRotated = false;
}

void sharkPuzzle::initCards() {
	sharkCards[0] = card(1,L1,H1,W2,S2);
	sharkCards[1] = card(2,L2,W2,S1,H2);
	sharkCards[2] = card(3,W1,S1,L1,H2);
	sharkCards[3] = card(4,W1,H1,L2,S1);
	sharkCards[4] = card(5,W1,H2,L2,S1);
	sharkCards[5] = card(6,H1,H2,L1,W1);
	sharkCards[6] = card(7,S2,H2,L2,W2);
	sharkCards[7] = card(8,S1,S2,L2,H1);
	sharkCards[8] = card(9,W2,H1,L2,S1);
	for (int index = 0; index < (ROWS*COLUMNS); index++) {
		ltAvailableCards.push_back(sharkCards[index].tGetCardNo());
		// reset the car rotations
		sharkCards[index].vResetRotations();
	}
}

void sharkPuzzle::initGrid() {
	for(int pos = 0; pos < 9; pos++) {
		tPositions[pos] = 0;
	}
}

void sharkPuzzle::init() {
	initGrid();
	initCards();
}

void sharkPuzzle::printPuzzle() {
	for(int pos=0;pos < 9; pos++) {
		int tRotations = sharkCards[tPositions[pos]-1].tGetNoOfRotations();
		std::cout << "pos[" << pos << "]:" << tPositions[pos] << ":[" << tRotations << "]" << std::endl;
	}
	std::cout << "******************" << std::endl;
	init();
}

eSharkPart sharkPuzzle::eGetMatchingSharkPart(eSharkPart eSharkPartToComp) {
	eSharkPart eSharkPartToReturn;
	switch(eSharkPartToComp) {
		case W1:{
			eSharkPartToReturn = W2;
			break;
		}
		case W2:{
			eSharkPartToReturn = W1;
			break;
		}
		case S1:{
			eSharkPartToReturn = S2;
			break;
		}
		case S2:{
			eSharkPartToReturn = S1;
			break;
		}
		case L1:{
			eSharkPartToReturn = L2;
			break;
		}
		case L2:{
			eSharkPartToReturn = L1;
			break;
		}
		case H1:{
			eSharkPartToReturn = H2;
			break;
		}
		case H2:{
			eSharkPartToReturn = H1;
			break;
		}
		default:{
			break;
		}
	}
	return eSharkPartToReturn;
}

bool sharkPuzzle::bCompareSharkParts(eSharkPart eSharkPart1, eSharkPart eSharkPart2) {
	if (eSharkPart2 == eGetMatchingSharkPart(eSharkPart1)) {
		return true;
	}
	else return false;
}

bool sharkPuzzle::eRotateCard
	(eSharkPart eNeighborCardSharkPart,
	 int tSelCard,
	 eDirection eDir) {
	bool bReturn = false;
	tRotations = (sharkCards.find(tSelCard-1)->second).tGetNoOfRotations();
	// if the card is already rotated, get the rotations and the corresponding shark part
	eSharkPart eSharkPartToComp =
			(sharkCards.find(tSelCard-1)->second).eRotateAndGetDetail(eDir,tRotations);

	if (true == bIsCardRotated) {
		return (bCompareSharkParts(eNeighborCardSharkPart,eSharkPartToComp));
	}
	while (tRotations < 4) {
		if(bCompareSharkParts(eNeighborCardSharkPart,eSharkPartToComp)) {
			bReturn = true;
			break;
		} else {
			tRotations++;
			eSharkPartToComp =
			(sharkCards.find(tSelCard-1)->second).eRotateAndGetDetail(eDir,tRotations);
		}
	}

	(sharkCards.find(tSelCard-1)->second).vSetRotations(tRotations);
	bIsCardRotated = true;
	return bReturn;
}

bool sharkPuzzle::bCheckMatchingOnTop(int CardNo,int pos) {
	//bIsCardRotated = false;
	// get the neighboring card position on top
	neighbors myNeighbors;
	int tNeighPos = myNeighbors.tGetNeighborPosOnTop(pos);
	if (DEFAULT == tNeighPos) {
		return true;
	} else if(0 == tPositions[tNeighPos]){
		return true;
	}
	else
	{
		//bIsCardRotated = true;
		// get the shark part for the neighbor card
		int tNeighborRotations =
			(sharkCards.find(tPositions[tNeighPos]-1)->second).tGetNoOfRotations();
		eSharkPart sharkPartNeighborCard =
			(sharkCards.find(tPositions[tNeighPos]-1)->second).eGetDetail(Bottom,tNeighborRotations);
		return eRotateCard(sharkPartNeighborCard,CardNo,Top);
	}
}

bool sharkPuzzle::bCheckMatchingOnRight(int CardNo,int pos) {
	// get the neighboring card position on top
	neighbors myNeighbors;
	int tNeighPos = myNeighbors.tGetNeighborPosOnRight(pos);
	if (DEFAULT == tNeighPos) {
		return true;
	} else if(0 == tPositions[tNeighPos]){
		return true;
	} else {
		//bIsCardRotated = true;
		// get the shark part for the neighbor card
		int tNeighborRotations =
			(sharkCards.find(tPositions[tNeighPos]-1)->second).tGetNoOfRotations();
		eSharkPart sharkPartNeighborCard =
			(sharkCards.find(tPositions[tNeighPos]-1)->second).eGetDetail(Left,tNeighborRotations);
		return eRotateCard(sharkPartNeighborCard,CardNo,Right);
	}
}

bool sharkPuzzle::bCheckMatchingOnBottom(int CardNo,int pos) {
	// get the neighboring card position on top
	neighbors myNeighbors;
	int tNeighPos = myNeighbors.tGetNeighborPosOnBottom(pos);
	if (DEFAULT == tNeighPos) {
		return true;
	} else if(0 == tPositions[tNeighPos]){
		return true;
	} else {
		// get the shark part for the neighbor card
		int tNeighborRotations =
			(sharkCards.find(tPositions[tNeighPos]-1)->second).tGetNoOfRotations();
		eSharkPart sharkPartNeighborCard =
			(sharkCards.find(tPositions[tNeighPos]-1)->second).eGetDetail(Top,tNeighborRotations);
		return eRotateCard(sharkPartNeighborCard,CardNo,Bottom);
	}
}

bool sharkPuzzle::bCheckMatchingOnLeft(int CardNo,int pos) {
	// get the neighboring card position on top
	neighbors myNeighbors;
	int tNeighPos = myNeighbors.tGetNeighborPosOnLeft(pos);
	if (DEFAULT == tNeighPos) {
		return true;
	} else if(0 == tPositions[tNeighPos]){
		return true;
	} else {
		// get the shark part for the neighbor card
		int tNeighborRotations =
			(sharkCards.find(tPositions[tNeighPos]-1)->second).tGetNoOfRotations();
		eSharkPart sharkPartNeighborCard =
			(sharkCards.find(tPositions[tNeighPos]-1)->second).eGetDetail(Right,tNeighborRotations);
		return eRotateCard(sharkPartNeighborCard,CardNo,Left);
	}
}

bool sharkPuzzle::bCheckMatchingOfCards(int CardNo, int pos) {
	bIsCardRotated = false;
	if (pos != 0) {
		tRotations = 0;
		(sharkCards.find(CardNo-1)->second).vResetRotations();
	}

	if (true == (bCheckMatchingOnTop(CardNo,pos) &&
	   bCheckMatchingOnRight(CardNo,pos) &&
	   bCheckMatchingOnBottom(CardNo,pos) &&
	   bCheckMatchingOnLeft(CardNo,pos))){
		(sharkCards.find(CardNo-1)->second).vSetRotations(tRotations);
		return true;
	} else {
		(sharkCards.find(CardNo-1)->second).vResetRotations();
		return false;
	}

}

std::vector<int> sharkPuzzle::GetAvailableChoices(int CardNo, int pos) {
	std::vector<int> ResultVector;
	ResultVector.clear();

	// check available card list until a valid card is obtained
	std::list<int>::iterator ltIterator;
	for(ltIterator = ltAvailableCards.begin();
			ltIterator != ltAvailableCards.end();
			ltIterator++) {
		if(bCheckMatchingOfCards(*ltIterator,pos)) {
			ResultVector.push_back(*ltIterator);
		}
	}
	return ResultVector;
}

void sharkPuzzle::removeCard(int pos) {
	// Update the available list of cards
	ltAvailableCards.push_back(tPositions[pos]);
	(sharkCards.find(tPositions[pos]-1)->second).vResetRotations();
	tPositions[pos]= 0;
}

bool sharkPuzzle::placeCard(int CardSelected, int pos) {
	bool bReturn = false;
	// check if card can be placed in the given position
	if ((tPositions[pos] == 0) &&
			(bCheckMatchingOfCards(CardSelected,pos))){
		// first set the rotations
		(sharkCards.find(CardSelected-1)->second).vSetRotations(tRotations);
		tPositions[pos] = CardSelected;
		bReturn = true;

		// remove this card from the list of available cards
		std::list<int>::iterator ltIterator;
		int tSize = ltAvailableCards.size();
		for (ltIterator = ltAvailableCards.begin();ltIterator != ltAvailableCards.end(); ltIterator++) {
			if(CardSelected == (*ltIterator)) {
				ltAvailableCards.erase(ltIterator);
				ltAvailableCards.resize(tSize-1);
				break;
			}
		}
	}
	return bReturn;
}

bool sharkPuzzle::bSolvePuzzle(int tCardSelected,int defRotations) {
	bool bReturn = false;
	if(tPosition >= 9) {
		printPuzzle();
		bReturn = true;
		return bReturn;
	} else {
		if(tPosition == 0) {
			sharkCards[tCardSelected-1].vSetRotations(defRotations);
			tRotations = defRotations;
			placeCard(tCardSelected,tPosition);
			tPosition++;
		}
		std::vector<int> vtAvailableChoices = GetAvailableChoices(tCardSelected,tPosition);
		std::vector<int>::iterator itAvailChoices;
		for(itAvailChoices = vtAvailableChoices.begin();itAvailChoices != vtAvailableChoices.end(); ++itAvailChoices) {
			if(placeCard(*itAvailChoices,tPosition)) {
				tPosition++;
				bSolvePuzzle(*itAvailChoices);
			}
		}
		if (tPosition >= 9) { // all the positions are filled. simply exit!
			bReturn = true;
		} else {
			--tPosition;
			removeCard(tPosition);
		}
	}
	return bReturn;
}

void sharkPuzzle::vRunLoop() {
	for(int tCardNo = 1; tCardNo < 10; tCardNo++) {
		//tPosition = 0;
		// do it considering all 4 rotations
		for (int defRotation = 0; defRotation < 4; defRotation++) {
			tPosition = 0;
			if(bSolvePuzzle(tCardNo,defRotation)) {
				//break;
			}
		}
	}
}


