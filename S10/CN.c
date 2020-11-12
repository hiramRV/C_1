//Cosas nuevas en c++
//Steven Rubio
//12/11/2020

#include<iostream>
using namespace :: std;

long long fact(int n){
	long long f = 1;
	for(int i = 1; i<=n;i++) f *=i; //Declaracion de i en el ciclo
	return f;
}

int main(void){
	
	cout << "This program uses some features not in C89\n";
	//Uso de auto para determinar el tipo de variablede i
	for(auto i = 0; i<=16; i++){
		cout << "factorial of " << i << " is " << fact(i) << endl;}
		
	cout << "Eso es todo amigos!" << endl;
}