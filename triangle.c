/*
 * triangle.c
 * ENCM 339 Fall 2009 Lab 1 Exercise C
 * Completed by: 
 * Lab Section:
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int nscan;
  int number_of_lines;
  int x,y,z;
  printf("How many lines would you like in the picture?\n");
  nscan = scanf("%d", &number_of_lines);
  if (nscan != 1) {
    printf("Your input could not be converted to an int.  I quit.\n\n");
    exit(1);
  }

  if (number_of_lines <= 0) {
    printf("The number of lines must be positive.  I quit.\n\n");
    exit(1);
  }

  printf("Here is your %d-line picture:\n", number_of_lines);
  
  for(x=number_of_lines;x>=1;--x)
  {
	  for(y=0;y<number_of_lines-x;++y)
		  printf(" ");
	  for(z=x;z<=2*x-1;++z)
		  printf("*");
	  for(z=0;z<(x-1);++z)
	  	  printf("*");
	  printf("\n");
  }
  return 0;
}

