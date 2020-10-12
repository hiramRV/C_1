/*  Full Merge Sort
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


void merge_sort(int key[], int NUM){
	
	int k,j;
	int w[NUM];
	
	for(k = 1; k<NUM; k*=2){
		for(j=0; j<NUM-k;j+=2*k)
			merge(key+j, key+j+k,w+j,k);
		for(j=0;j<NUM;j++)
			key[j]=w[j];
		//Modificacion para ver cada iteracion
		printf("\nk = %d:\t",k);
		print_array(NUM,key);
	}
}


int main(void){
	
	const int NUM = 8;
	int a[NUM] = {5,8,12,1,20,16,19,17};
	printf("Mis notas: \t");
	print_array(NUM, a);
	printf("\t\t");
	merge_sort(a,NUM);
	printf("\nMis notas en orden: \t");
	print_array(NUM, a);
	
	return 0;
}