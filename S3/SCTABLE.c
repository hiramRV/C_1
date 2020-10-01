/*  Sin and Cos Table 
	Steven Rubio
	29/09/2020
*/

#include<stdio.h>
#include<math.h> 

int main(void)
{ 
//Iniciacion de variables
double valor;
int i;

printf("%10s%10s%10s\n%10s%10s%10s\n\n","Valor","Sin","Cos","_______","_______","_______");

for(i = 0; i <=100; i++)
{
	valor = i/100.0; //Calculo de un valor entre 0 y 1
	printf(" %lf  | %lf  | %lf \n",valor,sin(valor),cos(valor)); //Print sin y Cos
}

return 0;
}