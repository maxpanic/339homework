// DynArray.h
// ENCM 339 Lab 6 Exercise E

// Author: Steve Norman
// Modified by: M. Moussavi

#ifndef DYNARRAY_H
#define DYNARRAY_H

// Edit this typedef if you want to change the element type.
typedef double EType;

class DynArray {
public:
  DynArray();
  // Create empty array.
  // PROMISES: size() == 0.

  DynArray(const EType *builtin, int sizeA); 
  // Create object by copying a built-in array.
  // REQUIRES
  //   sizeA >= 0. Elements builtin[0] ... builtin[sizeA - 1] exist.
  // PROMISES
  //   size() == sizeA.
  //   For i from 0 to sizeA-1, element i of object == builtin[i]. 

  DynArray(const DynArray& source);
  DynArray& operator =(const DynArray& rhs);
  ~DynArray();

  int size() const;
  // PROMISES: Return value is number of elements stored.

  EType at(int i) const;
  // REQUIRES: 0 <= i && i < size().
  // PROMISES: Return value is a reference to element i of array.

  void set(int i, EType new_value);
  // REQUIRES: 0 <= i && i < size().
  // PROMISES: assigns new_value to the ith element of storageM 

  void resize(int new_size);
  // REQUIRES: new_size >= 0.
  // PROMISES
  //   size() == new_size.
  //   If the operation shrinks the array or does not change the size,
  //   values of elements 0, 1, ... new_size - 1 are preserved.
  //   If the operation increases the size,
  //   values of elements 0, 1, ... one less than the old size
  //   are preserved.

private:
  int sizeM;
  EType *storageM;
};

// MEMORY MANAGEMENT STRATEGY
// 
//   storageM should point to a dynamic array of exactly sizeM elements.
//   constructors must allocate the array, and the destructor must deallocate it.
//   To change the size of the array, resize must allocate a new array,
//   copy elements from the old array, and deallocate the old array.
//
// NOTE
//   It may seem bizarre, but it's possible to allocate a dynamic
//   array with zero elements.  For example, the statement
//      storageM = new EType[0];
//   gives storageM the address of an array of size 0.
//   The advantage of this is that you don't have to write code
//   to handle empty arrays differently from non-empty arrays.


#endif
