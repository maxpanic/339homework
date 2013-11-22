/*
 * hydro.h
 *
 *  Created on: Nov 21, 2013
 *      Author: saasbook
 */

#ifndef HYDRO_H_
#define HYDRO_H_

#include "list.h"

void displayHeader();
//Print Title Screen

int menu();
//Print menu

void display();
//Display txt, average, and median

void addData(const FlowList& itemA);
//Add a data node

void removeData();
//Remove a data node

void pressEnter();
//Press enter cue

double average();
//Calculate the average

double median();
//Calculate the median

void saveData();
//Write new data to the txt

class readData{
public:

private:
};



#endif /* HYDRO_H_ */
