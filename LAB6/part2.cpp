// part2.cpp
// ENCM 339 Fall 2013 Lab 6 Exercise D



#include <iostream>
using namespace std;

#include "MyStringTwo.h"

int main()
{
  MyStringTwo x("foo");
  MyStringTwo y;
  MyStringTwo z("tball");

  x.append(y);
  cout << "Contents of x: \"" << x.c_str()
       << "\" (expected \"foo\")." << endl;
  cout << "Length of x: " << x.length()
       << " (expected 3).\n" << endl;

  x.append(z);
  cout << "Contents of x: \"" << x.c_str()
       << "\" (expected \"football\")." << endl;
  cout << "Length of x: " << x.length()
       << " (expected 8).\n" << endl;

  x.truncate(4);
  cout << "Contents of x: \"" << x.c_str()
       << "\" (expected \"foot\")." << endl;
  cout << "Length of x: " << x.length()
       << " (expected 4).\n" << endl;

  x.truncate(0);
  cout << "Contents of x: \"" << x.c_str()
       << "\" (expected \"\")." << endl;
  cout << "Length of x: " << x.length()
       << " (expected 0).\n" << endl;

  return 0;
}
