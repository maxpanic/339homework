/*
 * quadratic.c
 * ENCM 339 Fall 2009 Lab 1 Exercise E
 * Completed by: Sean Robertson
 * Lab Section:B03
 */

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

int exam_coef(double a, double b, double c, double discriminant);
/* REQUIRES: Real numbers provided by the user and discriminant function.
 * PROMISES: Returns an integer to use in a switch */

double disc(double a, double b, double c);
/* REQUIRES: Real numbers provided by the user.
 * PROMISES: Returns the value of the discriminant using the equation b^2-4ac */

double shortLin(double a, double b);
/* REQUIRES: Real numbers provided by the user.
 * PROMISES: Returns the value of a single variable polynomial using the equation -c/b */

double singleRoot(double a, double b);
/* REQUIRES: Real numbers provided by the user.
 * PROMISES: Returns the value of a single root polynomial using the equation -b/2a */

double posQuad(double a, double b, double discriminant);
/* REQUIRES: Real numbers provided by the user and discriminant function.
 * PROMISES: Returns the larger value of a two root polynomial using the quadratic formula. */

double negQuad(double a, double b, double discriminant);
/* REQUIRES: Real numbers provided by the user and discriminant function.
 * PROMISES: Returns the smaller value of a two root polynomial using the quadratic formula. */

int main(void)
{
  double a,b,c,discriminant,root;
  int examResults;

  printf("Please enter your first coefficient:");
  scanf("%lf", &a);
  printf("Please enter your second coefficient:");
  scanf("%lf", &b);
  printf("Please enter your last coefficient:");
  scanf("%lf", &c);

  discriminant = disc(a,b,c); //Find the value of the discriminant.

  examResults = exam_coef(a, b, c, discriminant); //Examine the coefficients and discriminant.

  switch(examResults)
  {
  case 0:
    printf("You have a constant: %.4f", c);
    break;
  case 1:
    printf("You have a single variable polynomial, root: ");
    root=shortLin(b,c);
    printf("%.4f", root);
    break;
  case 2:
	printf("This equation has a single root: ");
	root=singleRoot(a,b);
    printf("%.4f", root);
	break;
  case 3:
  	printf("This equation has two roots: ");
  	root=posQuad(a,b,discriminant);
  	printf("%.4f and ",root);
  	root=negQuad(a,b,discriminant);
  	printf("%.4f",root);
  	break;
  case 4:
  	printf("This equation has no roots");
  	break;
  }
  return 0;
}

int exam_coef(double a, double b, double c, double discriminant)
{
	int tmp= 0;

	if(a==0 && b==0)
		tmp = 0;
	else if(a==0 && b!=0)
		tmp = 1;
	else if(discriminant==0)
        tmp = 2;
    else if(discriminant>=0)
    	tmp = 3;
    else if(discriminant<=0)
    	tmp = 4;

	return tmp;
}
double disc(double a, double b, double c)
{
    return (((b)*(b))-(4*(a)*(c)));
}
double shortLin(double b, double c)
{
	return (-c)/b;
}
double singleRoot(double a, double b)
{
	return (-b)/(2*a);
}
double posQuad(double a, double b, double discriminant)
{
	double x = sqrt (discriminant);
	return ((-b)+(x))/(2*a);
}
double negQuad(double a, double b, double discriminant)
{
	double x = pow (discriminant, 0.5);
	return ((-b)-(x))/(2*a);
}
