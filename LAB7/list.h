/*
 * list.h
 *
 *  Created on: Nov 21, 2013
 *      Author: saasbook
 */

#ifndef LIST_H_
#define LIST_H_

typedef struct ListItem {
  int year;
  double flow;
}ListItem;

struct Node {
  ListItem item;
  Node *next;
};

class FlowList{
public:
  FlowList(); // PROMISES: Creates empty list.
  FlowList(const FlowList& source); // Make a copy of passed Flowlist.
  FlowList& operator =(const FlowList& rhs); // Assigns Flowlist on the left to the Flowlist on the right.
  ~FlowList(); // Destructor.

  void insert(ListItem itemA);
  // PROMISES:
  //    A node with a copy of itemA is added in
  //    a way that preserves the nondecreasing
  //    order of flow in nodes.

  void remove(int target_year);
  //  PROMISES:
  //    If no node has an year matching itemA.year,
  //    list is unchanged.
  //    Otherwise exactly one node with
  //    its year == itemA.year is removed.

  void print() const;
  // PROMISES:
  //   Prints items in list on a single line, with max width of 12 in order year    flow.

  const Node* cursor()const;
  // PROMISES: Returns the Node (including values) at cursorM's position.

  void reset();
  // PROMISES: Set cursorM to the beginning of the list.

  ListItem& getItem()const;
  // PROMISES: Get the items in the ListItem (of the node in this case).

  bool isOn() const;
  // PROMISES: Check to see if the cursor is NULL.

  void forward();
  // PROMISES: Moves the cursor up one on the linked list.

  const int count();
  // PROMISES: Count the amount of nodes in the list.

private:
  Node *headM;

  Node *cursorM;

  void destroy();
  // Deallocate all nodes, set headM to zero.

  void copy(const FlowList& source);
  // List becomes copy of source.
};
#endif /* LIST_H_ */
