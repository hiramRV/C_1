/*  ADT list Assigment 
	Steven Rubio
	02/11/2020
	Reference code: https://www.geeksforgeeks.org/bubble-sort-for-linked-list-by-swapping-nodes/?ref=rp
*/

#include<stdio.h>
#include<stdlib.h>

//Definition of List 
typedef struct list{ int data; struct list *next;} list;
//Verify if it is empty 
int vacia(const list *l){return (l==NULL);}

//Create and Empty list
list* crear_lista(int d){
	list* head = malloc(sizeof(list));
	head -> data = d;
	head -> next = NULL;
	return head;
}

//New Head
list* agregar_enfrente(int d, list* h){
	list* head = crear_lista(d);
	head -> next = h;
	return head;
}

//Array to list
list* array_to_list(int d[], int size){
	list* head = crear_lista(d[0]);
	int i;
	for(i=1;i<size;i++)
		head = agregar_enfrente(d[i],head);
	return head;
}

//Print
void print_list(list *h, char *titulo){
	printf("%s\n",titulo);
	int c = 0;
	while(h !=NULL){
		printf("%d\t",h->data);
		h = h -> next;
		c++;
		if(c%5 ==0) printf("\n"); //
	}
}

/*Function to swap the nodes */
list* swap(list* ptr1, list* ptr2) 
{ 
	//Temporal Variable
    list* tmp = ptr2->next; 
    ptr2->next = ptr1; 
    ptr1->next = tmp; 
    return ptr2; 
} 
  
/* Function to sort the list */
int bubbleSort(list* head, int count) 
{ 
    list** h; 
    int i, j, swapped; 
	//Loop for the number of iterations
    for (i = 0; i <= count; i++) { 
  
        h = head; 
        swapped = 0; //Initialization
		
        for (j = 0; j < count - i - 1; j++) { 
  
            list* p1 = *h; 
            list* p2 = p1->next; 
			//Check if the nodes are out of order
            if (p1->data > p2->data) { 
  
                /* update the link after swapping */
                *h = swap(p1, p2); 
                swapped = 1; 
            } 
			/*Update header
			We access h, then go to the next node and finally get the addres*/
            h = &(*h)->next; 
        } 
  
        /* break if the loop ended without any swap: The list is in order*/
        if (swapped == 0) 
            break; 
    } 
} 


int main(){
	list listOfInt2;
	list* head2 = NULL;
	int data[100] = {0};
	int i = 0;
	for(;i<100;i++){
		data[i] =rand()%100; //Numbers between 0 and 99 just to visualize better
	}
		
	head2 = array_to_list(data,100);
	print_list(head2,"\n\nList with 100 integers");
	printf("\n\n");
	//Sort
	bubbleSort(&head2,100);
	print_list(head2,"\n\nList with 100 sorted integers");
	
	
	return 0;
}