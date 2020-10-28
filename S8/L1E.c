/*  ADT list
	Steven Rubio
	25/10/2020
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//Definicion del tipo abstracto lista
typedef struct list{ int data; struct list *next;} list;
//Verificamos si esta vacia 
int vacia(const list *l){return (l==NULL);}

//Crear lista vacia
list* crear_lista(int d){
	list* head = malloc(sizeof(list));
	head -> data = d;
	head -> next = NULL;
	return head;
}

//Una nueva cabeza
list* agregar_enfrente(int d, list* h){
	list* head = crear_lista(d);
	head -> next = h;
	return head;
}

//Array a lista 
list* array_to_list(int d[], int size){
	list* head = crear_lista(d[0]);
	int i;
	for(i=1;i<size;i++)
		head = agregar_enfrente(d[i],head);
	return head;
}

//Forma de imprimir de forma iterativa
void print_list(list *h, char *titulo){
	printf("%s\n",titulo);
	while(h !=NULL){
		printf("%d :",h->data);
		h = h -> next;
	}
}

int main(){
	list listOfInt;
	list* head = NULL;
	head = malloc(sizeof(list));	//Funcion malloc para reservar espacio
	printf("sizeof(list) = %lu\n",sizeof(list)); //Print para ver el espacio que reservamos
	head -> data = 5;
	head -> next = NULL;
	print_list(head,"Lista con un elemento\n\n");
	
	list listOfInt2;
	list* head2 = NULL;
	int data[6] = {2,3,4,5,6,8};
	head2 = array_to_list(data,6);
	print_list(head2,"\n\nLista con varios elementos");
	return 0;
}