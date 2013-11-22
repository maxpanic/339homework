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
	//numRecords = readData(x);
	int quit = 0;

	while(1){
		switch(menu()){
		case 1:
			display();
			pressEnter();
			break;
		case 2:
			addData(x);
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

void displayHeader()
{
	cout << "HEF Hydropower Studies–Fall 2008\n"
		 << "Program: Flow Studies\n"
		 << "Version: 1.0\n"
		 << "Lab section: B03"
		 << "Instructor : M. Moshirpour\n"
		 << "Teaching Assistant: Devin Smith\n"
		 << "Produced by: Sean Robertson and Nabil Muthanna"<< endl;
	pressEnter();
}

void pressEnter()
{
	cout << "\n<<< Press Enter to Continue>>>>\n"<<endl;
	if (cin.get() == '\n')
	{
		cout << "Great job!\n";
		cin.clear();
		cin.ignore(100,'\n');
	}
	else
	{
		cout << "I meant ONLY the ENTER key... Oh well.\n";
		cin.clear();
		cin.ignore(100,'\n');
	}

//	while ( true )
//	{
//
//	  if ( cin.get() == '\n' )
//	    break;
//
//	  cin.clear();                 // clear the flags
//	  cin.ignore( 1024, '\n' );    // ignore at most 1024 chars until '\n' found
//	}

}

int menu()
{
	int a;
	cout << "Please select one of the following operations\n"
		 << "1. Display flow list, average and median\n"
		 << "2. Add data\n"
		 << "3. Save data into the file\n"
		 << "4. Remove data\n"
		 << "5. Quit"
		 << "Enter your choice (1, 2, 3, 4, or 5):" << endl;
	cin >> a;
	return a;
}

void display()
{

}

void addData(const FlowList& itemA)
{
	FlowList* temp = new FlowList;

	int a;
	double b;
	cout << "\nPlease enter a year: ";
	cin >>a;
	cout << "\nPlease enter the flow: ";
	cin >>b;
	//temp->headM->item->year=a;
	//temp->headM->item->flow=b;
	//itemA.insert(temp->headM->item);
	temp->cursor()->item.year=a;
	temp->cursor()->item.flow=b;

	if(1)
	{
		cout << "New record inserted successfully.";
	}
	else
	{
		cout << "Error: duplicate data.";
	}

}

void saveData()
{
	cout << "Data are saved to the file.";
}

void removeData()
{
	int a;
	cout << "Please enter the year that you want to remove: ";
	cin >> a;

	if(1)
	{
		cout << "Record successfully removed.";
	}
	else
	{
		cout << "Error: No such data.";
	}
}

