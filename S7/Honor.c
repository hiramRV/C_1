/*  Week 2 honors
	Steven Rubio
	28/10/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Typdef card*/
typedef struct card{ int suit; short pips;} card;

/*Creation of a card, given the values*/
card create_card(int s, short p){
	card card1;
	card1.suit = s%13 +1;	//We ensure values from 1 to 13
	card1.pips = p%4;		//We ensure values from 0 to 3
	return card1;
}

//Print card values
void print_card(card c){
	printf("(%d, %d) \n",c.suit, c.pips);
	
}

//Deck creation
void create_deck(card *deck){
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
	while(i<=500){	//I do 500 swaps. 
		int i1 = rand() % 52;
		int i2 = rand() % 52;
		if(i1!=i2)
			swap(&deck[i1],&deck[i2]);
		i++;
	}
}

//Create a hand for a player
void create_hand(card *hand, card *deck, int print){
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

//Basic int SWAP 
void swapInt(int *a, int *b){
	
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Bubble A. for Sorting
void bubble(int data[], int NUM){
	
	int i,j;
	for(i=0;i<NUM;i++){
		for(j = NUM-1;j>i;j--)
			if(data[j-1]>data[j])
				swapInt(&data[j-1],&data[j]);
	}
}

//Function to check 4OAK, FullHouse,3OAK, 2P, 1P and NP
int check_hand(card *hand, int print){
	//Print its a flag tho print specific thigs for debbuging 
	int i;
	int d[7] = {0};	//Array of stored cards values
	//Fist, i store only the values
	for(i=0;i<7;i++)
		d[i]=hand[i].suit;
	
	//Sorting the array
	bubble(d,7);
	
	//Check for different elemnts. 
	int value = 0;	//This value ints modified for each case!
						//Going from 0 to 5
	for(i=0;i<7;i++){
		//4OAK
		if(d[i]==d[i+1] && d[i]==d[i+2] && d[i]==d[i+3] && value==0){
			if(print) printf("\nFour of a Kind!");
			value = 5;
		}
		//3OAK and Full House
		//verify 3 equal and 1 not equal value
		if(d[i]==d[i+1] && d[i]==d[i+2]&& d[i]!=d[i+3] && d[i]!=d[i-1]){
			if(value == 1 || value == 2){
				//FullHouse
				if(print) printf("\nFull House");
				value = 4;}
				
			else{
				//3OAK
				if(print) printf("\nThree of a Kind!");
				value = 3;}
		}
		//FullHouse, 2P, 1P
		//Verify 2 equal and 2 not equal values, the next and the previous
		if(d[i]==d[i+1] && d[i]!=d[i+2] && d[i]!=d[i-1]){
			//FullHouse
			if(value == 3){
				if(print) printf("\nFull House");
				value = 4;}
				
			//3 pairs, just for fun :)
			if(value == 2)
				if(print) printf("\nMultiple Pair");
			//2P
			if(value == 1){
				if(print)printf("\nTwo Pair");
				value = 2;}
			//1P
			if(value == 0){
				if(print) printf("\nA Pair");
				value = 1;
			}

		}
	}
	//NP
	if(value == 0)
		if(print) printf("\n No Pair");
	if(print){
		printf("\n\n");
		printf("Sorted values of the cards: \n");
		for(i=0;i<7;i++)
			printf("%d ",d[i]);
	}
	return value;
}

//A print_case
void print_hand_case(int value){
	switch(value){
	case 0:	printf("\nNo Pair");			break;	
	case 1:	printf("\nA Pair");				break;	
	case 2:	printf("\nTwo Pair");			break;	
	case 3:	printf("\nThree of a Kind");	break;
	case 4:	printf("\nFull House");			break;
	case 5:	printf("\nFour of a Kind");		break;
	default:	printf("%d its an error",value);
	}
}

//Function to print your hand
void print_hand(card *hand){
	for(int i =0;i<=6;i++)
		print_card(hand[i]);
}

//Function to evaluate 1,0000,000 hands
void million_hands(card *deck, int NUM){
	int NP = 0;
	int P1 = 0;
	int P2 = 0;
	int TOAK  = 0;
	int FullH = 0;
	int FOAK  = 0;
	int i = 0;
	int value;
	//Create the hand and check it. 
	for(i = 0;i<NUM;i++){
		card hand[7];
		create_hand(hand, deck, 0);
		value = check_hand(hand,0);
		if(value==0) NP++;
		if(value==1) P1++;
		if(value==2) P2++;
		if(value==3) TOAK++;
		if(value==4) FullH++;
		if(value==5) FOAK++;
	}
	//Print results
	printf("%d No Pairs: %f, real: 0.174119\n\n"	,NP, (NP/(NUM+0.0)));
	printf("%d Pairs: %f, real: 0.438225\n\n"		,P1, (P1/(NUM+0.0)));
	printf("%d Two Pairs: %f, real: 0.234955\n\n"	,P2, (P2/(NUM+0.0)));
	printf("%d Three of a Kind: %f, real: 0.048298\n\n",TOAK,  (TOAK/(NUM+0.0)));
	printf("%d Full House: %f, real: 0.025961\n\n"	,FullH, (FullH/(NUM+0.0)));
	printf("%d Four of a Kind: %f, real: 0.001680\n\n",FOAK,  (FOAK/(NUM+0.0)));
	printf("Total: \t%f ",((NP+P1+P2+TOAK+FullH+FOAK)/(NUM+0.0)));
}


int main(){
	//Some Print to show functionality
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
	
	//Test Hand
	card hand[7];
	create_hand(hand, deck, 0);
	printf("Your hand: \n");
	print_hand(hand);
	//Check hand 
	int value;
	value = check_hand(hand,0);
	print_hand_case(value);
	
	//The million hand
	printf("\n\n***The million hands Results****\n\n");
	million_hands(deck,1000000);
	return 0;
}