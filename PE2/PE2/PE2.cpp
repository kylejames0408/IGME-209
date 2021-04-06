#include <stdio.h>	//#3 - include stdio.h to give access to "printf"

int main()
{
	//#4 - print "Hello World" with "\n" character
	printf("Hello World!\n");

	//#5 - experiment with variables
	//a - calculate how many seconds are in the month of December as an integer
	const int SECONDS_IN_MIN = 60;
	const int MINUTES_IN_HOUR = 60;
	const int HOURS_IN_DAY = 24;
	const int DAYS_IN_DECEMBER = 31;
	int secondsInDecember = SECONDS_IN_MIN * MINUTES_IN_HOUR * HOURS_IN_DAY * DAYS_IN_DECEMBER;

	//b - calculate the area of a circle with radius 6.2 (double) using 3.14159 as PI
	const double RADIUS = 6.2;
	const double PI = 3.14159;
	double circleArea = RADIUS * RADIUS * PI;

	//c - determine how integer division works in C
		//i - it truncates
	int a = 10;
	int b = 4;
	int c = a / b;

	//#6 - print out the results of calculations
	//5a
	printf("There are %i seconds in December\n", secondsInDecember);
	
	//5b
	printf("The area of a circle with radius 6.2 using 314159 as PI is %f \n", circleArea);

	//5c
	printf("The answer to 10 / 4 in integer division is %i, showing that integer division truncates in C\n", c);
}