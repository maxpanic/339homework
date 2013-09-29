/*
 * avgspeed.c
 *
 *  Created on: Sep 28, 2013
 *      Author: saasbook
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

void avg_speed(double kmDist, int timeMin, double timeSec, double *kilo, double *meter, double *mile);
double fail(void);
int read_int(void);
double read_double(void);
bool specialChars(const char st);
void get_input(double *km_dist, int *time_min, double *time_sec);

const double milsPerMet = 1/(5280*12*0.0254);

int main(void)
{
	int timeMin;
	double kmDist, timeSec, kilo, meter, mile;

	get_input(&kmDist, &timeMin, &timeSec);

	printf("You traveled: %.2fkm, in: %d minutes, and: %.2f seconds.\n",kmDist,timeMin,timeSec);

	avg_speed(kmDist, timeMin, timeSec, &kilo, &meter, &mile);

	printf("The average speed was %f km/h,or %f m/s, or %f miles per hour.", kilo, meter, mile);

	return 0;
}

void get_input(double *km_dist, int *time_min, double *time_sec)
{
	printf("Please enter distance travelled in km:");
	*km_dist = read_double();
	printf("Now enter time of travel in minutes and seconds.\nFirst enter an integer number of minutes:");
	*time_min = read_int();
	printf("Now enter a number of additional seconds:");
	*time_sec = read_double();
}

void avg_speed(double kmDist, int timeMin, double timeSec, double *kilo, double *meter, double *mile)
{

double hour, toMins, totMins, toSec, mets, mils;

mets = kmDist*1000;
mils = milsPerMet*mets;
toMins = timeSec/60;
totMins = timeMin+toMins;
toSec = totMins*60;
hour = (totMins)/60;
*kilo = kmDist/hour;
*meter = mets/toSec;
*mile = mils/hour;
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

	return x;
}
double fail()
{
	 puts("Incorrect input value.");
	 exit (0);

}

bool specialChars(const char s)
{
	 if (s=='.'||s=='+'||s=='-'||s==','||s=='?'||s=='<'||s=='>')
		 return 1;
	 else
		 return 0;
}
