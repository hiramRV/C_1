/*	Arrays como parametros 
	Steven Rubio
	08/10/2020
*/

#include<stdio.h> 
//Calculo de promedio
double promedio_notas(int NUM, int notas[]){
	int i;
	double prom =0.0;
	//Forma alterna de calcular promedio
	for (i=0;i<NUM;i++)
		prom += (notas[i]-prom)/(i+1.0);
	
	return prom;
}
//print de nots
void print_notas(int NUM, int notas[]){
	int i;
	
	printf("Notas: ");
	for (i=0;i<NUM;i++)
		printf("%d\t",notas[i]);
}

//Main
int main(void){
	
	const int NUM = 3;
	int notas[NUM] = {10,15,20};
	
	print_notas(NUM,notas);
	printf("\n\n");
	printf("El promedio es: %lf\n\n",promedio_notas(NUM,notas));
	
	return 0;
}