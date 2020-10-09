/*  Bubble Sort
	Steven Rubio
	08/10/2020
*/

#include<stdio.h>

void swap(int *a, int *b){
	
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int NUM, int data[]){
	
	int i;
	
	for( i=0;i<NUM;i++)
		printf("%d\t", data[i]);
	printf("\n\n");
}

void bubble(int data[], int NUM){
	
	int i,j;
	int seguir;
	
	for(i=0;i<NUM;i++){
		
		print_array(NUM,data);
		printf("\n\ni = %d. Ingresa un int  para continuar: ",i);
		scanf("%d",&seguir);
		
		for(j = NUM-1;j>i;j--)
			if(data[j-1]>data[j])
				swap(&data[j-1],&data[j]);
	}
}

int main(void){
	
	const int NUM = 5;
	int notas[NUM] = {88,55,67,83,50};
	
	printf("Notas Originales: ");
	bubble(notas,NUM);
	printf("\n\nNotas Ordenadas: ");
	print_array(NUM,notas);
	return 0;
	
	
	
}