/*	Pointers! 
	Steven Rubio
	08/10/2020
*/

#include<stdio.h>
int main(void){
	
	const int NUM = 5;
	int notas[NUM] = {78,67,92,83,88};
	double avg = 0;
	double *ptr_avg = &avg;
	int i;
	
	printf("\nMis notas son: \n");
	
	for (i=0;i<NUM;i++){
		printf("%d\t",notas[i]);
		avg = notas[i]+avg;
	}
	printf("\n\n");
	printf("El promedio es: %lf\n",avg/NUM);
	
	printf("El avg esta en %p, o %lu y el valor es %lf\n",ptr_avg,ptr_avg,*ptr_avg);
	printf("Las notas esta entre: %p, %p",notas,notas+5);
	return 0;
}