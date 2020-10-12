/*  Merge Sort
	Steven Rubio
	10/10/2020
*/

#include<stdio.h>

void print_array(int NUM, int data[]){
	
	int i;
	
	for( i=0;i<NUM;i++)
		printf("%d\t", data[i]);
	printf("\n\n");
}

void merge(int a[], int b[], int c[], int NUM){
	
	int i =0, j = 0, k = 0;
	
	while (i<NUM && j<NUM){
		if(a[i]<b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];	}
	while (i<NUM)
		c[k++] = a[i++];
	while (j<NUM)
		c[k++] = b[j++];	
}


int main(void){
	
	const int NUM = 5;
	int a[NUM] = {5,8,12,17,19};
	int b[NUM] = {0,3,10,15,18};
	int c[2*NUM];
	printf("Mis notas: \t");
	print_array(NUM, a);
	printf("\t\t");
	print_array(NUM, b);
	merge(a,b,c,NUM);
	printf("\n Mis notas en orden: \t");
	print_array(2*NUM, c);
	
	return 0;
}