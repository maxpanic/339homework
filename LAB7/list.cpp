/*
 * list.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: saasbook
 */

#include <iostream>
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
  cout << '[';
  if (headM != 0) {
    cout << ' ' << headM->item.year;
    for (const Node *p = headM->next; p != 0; p = p->next)
      cout << ", " << p->item.flow;
  }
  cout << " ]\n";
}

void FlowList::insert(const ListItem& itemA)
{
  Node *new_node = new Node;
  new_node->item.year = itemA.year;

  if (headM == 0 || itemA.year <= headM->item.year) {
    new_node->next = headM;
    headM = new_node;
  }
  else {
    Node *before = headM;      // will point to node in front of new node
    Node *after = headM->next; // will be 0 or point to node after new node
    while(after != 0 && itemA.year > after->item.year) {
      before = after;
      after = after->next;
    }
    new_node->next = after;
    before->next = new_node;
  }
}

void FlowList::remove(int target_year)
{
  if (headM == 0 || target_year < headM->item.year)
    return;

  Node *doomed_node = 0;
  if (target_year == headM->item.year) {
    doomed_node = headM;
    headM = headM->next;
  }
  else {
    Node *before = headM;
    Node *maybe_doomed = headM->next;
    while(maybe_doomed != 0 && target_year > maybe_doomed->item.year) {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->next;
    }

    before->next = maybe_doomed->next;

  }
}

void FlowList::destroy()
{
Node *srcPtr;
while(headM != NULL)
  {
    srcPtr=headM;
    headM = headM->next;
    free(srcPtr);
  }
}

void FlowList::copy(const FlowList& source)
{
  // The only effect of the next line is to tell the compiler
  // not to generate an "unused argument" warning.  Don't leave it
  // it in your solution.
//  (void) source;
//
//  cout << "FlowList::copy was called but isn't ready for use"
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

Node* FlowList::cursor()const
{
  return cursorM;
}


void FlowList::reset()
{
  cursorM=headM;
}

ListItem& FlowList::getItem()const
{
  assert(cursor()!=NULL);
  return cursorM->item;
}

bool FlowList::isOn() const
{
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
  cursorM = cursorM->next;
}

int FlowList::count()
{
  int counter=0;
  reset();
  while (cursorM != NULL)
  {
    counter ++;
    forward();
  }
  return counter;
}