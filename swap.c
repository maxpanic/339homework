/*
 *  swap.c
 *
 *  Started by:   S.A. Norman
 *
 *  Completed by:
 *   Lab Section:
 *          Date:
 *  
 */


#include <stdio.h>
#include <stdlib.h>



void swap(int* x, int* y);
/* REQUIRES: Given two integer values.
 *
 * PROMISES: To swap the value of the first integer with the value of the second integer.
 * 			 This is achieved by way of pointer arguments from the function call.
 */


int main(void)
{
  int a, b;     /* We try to exchange the values of these variables. */
  
  a = 339;
  b = 112;
  swap(&a, &b);
  
  return 0;
}


void swap(int* x, int* y)
{
  int temp;      /* extra storage needed for exchange */


  temp = *x;
  *x = *y;
  *y = temp;

}
