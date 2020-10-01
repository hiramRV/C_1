/*  Ternary-operator 
	Steven Rubio
	29/09/2020
*/

#include<stdio.h>


int main(void)
{ 
	int vel;
	printf("\nIngrese su velocidad como un int: ");
	scanf("%d", &vel);
	vel = (vel <= 65)? (65):(vel<=80)? (80): (90);
	switch (vel)
	{
	case 65:	printf("\nNo es necesaria una multa \n");break;
	case 80:	printf("\nMulta ligera\n");break;	
	case 90:	printf("\nMulta Alta!!!\n");break;
	default:	printf("\nValor incorrecto ingresado");
	}	
	
	return 0;
}