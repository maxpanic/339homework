/*
 * list.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: saasbook
 */

#include <iostream>
#include <iomanip>
#include <assert.h>
#include <stdlib.h>
#include "list.h"
using namespace std;

FlowList::FlowList()
  : headM(0), cursorM(0)
{
}

FlowList::FlowList(const FlowList& source)
{
  copy(source);
}

FlowList& FlowList::operator =(const FlowList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

FlowList::~FlowList()
{
  destroy();
}

void FlowList::print() const
{
  if (cursorM != NULL)
  {
    cout << cursorM->item.year<< setw(12)<< setfill(' ') << cursorM->item.flow <<endl;
  }
}

void FlowList::insert(ListItem itemA)
{
  Node *new_node = new Node;
  new_node->item.year = itemA.year;
  new_node->item.flow = itemA.flow;

  if (headM == 0 || itemA.flow <= headM->item.flow) {
    new_node->next = headM;
    headM = new_node;
  }
  else {
    Node *before = headM;      // will point to node in front of new node
    Node *after = headM->next; // will be 0 or point to node after new node
    while(after != 0 && itemA.flow > after->item.flow) {
      before = after;
      after = after->next;
    }
    new_node->next = after;
    before->next = new_node;
  }
}

void FlowList::remove(int target_year)
{
  if(headM!=0)
  {
    Node *doomed_node = 0;
      if (target_year == headM->item.year) // If the target year is in the first entry.
      {
      doomed_node = headM;
      headM = headM->next; // Set head to next.
    }
    Node*before=headM; // Create a node called before then set it to headM.
    Node*after=headM->next; // Create a node called after and set it to headM->next.

    // Do until the end of the list.
    while(after!=0)
    {
      if(after->item.year==target_year) // Check each item in after for the target year.
      {
        before->next=after->next; // Set before's next to after's next, so this node can be 'removed'
        free(after);
      }
      before=after; // Move the node pointers up.
      after=after->next;
    }
  }
}

void FlowList::destroy()
{
Node *srcPtr;
while(headM != NULL) // Do until headM is NULL.
  {
    srcPtr=headM; // Set srcPtr to headM.
    headM = headM->next; // Move headM up.
    free(srcPtr); // free srcPtr.
  }
}

void FlowList::copy(const FlowList& source)
{
  // This was all copied from OLList.cpp by unknown.
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
    newCpy->item.flow=srcPtr->item.flow;
    newCpy->item.year=srcPtr->item.year;
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

const Node* FlowList::cursor()const
{
  return cursorM; // Return the node cursorM is pointing to.
}

void FlowList::reset()
{
  cursorM=headM; // Set cursorM to headM.
}

ListItem& FlowList::getItem()const
{
  assert(cursor()!=NULL);
  return cursorM->item; // Return the ListItem cursorM is pointing to.
}

bool FlowList::isOn() const
{
  // Checks if cursorM is NULL, returns bool truth.
  if(cursorM==NULL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void FlowList::forward()
{
  assert(cursor()!=NULL);
  cursorM = cursorM->next; // Move cursorM to the next node.
}

const int FlowList::count()
{
  int counter=0; // Initialize counter.
  reset(); // Reset pointer.

  // Do until cursorM is NULL. Increment counter.
  while (cursorM != NULL)
  {
    counter ++;
    forward();
  }
  reset(); // Reset pointer.
  return counter; // Return the amount of nodes.
}
