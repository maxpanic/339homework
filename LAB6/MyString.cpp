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

// Compare storageM to a given string pointer.
bool MyString::equals(const char *b) const
{
	int i=0;
	int newL=0;
	while(*b != '\0') // Find the length of the pointer.
	{
		newL++;
		b++;
	}
	b -=newL; // Set the pointer head back to zero.

	if (lengthM != newL) // Quick check to compare the lengths of sizeM and the string pointer.
		return false;

	do // Compare each string position char by char.
	{
		if(at(i) !=*b)
			return false;
		b++;
		i++;
	// Since we have already asserted that the lengths must be equal we only to be limited by
	// one string length. This assumes \0 is only used once, at the end of the string. 
	} while(storageM[i] != '\0'); 
	return true;
}

// Compare storageM to another MyString.
bool MyString::equals(const MyString& other) const
{
	int i=0;

	if (length() != other.length()) // Compare the lengths for easy elimination.
		return false;

	do // Compare what is in each string char by char.
	{
		if(at(i) != other.at(i))
			return false;
		i++;
	// Since we have already asserted that the lengths must be equal we only to be limited by
	// one string length. This assumes \0 is only used once, at the end of the string. 
	} while(storageM[i] != '\0');
	return true;
}

// Set a char in any position except for the last to a given replacement.
void MyString::set_char_at(int index, char replacement)
{
	assert(0 <= index && index <= length()); // Assert that the index is within the strings limits. Ammended from the .h file to make it more usefull.
	storageM[index] = replacement;
}

// Append one string to the end of storageM, up until the end of the MAX_LENGTH or the end of b.
void MyString::append(const char *b)
{
	while(lengthM < MAX_LENGTH && *b != '\0')
	{
		set_char_at(lengthM, *b); // Append the beginning of b to the end of storageM.
		lengthM++;
		b++;
	};
	storageM[lengthM] ='\0'; // Tack on the limiter.
}

// Append the contents of other to storageM.
void MyString::append(const MyString& other)
{
	int i=0;
	while(lengthM < MAX_LENGTH && other.storageM[i] != '\0')
		{
			set_char_at(lengthM, other.at(i)); // Append the beginning of other to the end of storageM.
			lengthM++;
			i++;
		};
		storageM[lengthM] ='\0';
}

// Truncate storageM.
void MyString::truncate(int shorter_length)
{
	assert(0 <= shorter_length && shorter_length <= length()); // Assert that shorter_length is within working bounds.

	storageM[shorter_length] = '\0'; // Simply add the limiter to the desired position, destructive but effective.
	lengthM = shorter_length;
}