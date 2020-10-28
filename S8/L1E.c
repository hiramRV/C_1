/*  ADT list
	Steven Rubio
	25/10/2020
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <assert.h>

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

//Contar elemenos (recursivo)
int contar(list *h){
	if(h==NULL) 
		return 0;
	else 
		return(1+contar(h->next));
}


//Concatenar (recursivo)
void concat(list* h1, list* h2){
	assert(h1!=NULL);
	if(h1->next == NULL)
		h1->next = h2;
	else
		concat(h1->next, h2);
}

//Insertar elemento entre dos elemenos de la lista
void insert(list* p1, list* p2, list* q){
	assert(p1->next == p2);
	p1 ->next = q;
	q  -> next = p2;
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
	print_list(head,"Lista con un elemento:");
	
	list listOfInt2;
	list* head2 = NULL;
	int data[6] = {2,3,4,5,6,8};
	head2 = array_to_list(data,6);
	print_list(head2,"\n\nLista con varios elementos");
	printf("\nCantidad de elementos :%d",contar(head2));
	
	
	printf("\nConcatenando listas");
	concat(head,head2);
	printf("\nCantidad de elementos :%d",contar(head));
	print_list(head,"\n\nLista concatenada");
	
	list E_insert;
	list* head3 = NULL;
	head3 = malloc(sizeof(list));
	head3 -> data = 99;
	head3 -> next = NULL;
	
	insert(head, head->next, head3);
	print_list(head,"\n\nLista con elemento insertado");
	return 0;
}