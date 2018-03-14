/*
 * card.h
 *
 *  Created on: Feb 15, 2018
 *      Author: jyothi
 */

#ifndef CARD_H_
#define CARD_H_
#include "defines.h"
//#include <map>

class card {
public:
	card();
	card
	(
	  int tInt,
	  eSharkPart SharkPart1,
	  eSharkPart SharkPart2,
	  eSharkPart SharkPart3,
	  eSharkPart SharkPart4);
	~card();
	eSharkPart eRotateAndGetDetail(eDirection eDir, int tRotations=0);
	eSharkPart eGetDetail(eDirection eDir, int tRotations=0);
	int tGetCardNo() const;
	int tGetNoOfRotations() const;
	void vSetRotations(int tRotations);
	void vResetRotations();
private:
	int tCardNo;
	eSharkPart arCardSharkParts[4];
	int tNoOfRotations;
	eSharkPart eGetTop(int tRotations=0) const;
	eSharkPart eGetRight(int tRotations=0) const;
	eSharkPart eGetBottom(int tRotations=0) const;
	eSharkPart eGetLeft(int tRotations=0) const;
};

#endif /* CARD_H_ */
