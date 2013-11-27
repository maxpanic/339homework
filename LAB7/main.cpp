// main.cpp

// 

// ENCM 339 Lab 7 Exercise A

//

// Completed by: M. Moussavi



#include <iostream>

using namespace std;



#include "OLList.h"



int main()

{

  OLList the_list;



  cout << "List just after creation: ";

  the_list.print();

  

  the_list.insert(440);

  the_list.insert(330);

  the_list.insert(220);

  the_list.insert(550);

  cout << "List after some insertions: ";

  the_list.print();

  the_list.remove(550);

  the_list.remove(220);

  cout << "List after some removals: ";

  the_list.print();

  OLList a(the_list);

  a.insert(770);





  a.print();

  the_list.print();



  OLList b;

  OLList c(b); // This function uses copy!

  b.print(); // Should print blank

  c.print(); // Should print blank

  b.insert(89);

  b.print(); // Should print [89].

  OLList d(b);

  b.~OLList(); // This function uses destroy!

  b.print(); // Should print blank.

  d.insert(88);

  d.insert(15);

  d.insert(1000000);

  d.print(); // Should print [15,88,89,1000000]

  OLList e;

  e.insert(34);

  e=d; // Should make e from d, and disregard 34

  e.print(); // Should print [15,88,89,1000000]



  return 0;

}

