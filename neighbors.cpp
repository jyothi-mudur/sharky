#include "neighbors.h"

neighbors::neighbors() {
}

neighbors::~neighbors() {
}

int neighbors::tGetNeighborPosOnTop(int pos) {
	int neighborOnTop;
	switch(pos){
		case 0:
		case 1:
		case 2: {
			neighborOnTop = DEFAULT;
			break;
		}
		case 3:
		case 6: {
			neighborOnTop = pos-1;
			break;
		}
		case 4:
		case 7: {
			neighborOnTop = pos-3;
			break;
		}
		case 5:
		case 8: {
			neighborOnTop = pos-5;
			break;
		}
	}//switch
	return neighborOnTop;
}

int neighbors::tGetNeighborPosOnRight(int pos) {
	int neighborOnRight;
	switch (pos) {
		case 2:
		case 3:
		case 8: {
			neighborOnRight = DEFAULT;
			break;
		}
		case 0:
		case 1:
		case 6:
		case 7: {
			neighborOnRight = pos+1;
			break;
		}
		case 4:
		case 5: {
			neighborOnRight = pos-1;
			break;
		}
	}//switch
	return neighborOnRight;
}

int neighbors::tGetNeighborPosOnBottom(int pos) {
	int neighborOnBottom;
	switch(pos) {
		case 6:
		case 7:
		case 8:{
			neighborOnBottom = DEFAULT;
			break;
		}
		case 2:
		case 5:{
			neighborOnBottom = pos+1;
			break;
		}
		case 1:
		case 4:{
			neighborOnBottom = pos+3;
			break;
		}
		case 0:
		case 3:{
			neighborOnBottom = pos+5;
			break;
		}
	} // switch
	return neighborOnBottom;
}

int neighbors::tGetNeighborPosOnLeft(int pos) {
	int neighborOnLeft;
	switch(pos) {
		case 0:
		case 5:
		case 6:{
			neighborOnLeft = DEFAULT;
			break;
		}
		case 1:
		case 2:
		case 7:
		case 8: {
			neighborOnLeft = pos-1;
			break;
		}
		case 3:
		case 4:{
			neighborOnLeft = pos+1;
			break;
		}
	} // switch
	return neighborOnLeft;
}
