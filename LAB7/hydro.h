/*
 * hydro.h
 *
 *  Created on: Nov 21, 2013
 *      Author: saasbook
 */

#ifndef HYDRO_H_
#define HYDRO_H_
#include <fstream>
#include <iomanip>
#include "list.h"

void displayHeader();
//Print Title Screen

int menu();
//Print menu

void pressEnter();
//Press enter cue

int readData(FlowList& itemA);
//Read data

double average(FlowList& itemA);
//Calculate the average

double median(FlowList& itemA);
//Calculate the median

void display(FlowList& itemB);
//Display txt, average, and median

class data{
public:


	void saveData(const FlowList& itemA);
	//Write new data to the txt

	void addData(const FlowList& itemA);
	//Add a data node

	void removeData(const FlowList& itemA);
	//Remove a data node

private:
};



#endif /* HYDRO_H_ */
