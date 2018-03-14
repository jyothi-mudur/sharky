/*
 * neighbors.h
 *
 *  Created on: Feb 15, 2018
 *      Author: jyothi
 */

#ifndef NEIGHBORS_H_
#define NEIGHBORS_H_
#include <map>
#include <vector>
#include "defines.h"

class neighbors {
public:
	neighbors();
	~neighbors();
	int tGetNeighborPosOnTop(int pos);
	int tGetNeighborPosOnRight(int pos);
	int tGetNeighborPosOnBottom(int pos);
	int tGetNeighborPosOnLeft(int pos);
};

#endif /* NEIGHBORS_H_ */
