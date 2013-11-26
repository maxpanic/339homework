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
//PROMISES: Print Title Screen

int menu();
//PROMISES: Print menu

void pressEnter();
//PROMISES: Press enter cue

int readData(FlowList& itemA);
//PROMISES: Read data

double average(FlowList& itemA);
//PROMISES: Calculate the average.

double median(FlowList& itemA);
//PROMISES: Calculate the median.

void display(FlowList& itemB);
//PROMISES: Display txt, average, and median

void removeData(FlowList& itemA);
//PROMISES: Remove a data node

void addData(FlowList& itemA,int autoMatic,int newYear,double newFlow);
//PROMISES: Add a data node

void saveData(FlowList& itemA);
//PROMISES: Write new data to the txt

#endif /* HYDRO_H_ */
