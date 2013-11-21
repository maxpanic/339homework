// OLList.cpp

// ENCM 339  Lab 7 Exercise A



// Completed by:  YOUR NAME SHOULD GO HERE



#include <iostream>

using namespace std;



#include <stdlib.h>

#include "OLList.h"



OLList::OLList()

  : headM(0)

{

}



OLList::OLList(const OLList& source)

{

  copy(source);

}



OLList& OLList::operator =(const OLList& rhs)

{

  if (this != &rhs) {

    destroy();

    copy(rhs);

  }

  return *this;

}



OLList::~OLList()

{

  destroy();

}



void OLList::print() const

{

  cout << '[';

  if (headM != 0) {

    cout << ' ' << headM->item;

    for (const Node *p = headM->next; p != 0; p = p->next)

      cout << ", " << p->item; 

  }

  cout << " ]\n";

}



void OLList::insert(const ListItem& itemA)

{

  Node *new_node = new Node;

  new_node->item = itemA;



  if (headM == 0 || itemA <= headM->item) {

    new_node->next = headM;

    headM = new_node;

  }

  else {

    Node *before = headM;      // will point to node in front of new node

    Node *after = headM->next; // will be 0 or point to node after new node

    while(after != 0 && itemA > after->item) {

      before = after;

      after = after->next;

    }

    new_node->next = after;

    before->next = new_node;

  }

}



void OLList::remove(const ListItem& itemA)

{

  if (headM == 0 || itemA < headM->item)

    return;



  Node *doomed_node = 0;

  if (itemA == headM->item) {

    doomed_node = headM;

    headM = headM->next;

  }

  else {

    Node *before = headM;

    Node *maybe_doomed = headM->next;

    while(maybe_doomed != 0 && itemA > maybe_doomed->item) {

      before = maybe_doomed;

      maybe_doomed = maybe_doomed->next;

    }



  	before->next = maybe_doomed->next;



  }

    // point one

  

      // the remaining part of this function is missing. As part of exercise B

      // students are supposed to complete the rest of the definition of this function.



}



void OLList::destroy()

{



  // this function is not properly designed. As part part of the exercise B

  // students are supposed to complete the definition of this helper function. 

Node *srcPtr;

while(headM != NULL)

{

	srcPtr=headM;

	headM = headM->next;

	free(srcPtr);

}



}



void OLList::copy(const OLList& source)

{

  // The only effect of the next line is to tell the compiler

  // not to generate an "unused argument" warning.  Don't leave it

  // it in your solution.

//  (void) source;

//

//  cout << "OLList::copy was called but isn't ready for use"

//       << "--program is terminated.\n";

//  exit(1);

	if(source.headM == 0)

	{

		headM = 0;

	}

	else

	{

	Node *srcPtr = new Node;

	srcPtr = source.headM;

	Node *newCpy = new Node;

	Node *cpyPtr = newCpy;

	while(srcPtr)

	{

		newCpy->item=srcPtr->item;

		if(srcPtr->next !=0)

		{

		newCpy->next = new Node;

		newCpy = newCpy->next;

		}

		srcPtr = srcPtr->next;

	}

	headM = cpyPtr;

	}



}

