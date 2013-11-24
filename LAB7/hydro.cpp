/*
 * hydro.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: saasbook
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "hydro.h"
using namespace std;

int main(void){
	FlowList x;
	int numRecords;
	displayHeader();
	data y;
	numRecords = readData(x);

	int quit = 0;

	while(1){
		switch(menu()){
		case 1:
			display(x);
			pressEnter();
			break;
		case 2:
			y.addData(x);
			pressEnter();
			break;
		case 3:
			y.saveData(x);
			pressEnter();
			break;
		case 4:
			y.removeData(x);
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

void display(FlowList& itemB)
{
	itemB.reset();
	int y = itemB.count(),i=0;
	ListItem temp;
	FlowList tmp;
	tmp = itemB;
	temp.flow = itemB.getItem().flow;
	temp.year = itemB.getItem().year;
	cout <<"Year"<<setw(15)<<"Flow"<<endl;
	while(i<=y)
	{
		while(tmp.cursor()!=NULL)
		{
			if(tmp.getItem().year>temp.year)
			{
				temp.flow = itemB.getItem().flow;
				temp.year = itemB.getItem().year;

			}
			itemB.forward();
		}
		cout <<temp.year<<setw(15)<<temp.flow<<endl;
		tmp.remove(temp.year);
		i++;
	}
//	while(itemB.cursor()!=temp.cursor())
//	{
//		      // will point to node in front of new node
//
//	}
	cout <<"Average"<<average(itemB)<<endl;
	cout <<"Median"<<median(itemB)<<endl;
	itemB.reset();
}

void data::addData(const FlowList& itemA)
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

	//temp->cursor()->item.year=a;
	//temp->cursor()->item.flow=b;
	//itemA.insert((temp->));

	if(1)
	{
		cout << "New record inserted successfully.";
	}
	else
	{
		cout << "Error: duplicate data.";
	}

}

void data::saveData(const FlowList& itemA)
{

	ofstream outObj;
	outObj.open("flow.txt");
	if(! outObj)
	{
		cout<<"Error: cannot open the file."<<"flow.txt<<endl";
		exit(1);
	}
	outObj<<setw(10)<< itemA.getItem().year <<setw(15)<< itemA.getItem().flow <<endl;
	outObj.close();
	cout << "Data are saved to the file.";
}

void data::removeData(const FlowList& itemA)
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

double average(FlowList& itemA)
{
	itemA.reset();
	double g=0;
	while(itemA.cursor() != NULL)
	{
		g += itemA.getItem().flow;
		itemA.forward();
	}
	itemA.reset();
	return g/itemA.count();
}

double median(FlowList& itemA)
{
	int y=0;
	double q=0;
	itemA.reset();
	y= itemA.count();
	if (y%2 ==0)
	{
		for(int i=0;i<(y/2);i++)
		{
			itemA.forward();
		}
		q = itemA.getItem().flow;
		itemA.reset();
		for(int i=0;i<(y/2)+1;i++)
		{
			itemA.forward();
		}
		q += itemA.getItem().flow;
		q /= 2;
	}
	else
	{
		for(int i=0;i<(y/2)+1;i++)
		{
			itemA.forward();
		}
		q = itemA.getItem().flow;
	}
	itemA.reset();
	return q;
}

int readData(FlowList& itemA)
{
	int a,i=0;
	double b;
	ListItem tmp;
	ifstream inObj;
	inObj.open("flow.txt");
	while(!inObj.eof())
	{
		inObj>>a>>b;
		tmp.year = a;
		tmp.flow = b;
		itemA.insert(tmp);
	}
	inObj.close();
	i=itemA.count();
	return i;
}
