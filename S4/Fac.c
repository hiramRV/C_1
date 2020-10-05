/* Factorial
Steven Rubio
04/10/2020
*/
#include<stdio.h>
#include<time.h>

/*Para tener valores altos*/
//Metodo tradicional
long int factorial(int n){
	long f = 1;
	int i;
	for (i=1;i<=n;i++){
		f = f*i;
	}
	return f;
}

//Metodo recursivo
long int recursive_factorial(int n){
	if(n ==1)
		return 1;
	else
		return (recursive_factorial(n-1)*n);
}


int main(void){
	
	int how_many = 3,i;
	double timeI,timeT,timeI2,timeR;
	printf("Cuantos factoriales deseas calcular?: ");
	scanf("%d",&how_many);
	printf("factoriales\n");
	timeI = time(NULL);
	for (i=1;i<=how_many;i++){
		printf("\n%d\t %ld\n",i,factorial(i));
	}
	timeT = time(NULL);
	printf("---------------\n");
	
	timeI2 = time(NULL);
	for (i=1;i<=how_many;i++){
		printf("\n%d\t %ld\n",i,recursive_factorial(i));
	}
	timeR = time(NULL);
	printf("\n\n");
	printf("Algoritmo normal: %ld, Algoritmo recursivo: %ld",(timeI-timeT),(timeI2-timeR));
	return 0;
}