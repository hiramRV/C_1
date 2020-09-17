/*  Char's 
	Steven Rubio
	16/09/2020
*/

#include<stdio.h>

int main(void)
{   
	char s = 'g';
    printf("s en ASCII es %d \n", s);
	printf("s es el caracter %c \n", s);
	printf("Tres chars son: %c %c %c \n",s,s+10,s-10);
	printf("Tres notificaciones: %c%c%c \n",'\a','\a','\a');
	return 0;
}   