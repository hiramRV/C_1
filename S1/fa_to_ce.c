/* 	Fahrenheit a Celsius
	Hiram RV
	07/09/2020
*/

#include <stdio.h>
int main()
{
	int fahr, cels;
	printf("Ingrese una temperatura en Fahrenheit como un entero: ");
	scanf("%d",&fahr);
	cels = (fahr-32)/1.8; //A pesar de que 1.8 es un double, la respuesta
	// Es un int, es una conversion silenciosa
	
	printf("\n %d fahrenheit son %d grados celsius.\n",fahr, cels);
	return 0;
}