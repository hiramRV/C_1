/*  Week 2, assigment 1 
	Correcting code 
	Steven Rubio
	17/09/2020
*/

#include<stdio.h>
#define PI 3.14159
int main(void)
{ 
	int radius;
	printf("Enter radius:");
	scanf("%d", &radius);
	printf("volume is : %g \n\n", 4*PI*radius*radius*radius/3.0 );
return 0;
}