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



Node *srcPtr;

// With a new node to hold the head, move the head forward and free the new node

// until head becomes null.

while(headM != NULL)

{

  srcPtr=headM;

  headM = headM->next;

  free(srcPtr);

}



}



void OLList::copy(const OLList& source)

{



  // Check to see if passed OLList is null.

  if(source.headM == 0)

  {

    headM = 0;

  }

  else

  {

  Node *srcPtr = new Node; // Create a pointer for the source.

  srcPtr = source.headM; // Set source pointer to source head.

  Node *newCpy = new Node; // Set a new node for copying.

  Node *cpyPtr = newCpy; // Set a node to point to the node for copying.



  // While the pointer is not NULL.

  // Copy each item from source via the pointer to the newCpy node.

  while(srcPtr)

  {

    newCpy->item=srcPtr->item;

    if(srcPtr->next !=0) // While source ptr next is not null, set the points for the new node.

    {

    newCpy->next = new Node;

    newCpy = newCpy->next;

    }

    srcPtr = srcPtr->next;

  }

  headM = cpyPtr; // Set this.headM to the cpyPtr's

  }



}

