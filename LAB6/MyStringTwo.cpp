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
	int i=0; // Set a counter to 0.
	if (tail.length() != 0)
	{
		int j = lengthM; // Set a counter to the length of the first string.
		MyStringTwo temp(storageM); // Make a temp string and set it to hold the first string.
		this->~MyStringTwo(); // Delete the fisrt string.
		storageM = new char[(lengthM += tail.lengthM) + 1]; // Reallocate memory to storageM, whilst increasing lengthM to the proper size.
		strcpy(storageM, temp.c_str()); // Copy what was in temp to the reallocated storageM.
		while (i < tail.length())
		{
			this->set_char((j),tail.get_char(i)); // Starting at where the original string left off, add tail.
			i++;
			j++;
		}
		temp.~MyStringTwo(); // Deallocate temp.
	}

}

void MyStringTwo::truncate(int new_length)
{
	assert(0 <= new_length && new_length <= length()); // Make sure new_length is non-negative.
	int i=0;
	MyStringTwo temp(storageM); // Make a temp string and set it to hold the first string.
	if(new_length != 0) // For non-zero truncations.
	{

		this->~MyStringTwo(); // Deallocate this.
		storageM = new char[new_length+1]; // Reallocate to new size.
		lengthM = new_length; // Set length to new size.
		while (i < new_length)
		{
			storageM[i] = temp.get_char(i); // Copy temp into the new storageM up until the new size.
			i++;
		}
	}
	else // For truncation at zero, have to bypass set_char because of assertion.
	{
		storageM[i]='\0';
	}
	temp.~MyStringTwo(); // Deallocate temp.
}