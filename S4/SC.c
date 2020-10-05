/* Storage?
Steven Rubio
04/10/2020
*/
#include<stdio.h>
//Variable global?
int reps =0;

//Funcion
void f(void){
	static int called = 0;
	printf("f called %d\n",called);
	called++;
	reps = reps + called;
}

//Main
int main(void){
	int i = 1;
	const int Limit = 10;
	for(i=1;i<Limit;i++){
		printf("i local = %d, reps global =%d\n",i,reps);
		f();
	}
	return 0;
}