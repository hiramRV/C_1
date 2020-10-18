/*  Macros
	Steven Rubio
	18/10/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 0	

//Macro que genera valores aleatorios en un rango
#define RANGO 100
#define CANTIDAD 1000
#define	NOTA rand()%RANGO
#define LLENAR	for(i=0; i<CANTIDAD;i++)\
					data[i] = NOTA

//Funcion simple para imprimir data
void print_d(int d[], int NUM){
	int i;
	for(i=0;i<NUM;i++){
		printf("%d\t", d[i]);
		if((i+1)%10 ==0) printf("\n");
	}
}

//Main
int main(){
	int i;
	int data[CANTIDAD];
	srand(time(0));
	LLENAR;
	print_d(data, CANTIDAD);
	printf("\n");
	return 0;
}