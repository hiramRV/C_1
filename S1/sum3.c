/* 	Read 3 inputs
	Hiram RV
	06/09/2020
*/

/* Para compilar:
	gcc -o sum3.exe sum3.c
*/	

#include <stdio.h>

int main(void)
{
	float a, b, c, sum;
	printf("Input three floats: \n");
	scanf("%f%f%f", &a, &b, &c);
	printf("a = %f,b = %f,c = %f\n", a,b,c);
	sum = a+b+c;
	printf("sum = %f\n\n :)",sum);
	return 0;
}