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
void menu();

void display();

FlowList addData(const ListItem& itemA);

FlowList removeData(int target_year);

bool pressEnter();

class readData{
public:

private:
};



#endif /* HYDRO_H_ */
