/*
 * threenum.c
 * ENCM 339 Fall 2009 Lab 1 Exercise B
 *
 * Completed by:    REPLACE THIS WITH YOUR NAME
 * Lab Section:     REPLACE THIS WITH YOUR LAB SECTION
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isEqual(int *a,int *b,int *c);
bool isSeven(int *a,int *b,int *c);
bool twoEqual(int *a,int *b,int *c);
bool nonDec(int *a,int *b,int *c);
int main(void)
{
  int a, b, c, nscan;  
  
  int winRar;

  /* Get values for a, b, and c from user.    */
  /* Quit if the user enters garbage.     */
  printf("Please enter a value for the int variable a: ");
  nscan = scanf("%d", &a);
  if (nscan != 1) {
    printf("Your input could not be converted to an int.  I quit.\n\n");
    exit(1);
  }

  printf("Please enter a value for the int variable b: ");
  nscan = scanf("%d", &b);
  if (nscan != 1) {
    printf("Your input could not be converted to an int.  I quit.\n\n");
    exit(1);
  }
  printf("Please enter a value for the int variable c: ");
  nscan = scanf("%d", &c);
  if (nscan != 1) {
    printf("Your input could not be converted to an int.  I quit.\n\n");
    exit(1);
  }

  /* Echo the values entered by the user. */
  printf("\nThe values you entered were a = %d, b = %d, and c = %d.\n",
         a, b, c);
  if(isEqual(&a, &b, &c))
    printf("\nThe values you entered are all equal!\n");
  else
    printf("\nThe values you entered are not all equal!\n");
  
  if (twoEqual(&a, &b, &c))
	  printf("Only two of your entries are identical!\n");

  if(isSeven(&a, &b, &c)){
    printf("You sent me a seven!\n");
  }
  else{
    printf("You didn't send me any sevens!\n");
  }

  if(nonDec(&a, &b, &c))
	  printf("Your entries are non-decreasing, clever!\n");
  else
	  printf("Your entries are not non-decreasing :(\n");


  return 0;
}

bool isEqual(int *a,int *b,int *c)
{
  if(*a==*b && *b==*c && *c==*a)
    return true;
  else
    return false;
}

bool isSeven(int *a,int *b,int *c)
{
  if(*a==7 || *b==7 || *c==7)
    return true;
  else
    return 0;
}

bool twoEqual(int *a,int *b,int *c)
{
  if(*a==*b || *a==*c || *b==*c)
	  return true;
  return false;
}

bool nonDec(int *a,int *b,int *c)
{
  if(*a<=*b && *b<=*c)
	  return true;
  return false;
}

