/*  Tamaño de variables
	Steven Rubio
	16/09/2020
*/

#include<stdio.h>

int main(void)
{   
    printf("En mi sistema\n");
	printf("int ocupa %lu bytes. \n",sizeof(int));
	printf("long int ocupa %lu bytes. \n",sizeof(long int));
	printf("char ocupa %lu bytes. \n",sizeof(char));
	printf("float ocupa %lu bytes. \n",sizeof(float));
	printf("double ocupa %lu bytes. \n",sizeof(double));
	printf("long double ocupa %lu bytes. \n",sizeof(long double));
    return 0;
}   