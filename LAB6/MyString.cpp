// MyString.cpp
// ENCM 339 Fall 2006Lab 6 Exercise B

#include <cassert>
#include "MyString.h"

// IMPLEMENTATION GUIDELINES
//
// These guidelines must be followed to ensure that the c_str and
// length functions always do the right thing.
//
// 1. Ctors and non-const member functions are responsible for
// ensuring that '\0' is in the correct location in storageM when the
// function is done.
//
// 2. Ctors and non-const member functions are responsible for
// ensuring that the lengthM variable has the correct value when the
// function is done.


MyString::MyString()
  : lengthM(0)
{
  storageM[0] = '\0';
}

MyString::MyString(const char *b)
{
  int i;
  for (i = 0; i < MAX_LENGTH && b[i] != '\0'; i++)
    storageM[i] = b[i];
  storageM[i] = '\0';
  lengthM = i;
}

int MyString::length() const
{
  return lengthM;
}

const char * MyString::c_str() const
{
  return storageM;
}

char MyString::at(int index) const
{
  assert(0 <= index && index < length());
  return storageM[index];
}

bool MyString::equals(const char *b) const
{
	int i=0;
	int newL;
	while(*b != '\0')
	{
		newL++;
		b++;
	}
	b -=newL;

	if (lengthM != newL)
		return false;

	do
	{
		if(at(i) !=*b)
			return false;
		b++;
		i++;
	} while(storageM[i] != '\0');
	return true;
}

bool MyString::equals(const MyString& other) const
{
	int i=0;

	if (length() != other.length())
		return false;

	do
	{
		if(at(i) != other.at(i))
			return false;
		i++;
	} while(storageM[i] != '\0');
	return true;
}

void MyString::set_char_at(int index, char replacement)
{
	assert(0 <= index && index < length());
	storageM[index] = replacement;
}

void MyString::append(const char *b)
{

	while(lengthM < MAX_LENGTH && *b != '\0')
	{

		storageM[lengthM] = *b;
		lengthM++;
		b++;

	};
	storageM[lengthM] ='\0';

}

void MyString::append(const MyString& other)
{
	int i=0;
	while(lengthM < MAX_LENGTH && other.storageM[i] != '\0')
		{

			storageM[lengthM] = other.storageM[i];
			lengthM++;
			i++;

		};
		storageM[lengthM] ='\0';
}

void MyString::truncate(int shorter_length)
{
	assert(0 <= shorter_length && shorter_length <= length());

	storageM[shorter_length] = '\0';
	lengthM = shorter_length;
}
