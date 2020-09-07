/* 	Millas y Yardas a Km
	Hiram RV
	07/09/2020
*/
/*Comando de Pre - Procesamiento*/
#include <stdio.h>

int main(void)
{
	
	int millas, yardas;
	double km;
	printf("Ingrese las millas y yardas como enteros: ");
	scanf("%d%d",&millas,&yardas);
	
	km = 1.609 * (millas + yardas/1760.0);
	printf("\n%d Millas y %d Yardas son %lf km.\n",millas, yardas,km);
	return 0;
}