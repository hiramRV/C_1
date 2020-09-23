/*  Week 2, assigment 2 
	Sine function
	Steven Rubio
	17/09/2020
*/

#include<stdio.h>
#include <math.h>

int main()
{ 
	//Flag for validate the input 
	bool flag = true;
	//Float variables
	float value, upperLimit = 1.0, downLimit = 0.0;
	
	//Loop to ensure the desired input 
	while (flag)
	{
		printf("\n\nType a value between 0 and 1 (not included): ");
		scanf("%f",&value);
		// If to check if the input is in range
		if (value> downLimit && value < upperLimit)
		{	
			printf("\n¡Value inside desired range!");
			// Flag value change to break loop
			flag = false;
		}
		else {
			printf("\n¡Value outside desired range!");
		}
	}
		//Print the sin of the input
		printf("\nSine of value typed: %f \n",sin(value));
	return 0;
}