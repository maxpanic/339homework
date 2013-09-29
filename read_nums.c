/*
 *  read_nums.c
 *
 *  Functions to read numbers with input error detection.
 *
 *    Started by:  S. A. Norman
 *
 *  Completed by:
 *   Lab section:
 *          Date:
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int read_int(void);
/*
 *  REQUIRES
 *      User has been prompted to type in an int.
 *  PROMISES
 *      If an int can be read from the standard input stream, that
 *      int is the return value.  If not, an error message is printed
 *      and exit is called with an argument of 1.
 */

double read_double(void);
/*
 *  REQUIRES
 *      User has been prompted to type in a double.
 *  PROMISES
 *      If a double can be read from the standard input stream, that
 *      double is the return value.  If not, an error message is printed
 *      and exit is called with an argument of 1.
 */
double fail(void);

bool specialChars(const char st);

int main(void)
{
  int the_int;
  double the_double;

  printf("Doing tests of read_int and read_double functions ...\n\n");  
  
  printf("Please try to enter an int: ");
  the_int = read_int();
  printf("read_int succeeded.  It read a value of %d.\n", the_int);

  /* Uncomment the following code when you're ready to test read_double. */

  printf("Please try to enter an double: ");
  the_double = read_double();
  printf("read_double succeeded.  It read a value of %g.\n", the_double);


  return 0;
}
 int read_int()
 {

	 int x,z;

	 scanf("%d",&x);
		 do
		 {

			 z=getc(stdin);

			 if (isalpha(z))
				 fail();
			 if (specialChars(z))
				 fail();
		 }while (z!='\n');

	puts("complete success");
	return x;

 }

 double read_double()
 {

	 double x,z;

	 scanf("%lf",&x);
		 do
		 {

			 z=getc(stdin);

			 if (isalpha(z))
				 fail();
			 if (specialChars(z))
				 fail();
		 }while (z!='\n');

	puts("complete success");
	return x;

 }
 double fail()
 {
	 puts("fail");
	 exit (0);

 }

 bool specialChars(const char s)
 {
	 if (s=='.'||s=='+'||s=='-'||s==','||s=='?'||s=='<'||s=='>')
		 return 1;
	 else
		 return 0;
//	 char str[20];
//	 if (sscanf(str, "%*[A-Za-z0-9_]%c", &st)){
//		 printf("%c",st);
//		 return 1;}
//	 else
//		 puts("serious");
//		 return 0;
 }
