/* Fibonacci
Steven Rubio
04/10/2020
*/
#include<stdio.h>

long fib_t(int n){
	long f2 = 0, f1 = 1, f_old;
	int i;
	
	for(i=0; i<n;i++){
		f_old = f2;
		f2 = f2 + f1;
		f1 = f_old;
	};
	return f2;
}

long fib_r(int n){
	if(n<=1)
		return n;
	else
		return(fib_r(n-1) + fib_r(n-2));
}


int main(void){
	int how_many = 0,i;
	printf("Cuantos numeros de fibonacci deseas calcular?: ");	
	scanf("%d",&how_many);
	printf("\t Fibonacci \n");
	printf("i\t |normal |recursivo");
	for(i=0;i<how_many;i++)
		printf("\n%d\t |%ld \t |%ld",i,fib_t(i),fib_r(i));
	return 0;
}