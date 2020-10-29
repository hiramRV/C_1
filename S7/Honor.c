/*  Week 2 honors
	Steven Rubio
	28/10/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Typdef card
typedef struct card{ int suit; short pips;} card;

//Creation of a card, given the values
card create_card(int s, short p){
	card card1;
	card1.suit = s%13 +1;	//We ensure values from 1 to 13
	card1.pips = p%4;		//We ensure values from 0 to 3
	return card1;
}

//Print card values
card print_card(card c){
	printf("(%d, %d) \n",c.suit, c.pips);
	
}

//Deck creation
card* create_deck(card *deck){
	int i,j,counter = 0;	//Index and counter for the number of cards
	for(i=0;i<=3;i++){
		for(j=0;j<=12;j++){
			deck[counter] = create_card(j,i);
			counter++;
		}
	}
}

//Fuction to swap cards
void swap(card *a, card *b){
	//swap in suits
	int temp = a -> suit;
	a -> suit= b -> suit;
	b -> suit = temp;
	//swap in pips
	int temp2 = a -> pips;
	a -> pips = b -> pips;
	b -> pips = temp2;
}

//Fuction to shuffle deck
void shuffle(card *deck){
	int i = 0;
	while(i<=100){	//I do 100 swaps. 
		int i1 = rand() % 52;
		int i2 = rand() % 52;
		if(i1!=i2)
			swap(&deck[i1],&deck[i2]);
		i++;
	}
}

//Create a hand for a player
card* create_hand(card *hand, card *deck, int print){
	//Print its a flag tho print specific thigs for debbuging 
	int r_val;		//Int to store the random value
	int i = 0;		//Index for the card in the hand
	int d[7] = {0};	//Array of stored cards values
	int count;		//Counter to now how many equal cards
	int ne;			//Flag when we have a new card
	while(i<=6){
		r_val = rand() % 52;	
		if(print) printf("Iteration/card> %d\n",i);
		if(i==0){	//The first case its always asigned
			if(print) printf("d[i]:%d-> %d \n",i,d[i]);
			hand[i] = deck[r_val];
			d[i] = r_val;		
			i++;
			}
		else{
			ne = 0;
			count=0;	//Initialization
			while(ne==0){
			//Check if the value was already used
				for(int k=0;k<i;k++){
					//This print its just to see the process
					if(print) printf("d[k]:%d-> %d =? %d\n",k,d[k],r_val); 
					if(d[k]==r_val)
						count++; //If a match its encounter, add 1
					}	
				if(count==0){ //This is the case for a new card
					if(print) printf("Count its 0!: %d\n",count);
					if(print) printf("i:%d-> %d \n\n",i,r_val);
					hand[i] = deck[r_val];
					d[i] = r_val;
					i++;
					ne = 1;			//We break the cycle
					}
				else{
					if(print) printf("Count not 0!!!!: %d\n\n",count);
					r_val = rand() % 52; 	//If it is no 0, we generate a new number
					count=0;				//Reset the counter
					}	
				}
			}
		}
}
//Function to print your hand
void print_hand(card *hand){
	for(int i =0;i<=6;i++)
		print_card(hand[i]);
}
int main(){
	
	srand(time(NULL)); //Seed
	//Deck
	card deck[52]; 
	create_deck(deck);
	printf("\n\nFirst card: ");
	print_card(deck[0]);
	printf("Last card: ");
	print_card(deck[51]);
	
	//shuffle
	shuffle(deck);
	printf("\n\tShuffle! \n\nFirst card: ");
	print_card(deck[0]);
	printf("Last card:  ");
	print_card(deck[51]);
	printf("\n\n");
	
	//Hand
	card hand[7];
	create_hand(hand, deck, 0);
	printf("Your hand: \n");
	print_hand(hand);
	
	return 0;
}