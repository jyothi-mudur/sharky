/*
 * card.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: jyothi
 */

#include "card.h"

card::card() {
	tCardNo = 0;
	tNoOfRotations = 0;
}

card::card
	(int cardNo,eSharkPart top, eSharkPart right, eSharkPart bottom, eSharkPart left) {
	tCardNo = cardNo;
	tNoOfRotations = 0;
	arCardSharkParts[Top]=top;
	arCardSharkParts[Right]=right;
	arCardSharkParts[Bottom]=bottom;
	arCardSharkParts[Left]=left;
}

card::~card() {
	tCardNo = 0;
	//CardDetails.clear();
}

eSharkPart card::eGetDetail(eDirection eDir, int tRotations) {
	eSharkPart eSharkPartToReturn;
	// get the card detail
	switch(eDir) {
		case Top:{
			eSharkPartToReturn = eGetTop(tRotations);
			break;
		}
		case Right:{
			eSharkPartToReturn = eGetRight(tRotations);
			break;
		}
		case Bottom:{
			eSharkPartToReturn = eGetBottom(tRotations);
			break;
		}
		case Left: {
			eSharkPartToReturn = eGetLeft(tRotations);
			break;
		}
		default:{
			// error case, do nothing
			break;
		}
	} // switch
	return eSharkPartToReturn;
}

eSharkPart card::eRotateAndGetDetail(eDirection eDir, int tRotations) {
	return eGetDetail(eDir,tRotations);
}

int card::tGetCardNo() const {
	return tCardNo;
}
eSharkPart card::eGetTop(int tRotations) const {
	int tToFind = ((Top + tRotations) % 4);
	return arCardSharkParts[tToFind];
}

eSharkPart card::eGetRight(int tRotations) const {
	int tToFind = ((Right + tRotations) % 4);
	return arCardSharkParts[tToFind];
}

eSharkPart card::eGetBottom(int tRotations) const {
	int tToFind = ((Bottom + tRotations) % 4);
	return arCardSharkParts[tToFind];
}

eSharkPart card::eGetLeft(int tRotations) const {
	int tToFind = ((Left + tRotations) % 4);
	return arCardSharkParts[tToFind];
}

int card::tGetNoOfRotations() const {
	return tNoOfRotations;
}

void card::vSetRotations(int tRotations) {
	tNoOfRotations = tRotations;
}

void card::vResetRotations() {
	tNoOfRotations = 0;
}
