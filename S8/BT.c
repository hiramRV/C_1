/*  ADT Binary Tree
	Steven Rubio
	28/10/2020
*/

#include<stdio.h>
#include<stdlib.h>

typedef char DATA;
struct node{
	DATA d;
	struct node *left;
	struct node *right;
};

//Typedef para ahorra codigo
typedef struct node NODE;
typedef NODE *BTREE;

//Algoritmo para imprimir valores
void inorder(BTREE root){
	if(root != NULL){
		inorder(root->left);
		printf("%3c", root -> d); //Modificaro de print
		inorder(root->right);
	}
}
// Reserva de espacio en memoria para el nodo
BTREE new_node(void){
	return( malloc(sizeof(NODE))); }

//Creacion de nodo	
BTREE init_node(DATA d1, BTREE p1, BTREE p2){
	BTREE t;
	t = new_node();
	t -> d = d1;
	t -> left  = p1;
	t -> right = p2;
	return t;
}

//Metodo recursivo para crear arbol
BTREE create_tree(DATA a[], int i, int size){
	if(i>=size)
		return NULL;
	else
		return(init_node(a[i],
			create_tree(a, 2*i +1, size),
			create_tree(a, 2*i +2, size)));
}

int main(){
	char d[] = {'a', 'b', 'c', 'd', 'e','f','g'};
	BTREE b;
	b = create_tree(d,0,7);
	inorder(b);
	printf("\n\n");
	return 0;
}