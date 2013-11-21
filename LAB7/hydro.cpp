/*
 * hydro.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: saasbook
 */

#include <iostream>
#include <stdlib.h>
#include "hydro.h"
using namespace std;

int main(void){
	FlowList x;
	int numRecords;
	displayHeader();
	numRecords = readData(x);
	int quit = 0;

	while(1){
		switch(menu()){
		case 1:
			displayHeader();
			pressEnter();
			break;
		case 2:
			addData();
			pressEnter();
			break;
		case 3:
			saveData();
			pressEnter();
			break;
		case 4:
			removeData();
			pressEnter();
			break;
		case 5:
			cout << "\nProgram terminated!\n\n";
			quit = 1;
			break;
		default:
			cout << "\nNot a valid input.\n";
			pressEnter();
		}
		if(quit == 1) break;
	}
}
