// MyStringTwo.h
// ENCM 339 Fall 2013 lab 6 Exercise D

// Author: S. A. Norman
// Modified by: M. Moussavi 

#ifndef STRING_ONE_H
#define STRING_ONE_H

// WARNING
//   The MyStringTwo class has a major defect.  If you try to
//   copy a MyStringTwo object, bad things will happen.

class MyStringTwo {
public:
  MyStringTwo();
  // PROMISES: Empty string object is created.

  MyStringTwo(const char *s);
  // PROMISES: s points to first char of a built-in string. 
  // REQUIRES: String object is created by copying chars from s.

  ~MyStringTwo();

  int length() const;
  // PROMISES: Return value is number of chars in string.

  char get_char(int pos) const;
  // REQUIRES: pos >= 0 && pos < length()
  // PROMISES:
  //   Return value is char at position pos.
  //   (The first char in the string is at position 0.)

  const char * c_str() const;
  // PROMISES:
  //   Return value points to first char in built-in string
  //   containing the chars of the string object.

  void set_char(int pos, char c);
  // REQUIRES: pos >= 0 && pos < length(), c != '\0'
  // PROMISES: Character at position pos is set equal to c.
  
  void append(const MyStringTwo& tail);
  // PROMISES: chars are copied from tail to the end of the
  //     string object.

  void truncate(int new_length);
  // REQUIRES: new_length >= 0 && new_length <= length()
  // PROMISES: 
  //   Length of string is reduced to new_length.

private:
  int lengthM;
  char *storageM;
};

#endif
