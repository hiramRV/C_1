/* 	Calculo area circulo
	Hiram RV
	07/09/2020
*/
	
#include <stdio.h>

#define PI 3.14159

int main()
{
	double area = 0.0, radio = 0.0;
	printf("Ingrese radio: \n");
	scanf("%lf", &radio);
	area = PI * radio * radio;
	printf("Radio de %lf unidades; Genera un area de %lf unidades cuadradas)",radio, area);
	return 0;
}