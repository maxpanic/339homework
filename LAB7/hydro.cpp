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
	int numRecords=0;
	displayHeader();
	numRecords = readData(x);

	int quit = 0;

	while(1){
		switch(menu()){
		case 1:
			display(x);
			pressEnter();
			break;
		case 2:
			addData(x,0,0,0);
			pressEnter();
			break;
		case 3:
			saveData(x);
			pressEnter();
			break;
		case 4:
			removeData(x);
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
	FlowList copy1;
	copy1 =x;
	addData(copy1,1,2012,459.99);
	addData(copy1,1,2013,2000.34);

	FlowList copy2;
	copy2 = copy1;
	copy2.remove(1922);
	copy2.remove(2003);
	copy2.remove(2001);

	cout << "\nValues in copy2 are:\n";
	display(copy2);

	cout << "\nValues in copy1 are:\n";
	display(copy1);

	cout << "\nValues in x are:\n";
	display(x);

	return 0;
}

void displayHeader()
{
	cout << "HEF Hydropower Studies–Fall 2008\n"
		 << "Program: Flow Studies\n"
		 << "Version: 1.0\n"
		 << "Lab section: B03"
		 << "Instructor : M. Moshirpour\n"
		 << "Teaching Assistant: Devin Smith\n"
		 << "Produced by: Sean Robertson and Nabil Muthanna\n"
		 << "Please press enter twice." <<endl;
	pressEnter();
}

void pressEnter()
{
	cout << "\n<<< Press Enter to Continue>>>>"<<endl;
	if (cin.get() == '\n') // Wait for input and check if input was strictly the enter key.
	{
		cin.clear(); // Clear the cin buffer.
		cin.ignore(100,'\n'); // Ignore all values except for \n and continue.

	}
	else // If not, display a gentle reminder and continue.
	{
		cout << "I meant ONLY the ENTER key... Oh well.\n";
		cin.clear();
		cin.ignore(100,'\n');
	}


}

int menu()
{
	int input; // Set a var to hold the user input.

	// Display the options.
	cout << "Please select one of the following operations\n"
		 << "1. Display flow list, average and median\n"
		 << "2. Add data\n"
		 << "3. Save data into the file\n"
		 << "4. Remove data\n"
		 << "5. Quit"
		 << "Enter your choice (1, 2, 3, 4, or 5):" << endl;
	cin >> input; // Get input.
	return input; // Return input for use in a switch.
}

void display(FlowList& itemB)
{
	itemB.reset(); // Reset the cursor.
	if (itemB.isOn()) // Quick check to make sure itemB has values and reset worked.
	{

	// Format the table header.
	cout <<"\nYear"<<setw(12)<<"Flow"<<endl;
	cout <<setw(16)<<setfill('-')<<""<<endl;

// The following function was created hastily to print the order by year, not implemented in this version
// but potentially useful.
//  ListItem temp;
//  FlowList tmp;
//  tmp = itemB;
//  tmp.reset();
//  int i=0, y = itemB.count();
//	while(i<y)
//	{
//	temp.flow = tmp.getItem().flow;
//	temp.year = tmp.getItem().year;
//	tmp.forward();
//
//		while(tmp.cursor()!=NULL)
//		{
//			if(tmp.getItem().year>temp.year)
//			{
//				temp.flow = tmp.getItem().flow;
//				temp.year = tmp.getItem().year;
//
//			}
//			tmp.forward();
//		}
//		cout <<temp.year<<setw(15)<<temp.flow<<endl;
//		tmp.reset();
//		tmp.remove(temp.year);
//		tmp.reset();
//		i++;
//	}

	// Do until the end of the link list.
	while(itemB.cursor()!=NULL)
	{
		itemB.print(); // Print the values at the node.
		itemB.forward(); // Move the cursor forward.
	}

	// Print the average and median values as calculated by the functions.
	cout <<"\nThe annual average of the flow is: "<<average(itemB)<<" million cubic meters."<<endl;
	cout <<"The median flow is: "<<median(itemB)<<" million cubic meters." <<endl;
	itemB.reset(); // Reset the node for safety.
	}
}

void addData(FlowList& itemA,int autoMatic,int newYear,double newFlow)
{
	ListItem temp; // Create a temp struct for passing data.
	int notExist=0; // Variable used in determining if duplicate data exists.

	// If values are to be manually added by uses autoMatic is false.
	if (autoMatic==0)
	{
	cout << "\nPlease enter a year: ";
	cin >>newYear;
	cout << "\nPlease enter the flow: ";
	cin >>newFlow;
	}

	// Set user data inside the temp struct, so it can be passed forward.
	temp.year=newYear;
	temp.flow=newFlow;
	itemA.reset(); // Reset the cursor.
	if(itemA.isOn()) // Check to see if reset was successful.
	{

	// Do until the end of the list.
	while(itemA.cursor()!=NULL)
	{
		notExist=1; // So far the users data is unique.

		// When the loop finds a matching year.
		if(itemA.getItem().year==newYear)
		{
			// Print and set notExist to false.
			cout << "\nError: duplicate data.\n";
			notExist=0;
			break;
		}
	itemA.forward(); // Move the cursor forward.
	}

	// If unique call insert and print success.
	if (notExist)
	{
		itemA.insert(temp);
		cout << "\nNew record inserted successfully.\n";
	}
	itemA.reset(); // Reset the cursor.
	}
}

void saveData(FlowList& itemA)
{
	ofstream outObj; // Create new ofstream object.
	outObj.open("flow.txt"); // Open flow.txt.

	// If open fails warn the user and exit.
	if(! outObj)
	{
		cout<<"\nError: cannot open the file."<<"flow.txt"<<endl;
		exit(1);
	}
	itemA.reset(); // Reset the cursor.
	if (itemA.isOn())
	{

	// Do until the end of the linked list. Print The current node, and move the cursor forward.
	while(itemA.cursor()!=NULL)
	{
		outObj<< itemA.getItem().year <<setw(12)<< itemA.getItem().flow <<endl;
		itemA.forward();
	}
	itemA.reset(); // Reset the cursor.
	outObj.close(); // Close the file.
	cout << "\nData are saved to the file.\n";
	}
}

void removeData(FlowList& itemA)
{
	int removeYear,notExist=0; // removeYear to hold target year, notExist to be used for uniquness checking.
	cout << "Please enter the year that you want to remove: ";
	cin >> removeYear;
	itemA.reset(); // Reset the cursor.
	if (itemA.isOn())
	{

	// Do until the end of the list.
	while(itemA.cursor()!=NULL)
	{
		notExist=1; // No matches yet.

		// Check each year item. Call remove on match, set notExist to false and message user.
		if(itemA.getItem().year==removeYear)
		{
			itemA.remove(removeYear);
			cout << "\nRecord successfully removed.\n";
			notExist=0;
			break;
		}
		itemA.forward(); // Move the cursor forward.
	}

	// If no matches were found prompt the user.
	if(notExist)
	{
		cout << "\nError: No such data.\n";
	}
	itemA.reset(); // Reset the cursor.
	}
}

double average(FlowList& itemA)
{
	double sum=0;
	itemA.reset(); // Reset the cursor.
	if(itemA.isOn()) // Check if reset was successful.
	{

	// Do until the end of the list.
	while(itemA.cursor() != NULL)
	{
		sum += itemA.getItem().flow; // Add each flow item together.
		itemA.forward(); // Move the cursor forward.
	}
	itemA.reset(); // Reset the cursor
	}
	return sum/itemA.count(); // Return the average, which is calculated by dividing the sum by the amount of nodes.
}

double median(FlowList& itemA)
{
	int nodes=0; // Initialize the nodes.
	double median=0; // Initialize the median.
	itemA.reset(); // Reset the counter.
	if(itemA.isOn()) // Check to see if reset operation was successful.
	{
	nodes= itemA.count(); // Get the number of nodes.

	// Two different methods to determine the median based on odd or even symmetry.
	if (nodes%2 ==0) // If an even amount of nodes.
	{
		for(int i=0;i<(nodes/2)-1;i++) // Count up the the first of the two middle nodes.
		{
			itemA.forward();
		}
		median = itemA.getItem().flow; // Add to the median.
		itemA.forward(); // Go to the next middle node.
		median += itemA.getItem().flow; // Add the two together.
		median /= 2; // Crudely interpolate.
	}
	else // If an odd node.
	{
		for(int i=0;i<(nodes/2);i++) // Move up to the middle
		{
			itemA.forward();
		}
		median = itemA.getItem().flow; // Get the middle value.
	}
	itemA.reset(); // Reset the counter.
	}
	return median; // Return the median.
}

int readData(FlowList& itemA)
{
	int newYear;
	double newFlow;
	ListItem temp; // Create a list item for temporary storage of variables.
	ifstream inObj; // Create a new ifstream object.
	inObj.open("flow.txt"); // Attempt opening of file.

	// If open fails warn the user and exit.
	if(! inObj)
	{
		cout<<"\nError: cannot open the file."<<"flow.txt"<<endl;
		exit(1);
	}

	// While cin is successful, until EOF is detected.
	while(inObj>>newYear>>newFlow)
	{
		// Set temp to the read values, and insert the node.
		temp.year = newYear;
		temp.flow = newFlow;
		itemA.insert(temp);
	}
	inObj.close(); // Close the file.

	return itemA.count(); // Return the number of nodes.
}
