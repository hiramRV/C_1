/* 	Millas y Yardas a Km
	Hiram RV
	07/09/2020
*/
/*Comando de Pre - Procesamiento*/
#include <stdio.h>

int main(void)
{
	/*Declaracion con Inializacion*/
	int millas = 26, yardas = 385;
	/*Declatacion sin Inializacion*/
	double km;
	
	km = 1.609 * (millas + yardas/1760.0);
	printf("\n Una maraton son %lf km.\n",km);
	return 0;
}