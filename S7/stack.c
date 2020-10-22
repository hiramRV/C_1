/*  ADT (Abstrack Data Types) STACK/PILA
	Ejemplo de esta estructura de datos no trivial
	Steven Rubio
	21/10/2020
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define VACIO -1
#define LLENO (MAX-1)

//Definicion del tipo de dato abstracto, las partes son
/*  - s   = La pila
	- top = Elemento en el top 
*/
typedef struct stack{char s[MAX];int top;} stack;
//Reinicio de la pila
void reset(stack *stk){stk->top = VACIO;}
//Nuevo elemento a la pila, este necesita un pointer (*)
// ya que vamos a modificar el valor de la variable
void push(char c, stack *stk){
	stk-> top++;
	stk-> s[stk->top] = c;
}

//Sacar el elemento superior
char pop(stack *stk){return (stk-> s[stk-> top--]);}
//Ver el elemento superior
char top(const stack *stk){return(stk->s[stk->top]);}

//Para revisar si la pila esta vacia o llena
int pila_vacia(const stack *stk){return (stk-> top == VACIO);}
int pila_llena(const stack *stk){return (stk-> top == LLENO	);}

int main(){
	//Inicializacion
	stack la_pila;
	const char *str = "murder ";
	char str_r[20];
	int i =0;
	//Reseteo de la pila y print de valores originales
	reset(&la_pila);
	printf("La lista original es: %s\n",str);
	//LLenado de la pila
	while(i <= 5){
		printf("%c\n",str[i]);
		push(str[i++],&la_pila);
	}
	i = 0;
	printf("--------\n");
	//Llenado en orden opuesto
	while(!pila_vacia(&la_pila)&& i<20)
		str_r[i++]=pop(&la_pila);

	printf("El reverso de la lista es: %s\n",str_r);
	return 0;
}