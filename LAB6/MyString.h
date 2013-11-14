// MyString.h
// ENCM 339 Fall 2006 Lab 6 Exercise B

#ifndef MyString_H
#define MyString_H

const int MAX_LENGTH = 19;

class MyString {
public:
  MyString();
  // PROMISES: length() == 0

  MyString(const char *b);
  // Creates object by copying a builtin string.
  // REQUIRES: b points to the beginning of a builtin string.
  // PROMISES:
  //    If strlen(b) <= MAX_LENGTH, object is initialized using
  //    all of the chars in the builtin string, and length() == strlen(b).
  //    Otherwise, the object is initialized using the first
  //    MAX_LENGTH chars in the builtin string, and length() == MAX_LENGTH.

  int length() const;
  // PROMISES: Returns number of valid characters (not including '\0')
  //    in the object.

  char at(int index) const;
  // REQUIRES: index >=0 && index < length()
  // PROMISES: Returns char at position i in the string.
  
  bool equals(const char *b) const;
  // REQUIRES: b points to the beginning of a builtin string.  
  // PROMISES: Returns true if this object contains the same string as
  //    the builtin string, false otherwise.
  
  bool equals(const MyString& other) const;
  // PROMISES: Returns true if this object contains the same string as
  //    the object other, false otherwise.

  const char* c_str() const;
  // PROMISES: Return value is points to beginning of builtin string
  //    within object.

  void set_char_at(int index, char replacement);
  // REQUIRES:
  //    index >=0 && index < length()
  //    replacement is a character code that is not '\0'.
  // PROMISES: at(index) == replacement.

  void append(const char *b);
  // REQUIRES: b points to the beginning of a builtin string.
  // PROMISES: String within object is lengthened by adding characters
  //   from the builtin string until either the end of the builtin string
  //   is reached or until the length of the string in the object is
  //   MAX_LENGTH.
 
  void append(const MyString& other);
  // PROMISES: String within object is lengthened by adding characters
  //   from other until either the end of other is reached or until
  //   the length of the string in the object is MAX_LENGTH.
  
  void truncate(int shorter_length);
  // REQUIRES: shorter_length >= 0 && shorter_length <= length()
  // PROMISES: 
  //   The string is shortened as follows: the first shorter_length
  //   characters are kept, and length() == shorter_length.

private:
  char storageM[MAX_LENGTH + 1];
  int lengthM;
};

#endif
