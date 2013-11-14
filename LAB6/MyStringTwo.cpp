// MyStringTwo.cpp
// ENCM 339 Fall 2013 Lab 6 Exercise D
//
// completed by:
// lab section:

#include <assert.h>
#include <string.h>
#include <iostream>

#include "MyStringTwo.h"

MyStringTwo::MyStringTwo()
  : lengthM(0), storageM(new char[1])
{
  storageM[0] = '\0';
}

MyStringTwo::MyStringTwo(const char *s)
  : lengthM(strlen(s))
{
  storageM = new char[lengthM + 1];
  strcpy(storageM, s);
}

MyStringTwo::~MyStringTwo()
{
  delete [] storageM;
  storageM = NULL;
}

int MyStringTwo::length() const
{
  return lengthM;
}

char MyStringTwo::get_char(int pos) const
{
  assert(pos >= 0 && pos < length());
  return storageM[pos];
}

const char * MyStringTwo::c_str() const
{
  return storageM;
}

void MyStringTwo::set_char(int pos, char c)
{
  assert(pos >= 0 && pos < length());
  assert(c != '\0');

  // point one 
  storageM[pos] = c;
}

// Students write definitions for append and truncate.

void MyStringTwo::append(const MyStringTwo& tail)
{
	int i=0;
	if (tail.length() != 0)
	{
		int j = lengthM;
		MyStringTwo temp(storageM);
		this->~MyStringTwo();
		storageM = new char[(lengthM += tail.lengthM) + 1];
		strcpy(storageM, temp.c_str());
		while (i < tail.length())
		{
			this->set_char((j),tail.get_char(i));
			i++;
			j++;
		}
		tail.~MyStringTwo();
	}

}

void MyStringTwo::truncate(int new_length)
{
	assert(0 <= new_length && new_length <= length());
	int i=0;
	MyStringTwo temp(storageM);
	if(new_length != 0)
	{

		this->~MyStringTwo();
		storageM = new char[new_length+1];
		lengthM = new_length;
		while (i < new_length)
		{
			storageM[i] = temp.get_char(i);
			i++;
		}
	}
	else
	{
		storageM[i]='\0';
	}
	temp.~MyStringTwo();
}
